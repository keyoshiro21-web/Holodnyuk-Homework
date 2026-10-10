
#include <iostream>
#include <vector>
using namespace std;

void sortedSquares(const vector<int>& nums,
                   vector<int>& res, int left, int right,
                   int pos) {
    if (left > right) {
        return;
    }

    int l = nums[left] * nums[left];
    int r = nums[right] * nums[right];

    if (l > r) {
        res[pos] = l;
        sortedSquares(nums, res, left + 1, right, pos - 1);
    } else {
        res[pos] = r;
        sortedSquares(nums, res, left, right - 1, pos - 1);
    }
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res(nums.size());

    sortedSquares(nums, res, 0, nums.size() - 1,
                  nums.size() - 1);

    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
