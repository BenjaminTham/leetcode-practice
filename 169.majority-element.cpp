/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
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
// @lc code=end

