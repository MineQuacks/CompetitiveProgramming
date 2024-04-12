import requests
url = 'http://web-10.challs.olicyber.it/'
print(requests.options(url).headers)
r = requests.patch(url)
print(r.headers)