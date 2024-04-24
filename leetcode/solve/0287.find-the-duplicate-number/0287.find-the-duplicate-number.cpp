#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 287
 * @title 寻找重复数
 * @difficulty 中等
 * @tags bit-manipulation,array,two-pointers,binary-search
 * @draft false
 * @link https://leetcode.cn/problems/find-the-duplicate-number/description/
 * @frontendId 287
 * @solved true
*/

#include <vector>
using namespace std;

// use fast-slow pointer to find the meet point.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        // do .. while
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (nums[slow] == nums[fast]) {
                break;
            }
        }
        // move to start
        slow = 0;
        // while
        while (nums[slow] != nums[fast]) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
};

// 另有写法，判断 slow == fast。但是这里为了方便思考，与图逻辑对应，就使用
// nums[slow] == nums[fast] 的写法。

int main() {
    vector<int> nums = {1,3,4,2,2};
    int ans = Solution().findDuplicate(nums);
    printf("%d\n", ans);
    return 0;
}
