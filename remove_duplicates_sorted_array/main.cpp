#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


int removeDuplicates(vector<int>& nums) {
    int k = 1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i-1] != nums[i]){
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4}; // Input array
    vector<int> expectedNums = {0,1,2,3,4}; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " and " << expectedNums[i] << endl;
    }
}
