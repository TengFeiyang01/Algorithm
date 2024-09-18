import sys

from collections import *





def solve() -> None:
    vars = defaultdict(int)
    while True:
        try:
            opts = list(input().split())
            if opts[0] == "MOV":
                vars[opts[1]] = int(opts[2])
            elif opts[0] == "ADD":
                vars[opts[1]] = (int(opts[2]) if opts[2].isdigit() else vars[opts[2]]) + (int(opts[3]) if opts[3].isdigit() else vars[opts[3]])
            elif opts[0] == "SUB":
                vars[opts[1]] = (int(opts[2]) if opts[2].isdigit() else vars[opts[2]]) - (int(opts[3]) if opts[3].isdigit() else vars[opts[3]])
                
            elif opts[0] == "MUL":
                vars[opts[1]] = (int(opts[2]) if opts[2].isdigit() else vars[opts[2]]) * (int(opts[3]) if opts[3].isdigit() else vars[opts[3]])
            elif opts[0] == "DIV":
                vars[opts[1]] = (int(opts[2]) if opts[2].isdigit() else vars[opts[2]]) // (int(opts[3]) if opts[3].isdigit() else vars[opts[3]])
            else:
                print(vars[opts[1]])
        except:
            break
                
    


if __name__ == '__main__':
    solve()