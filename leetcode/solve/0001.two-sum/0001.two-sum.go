package main 

import "fmt"

/**
 * @index 1
 * @title 两数之和
 * @difficulty 简单
 * @tags array,hash-table
 * @draft false
 * @link https://leetcode.cn/problems/two-sum/description/
 * @frontendId 1
 * @solved false
*/

func twoSum(nums []int, target int) []int {
    mp := make(map[int]int, 0)
    for i, num := range nums {
        if _, ok := mp[target - num]; ok {
            return []int{i, mp[target - num]}
        } else {
            mp[num] = i
        }
    }
    return []int{}
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	result := twoSum(nums, target)
	fmt.Println(result)
}