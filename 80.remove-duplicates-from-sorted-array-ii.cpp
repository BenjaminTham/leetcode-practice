/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
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
        
        std::cout << "[";
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
// @lc code=end

