
#include <iostream>
#include <vector>
using namespace std;

void sortByParity(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    if (nums[left] % 2 == 0) {
        sortByParity(nums, left + 1, right);
        return;
    }

    if (nums[right] % 2 != 0) {
        sortByParity(nums, left, right - 1);
        return;
    }

    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;

    sortByParity(nums, left + 1, right - 1);
}

void printArray(const vector<int>& nums, int i = 0) {
    if (i == nums.size()) {
        cout << endl;
        return;
    }

    cout << nums[i] << " ";
    printArray(nums, i + 1);
}

int main() {
    vector<int> nums = {3, 1, 2, 4};

    sortByParity(nums, 0, nums.size() - 1);
    printArray(nums);

    return 0;
}
