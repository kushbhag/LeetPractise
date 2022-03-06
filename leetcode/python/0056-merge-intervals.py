# https://leetcode.com/problems/merge-intervals/
# Medium

# Key is to use ret[-1]
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        ret = [intervals[0]]
        for i in intervals[1:]:
            if i[0] <= ret[-1][1]:
                ret[-1][1] = max(i[1], ret[-1][1])
            else:
                ret.append(i)
        return ret