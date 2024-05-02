#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/**
 * @index 48
 * @title 旋转图像
 * @difficulty 中等
 * @tags array,math,matrix
 * @draft false
 * @link https://leetcode.cn/problems/rotate-image/description/
 * @frontendId 48
 * @solved true
*/

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        // 对折
        for (int i=0; i< n; i++) {
           for (int j=i+1; j<n; j++) {
                swap(matrix, i, j, j, i);
            }
        }

        for (int j=0; j<n/2; j++) {
            for (int i=0; i<n; i++) {
                swap(matrix, i, j, i, n - j - 1);
            }
        }
    }
    void swap(vector<vector<int>>&matrix, int x1, int y1, int x2, int y2) {
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
    }
};



