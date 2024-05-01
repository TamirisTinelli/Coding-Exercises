/*
Leet Code Problem
34. Find First and Last Position of Element in Sorted Array
link: leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

solution by: Tamiris Tinelli
Date: 02/Apr/2024
Time Complexity: O(log n)
*/

// Solution Version 2 - Iterative Binary Search

#include <iostream>
#include <vector>

using namespace std;

// encontra a primeira vez que o target aparece no array e retorna a posição
// se não tiver target no array, retorna -1 
int findFirst (vector<int>& nums, int target) {
    int ini = 0;
    int fim = nums.size()-1;
    while (ini <= fim){
        if (ini == fim && nums[ini] == target) return ini;

        int meio = (ini + fim) / 2;

        if (nums[meio] > target) fim = meio - 1;
        else if (nums[meio] < target) ini = meio + 1;
        else fim = meio;
    }
    return -1;
}

// encontra a última vez que o target aparece no array e retorna a posição
// se não tiver target no array, retorna -1 
int findLast (vector<int>& nums, int target) {
    int ini = 0;
    int fim = nums.size()-1;
    while (ini <= fim){
        if (ini == fim && nums[ini] == target) return ini;

        int meio = (ini + fim + 1) / 2;

        if (nums[meio] > target) fim = meio - 1;
        else if (nums[meio] < target) ini = meio + 1;
        else ini = meio;
    }
    return -1;
}

//function solution for submission
//binary search
vector<int> searchRange(vector<int>& nums, int target) {
    int f = findFirst(nums, target);
    int l = findLast(nums, target);

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

    int f = findFirst(nums, target);
    int l = findLast(nums, target);

    printf("Resposta: %d e %d\n", f, l);

    return 0;
}