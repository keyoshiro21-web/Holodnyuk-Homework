
#include <iostream>
#include <vector>
using namespace std;

void replaceElements(vector<int>& arr, int i, int mx) {
    if (i < 0) {
        return;
    }

    int current = arr[i];
    arr[i] = mx;

    if (current > mx) {
        mx = current;
    }

    replaceElements(arr, i - 1, mx);
}

void printArray(const vector<int>& arr, int i = 0) {
    if (i == arr.size()) {
        cout << endl;
        return;
    }

    cout << arr[i] << " ";
    printArray(arr, i + 1);
}

int main() {
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    arr[arr.size() - 1] = -1;
    replaceElements(arr, arr.size() - 2, -1);

    printArray(arr);

    return 0;
}
