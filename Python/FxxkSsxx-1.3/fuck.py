#!/usr/bin/python3

# -*- coding: utf-8 -*-

import requests
import json
import time
import random
import re
import hashlib
import os
import platform
import sys
import traceback
import getopt
import base64

VERSION_NAME = "fxxkSsxx 1.3 test"

answer_dictionary = {}
expireTime = -1
hit_count = 0
modeIdList = [
    "5f71e934bcdbf3a8c3ba51d5",  # 英雄篇
    "5f71e934bcdbf3a8c3ba51d6",  # 创新篇
    "5f71e934bcdbf3a8c3ba51d7",  # 复兴篇
    "5f71e934bcdbf3a8c3ba51d8",  # 信念篇
]
modeId = modeIdList[1]
informEnabled = False
autoRefreshTokenEnabled = False


class MyError(Exception):
    def __init__(self, code, msg):
        self.code = code
        self.msg = msg

    def __str__(self):
        return "{}({})".format(self.msg, self.code)


def SubmitVerification(header):
    code = "HD1bhUGI4d/FhRfIX4m972tZ0g3jRHIwH23ajyre9m1Jxyw4CQ1bMKeIG5T/voFOsKLmnazWkPe6yBbr+juVcMkPwqyafu4JCDePPsVEbVSjLt8OsiMgjloG1fPKANShQCHAX6BwpK33pEe8jSx55l3Ruz/HfcSjDLEHCATdKs4="
    submit_data = {
        "activity_id": "5f71e934bcdbf3a8c3ba5061",
        "mode_id": modeId,
        "way": "1",
        "code": code
    }
    url = "https://ssxx.univs.cn/cgi-bin/save/verification/code/"
    response = requests.post(url, json=submit_data, headers=header)
    result = json.loads(response.text)
    if result["code"] != 0:
        raise MyError(result["code"], "提交验证码失败：" + str(result))


def CheckVerification(header):
    code = "E5ZKeoD8xezW4TVEn20JVHPFVJkBIfPg+zvMGW+kx1s29cUNFfNka1+1Fr7lUWsyUQhjiZXHDcUhbOYJLK4rS5MflFUvwSwd1B+1kul06t1z9x0mfxQZYggbnrJe3PKEk4etwG/rm3s3FFJd/EbFSdanfslt41aULzJzSIJ/HWI="
    submit_data = {
        "activity_id": "5f71e934bcdbf3a8c3ba5061",
        "mode_id": modeId,
        "way": "1",
        "code": code
    }
    url = "https://ssxx.univs.cn/cgi-bin/check/verification/code/"
    response = requests.post(url, json=submit_data, headers=header)
    result = json.loads(response.text)
    if result["code"] != 0:
        raise MyError(result["code"], "检查验证码失败：" + str(result))

    return result["status"]


def ParseToken(token):
    data = token.split('.')
    userInfo = json.loads(str(base64.b64decode(data[1] + "=="), "utf-8"))

    token_info = {
        "name": userInfo["name"],
        "uid": userInfo["uid"],
        "time": int(userInfo["iat"]),
        "expire": int(userInfo["exp"])
    }
    return token_info


def RefreshToken(header):
    url = "https://ssxx.univs.cn/cgi-bin/authorize/token/refresh/"
    response = requests.get(url, headers=header)

    result = json.loads(response.text)
    if result["code"] != 0:
        raise MyError(result["code"], "更新token失败：" + str(result["message"]))

    new_token = result["token"]

    detail = ParseToken(new_token)
    print("token更新完成，于 ", time.asctime(time.localtime(detail["time"])), " 生效")
    print("将在 ", time.asctime(time.localtime(detail["expire"])), " 失效")

    return new_token


def SendNotification(msg):
    if not informEnabled:
        print("[info] ", msg)
        return
    url = "http://localhost:6666"
    payload = {"type": "fxxkSsxx", "msg": msg}
    response = requests.post(url, json=payload)
    print(response.text)


def ReadAnswerFromFile():
    global answer_dictionary
    answer_file = open('answer.txt', 'r')
    answer_dictionary = json.loads(answer_file.read())
    print("已读取", len(answer_dictionary.items()), "个答案！")
    answer_file.close()


def SaveAnswerToFile():
    global answer_dictionary
    answer_file = open('answer.txt', 'w')
    answer_file.write(json.dumps(answer_dictionary))
    print("已保存", len(answer_dictionary.items()), "个答案！")
    answer_file.close()


def BuildHeader(token):
    headers = {
        'Accept': 'application/json, text/plain, */*',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'en-GB,en;q=0.9,zh-CN;q=0.8,zh;q=0.7',
        'Connection': 'keep-alive',
        'DNT': '1',
        'Host': 'ssxx.univs.cn',
        'Referer': 'https://ssxx.univs.cn/client/exam/5f71e934bcdbf3a8c3ba5061/1/1/' + modeId,
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36',
        'Authorization': 'Bearer ' + token,
    }

    return headers


