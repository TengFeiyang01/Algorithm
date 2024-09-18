import numpy as np
from sklearn import svm

def calculate_svm_margin(data):
    # 提取特征和标签
    X = np.array([item[:-1] for item in data])
    y = np.array([item[-1] for item in data])
    
    # 使用线性SVM进行训练
    model = svm.SVC(kernel='linear', C=1.0)
    model.fit(X, y)
    
    # 计算每个样本的拉格朗日乘数（也即决策函数值）
    decision_function = model.decision_function(X)
    
    # 计算每个样本到超平面的距离并四舍五入保留两位小数
    margins = np.abs(decision_function) / np.linalg.norm(model.coef_)
    margins = [f"{round(margin, 2):.2f}" for margin in margins]
    
    return margins

# 示例输入
input_data = [
    [1.0, 2.0, 1],
    [2.0, 3.0, -1]
]

# 计算并输出结果
output = calculate_svm_margin(input_data)
print(output)
