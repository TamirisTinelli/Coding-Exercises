/*
Leet Code Problem
34. Find First and Last Position of Element in Sorted Array
link: leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

solution by: Tamiris Tinelli
Date: 02/Apr/2024
Time Complexity: O(log n)
*/

// Solution Version 3 - Recursive Binary Search

#include <iostream>
#include <vector>

using namespace std;

int findFirstRec (vector<int>& nums, int target, int ini, int fim) {
    if (ini > fim) return -1;
    if (ini == fim && nums[ini] == target) return ini;

    int meio = (ini + fim) / 2;

    if (nums[meio] > target)
        return findFirstRec(nums, target, ini, meio-1);
    if (nums[meio] < target)
        return findFirstRec(nums, target, meio+1, fim);
    return findFirstRec(nums, target, ini, meio);
}

int findLastRec (vector<int>& nums, int target, int ini, int fim) {
    if (ini > fim) return -1;

    if (ini == fim && nums[ini] == target) return ini;

    int meio = (ini + fim + 1) / 2;

    if (nums[meio] > target)
        return findLastRec(nums, target, ini, meio-1);
    if (nums[meio] < target)
        return findLastRec(nums, target, meio+1, fim);
    return findLastRec(nums, target, meio, fim);
}


//function solution for submission
vector<int> searchRange(vector<int>& nums, int target) {
    int f = findFirstRec(nums, target, 0, nums.size()-1);
    int l = findLastRec(nums, target, 0, nums.size()-1);

    vector<int>res;
    res.push_back(f);
    res.push_back(l);
    return res; 
}


int main() {
    //input for test
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    int target = 8;
    //answer: 3, 4

    int f = findFirstRec(nums, target, 0, nums.size()-1);
    int l = findLastRec(nums, target, 0, nums.size()-1);

    printf("Resposta: %d e %d\n", f, l);

    return 0;
}