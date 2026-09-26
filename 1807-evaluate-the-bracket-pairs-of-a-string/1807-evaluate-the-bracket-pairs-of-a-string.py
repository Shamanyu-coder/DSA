class Solution(object):
    def evaluate(self, s, knowledge):
        """
        :type s: str
        :type knowledge: List[List[str]]
        :rtype: str
        """
        
        k_map ={key:val for key, val in knowledge}
        res=[]
        in_bracket=False
        curr_key =[]
        for char in s:
            if char=='(':
                in_bracket=True

            elif char ==')':
                in_bracket=False
                key_str="".join(curr_key)
                res.append(k_map.get(key_str,"?"))
                curr_key=[]
            elif in_bracket:
                curr_key.append(char)
            else:
                res.append(char)

        return"".join(res)
         