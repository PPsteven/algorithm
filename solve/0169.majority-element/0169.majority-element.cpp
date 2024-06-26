#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 169
 * @title 多数元素
 * @difficulty 简单
 * @tags array,hash-table,divide-and-conquer,counting,sorting
 * @draft false
 * @link https://leetcode.cn/problems/majority-element/description/
 * @frontendId 169
 * @solved true
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                candidate = nums[i];
                continue;
            }
            if (nums[i] == candidate) {
                count--;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};
    int ans = Solution().majorityElement(nums);
    cout << ans << endl;
    return 0;
}
