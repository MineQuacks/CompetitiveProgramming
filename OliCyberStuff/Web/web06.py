import requests
url = 'http://web-06.challs.olicyber.it/token' 
url2 = 'http://web-06.challs.olicyber.it/flag' 
s=requests.session()
s.get(url)
r=s.get(url2)
print(r.content)

