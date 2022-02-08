# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
# Medium

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        currHead = head
        for i in range(n):
            currHead = currHead.next
        
        if currHead == None:
            return head.next

        theHead = head
        while currHead.next:
            currHead = currHead.next
            head = head.next
        
        head.next = head.next.next
        return theHead