class ExpressionEvaluator:
    def __init__(self):
        self.tokens = []
        self.position = 0
        self.variables = {}

    def trim(self, s):
        return s.strip()

    def tokenize(self, expr):
        import re
        tokens = re.findall(r"[a-zA-Z_][a-zA-Z0-9_]*|['()=]|[^ \t\n\r\f\v'()=]+", expr)
        return tokens

    def parse_term(self):
        if self.position >= len(self.tokens):
            return False
        if self.tokens[self.position] == "(":
            self.position += 1
            result = self.parse_or()
            if self.position < len(self.tokens) and self.tokens[self.position] == ")":
                self.position += 1
            return result
        key = self.tokens[self.position]
        self.position += 2  # Skip the key and '='
        value = self.tokens[self.position]
        self.position += 1
        return self.variables.get(key, '') == value

    def parse_and(self):
        result = self.parse_term()
        while self.position < len(self.tokens) and self.tokens[self.position] == "AND":
            self.position += 1
            result = result and self.parse_term()
        return result

    def parse_or(self):
        result = self.parse_and()
        while self.position < len(self.tokens) and self.tokens[self.position] == "OR":
            self.position += 1
            result = result or self.parse_and()
        return result

    def evaluate(self, expressions, assignments):
        for key, value in assignments:
            self.variables[key] = value
        results = []
        for expr in expressions:
            self.tokens = self.tokenize(expr)
            self.position = 0
            result = self.parse_or()
            results.append('1' if result else '0')
        return results

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    n, m = map(int, data[0].split())
    expressions = [line.strip() for line in data[1:n+1]]
    assignments = [line.split() for line in data[n+1:n+1+m]]

    evaluator = ExpressionEvaluator()
    results = evaluator.evaluate(expressions, assignments)
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
