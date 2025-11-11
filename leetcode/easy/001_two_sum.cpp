// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Link: https://leetcode.com/problems/two-sum/description/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(const vector<int> &nums, const int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        int remainder = target - nums[i];

        if (hash.find(remainder) != hash.end()) {
            return {hash[remainder], i};
        }

        hash[nums[i]] = i;
    }
    return {};
}

void initArray(vector<int> &arr, int &n) {
    cout << "Input n=";
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> arr[i];
    }
}

void printArray(const vector<int> &arr) {
    for (const int i: arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main(int argc, char *argv[]) {
    int n, target;
    vector<int> nums;

    initArray(nums, n);
    cout << "Enter target: ";
    cin >> target;

    const vector<int> expect = twoSum(nums, target);
    printArray(expect);
}
