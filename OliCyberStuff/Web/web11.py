import requests
login = 'http://web-11.challs.olicyber.it/login'
piece = 'http://web-11.challs.olicyber.it/flag_piece'
datas = {'username': 'admin' , 'password':'admin'}
s = requests.session()
r = s.post(login,json=datas)
print(r.content)
print(s.get(piece,cookies=s.cookies,data=r.content).content)
