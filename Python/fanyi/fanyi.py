
with open("rr(5).txt", "rb") as f:  # 打开文件
    data = f.read()  # 读取文件
    print(data)



with open("fanyi.txt","w") as d:
    d.write("这是个测试！")