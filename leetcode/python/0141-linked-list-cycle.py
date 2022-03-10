# https://leetcode.com/problems/linked-list-cycle/
# Medium

# Have one fast and one slow node
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast, slow = head.next if head else None, head
        while fast:
            if slow is fast:
                return True
            fast = fast.next.next if fast.next else None
            slow = slow.next
        return False