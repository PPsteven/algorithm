#include <map>
#include <vector>
#include <iostream>
using namespace std;

/**
 * @index 1
 * @title 两数之和
 * @difficulty 简单
 * @tags array,hash-table
 * @draft false
 * @link https://leetcode.cn/problems/two-sum/description/
 * @frontendId 1
 * @solved true
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                return {i, mp[target - nums[i]]};
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans;
    ans = Solution().twoSum(nums, 9);
    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}
