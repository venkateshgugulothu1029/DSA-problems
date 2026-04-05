#include <iostream>
using namespace std;

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    cout << reverseString("hello");
    return 0;
}
