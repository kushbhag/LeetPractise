# https://leetcode.com/problems/valid-parentheses/
# Easy

class Solution:
    def isValid(self, s: str) -> bool:
        par = []
        for c in s:
            if c == '(':
                par.append(')')
            elif c == '[':
                par.append(']')
            elif c == '{':
                par.append('}')
            elif len(par) == 0 or par[-1] != c:
                return False
            else:
                par.pop()
        return len(par) == 0