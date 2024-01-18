#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // edge case, nums1 is the same size of nums2
    if (m==0) {
        nums1 = nums2;
    }

    int index_nums2 = 0;
    while (index_nums2 < n) {
        for(int i=0; i<m+index_nums2; i++) {
            if (nums1[i] > nums2[index_nums2]) {
                int save_num1 = nums1[i];
                nums1[i] = nums2[index_nums2];
                nums2[index_nums2] = save_num1;
            }
        }
        nums1[m+index_nums2] = nums2[index_nums2];
        index_nums2++;
    }
}

int main() {
    vector<int> a = {4,5,6,0,0,0};
    vector<int> b = {1,2,3};
    
    merge(a, 3, b, 3);

    for (int i = 0; i<a.size(); i++) {
        cout << a[i];
    }
}