# Reflections

## 88. Merge Sorted Array

at first i didnt pay attention to integers m and n, i brute force a solution by combining both arrays immediately and tried to remove all 0's manually doing this

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums3 = nums1
        nums3.extend(nums2)
        nums3.sort()
        nums3 = [item for item in nums3 if item != 0]
        nums1[:] = nums3
        print(nums1)
```

but very quickly realise this is a terrible way

so i took a step back and saw that since `nums` arrays can do this [0:m], i first saved nums1 into a separate nums while shortening it using [0:3] since nums1 is the one with all the 0's as place holders.

then i combined nums2 into nums3, and sorted it

finally i stored nums3 back into nums1 with [:]

### [!IMPORTANT] attention

if you try to store back into nums1 like this

```python

nums1 = nums3
```

it wont work. python create another in memory storage for the new nums1. so you have to use [:]

### solution

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums3 = nums1[0:m]
        nums3.extend(nums2)
        nums3.sort()
        nums1[:] = nums3
```
