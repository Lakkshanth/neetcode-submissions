class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d={}
        avg=len(nums)/2
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        for x in d:
            if d[x]>avg:
                return x
        
