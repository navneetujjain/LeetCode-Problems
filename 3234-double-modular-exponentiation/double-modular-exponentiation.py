class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        ans = []
        for i in range(0, len(variables)):
            x = pow(pow(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3])
            if x is target:
                ans.append(i)
        

        return ans
        