def OptimalExecutionCost(n, a, b, k, p):
    avg = (a + b) / 2
    k = min(k, n)
    if p < avg:
        return p * k + (n - k) * avg
    else:
        return avg * k