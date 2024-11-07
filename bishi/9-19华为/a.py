import sys

def trim_str(s):
    return s.strip()

def tokenize(expr):
    tokens = []
    i = 0
    while i < len(expr):
        if expr[i].isspace():
            i += 1
            continue
        if expr[i].isalpha() or expr[i] == '_':
            start = i
            while i < len(expr) and (expr[i].isalnum() or expr[i] == '_'):
                i += 1
            tokens.append(expr[start:i])
        elif expr[i] in ['(', ')', '=']:
            tokens.append(expr[i])
            i += 1
        elif expr[i] == "'":
            i += 1  # skip opening quote
            start = i
            while i < len(expr) and expr[i] != "'":
                i += 1
            tokens.append(expr[start:i])
            i += 1  # skip closing quote
        else:
            # Skip unknown characters or handle operators like AND, OR
            if expr.startswith("AND", i):
                tokens.append("AND")
                i += 3
            elif expr.startswith("OR", i):
                tokens.append("OR")
                i += 2
            else:
                i += 1
    return tokens

class Parser:
    def __init__(self, tokens, vars_map):
        self.tokens = tokens
        self.pos = 0
        self.vars_map = vars_map

    def current_token(self):
        if self.pos < len(self.tokens):
            return self.tokens[self.pos]
        return None

    def consume(self, expected=None):
        token = self.current_token()
        if expected and token != expected:
            raise ValueError(f"Expected {expected}, got {token}")
        self.pos += 1
        return token

    def parse_expression(self):
        return self.parse_or()

    def parse_or(self):
        result = self.parse_and()
        while self.current_token() == "OR":
            self.consume("OR")
            right = self.parse_and()
            result = result or right
        return result

    def parse_and(self):
        result = self.parse_term()
        while self.current_token() == "AND":
            self.consume("AND")
            right = self.parse_term()
            result = result and right
        return result

    def parse_term(self):
        token = self.current_token()
        if token == "(":
            self.consume("(")
            result = self.parse_expression()
            self.consume(")")
            return result
        else:
            key = self.consume()
            self.consume("=")
            value = self.consume()
            return self.vars_map.get(key, "") == value

def main():
    input_data = sys.stdin.read().split('\n')
    if input_data[-1] == '':
        input_data.pop()
    n, m = map(int, input_data[0].split())
    expressions = [trim_str(line) for line in input_data[1:n+1]]
    var_values = {}
    for i in range(m):
        k, v = input_data[n + 1 + i].split()
        var_values[k] = v.strip("'")
    
    results = []
    for expr in expressions:
        tokens = tokenize(expr)
        parser = Parser(tokens, var_values)
        try:
            result = parser.parse_expression()
            results.append('0' if result else '1')
        except:
            # In case of any parsing error, treat as False
            results.append('1')
    
    for res in results:
        print(res)

if __name__ == "__main__":
    main()
