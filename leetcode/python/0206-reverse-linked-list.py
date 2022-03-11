# https://leetcode.com/problems/reverse-linked-list
# Easy

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        while curr:
            prev, curr.next, curr = curr, prev, curr.next
        return prev