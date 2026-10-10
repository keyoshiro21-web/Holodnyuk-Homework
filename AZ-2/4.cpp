
#include <iostream>
#include <vector>
using namespace std;

void duplicateZerosRec(const vector<int>& arr,
                       vector<int>& res, int i, int j) {
    if (i == arr.size() || j >= res.size()) {
        return;
    }

    res[j] = arr[i];

    if (arr[i] == 0 && j + 1 < res.size()) {
        res[j + 1] = 0;
        duplicateZerosRec(arr, res, i + 1, j + 2);
    } else {
        duplicateZerosRec(arr, res, i + 1, j + 1);
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    vector<int> res(arr.size());

    duplicateZerosRec(arr, res, 0, 0);

    // Рекурсивне виведення
    auto print = [&](auto&& self, int i) -> void {
        if (i == res.size()) return;
        cout << res[i] << " ";
        self(self, i + 1);
    };

    print(print, 0);
    cout << endl;

    return 0;
}
