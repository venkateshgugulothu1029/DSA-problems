#include <iostream>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;

        while (n > 0) {
            ans ^= n;
            n >>= 1;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int n = 6;
    cout << obj.minimumOneBitOperations(n);
    return 0;
}