# coding = utf-8
import HW
import time
import bs4
import re
import urllib.request,urllib.error
#启动控制！启动游戏！
def run_game():
    youxi = HW.Dagame()
    youxi.giao_play()
    time.sleep(10)
#获得网页
def web_get_data():
    data = urllib.request.urlopen("")
    data.read().decode("utf-8")






if __name__ == "__main__":
    run_game()