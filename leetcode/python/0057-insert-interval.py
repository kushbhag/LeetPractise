# https://leetcode.com/problems/insert-interval/
# Medium

# Key is to change newInterval so that it keeps track of the largest interval so far
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ret = []
        for i in intervals:
            if i[1] < newInterval[0]:
                ret.append(i)
            elif newInterval[1] < i[0]:
                ret.append(newInterval)
                newInterval = i
            else:
                newInterval[0] = min(i[0], newInterval[0])
                newInterval[1] = max(i[1], newInterval[1])

        ret.append(newInterval)
        return ret
        