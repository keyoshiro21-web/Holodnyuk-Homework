
#include <iostream>
#include <string>
using namespace std;

void reverseString(const string& s, int index) {
    if (index < 0) {
        return;
    }

    cout << s[index];
    reverseString(s, index - 1);
}

int main() {
    string s = "tiger";

    reverseString(s, s.length() - 1);
    cout << endl;

    return 0;
}
