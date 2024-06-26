#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 225
 * @title 用队列实现栈
 * @difficulty 简单
 * @tags stack,design,queue
 * @draft false
 * @link https://leetcode.cn/problems/implement-stack-using-queues/description/
 * @frontendId 225
 * @solved false
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
#include <queue>
#include <list>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q2.empty()) {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
        int ans = q1.front();
        q2.pop();
        return ans;
    }

    int top() {

    }

    bool empty() {
        return q.size() == 0;
    }
};
