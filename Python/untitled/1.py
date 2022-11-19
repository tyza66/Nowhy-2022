import urllib.request
request = urllib.request.Request('http://www.baidu.com')
request.add_header("User-Agent","Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.141 Safari/537.36 Edg/87.0.664.75")
request = urllib.request.urlopen(request)
print(request.read().decode("utf-8"))