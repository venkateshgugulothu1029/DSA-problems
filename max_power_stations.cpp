#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stations[i];
        }

        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        long long low = 0, high = 1e18, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(power, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    bool canAchieve(vector<long long> power, int r, long long k, long long target) {
        int n = power.size();
        vector<long long> extra(n + 1, 0);

        long long used = 0, currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += extra[i];
            power[i] += currAdd;

            if (power[i] < target) {
                long long need = target - power[i];
                used += need;

                if (used > k) return false;

                currAdd += need;

                int end = i + 2 * r + 1;
                if (end < n) extra[end] -= need;
            }
        }

        return true;
    }
};