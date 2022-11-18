import keyring
from imbox import Imbox
import time
from email import yino

class yinoget():
    yinoout = yino()
    password = 'BIGFVVUALEOUMXYJ'
    def az():
        with Imbox('imap.163.com', 'qq1520600496@163.com', password, ssl=True) as imbox:
            unread_inbox_messages = imbox.messages(unread=True)  # 获取未读邮件
            for uid, message in unread_inbox_messages:
                title = message.subject
                email = message.sent_from[0]['email']
                results = ''
                if title == '来句诗':
                    results = "giao"
                if title[-2:] == '天气':
                    results = "az"
                if results:
                    yinoout.sendTextSthToSb(results,"1520600496@qq.com")
                imbox.mark_seen(uid)
