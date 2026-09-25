class Solution(object):
    def braceExpansionII(self, expression):
        """
        :type expression: str
        :rtype: List[str]
        """
        res = set()

        def dfs(exp):
            # Find the first closing brace
            j = exp.find('}')
            
            # Base Case: No braces left, add full string to set
            if j == -1:
                res.add(exp)
                return

            # Find the corresponding innermost opening brace
            i = exp.rfind('{', 0, j)

            a = exp[:i]                  # Prefix before '{'
            c = exp[j + 1:]              # Suffix after '}'
            options = exp[i + 1:j].split(',') # Elements inside '{...}'

            for b in options:
                dfs(a + b + c)

        dfs(expression)
        return sorted(list(res))