
#include <iostream>
#include <vector>
using namespace std;

bool descending(const vector<int>& arr, int i);

bool mountain(const vector<int>& arr, int i) {
    if (i >= arr.size() - 1) {
        return false;
    }

    if (arr[i] > arr[i - 1]) {
        return mountain(arr, i + 1);
    }

    return descending(arr, i);
}

bool descending(const vector<int>& arr, int i) {
    if (i == arr.size() - 1) {
        return true;
    }

    if (arr[i] <= arr[i + 1]) {
        return false;
    }

    return descending(arr, i + 1);
}

bool isMountain(const vector<int>& arr) {
    if (arr.size() < 3 || arr[0] >= arr[1]) {
        return false;
    }

    return mountain(arr, 1);
}

int main() {
    vector<int> arr = {0, 3, 2, 1};

    cout << (isMountain(arr) ? "true" : "false") << endl;

    return 0;
}
