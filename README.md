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

## 27. Remove Element

use same idea as 88, store in a separate list, use if statement to remove, store back in original list in place

### solution

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums1 = nums
        nums1 = [item for item in nums1 if item != val]
        nums[:] = nums1
        return len(nums)

```

## 27. Remove Element

at first i thought need use hash map to quickly locate duplicates. but no need. python has `nums = list(set(nums))` to remove duplicates. use that, plus the [:] to modify in place. this will cause -1 to be the last value, so use `.sort()` to sort them

### solution

```python

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = list(set(nums))
        nums.sort()
```

## 80. Remove Duplicates from Sorted Array II

i need to switch to practicing c++ for my work

std::vector which is equivalent to list or array cannot be printed directly using std::cout

have to tell the compiler to iterate and print each element one by one

```c++
std::cout << "[";
for (int x : nums) {
    std::cout << x << " ";
}
std::cout << "]" << std::endl;

```

`<<` means insert operator, when using `std::cout`, it means insert data into the console

`std::endl` is end line. so next print will print on new line

`sizeof(nums)` calculates memory size taken up by nums array. `nums.size()` calculates actual number of elements in nums array

c++ has two types of array: one called array which is immutable and cannot be changed. one is called vector which can be changed but has strict data types. can use variant and define the different data types to be used in that array.

previously, when i used while loop and popped elements out, it changed the length of array and the index, although remained the same, points to a different element now. so i have to replace with `-`

so i had to store all the elements in another vector array with variant types because original nums vector only accepts int. copied nums and store in nums 2 like this

```c++
std::vector<std::variant<int, std::string>> nums2(nums.begin(), nums.end());
```

then to remove a certain element (in this case `-`), have to use this

```c++
std::erase(nums2, std::variant<int, std::string>("-"));
```

finally, i dont know how to copy nums2 back into nums because of type difference even though i removed all the `-`

so have to use another for loop to paste everything back to nums from nums2

also, to print a variant vector, seems to need to use something called visit

```c++
        std::cout << "[";
        for (int i = 0; i < nums2.size(); i++) {
            // std::visit lets us access the value inside the variant
            std::visit([](auto&& arg) {
                std::cout << arg;
            }, nums2[i]);

            std::cout << " ";
        }
        std::cout << "]" << std::endl;
```

so that everything, int and strings, can all be printed

### solution

```c++

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // printing arrays need for loops now
        // std::cout << "[";
        // for (int x : nums) {
        //     std::cout << x << " ";
        // }
        // std::cout << "]" << std::endl;

        int leftPointer = 0;
        int rightPointer = leftPointer + 1;
        std::vector<std::variant<int, std::string>> nums2(nums.begin(), nums.end());

        while (leftPointer != rightPointer && rightPointer != nums2.size()){
            // std::cout<<"index: "<<i<<" nums "<<nums[i]<< std::endl;
            if(nums2[leftPointer] == nums2[rightPointer] && (rightPointer - leftPointer) == 1){
                rightPointer += 1;
                continue;
            }
            if(nums2[leftPointer] == nums2[rightPointer] && (rightPointer - leftPointer) > 1){
                nums2[rightPointer] = "-";
                rightPointer += 1;
                continue;
            }
            if(nums2[leftPointer] != nums2[rightPointer]){
                leftPointer = rightPointer;
                rightPointer += 1;
            }

        }

        std::erase(nums2, std::variant<int, std::string>("-"));

        // std::cout << "[";
        // for (int i = 0; i < nums2.size(); i++) {
        //     // std::visit lets us access the value inside the variant
        //     std::visit([](auto&& arg) {
        //         std::cout << arg;
        //     }, nums2[i]);

        //     std::cout << " ";
        // }
        // std::cout << "]" << std::endl;

        nums.resize(nums2.size());

        for (int i = 0; i < nums2.size(); i++) {
            nums[i] = std::get<int>(nums2[i]);
        }

        return nums.size();
    }
};
```

## 169. Majority Element

immediately use hash table for counting occurences

key is the thing you want to count

value is the count of how many occurence the key appeared

simple way to initialize a hash table

```c++
        std::unordered_map<int, int> numsMap;
```

unfortunately c++ has no way of automatically finding key with highest value. so we have to use for loop, and look for maximum value

### solution

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> numsMap;

        for(int x : nums) {
            numsMap[x]++;
        }

        int maxKey = -1;
        int maxValue = -1;

        for (auto const& [key, val] : numsMap) {
            if (val > maxValue) {
                maxValue = val;
                maxKey = key;
            }
        }
        return maxKey;

    }
};
```

## 189. Rotate Array

just bring the back `k` number to the front

warning: there might be cases where k is larger than the size of the vector

so we have to use modulo to get remainder, then take the size of the vector to minus off the remainder to know where to split (call it `place_to_split`)

then, we divide this part into 2 parts; a front part and a back part.

front part will do `nums.begin()`, `nums.begin()` + `place_to_split`

back part will do `nums.begin()` + `place_do_split` , `nums.end()`

this will solve 3 splits:

1. when nums.size() is even
2. when nums.size() is odd
3. when k > nums.size() where nums.size() is either even or odd

### solution

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int placeToSplit = nums.size() - (k %= nums.size());

        std::vector<int> last_N_items(nums.begin()+ placeToSplit, nums.end());
        std::vector<int> first_N_items(nums.begin(), nums.begin() + placeToSplit);

        // std::cout<<"[";
        // for (int x:last_N_items){
        // std::cout<<x<<",";
        // }
        // std::cout<<"]"<<std::endl;


        // std::cout<<"[";
        // for (int x:first_N_items){
        // std::cout<<x<<",";
        // }
        // std::cout<<"]"<<std::endl;

    nums = last_N_items;
    nums.insert(nums.end(), first_N_items.begin(), first_N_items.end());

        std::cout<<"[";
        for (int x:nums){
        std::cout<<x<<",";
        }
        std::cout<<"]"<<std::endl;

    }
};
```
