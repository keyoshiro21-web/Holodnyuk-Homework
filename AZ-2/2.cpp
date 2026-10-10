
#include <iostream>
#include <vector>
using namespace std;

int countDigits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int countEvenDigits(const vector<int>& nums, int i) {
    if (i == nums.size()) {
        return 0;
    }

    int count = countDigits(nums[i]) % 2 == 0 ? 1 : 0;

    return count + countEvenDigits(nums, i + 1);
}

int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};

    cout << countEvenDigits(nums, 0) << endl;
    return 0;
}
