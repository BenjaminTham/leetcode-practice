#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums1 = nums
        nums1 = [item for item in nums1 if item != val]
        nums[:] = nums1
        return len(nums)        
# @lc code=end

