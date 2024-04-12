from pwn import *
conn = remote("ihc.challs.olicyber.it", 34008)
conn.recvuntil(b'invio!')
conn.sendline()

flag = ""
while True:
    richiesta = str(conn.recvuntil(b'Risposta: ').decode())
    if "contrario" in richiesta:
        stringa = richiesta.split(": ",1)[1].split("\n")[0]
        conn.sendline(str(stringa[::-1]).encode())
    elif "compare" in richiesta:
        lettera = richiesta.split("lettera ")[1]
        lettera=lettera[0]
        stringa = richiesta.split("stringa ")[1].split("\n")[0]
        conn.sendline(str(stringa.count(lettera)).encode())
    elif "risultato" in richiesta:
        stringa = richiesta.split(": ",1)[1]
        if "(troncato)" in stringa:
            stringa = stringa.split("(troncato) ")[1]
        n1 = int(stringa.split(" ")[0])
        n2 = int(stringa.split(" ")[2].split("?")[0])
        segno=stringa.split(" ")[1]
        res=-1
        if segno == '+':
            res = n1+n2
        elif segno == '-':
            res= n1-n2
        elif segno == '/':
            res = n1//n2
        elif segno == '*':
            res = n1*n2
        conn.sendline(str(res).encode())
    elif "Quali" in richiesta:
        stringa = richiesta.split("[")[1].strip()
        stringa = stringa.split("]")[0]
        stringa = stringa.split(", ")
        res=""
        riga =richiesta.split("stringa ")[1]
        for i in stringa:
            res+=riga[int(i)-1]
        conn.sendline(res.strip().encode())
    
    
    premio = conn.recvuntil(b'\n').decode()
    
    flag += premio.split(' ')[-1][0]
    print(flag)
    if "agliato" in premio:
        break
    if '}' in flag:
        break
print(flag)