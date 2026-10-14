class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if not (1<=sum<=9*num):
            return ""
        result=[]
        rem_sum=sum
        rem_len= num
        for i in range(num):
            rem_len-=1
            for d in range(9,-1,-1):
                if rem_sum-d<= 9*rem_len and  rem_sum -d>=0:
                    result.append(str(d))
                    rem_sum-=d
                    break
        return "".join(result)