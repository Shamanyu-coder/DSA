class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack=[0]
        for c in s:
            if c=='(':
                stack.append(0)
            else:
                top= stack.pop()
                cur=1 if top==0 else 2* top
                prev = stack.pop()
                stack.append(prev+cur)
        return stack[-1]
    
                