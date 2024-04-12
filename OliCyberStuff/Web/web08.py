import requests
url='http://web-08.challs.olicyber.it/login'
data={'username':'admin','password':'admin'}
p = requests.post(url,data)
print(p.content)