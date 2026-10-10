
#include <iostream>
#include <vector>
using namespace std;

int maxOnes(const vector<int>& nums, int i,
            int current, int best) {
    if (i == nums.size()) {
        return best;
    }

    if (nums[i] == 1) {
        current++;
        if (current > best) {
            best = current;
        }
    } else {
        current = 0;
    }

    return maxOnes(nums, i + 1, current, best);
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << maxOnes(nums, 0, 0, 0) << endl;
    return 0;
}
