/**
 * @index 7
 * @title 整数反转
 * @difficulty 中等
 * @tags math
 * @draft false
 * @link https://leetcode.cn/problems/reverse-integer/description/
 * @frontendId 7
 * @solved false
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        int ans = 0;
        while (x != 0) {
            // INT_MAX/10 is to prevent ans*10 overflow
            if (ans < INT_MIN/10 || ans > INT_MAX/10) {
                return 0;
            }
            ans = ans*10 + (x % 10);
            x = x / 10;
        }
        return ans;
    }
};

int main() {
    int x = -2147483412;
    int ans = Solution().reverse(x);
    cout << ans << endl;
    return 0;
}


