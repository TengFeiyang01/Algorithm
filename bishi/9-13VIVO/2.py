P = 13331

def main():
    n = int(input())
    mp = {}
    st = []
    h = [0] * (n + 1)  
    cnt = 0  

    for i in range(n):
        parts = input().split()
        cmd = parts[0]
        
        if cmd == "push":
            k = parts[1]
            st.append(k)
            for j in range(len(k)):
                cnt += 1
                h[cnt] = h[cnt - 1] * P + ord(k[j])
            if h[cnt] not in mp:
                mp[h[cnt]] = 0
            mp[h[cnt]] += 1
        elif cmd == "pop" and st:
            k = st.pop()
            cnt -= len(k) 

    print(len(mp))

if __name__ == "__main__":
    main()
