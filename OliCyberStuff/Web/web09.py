import requests
import json
url='http://web-09.challs.olicyber.it/login'
datas={'username':'admin','password':'admin'}
p = requests.post(url,json=datas)
print(p.content)