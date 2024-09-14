def custom_sort(s, words):
    order = {c: i for i, c in enumerate(s)}

    def compare(x, y):
        for i in range(min(len(x), len(y))):
            if x[i] != y[i]:
                return order[x[i]] - order[y[i]]
        return (len(x) - len(y)) if len(x) != len(y) else (x < y)

    return sorted(words, key=lambda w: [order[c] for c in w])

s = input()
n = int(input())
words = [input() for _ in range(n)]

sorted_words = custom_sort(s, words)
for word in sorted_words:
    print(word)
