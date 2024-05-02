#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 316
 * @title 去除重复字母
 * @difficulty 中等
 * @tags stack,greedy,string,monotonic-stack
 * @draft false
 * @link https://leetcode.cn/problems/remove-duplicate-letters/description/
 * @frontendId 316
 * @solved true
*/

#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 通过统计数字出现评率，辅助入栈
class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.length();
        vector<int> letters(26, 0);
        vector<bool> vis(26, false);
        for (char& c: s) {
            letters[c-'a']++;
        }

        stack<char> st;
        for (int i=0; i<n; i++) {
            letters[s[i]-'a']--;
            if (vis[s[i]-'a']) {
                continue;
            }
            // 删除条件：1. 不符合字典序 2.后面还有
            while (!st.empty() && s[i] < st.top() && letters[st.top() - 'a'] > 0) {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            vis[s[i]-'a'] = true;
            st.push(s[i]);
        }
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().removeDuplicateLetters("cbacdcbc");
    cout << ans << endl;
    return 0;
}
