#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = ListNode(-1)
        res_loop = res
        remind = 0
        while (l1 or l2):
            value = 0
            if l1:
                value = value + l1.val
                l1 = l1.next
            if l2:
                value = value + l2.val
                l2 = l2.next
            value = value + remind
            remind = int(value / 10)
            # create a new node.
            tmpL = ListNode(value % 10)
            res_loop.next = tmpL
            res_loop = res_loop.next
        if remind:
            res_loop.next = ListNode(remind)

        return res.next

"""
def printL(l):
    print('')
    while (l):
        print(f"-->{l.val}",end='')
        l = l.next
    print('')


test         = Solution()
l1           = ListNode(2)
l1.next      = ListNode(4)
l1.next.next = ListNode(3)
l2           = ListNode(5)
l2.next      = ListNode(6)
l2.next.next = ListNode(4)
printL(l1)
printL(l2)
l3 = test.addTwoNumbers(l1, l2)
printL(l3)

"""
# @lc code=end
