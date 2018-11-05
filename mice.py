def divide(n):
	a=b=c=n/3
	rem = n%3
	if(rem>0):
		a+=1
		rem-=1
	if(rem>0):
		b+=1
		rem-=1
	return (a,b,c)
 
f=[]
f.append(0)
f.append(0)
f.append(2)
f.append(2)
f.append(3)
for i in range(5,100001):
	a,b,c = divide(i)
	ans = 2 + max(f[a],f[b],f[c])
	f.append(ans)
 
for i in range(int(raw_input())):
	n = int(raw_input())
	print f[n]