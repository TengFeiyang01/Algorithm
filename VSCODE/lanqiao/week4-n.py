from math import sqrt
def cal(n,pos): # n等级下pos的坐标
    if n==0:
        return [0,0]
    len,block = 2**(n-1),2**(2*n-2) 
    x,y = cal(n-1,pos%block)
    flag = pos//block
    if flag==0:
        return [y,x]
    elif flag==1:
        return [x,y+len]
    elif flag==2:
        return [x+len,y+len]
    return [2*len-1-y,len-1-x]
t = int(input())
for _ in range(t):
    n,a,b = map(int,input().split())
    pa,pb = cal(n,a-1),cal(n,b-1)
    dx,dy = pa[0]-pb[0],pa[1]-pb[1]
    print('{:.0f}'.format(sqrt(dx*dx+dy*dy)*10))
