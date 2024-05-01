/*
Leet Code Problem
34. Find First and Last Position of Element in Sorted Array
link: leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

solution by: Tamiris Tinelli
Date: 02/Apr/2024
Time Complexity: O(n)
*/

// Solution Version 1 - Linear Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for (int i=0; i < nums.size();i++) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                else last = i;
            }
            else if (nums[i] > target) break;
        }
        if (last < first) last = first;
        printf ("[%d,%d]", first, last);

        vector<int>res;
        res.push_back(first);
        res.push_back(last);
        return res; 
    }
};