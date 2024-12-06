import numpy as np
from scipy.optimize import minimize


def svm_dual_problem(dataset):
    # 提取特征和标签
    X = np.array([data[:2] for data in dataset])
    y = np.array([data[2] for data in dataset])

    n_samples, n_features = X.shape

    # 定义对偶问题的目标函数
    def objective(alpha):
        return 0.5 * np.sum(alpha[i] * alpha[j] * y[i] * y[j] * np.dot(X[i], X[j])
                            for i in range(n_samples) for j in range(n_samples)) - np.sum(alpha)

    # 定义约束条件
    constraints = ({'type': 'eq', 'fun': lambda alpha: np.dot(alpha, y)},
                   {'type': 'ineq', 'fun': lambda alpha: alpha})

    # 初始猜测
    alpha_initial = np.zeros(n_samples)

    # 边界条件
    bounds = [(0, None) for _ in range(n_samples)]

    # 使用scipy.optimize.minimize求解二次规划问题
    result = minimize(objective, alpha_initial, bounds=bounds, constraints=constraints)

    # 结果中的拉格朗日乘数
    alpha = result.x

    # 保留两位小数，并且将负0.00替换为0.00
    alpha = np.round(alpha, 2)
    alpha = [0.00 if np.isclose(a, 0, atol=1e-2) else a for a in alpha]

    return alpha


# 读取输入
import sys

input_data = []
for i in range(2):
    input_data.append(list(map(float, input().split())))

# 计算拉格朗日乘数
lagrange_multipliers = svm_dual_problem(input_data)

# 打印结果
print(lagrange_multipliers)