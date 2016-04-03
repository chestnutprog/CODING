ins = input().split()
n = int(ins[0])
m = int(ins[1])
x = []
for i in range(0,n):
	x.append([])
	t = input().split()
	map(int,t)
	x[i]=t
p = [None]*(n+1)
for i in range(len(p)):
	p[i] = [0]*(m+1)
maxn = pow(10,10000)
for i in range(0,n):
	for j in range(i,m):
		p[i][j]=maxn
		for k in range(i-1,j):
			d[i][j]
<p>有<img alt="m" src="http://latex.codecogs.com/gif.latex?m" />件校服，由于众所周知的原因，每一件校服都非常的难看，现在有<img alt="n" src="http://latex.codecogs.com/gif.latex?n" />个同学，需要给每个同学一件校服，每一件校服穿在不同的同学身上有不同的难看度</p>