def PrintQuizObject(quiz_object):
    print("问题ID列表：")
    for i in range(0, 20):
        print("问题", i, "：", quiz_object["question_ids"][i])


def StartQuiz(header):
    global hit_count
    hit_count = 0

    print("尝试开始考试……")

    url = "https://ssxx.univs.cn/cgi-bin/race/beginning/?activity_id=5f71e934bcdbf3a8c3ba5061&mode_id={}&way=1".format(
        modeId)

    for fail in [0, 1, 2]:    # 最多尝试等待3次
        response = requests.request("GET", url, headers=header)
        quiz_object = json.loads(response.text)
        status_code = quiz_object["code"]

        if status_code == 0:
            print("开始考试成功，本次考试信息如下：")
            print("race_code", quiz_object["race_code"])

            return quiz_object["question_ids"], quiz_object["race_code"]

        elif status_code == 4832:
            print("答题次数用完，等待10分钟")
            if fail == 0:   # 在开始等待时发送通知
                SendNotification("...")
            time.sleep(600)

        else:
            raise MyError(status_code, "开始考试失败：" + str(quiz_object))


def GetTitleMd5(title):
    title = re.sub(
        r"<(\w+)[^>]+?(?:display: {0,}none;).*?>.*?<\/\1>", "", title)
    title = re.sub("<.*?>", "", title)
    result = hashlib.md5(title.encode(encoding='UTF-8')).hexdigest()
    print(title, ", hash:", result)
    return result


def GetQuestionDetail(question_id, header):
    url = "https://ssxx.univs.cn/cgi-bin/race/question/?activity_id=5f71e934bcdbf3a8c3ba5061&question_id={}&mode_id={}&way=1".format(
        question_id, modeId)

    response = requests.request("GET", url, headers=header)

    question_detail_object = json.loads(response.text)
    if question_detail_object["code"] != 0:
        raise MyError(question_detail_object["code"], "获取题目信息失败。问题ID：" +
                      question_id + "错误信息：" + str(question_detail_object))

    print("获取题目信息成功。")

    question = {}
    question["id"] = question_detail_object["data"]["id"]
    question["title"] = GetTitleMd5(question_detail_object["data"]["title"])
    question["answer_list"] = []
    for i in question_detail_object["data"]["options"]:
        question["answer_list"].append((i["id"], GetTitleMd5(i["title"])))

    return question


def BuildAnswerObject(question):
    global answer_dictionary
    global hit_count

    print("正在尝试寻找答案……")

    answer_object = {
        "activity_id": "5f71e934bcdbf3a8c3ba5061",
        "question_id": question["id"],
        "answer": None,
        "mode_id": modeId,
        "way": "1"
    }

    if answer_dictionary.__contains__(question["title"]):
        hit_count += 1
        print("答案库中存在该题答案")
        answer_object["answer"] = []
        for i in question["answer_list"]:
            if i[1] in answer_dictionary[question["title"]]:
                answer_object["answer"].append(i[0])
    else:
        print("答案库中不存在该题答案，蒙一个A选项吧")
        answer_object["answer"] = [question["answer_list"][0][0]]

    return answer_object, question


def SubmitAnswer(answer_object, header):
    global answer_dictionary

    url = "https://ssxx.univs.cn/cgi-bin/race/answer/"

    header["Content-Type"] = "application/json;charset=utf-8"

    response = requests.request(
        "POST", url, headers=header, data=json.dumps(answer_object[0]))

    if response.status_code != 200:
        raise MyError(response.status_code, "提交答案失败")

    result_object = json.loads(response.text)

    if not result_object["data"]["correct"] and answer_dictionary.__contains__(answer_object[1]["title"]):
        print("答案库中已有答案但不正确！")
    elif result_object["data"]["correct"] and answer_dictionary.__contains__(answer_object[1]["title"]):
        return True
    elif result_object["data"]["correct"] and not answer_dictionary.__contains__(answer_object[1]["title"]):
        print("运气不错，居然蒙对了，保存答案")
    elif not result_object["data"]["correct"] and not answer_dictionary.__contains__(answer_object[1]["title"]):
        print("答案错误，更新答案")

    if not answer_dictionary.__contains__(answer_object[1]["title"]):
        answer_dictionary[answer_object[1]["title"]] = []

    for i in result_object["data"]["correct_ids"]:
        print("服务器返回的正确答案：", i)
        for j in answer_object[1]["answer_list"]:
            if i == j[0]:
                print("已在问题列表中找到该答案，元组为", j)
                answer_dictionary[answer_object[1]["title"]].append(j[1])
                break

    return result_object["data"]["correct"]


