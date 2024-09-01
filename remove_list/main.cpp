#include <vector>
#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int removeElement(vector<int>& nums, int val) {
    // base case
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0] != val;

    int lastIdx = nums.size()-1;
    for (int i=0;i<lastIdx; i++) {
        if (nums[i] == val) {
            while (nums[lastIdx] == val && lastIdx-1 > i) {
                lastIdx--;
            }

            swap(nums[i], nums[lastIdx]);
        }

        
        for (int i=0;i<nums.size(); i++) {
            cout << nums[i] << ", ";
        }
        cout << endl;
    }

    for (int i=0;i<nums.size(); i++) {
        if (nums[i] == val) return i;
    }
    return nums.size();
}

int main() {
    vector<int> nums = {4,2,0,2,2,1,4,4,1,4,3,2}; // Input array
    int val = 4; // Value to remove

    int k = removeElement(nums, val); // Calls your implementation

    cout << "nb elements: " << k << endl;
    for (int num : nums ){
        cout << num << ", ";
    }

    return 0;
}