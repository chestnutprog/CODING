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
<p>��<img alt="m" src="http://latex.codecogs.com/gif.latex?m" />��У��������������֪��ԭ��ÿһ��У�����ǳ����ѿ���������<img alt="n" src="http://latex.codecogs.com/gif.latex?n" />��ͬѧ����Ҫ��ÿ��ͬѧһ��У����ÿһ��У�����ڲ�ͬ��ͬѧ�����в�ͬ���ѿ���</p>
