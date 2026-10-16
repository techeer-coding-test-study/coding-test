# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: ListNode | None) -> int:
        answer=0
        result=[]
        while head:
            result.append(head.val)
            head=head.next
        n=len(result)
        
        return max(result[i]+result[n-1-i] for i in range(n//2))


       