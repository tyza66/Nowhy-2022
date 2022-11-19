import urllib.request
import urllib.parse
rurl = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule"
data = {
     "i": "help",
    "from": "AUTO",
    "to": "AUTO",
    "smartresult": "dict",
     "client": "fanyideskweb",
    "salt": "16106967763774",
    "sign": "24437dc84dd1b4305cb2e3361f4ec3e4",
    "lts": "1610696776377",
    "bv": "0b7d3ae31003a4c7011e6d3b0d3ebfe8",
    "doctype": "json",
    "version": "2.1",
    "keyfrom": "fanyi.web",
    "action": "FY_BY_CLICKBUTTION"
}

data = urllib.parse.urlencode(data).encode("utf-8")
head= {
"User-Agent":"Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.141 Safari/537.36 Edg/87.0.664.75"
}
a1 = urllib.request.Request(rurl,data,head)
b = urllib.request.urlopen(a1)
print(b.read().decode("utf-8"))