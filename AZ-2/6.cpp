
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums, int i, int k) {
    if (i == nums.size()) {
        return k;
    }

    if (k == 0 || nums[i] != nums[k - 1]) {
        nums[k] = nums[i];
        return removeDuplicates(nums, i + 1, k + 1);
    }

    return removeDuplicates(nums, i + 1, k);
}

void printArray(const vector<int>& a, int i, int k) {
    if (i == k) {
        cout << endl;
        return;
    }
    cout << a[i] << " ";
    printArray(a, i + 1, k);
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums, 0, 0);

    cout << "K = " << k << endl;
    printArray(nums, 0, k);

    return 0;
}
