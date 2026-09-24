class Solution(object):
    def largestNumber(self, nums):
        # """
        # :type nums: List[int]
        # :rtype: str
        # """
        str_nums=[str(num) for num in nums]
        def compare(x,y):
            return cmp(y+x,x+y)
        str_nums.sort(cmp=compare) 
        largest="".join(str_nums)
        return "0"if largest[0]=="0" else largest   

        