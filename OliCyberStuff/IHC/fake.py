
#!/bin/python3

from pwn import *
import os

r = remote("ihc.challs.olicyber.it", 34008)
r.recvuntil(b'invio!')
r.sendline()
flag = ''
while True:
    data = r.recvuntil(b'Risposta: ')

    # Semplice operazione
    if b'risultato' in data:
        data = data.split(b'\n')[0].split(b' ')
        b = data[-1][:-1].decode()
        op = data[-2].decode()
        a = data[-3].decode()
        if op == '+':
            r.sendline(str(int(a) + int(b)).encode())
        elif op == '-':
            r.sendline(str(int(a) - int(b)).encode())
        elif op == '*':
            r.sendline(str(int(a) * int(b)).encode())
        else:
            r.sendline(str(int(a) // int(b)).encode())

    # Lettere in stringa
    elif b'Quali' in data:
        data = data.split(b'\n')[0].split(b'posizioni ')[1].split(b']')
        positions = eval(data[0].decode() + ']')
        word = data[1].split(b' ')[-1].decode()[:-1]
        res = ''
        for p in positions:
            res += word[p-1]
        r.sendline(res.encode())

    # Stringa al contrario
    elif b'Restituiscimi' in data:
        data = data.split(b'\n')
        parola = data[0].split(b' ')[-1]
        r.sendline(parola[::-1])

    # Conta occorrenze
    else:
        data = data.split(b'\n')
        lettera = data[0].split(b'lettera ')[1][0]
        parola = data[0].split(b' ')[-1][:-1]
        r.sendline(str(parola.count(lettera)).encode())
    data = r.recvuntil(b'\n').decode()
    if 'Corretto' in data:
        flag += data.split(' ')[-1]
    if '}' in flag:
        break
    
    print (flag)

print(flag.replace('\n', ''))
