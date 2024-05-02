#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 163
 * @title 缺失的区间
 * @difficulty 简单
 * @tags array
 * @draft false
 * @link https://leetcode.cn/problems/missing-ranges/description/
 * @frontendId 163
 * @solved true
*/

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int l = lower;
        int r;
        vector<string> ans;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == l) {
                l = nums[i] + 1;
            } else if (nums[i] > l) {
                r = nums[i] - 1;
                if (l == r) {
                    ans.push_back(to_string(l));
                } else {
                    ans.push_back(to_string(l) + "->" + to_string(r));
                }
                l = nums[i]+1;
            }
        }
        if (l <= upper) {
            r = upper;
            if (l == r) {
                ans.push_back(to_string(l));
            } else {
                ans.push_back(to_string(l) + "->" + to_string(r));
            }
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {0,1,3,50,75};
    auto ans = Solution().findMissingRanges(nums, 0, 99);
    for (auto x: ans) {
        cout << x << endl;
    }
    return 0;
}