def FinishQuiz(race_code, header):
    url = "https://ssxx.univs.cn/cgi-bin/race/finish/"

    header["Content-Type"] = "application/json;charset=utf-8"
    payload = "{\"race_code\":\"" + race_code + "\"}"

    result = json.loads(requests.request(
        "POST", url, headers=header, data=payload).text)
    fail = 0
    while result["code"] != 0:
        print("完成考试时出错，错误代码：", result)
        err_code = result["code"]
        if err_code == 1001 or err_code == 1002:
            raise MyError(err_code, "请重新登录")
        fail += 1
        if fail > 5:
            raise MyError(err_code, "完成时出错：" + str(result))
        time.sleep(0.5)
        result = json.loads(requests.request(
            "POST", url, headers=header, data=payload).text)

    print("回答完毕，本次得分：", result["data"]["owner"]
          ["correct_amount"], "答案库命中数：", hit_count)


def Pause():
    if platform.system() == "Windows":
        os.system("pause")


def Start(token):
    global modeId
    global expireTime

    ReadAnswerFromFile()

    header = BuildHeader(token)

    try:
        while True:
            question_list, race_code = StartQuiz(header)
            for i in range(0, 20):
                if SubmitAnswer(BuildAnswerObject(GetQuestionDetail(question_list[i], header)), header):
                    print("第", i, "题回答正确！")
                    time.sleep(float(random.randint(500, 900)) / 1000)
                else:
                    print("第", i, "题回答错误，答案已更新！")
                    time.sleep(float(random.randrange(1500, 3000)) / 1000)

                if i == 10:
                    if CheckVerification(header):
                        print("验证码已通过")
                    else:
                        SubmitVerification(header)
                        print("验证码状态：", CheckVerification(header))

            FinishQuiz(race_code, header)
            time.sleep(float(random.randrange(700, 2000)) / 1000)

            if autoRefreshTokenEnabled and expireTime - time.time() < 500:
                new_token = RefreshToken(header)
                expireTime = ParseToken(new_token)["expire"]
                header = BuildHeader(new_token)
                SendNotification(new_token)
                SendNotification(
                    "token已更新至 " + time.asctime(time.localtime(expireTime)))
                time.sleep(5)

    except MyError as err:
        tag = "[{}] ".format(time.asctime(time.localtime(time.time())))

        if err.code == 1001 or err.code == 1002:
            print(tag, "登录无效，通知重新登录")
            SendNotification("请重新登录（代码：{}）".format(err.code))
        elif err.code == 1005:
            print(tag, "当前token已退出登录，请重新获取")
        else:
            msg = "已停止，原因：" + str(err)
            print(tag, msg)
            SendNotification(msg)
    except Exception as err:
        tag = "[{}] ".format(time.asctime(time.localtime(time.time())))
        print(tag, traceback.format_exc())
    finally:
        SaveAnswerToFile()
        SendNotification("awsl")   # 程序退出时发送通知
        Pause()


def PrintHelp():
    print("fxxkSsxx")
    print(sys.argv[0])
    print()
    print("    -a, --auto       自动更新token  （默认关）")
    print("    -h, --help       显示此帮助信息")
    print("    -i, --inform     启用webhook通知（默认关）")
    print("    -v, --version    显示版本号")
    print()
    print("https://github.com/deximy/FxxkSsxx")


if __name__ == "__main__":
    argv = sys.argv[1:]

    try:
        opts, args = getopt.getopt(
            argv, "ahiv", ["auto", "help", "inform", "version"])
    except getopt.GetoptError:
        PrintHelp()
        Pause()
        sys.exit(2)

    for opt, arg in opts:
        if opt in ['-a', '--auto']:
            autoRefreshTokenEnabled = True
        elif opt in ['-h', '--help']:
            PrintHelp()
            Pause()
            sys.exit()
        elif opt in ['-i', '--inform']:
            informEnabled = True
        elif opt in ['-v', '--version']:
            print(VERSION_NAME)
            Pause()
            sys.exit()

    print("打开网页端：https://ssxx.univs.cn/client/detail/5f71e934bcdbf3a8c3ba5061 认证登录成功后")
    print("在地址栏输入javascript:document.write(localStorage.token)复制显示的内容")
    print("或按F12，转到Console页面，输入localStorage.token后回车，输出的结果复制下来并输入即可")
    token = input("请输入token：").strip()
    if token.find("token:") == 0:
        token = token[6:]
    token = token.strip("\"")

    tokenInfo = ParseToken(token)
    expireTime = tokenInfo["expire"]
    print(tokenInfo["name"], "，欢迎使用！")
    print("uid: ", tokenInfo["uid"])
    print("token有效期剩余：", time.strftime(
        "%Hh %Mm %Ss", time.gmtime(expireTime - time.time())))

    time.sleep(2.5)
    Start(token)
