import math
import sys

input = lambda: sys.stdin.readline().rstrip()

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def get(points):
    def divide(X, Y):
        n = len(X)
        if n <= 3:
            min_dist = float('inf')
            min_pair = None
            for i in range(n):
                for j in range(i + 1, n):
                    d = distance(X[i], X[j])
                    if d < min_dist:
                        min_dist = d
                        min_pair = (X[i], X[j])
            return min_pair, min_dist
        
        mid = n // 2
        dist = X[mid]
        
        left_X = X[:mid]
        right_X = X[mid:]
        
        left_Y = list(filter(lambda x: x[0] <= dist[0], Y))
        right_Y = list(filter(lambda x: x[0] > dist[0], Y))
        
        (lp, ld) = divide(left_X, left_Y)
        (rp, rd) = divide(right_X, right_Y)
        
        if ld < rd:
            d_min = ld
            best_pair = lp
        else:
            d_min = rd
            best_pair = rp
        
        strip = [p for p in Y if abs(p[0] - dist[0]) < d_min]
        strip_size = len(strip)
        
        for i in range(strip_size):
            for j in range(i + 1, strip_size):
                if strip[j][1] - strip[i][1] >= d_min:
                    break
                d = distance(strip[i], strip[j])
                if d < d_min:
                    d_min = d
                    best_pair = (strip[i], strip[j])
        
        return best_pair, d_min
    
    X = sorted(points, key=lambda p: p[0])
    Y = sorted(points, key=lambda p: p[1])
    
    return divide(X, Y)[0]

def process_input(input_str):
    cleaned_input = input_str.replace('.', ',')
    return eval(cleaned_input)

def solve() -> None:
    points = process_input(input())
    result = get(points)
    print(result)

if __name__ == '__main__':
    solve()