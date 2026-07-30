class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for i in range(len(tokens)):
            token = tokens[i]

            if token in ("+", "-", "*", "/"):
                b = stack.pop()
                a = stack.pop()

                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else: # /
                    stack.append(math.trunc(a / b))
            else:
                stack.append(int(token))

        return stack[0]
        