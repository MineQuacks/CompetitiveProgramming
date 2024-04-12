import requests
url = 'http://web-04.challs.olicyber.it/users'
header = {'Accept' : 'application/xml'}
r= requests.get(url,headers=header)
print(r.content)