from pwn import *
host = "software-17.challs.olicyber.it"
port = 13000
r = remote(host,port)
r.recvuntil("iniziare ...")
r.sendline(b'LEZ GOO')
for i in range(0,10):
    richiesta =  r.recvline().decode()
    if 'somma' in str(richiesta):
        numeri = str( r.recvline().decode())
        numeri = numeri.replace("[",'')
        numeri = numeri.replace("]",'')
        numeri = numeri.split(", ")
        sum = 0
        for i in numeri:
            sum += int(i)
        r.recvuntil(": ")
        r.sendline(str(sum).encode())
r.recvlines(4)

