import pymysql

config = {
    'host': '127.0.0.1',
    'user': 'root',
    'passwd': '',
    "port": 3306,
    'db': 'menu',
    "charset": "utf8"
}
conn = 1
try:
    conn = pymysql.Connect(**config)
    print('数据库连接成功')
except Exception as e:
    print('连接数据库失败！', str(e))

cursor = conn.cursor(cursor=pymysql.cursors.DictCursor)

cursor.execute("INSERT INTO menu1 VALUES(1,'2','3','4')")

cursor.execute("SELECT * FROM menu1")
print(cursor.fetchall())

conn.commit()