import smtplib
from email.mime.text import MIMEText


class yino():
    def sendTextSthToSb(self, sth, sb):
        msg = MIMEText(sth.toString(), 'plain', 'utf-8')
        msg['From'] = '狗神先生'
        msg['To'] = '<'+sb+'>'
        msg['Subject'] = '事件汇报'
        from_addr = 'qq1520600496@163.com'
        password = 'BIGFVVUALEOUMXYJ'
        to_addr = sb.toString()
        smtp_server = 'smtp.163.com'
        server = smtplib.SMTP_SSL(smtp_server)
        server.set_debuglevel(1)
        server.login(from_addr, password)
        server.sendmail(from_addr, [to_addr], msg.as_string())
        server.quit()

    def sendHtmlSthToSb(self, html, sb):
        msg = MIMEText(html.toString(), 'html', 'utf-8')
        msg['From'] = '狗神先生'
        msg['To'] = '<'+sb+'>'
        msg['Subject'] = '事件汇报'
        from_addr = 'qq1520600496@163.com'
        password = 'BIGFVVUALEOUMXYJ'
        to_addr = sb.toString()
        smtp_server = 'smtp.163.com'
        server = smtplib.SMTP_SSL(smtp_server)
        server.set_debuglevel(1)
        server.login(from_addr, password)
        server.sendmail(from_addr, [to_addr], msg.as_string())
        server.quit()
