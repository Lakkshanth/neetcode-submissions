class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        x=len(word1)
        y=len(word2)
        a=0
        newstr=""
        if x>y:
            for i in range(y):
                newstr+=word1[a]
                newstr+=word2[a]
                a+=1
            for j in range(x-y):
                newstr+=word1[a]
                a+=1
        else:
            for i in range(x):
                    newstr+=word1[a]
                    newstr+=word2[a]
                    a+=1
            for j in range(y-x):
                    newstr+=word2[a]

                    a+=1
        return newstr
        

