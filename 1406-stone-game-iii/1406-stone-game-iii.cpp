class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int turn, vector<int>& stoneValue) {

        if (index >= stoneValue.size())
            return 0;

        if (dp[index][turn] != -1)
            return dp[index][turn];

        if (turn == 0) {

            int ans = INT_MIN;
            int sum = 0;

            for (int i = index; i < min(index + 3, (int)stoneValue.size());
                 i++) {

                sum += stoneValue[i];

                ans = max(ans, sum + solve(i + 1, 1, stoneValue));
            }

            return dp[index][turn] = ans;
        } else {

            int ans = INT_MAX;

            for (int i = index; i < min(index + 3, (int)stoneValue.size());
                 i++) {

                ans = min(ans, solve(i + 1, 0, stoneValue));
            }

            return dp[index][turn] = ans;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        dp.assign(n + 1, vector<int>(2, -1));

        int total = 0;

        for (auto x : stoneValue)
            total += x;

        int alice = solve(0, 0, stoneValue);

        int bob = total - alice;

        if (alice > bob)
            return "Alice";

        if (alice < bob)
            return "Bob";

        return "Tie";
    }
};