
#include <iostream>
#include <vector>
using namespace std;

bool findDouble(const vector<int>& arr, int i, int j) {
    if (j == arr.size()) {
        return false;
    }

    if (i != j && arr[i] == 2 * arr[j]) {
        return true;
    }

    return findDouble(arr, i, j + 1);
}

bool checkDouble(const vector<int>& arr, int i = 0) {
    if (i == arr.size()) {
        return false;
    }

    if (findDouble(arr, i, 0)) {
        return true;
    }

    return checkDouble(arr, i + 1);
}

int main() {
    vector<int> arr = {10, 2, 5, 3};

    cout << (checkDouble(arr) ? "true" : "false") << endl;

    return 0;
}
