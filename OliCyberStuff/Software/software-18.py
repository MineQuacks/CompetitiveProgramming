from pwn import *
import struct
from struct import pack
r = remote('software-18.challs.olicyber.it' , 13001)
r.recvuntil("...")
r.sendline("ANNAMO".encode())
for i in range (0,100):
    r.recvline()
    richiesta = str(r.recvuntil("bit").decode())
    print(richiesta)
    num = richiesta.split(' ')[4]
    print(num)
    if '32' in richiesta:
        r.sendline(struct.pack('I', num))
    if '64' in richiesta:
        r.sendline(struct.pack('I', num))

    
    