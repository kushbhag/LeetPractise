# https://leetcode.com/problems/merge-k-sorted-lists/
# Medium

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = []
        for i, l in enumerate(lists):
            if l:
                h.append((l.val, i))
        ret = head = ListNode()
        heapify(h)
        while len(h) > 0:
            smallest = lists[h[0][1]]
            head.next = smallest
            head = head.next
            if smallest.next != None:
                lists[h[0][1]] = smallest.next
                heapreplace(h, (smallest.next.val, h[0][1]))
            else:
                heappop(h)
        return ret.next