n = int(input())
logs = [input() for _ in range(n)]
m = int(input())
prices = [input() for _ in range(m)]

pd = {f: int(p) for f, p in (e.split(',') for e in prices)}
    
a = {}
st = set()
    
for e in logs:
    t, cid, bf, d = e.split(',')
    d = int(d)
    if not (0 <= d <= 100) or (t, cid, bf) in st:
        continue
    st.add((t, cid, bf))
        
    a[cid] = a.get(cid, 0) + pd.get(bf, 0) * d
    

for cid, cost in sorted(a.items()):
    print(f'{cid},{cost}')
