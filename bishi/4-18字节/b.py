s = input() + '*'  
stk = []
nums = []
temp = ''
times = 0
for i in range(len(s)): 
    if s[i].isdigit():
        temp = temp + s[i]
    else:
        if temp != '':
            nums.append(int(temp))  
            temp = ''

        if len(stk) >= 1 and stk[-1] == '#':
            sum1 = 4 * nums[-2] + 3 * nums[-1] + 2
            nums.pop()
            nums.pop()
            stk.pop()
            nums.append(sum1)

        if s[i] == '#':
            stk.append('#')

        if s[i] == '$':
            stk.append('$')
            times += 1

while times > 0:
    sum2 = 2 * nums[-2] + nums[-1] + 3
    nums = nums[:-2]
    stk.pop()
    nums.append(sum2)
    times -= 1

print(nums[0], end='')  
