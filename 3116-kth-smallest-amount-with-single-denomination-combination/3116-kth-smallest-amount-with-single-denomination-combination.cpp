

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    long long countMultiples(long long M, vector<int>& coins) {
        long long count = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    bits++;
                    l = lcm(l, 1LL * coins[j]);

                    if (l > M)
                        break;
                }
            }

            if (l > M)
                continue;

            if (bits % 2)
                count += M / l;
            else
                count -= M / l;
        }

        return count;
    }
};