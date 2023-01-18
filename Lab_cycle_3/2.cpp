SA
Array
Matrix
Strings
Hashing
Linked List
Stack
Queue
Binary Tree
Binary Search Tree
Heap
Graph
Searching
Sorting
Divide & Conquer
Mathematical
Geometric
Bitwise
Greedy
Backtracking
Branch and Bound
Dynamic Programming
Pattern Searching
Randomized

▲
Related Articles
Write an Article
Write an Interview Experience
Dynamic Programming
Optimal Substructure Property in Dynamic Programming | DP-2
Overlapping Subproblems Property in Dynamic Programming | DP-1
How to solve a Dynamic Programming Problem ?
Tabulation vs Memoization
Bitmasking and Dynamic Programming | Set 1 (Count ways to assign unique cap to every person)
Digit DP | Introduction
Basic problem of Dynamic programming
Intermediate problems of Dynamic programming
Floyd Warshall Algorithm | DP-16
0-1 Knapsack Problem | DP-10
Egg Dropping Puzzle | DP-11
Box Stacking Problem | DP-22
Partition problem | DP-18
Travelling Salesman Problem using Dynamic Programming
Longest Palindromic Subsequence | DP-12
Longest alternating subsequence
Find all distinct subset (or subsequence) sums of an array
Weighted Job Scheduling
Number of paths with exactly k coins
Count number of ways to jump to reach end
Count number of ways to partition a set into k subsets
Maximum subarray sum in O(n) using prefix sum
Maximum number of trailing zeros in the product of the subsets of size k
Minimum number of deletions to make a string palindrome
Find if string is K-Palindrome or not | Set 1
Find the longest path in a matrix with given constraints
Find minimum sum such that one of every three consecutive elements is taken
Dynamic Programming | Wildcard Pattern Matching | Linear Time and Constant Space
Dynamic Programming | Building Bridges
Hard problems on Dynamic programming
0-1 Knapsack Problem | DP-10

Difficulty Level : Medium
Last Updated : 05 Dec, 2022
Read
Discuss(110+)
Courses
Practice
Video
Given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that the sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property)

Example:

Input: N = 3, W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Input: N = 3, W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

Recommended Problem
0 - 1 Knapsack Problem
Dynamic Programming
Algorithms
Amazon
Directi
+9 more
Solve Problem
Submission count: 2.8L
0-1 Knapsack Problem using recursion:
To solve the problem follow the below idea:

A simple solution is to consider all subsets of items and calculate the total weight and value of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the maximum value subset.

Optimal Sub-structure: To consider all subsets of items, there can be two cases for every item. 

Case 1: The item is included in the optimal subset.
Case 2: The item is not included in the optimal set.
Follow the below steps to solve the problem:

The maximum value obtained from ‘N’ items is the max of the following two values. 

Maximum value obtained by N-1 items and W weight (excluding nth item)
Value of nth item plus maximum value obtained by N-1 items and W minus the weight of the Nth item (including Nth item)
If the weight of the ‘Nth’ item is greater than ‘W’, then the Nth item cannot be included and Case 1 is the only possibility.
Below is the implementation of the above approach: 

C++
/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
// Driver code
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
