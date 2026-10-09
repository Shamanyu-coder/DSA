class Solution:
    def minInsertions(self, s: str) -> int:
        insertion=0
        needed_rights=0
        for char in s:
            if char =='(':
                needed_rights+=2
                if needed_rights%2==1:
                    insertion+=1
                    needed_rights-=1
            else:
                needed_rights-=1
                if needed_rights<0:
                    insertion+=1
                    needed_rights+=2
        return insertion+ needed_rights
