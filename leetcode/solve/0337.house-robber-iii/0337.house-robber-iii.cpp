#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 337
 * @title 打家劫舍 III
 * @difficulty 中等
 * @tags tree,depth-first-search,dynamic-programming,binary-tree
 * @draft false
 * @link https://leetcode.cn/problems/house-robber-iii/description/
 * @frontendId 337
 * @solved true
*/

#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 简单DFS+cache
class Solution {
public:
    unordered_map <TreeNode*, int> robcache, soncache;
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (robcache.find(root) != robcache.end()) {
            return robcache[root];
        }
        // 有重复计算问题，加cache 解决
        int v = max(root->val + son(root->left) + son(root->right),
         rob(root->left) + rob(root->right));
        robcache[root] = v;
        return v;
    }

    int son(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (soncache.find(root) != soncache.end()) {
            return soncache[root];
        }
        int v = rob(root->left) + rob(root->right);
        soncache[root] = v;
        return v;
    }
};


