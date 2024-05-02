#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;

/**
 * @index 3
 * @title 无重复字符的最长子串
 * @difficulty 中等
 * @tags hash-table,string,sliding-window
 * @draft false
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 * @frontendId 3
 * @solved true
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; int r = -1; int ans = 0;
        set<char> visited;
        int n = s.length();
        while (r + 1 < n) {
            if ((r + 1) < s.length() && (visited.find(s[r+1]) == visited.end())) {
                visited.insert(s[++r]) ;
                ans = max(ans, r - l + 1);
            } else {
                visited.erase(s[l++]);
            }
        }
        return ans;
    }
};


int main() {
    int ans;
    ans = Solution().lengthOfLongestSubstring("abcabcbb");
    cout << ans << endl;
    return 0;
}
