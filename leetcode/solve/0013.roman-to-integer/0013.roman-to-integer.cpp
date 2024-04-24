#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 13
 * @title 罗马数字转整数
 * @difficulty 简单
 * @tags hash-table,math,string
 * @draft false
 * @link https://leetcode.cn/problems/roman-to-integer/description/
 * @frontendId 13
 * @solved true
*/

#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && mp[s[i+1]] > mp[s[i]]) {
            ans = ans - mp[s[i]];
        } else {
            ans = ans + mp[s[i]];
        }
    }
    return ans;
    }
};


int main() {
    int ans = Solution().romanToInt("CXI");
    cout << ans << endl;
    return 0;
}
