import pymysql
#便捷数据库控制 by：洮羱芝闇 依赖库：pymysql
class sqlcon:
    #构造函数创建对象时连接数据库并生成成员变量conn作为连接的数据库,成员变量cursor作为字典型游标
    config = {
        'host': '127.0.0.1',
        'user': 'root',
        'passwd': '',
        "port": 3306,
        'db': 'menu',
        "charset": "utf8"
    }
    def __init__(self):
        config = {
            'host': '127.0.0.1',
            'user': 'root',
            'passwd': '',
            "port": 3306,
            'db': 'menu',
            "charset": "utf8"
        }
        try:
            self.conn = pymysql.Connect(**config)
            print('数据库连接成功')
        except Exception as e:
            print('连接数据库失败！', str(e))
        self.cursor = self.conn.cursor(cursor=pymysql.cursors.DictCursor)

    #提交
    def commit(self):
        self.conn.commit()
        print("发生提交");

    #回滚
    def rollback(self):
        self.conn.rollback()
        print("发生回滚")

    #产生保留点

    #menu1索引
    def menu1(self):
        try:
            self.cursor.execute("SELECT * FROM menu1")
            return self.cursor.fetchall()
        except Exception as e:
            print("获取menu1失败", str(e))
            self.conn = pymysql.Connect(**self.config)
            self.cursor = self.conn.cursor(cursor=pymysql.cursors.DictCursor)
            print('数据库连接成功')
            return self.menu1()

    def one_menu1(self,id):
        try:
            self.cursor.execute("SELECT * FROM menu1 WHERE id="+id)
            return self.cursor.fetchall()
        except Exception as e:
            print("按id获取比赛信息失败", str(e))

    def games(self):
        try:
            self.cursor.execute("SELECT * FROM games")
            return self.cursor.fetchall()
        except Exception as e:
            print("获取失败", str(e))

    #二手车
    def cars1(self):
        try:
            self.cursor.execute("SELECT * FROM cars  ORDER BY  RAND() LIMIT 10")
            return self.cursor.fetchall()
        except Exception as e:
            print("获取失败1", str(e))
            self.conn = pymysql.Connect(**self.config)
            self.cursor = self.conn.cursor(cursor=pymysql.cursors.DictCursor)
            print('数据库连接成功')
            return self.cars1()

    def cars2(self,id,uuid,pinpai,nian,yue,chexing,huji,jiage,dianhua,zhaopian,wx,ban):
        try:
            nei = id+",'"+uuid+"','"+pinpai+"','"+nian+"','"+yue+"','"+chexing+"','"+huji+"','"+jiage+"','"+dianhua+"','"+zhaopian+"','"+wx+"','"+ban+"'"
            self.cursor.execute("INSERT INTO cars VALUES ("+nei+")")
            self.commit()
            return self.cursor.fetchall()
        except Exception as e:
            print("添加失败2", str(e))
            return str(e)
    def cars3(self,uuid):
        try:
            self.cursor.execute("SELECT * FROM cars WHERE uuid='"+uuid+"'")
            return self.cursor.fetchall()
        except Exception as e:
            print("获得失败3", str(e))
            return str(e)

    def cars4(self,uuid):
        try:
            self.cursor.execute("SELECT * FROM cars WHERE uuid='"+uuid+"'")
            return self.cursor.fetchall()
        except Exception as e:
            print("获得失败3", str(e))
            return str(e)

    def cars5(self,uuid):
        try:
            self.cursor.execute("DELETE FROM cars WHERE uuid='"+uuid+"'")
            self.commit()
            return self.cursor.fetchall()
        except Exception as e:
            print("获得失败3", str(e))
            return str(e)

    def cars6(self,jiage):
        try:
            self.cursor.execute("SELECT * FROM cars WHERE jiage='"+jiage+"'")
            return self.cursor.fetchall()
        except Exception as e:
            print("获得失败3", str(e))
            return str(e)



