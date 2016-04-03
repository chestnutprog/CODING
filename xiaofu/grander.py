import random
for i in range(1,4):
	ass = open('input'+str(i)+'.txt','w')
	n = 10
	m = 20
	ass.write("10 20\n")
	for i in range(0,n):
		for j in range(0,m):
			ass.write(str(random.randint(1,pow(10,9)))+ ' ')
		ass.write('\n')
	ass.close()
for i in range(4,7):
	ass = open('input'+str(i)+'.txt','w')
	n = 10
	m = 20
	ass.write("10 20\n")
	for i in range(0,n):
		for j in range(0,m):
			ass.write(str(random.randint(1,pow(10,500)))+ ' ')
		ass.write('\n')
	ass.close()
for i in range(7,11):
	ass = open('input'+str(i)+'.txt','w')
	n = 90
	m = 100
	ass.write("90 100\n")
	for i in range(0,n):
		for j in range(0,m):
			ass.write(str(random.randint(1,pow(10,500)))+ ' ')
		ass.write('\n')
	ass.close()