/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
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
// @lc code=end

