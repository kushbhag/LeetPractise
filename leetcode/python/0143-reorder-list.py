# https://leetcode.com/problems/reorder-list/
# Medium

# This is the O(1) memory solution
# 1. Use fast and slow pointer to find where the middle is
# 2. Reverse the second half of the linked list
# 3. Merge the two lists that you have
#    - Merge as 'while prev and prev.next'
#      because we do not want loops
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow, fast = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        curr, prev = slow, None
        while curr:
            curr.next, curr, prev = prev, curr.next, curr
        
        curr = head
        while prev and prev.next:
            curr.next, curr = prev, curr.next
            prev.next, prev = curr, prev.next
            
        return head

# Use a list to keep track of all the nodes
# Keep a 'curr' node and then pop from the list, and 
#   set curr.next to the pop as well as viceversa
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        curr = head
        l = []
        while curr:
            l.append(curr)
            curr = curr.next

        curr = head
        right = l.pop()
        while curr != right:
            temp = curr.next
            curr.next = right
            curr = temp
            if curr == right:
                break
            right.next = curr
            right = l.pop()
        curr.next = None
        return head