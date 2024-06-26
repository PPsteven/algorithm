#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 301
 * @title 删除无效的括号
 * @difficulty 困难
 * @tags breadth-first-search,string,backtracking
 * @draft false
 * @link https://leetcode.cn/problems/remove-invalid-parentheses/description/
 * @frontendId 301
 * @solved true
*/

#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

// 本题需要移除"最小"的括号，显而易见的方式是BFS，但是BFS 只能依次去除一个括号，无法做更深入的剪枝，所以效率不高。
// 本题还有一个更优的方式是 DFS+剪枝，只要合适的定义DFS搜索条件，结果是更优的。
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        vector<string> ans;
        set<string> st;
        string cur, next;
        if (isValid(s)) {
            return {s};
        }

        q.push(s);

        while (!q.empty()) {
            int level_num = q.size();
            for (int l=0; l<level_num;l++) {
                cur = q.front(); q.pop();
                for (int i = 0; i < cur.length(); i++) {
                    // case: (((((()
                    if (i > 0 && cur[i] == cur[i-1]) {
                        continue;
                    }
                    // case: a()
                    if (cur[i] == '(' || cur[i] == ')') {
                        next = cur.substr(0, i) + cur.substr(i+1, cur.length()-1-i);
                        // tip: remove duplicate node to current level.
                        st.insert(next);
                    }
                }
            }

            for (auto it = st.cbegin(); it != st.cend(); it++) {
                if (isValid(*it)) {
                    ans.push_back(*it);
                }
                q.push(*it);
            }
            if (ans.size()>0) {
                return ans;
            }
        }
        return {""};
    }

    bool isValid(string s) {
        int cnt = 0;
        for (auto c: s) {
            switch (c) {
                case '(':
                    cnt++;
                    break;
                case ')':
                    cnt--;
                    break;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
};

int main() {
    vector<string> ans = Solution().removeInvalidParentheses("()(((((((()");
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
