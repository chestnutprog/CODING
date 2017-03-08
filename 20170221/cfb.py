a = {0:0,1:1}
x = input().split()
n = int(x[0])
l = int(x[1])
r = int(x[2])
def search(p,left,right):
    mid = (left+right)>>1
    print(p,left,right,mid)
    if (right < l or left > r):
        return 0
    if p in a:
            return a[p]
    if r<=mid:
        return search(p>>1,left,mid-1)+(r==mid and p%2)
    if l>=mid:
        return search(p>>1,mid+1,right)+(l==mid and p%2)
    return search(p>>1,left,mid)+(l<=mid and mid <= r and p%2)+search(p>>1,mid+1,right)
print(search(n,1,2**(len(bin(n))-2)-1))
