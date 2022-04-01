def EvenGenerator(n):
    i=0
    while i<=n:
        if i%2==0:
            yield i
        i+=1

# Bài tập Python 68, Code by Quantrimang.com
n=int(input("Nhập n: "))
values = []
for i in EvenGenerator(n):
    values.append(str(i))

print ("Các số chẵn trong khoảng 0 và n là: ",",".join(values))

