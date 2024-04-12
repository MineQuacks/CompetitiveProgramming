def xor(b,a):
    return bytes([x^y for x,y in zip(a,b)])

word = "104e137f425954137f74107f525511457f5468134d7f146c4c"
for i in range(0,255):
    print(str(xor(bytes.fromhex(word),i.to_bytes(1,"big")*25)))