class Solution:
    def maxScore(self, s: str) -> int:
        total_ones = s.count('1')
        max_score = 0
        left_zeros = 0

        for i in range(len(s) - 1):
            if s[i] == '0':
                left_zeros += 1
            else:
                total_ones -= 1

            max_score = max(max_score, left_zeros + total_ones)

        return max_score
