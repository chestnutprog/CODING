x=input().split()
x1=int(x[0])
y1=int(x[1])
x2=int(x[2])
y2=int(x[3])
if ((x1+y1)&1)==1:
 if ((x2+y2)&1)==1:
  print()
 else:
  print()
else:
 if ((x2+y2)&1)==1:
  print()
 else:
  print(((y2-y1)/2+1)*((x2-x1+1)/2)+((y2-y1)/2+1)*((x2-x1)/2))
