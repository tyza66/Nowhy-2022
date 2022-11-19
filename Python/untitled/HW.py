from appium import webdriver
import time
from appium.webdriver.common.touch_action import TouchAction
from selenium.webdriver.support.wait import WebDriverWait

class Dagame:

    #by:洮羱芝闇 appium范例 小鸡模拟器启动fc游戏文件夹下第一个游戏

        info = {
            "platformName": "Android",
            "platformVerson": "5.1",
            "deviceName": "127.0.0.1:7555",
            "appPackage": "com.xiaoji.emulator",
            "appActivity": ".ui.activity.AppStoreActivity",
            "unicodeKeyboard": True,
            "resetKeyboard": True
        }

        def __init__(self):
            self.driver = webdriver.Remote("http://127.0.0.1:4723/wd/hub",self.info)
            time.sleep(5)
            if self.driver.is_app_installed("com.xiaoji.emulator"):
                print("这台手机有模拟器！")

        def giao_play(self):
            self.driver.implicitly_wait(100)
            self.driver.find_element_by_xpath("//*[@text='跳过']").click()
            for i in range(10):
                play_1 = WebDriverWait(self.driver,5).until(lambda x : x.find_elements_by_class_name("android.widget.RelativeLayout"))
                if len(play_1) == 25:
                    play_1[21].click()
                    break
                print("我giao！？没找到控件！？")
            time.sleep(1)
            TouchAction(self.driver).tap(x=1394, y=675,count=1).perform()
            time.sleep(1)
            TouchAction(self.driver).tap(x=746, y=754).perform()
            time.sleep(1)
            TouchAction(self.driver).tap(x=1368, y=193).perform()
            time.sleep(1)
            TouchAction(self.driver).tap(x=710, y=745).perform()

        def giao_pr(self):
            self.driver.current_package
            self.driver.current_activity
        def giao_exit(self):
            self.driver.__exit__()
        def game_up(self):
             TouchAction(self.driver).tap(x=221, y=473, count=1).perform()
        def game_down(self):
             TouchAction(self.driver).tap(x=220, y=698, count=1).perform()
        def game_left(self):
             TouchAction(self.driver).tap(x=134, y=604, count=1).perform()
        def game_right(self):
             TouchAction(self.driver).tap(x=311, y=598, count=1).perform()
        def game_x(self):
             TouchAction(self.driver).tap(x=1344, y=559, count=1).perform()
        def game_y(self):
             TouchAction(self.driver).tap(x=1191, y=486, count=1).perform()
        def game_b(self):
             TouchAction(self.driver).tap(x=1194, y=648, count=1).perform()
        def game_a(self):
             TouchAction(self.driver).tap(x=1364, y=717, count=1).perform()