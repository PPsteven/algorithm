#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 240
 * @title 搜索二维矩阵 II
 * @difficulty 中等
 * @tags array,binary-search,divide-and-conquer,matrix
 * @draft false
 * @link https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
 * @frontendId 240
 * @solved true
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Most Important Thing: start point must place to the top right cell
        int x = 0; int y= m - 1;
        while (x >=0 && x < n && y >= 0 && y <m) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};


