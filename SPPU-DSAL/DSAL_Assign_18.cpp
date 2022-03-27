/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSAL Lab
Assignment: #18
*/

#include <iostream>
#include <climits>
using namespace std;

// Find optimal cost to construct a binary search tree from keys
// `i` to `j`, where each key `k` occurs `freq[k]` number of times
int findOptimalCost(int freq[], int i, int j, int level)
{
    // base case
    if (j < i) {
        return 0;
    }

    int optimalCost = INT_MAX;

    // consider each key as a root and recursively find an optimal solution
    for (int k = i; k <= j; k++)
    {
        // recursively find the optimal cost of the left subtree
        int leftOptimalCost = findOptimalCost(freq, i, k - 1, level + 1);

        // recursively find the optimal cost of the right subtree
        int rightOptimalCost = findOptimalCost(freq, k + 1, j, level + 1);

        // current node's cost is `freq[k]×level`
        int cost = freq[k] * level + leftOptimalCost + rightOptimalCost;

        // update the optimal cost
        optimalCost = min (optimalCost, cost);
    }

    // Return minimum value
    return optimalCost;
}

int main()
{
    int freq[] = { 25, 10, 20};
    int n = sizeof(freq) / sizeof(freq[0]);

    cout << "The optimal cost of constructing BST is "
         << findOptimalCost(freq, 0, n - 1, 1);
    cout<<"."<<endl;
    return 0;
}
