import zlib
import binascii
mode = raw_input()
if(mode=='encode'):
 t=''
 for i in range(0,1024):
  s=raw_input().split()
  k=s[0]
  v=s[1]
  t=t+binascii.a2b_hex(hex(int(k)+0L)[2:-1])+' '+binascii.a2b_hex(hex(int(v)+0L)[2:-1])+'\n'
print(bin(int(binascii.b2a_hex(zlib.compress(t)),16))[2:])