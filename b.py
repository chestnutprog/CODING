# -*- coding: UTF-8 -*-
import sys
f=open("input.txt","r")
g=open("output.txt","w")
sys.stdin=f
sys.stdout=g
n=int(raw_input())
a=raw_input().split()
ans=0
for i in range(n):
  ans=ans+int(a[i])
print ans
f.close()
g.close()