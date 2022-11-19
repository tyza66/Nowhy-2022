import os
import time

from flask import Flask, jsonify, render_template, sessions, send_file
from flask import request
from flask_cors import CORS
from gevent import pywsgi
import sql

app = Flask(__name__)

cors = CORS(app, resources={"/api/*": {"origins": "*"}})
sql1 = sql.sqlcon()

@app.route('/')
def hello_world():
    return '后端由洮羱芝闇制作，求求了别攻击我服务器555555'

@app.route('/api/help', methods=['GET'])
def get_name():
    a = {'help': '本后端接口列表', 'info': "大佬别攻击我"}
    jk = {
        '1': 'menu1:获得主页目录part1',
        '2': 'menu1:获得主页目录part2',
        '3': 'menu1:获得主页目录part3',
        '4': 'menu1:获得主页目录part4',
        '5': '',
        '6': '',
        '7': ''
    }
    info = a
    return info
@app.route('/data', methods=['GET'])
def update():
    it = {
        "a":"1.0.0",
        "b":""
    }
    return jsonify(it)

@app.route('/api/menu', methods=['GET'])
def menu1():
    if request.args.get("index","") == "1":
        info = [dict(i) for i in sql1.menu1()]
        return jsonify(info)
    if request.args.get("index","") == "2":
        info = [dict(i) for i in sql1.games()]
        return jsonify(info)

@app.route('/comp',methods=['GET'])
def comp():
    id = request.args.get("id", "")
    info = sql1.one_menu1(id)
    return jsonify(info)



#二手车
@app.route('/cars',methods=['GET'])
def car1():
    if request.args.get("uuid", "") != "":
        info = [dict(i) for i in sql1.cars1()]
        return jsonify(info)

@app.route('/cars/picup',methods=['POST'])
def picup():
    file = request.files.get("file")
    ticks = time.time()
    fq = "static/xqc/"+str(ticks)+".png"
    file.save(fq)
    return fq

@app.route('/cars/carup',methods=['POST'])
def carup():
    if sql1.cars3(str(request.json.get("uuid"))) != ():
        return jsonify("已上传")
    ticks = time.time()
    print(request.json.get("jiage "))
    a = sql1.cars2(str(ticks),
                   str(request.json.get("uuid")),
                   str(request.json.get("pinpai")),
                   str(request.json.get("nian")),
                   str(request.json.get("yue")),
                   str(request.json.get("chexing")),
                   str(request.json.get("huji")),
                   str(request.json.get("jiage")),
                   str(request.json.get("dianhua")),
                   str(request.json.get("tupian")),
                   str(request.json.get("weixin")),
                   "0")
    return jsonify(a)

@app.route('/cars/zaime',methods=['GET'])
def zaime():
    if sql1.cars3(str(request.args.get("uuid", ""))) != ():
        return jsonify("已上传")
    return jsonify("666")

@app.route('/car',methods=['GET'])
def car():
    id = request.args.get("uuid", "")
    info = [dict(i) for i in sql1.cars4(id)]
    return jsonify(info)

@app.route('/carsan',methods=['GET'])
def carsan():
    id = request.args.get("uuid", "")
    info = [dict(i) for i in sql1.cars5(id)]
    return jsonify(info)

@app.route('/search',methods=['GET'])
def suosuo():
    id = request.args.get("jiage", "")
    info = [dict(i) for i in sql1.cars6(id)]
    return jsonify(info)


@app.route('/azaz',methods=['GET'])
def azaz():
    info = {
        "1":"1.0.0",
        "2":"https://www.liminershouche.xyz"
    }
    return jsonify(info)









def runle():
    server = pywsgi.WSGIServer(('0.0.0.0', 5001), app)
    print("启动服务器")
    server.serve_forever()


if __name__ == '__main__':
    runle()

