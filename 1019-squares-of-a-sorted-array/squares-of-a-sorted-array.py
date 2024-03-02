class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted(list(i**2 for i in nums))
        