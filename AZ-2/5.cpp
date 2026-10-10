
#include <iostream>
#include <vector>
using namespace std;

void mergeRec(vector<int>& nums1, int m,
              const vector<int>& nums2, int n, int k) {
    if (n == 0) return;

    if (m > 0 && nums1[m - 1] > nums2[n - 1]) {
        nums1[k - 1] = nums1[m - 1];
        mergeRec(nums1, m - 1, nums2, n, k - 1);
    } else {
        nums1[k - 1] = nums2[n - 1];
        mergeRec(nums1, m, nums2, n - 1, k - 1);
    }
}

void printArray(const vector<int>& a, int i = 0) {
    if (i == a.size()) {
        cout << endl;
        return;
    }
    cout << a[i] << " ";
    printArray(a, i + 1);
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    mergeRec(nums1, 3, nums2, 3, 6);
    printArray(nums1);

    return 0;
}
