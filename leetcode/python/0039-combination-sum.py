# https://leetcode.com/problems/combination-sum/
# Medium

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ret = []
        currList = []
        candidates.sort()
        
        def combinationRec(currIndex: int):
            nonlocal target
            if target == 0:
                ret.append(currList.copy())
                return
            
            for i in range(currIndex, len(candidates)):
                target -= candidates[i]
                if target < 0:
                    target += candidates[i]
                    break

                currList.append(candidates[i])
                combinationRec(i)
                target += currList.pop()
        
        combinationRec(0)
        return ret
                