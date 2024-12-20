#include <iostream>
#include <vector>
using namespace std;

// Program to remove duplicates from a sorted array

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0; // Points to the last unique element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1; // The count of unique elements
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int uniqueCount = removeDuplicates(nums);

    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
