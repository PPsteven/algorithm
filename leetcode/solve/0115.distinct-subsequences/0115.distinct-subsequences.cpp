#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 115
 * @title 不同的子序列
 * @difficulty 困难
 * @tags string,dynamic-programming
 * @draft false
 * @link https://leetcode.cn/problems/distinct-subsequences/description/
 * @frontendId 115
 * @solved true
*/

#include <stack> using namespace std;

// add a help stack to store the mininum value in the stack
class MinStack {
public:
    stack<int> st;
    stack<int> min_st; // push the mininum value of stack

    MinStack() {
        min_st.push(INT_MAX);
    }

    void push(int val) {
        st.push(val);
        min_st.push(min(val, min_st.top()));
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
