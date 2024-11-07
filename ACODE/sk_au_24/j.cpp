# coding=utf-8
def generate_spiral_tower(s, n):
    result = []
    current_layer = s  # 第一层

    for i in range(n):
        result.append(current_layer)  # 保存当前层
        # 生成下一层，通过将第一个字符移到末尾
        current_layer = current_layer[1:] + current_layer[0]  # 移动第一个字符到末尾

    return result

# 输入部分
s = input()
n = int(input())

# 生成并输出螺旋塔
spiral_tower = generate_spiral_tower(s, n)
for layer in spiral_tower:
    print(layer)
