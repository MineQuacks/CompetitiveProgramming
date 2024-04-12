import requests

header={'x-Password' : 'admin'}
url='http://web-03.challs.olicyber.it/flag'
r = requests.get(url,headers = header)
print(r.content)