class Solution {
public:
    int modme = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int start = 1;
        int end = r - l + 1;

        vector<vector<int>> next(end + 1, vector<int>(2, 1));
        vector<vector<int>> curr(end + 1, vector<int>(2, 0));

        int retme = 0;

        vector<int> fortrue(end + 1, 0);
        vector<int> forfalse(end + 1, 0);

        for(int index = n - 1; index >= 1; index--) {

            fill(fortrue.begin(), fortrue.end(), 0);
            fill(forfalse.begin(), forfalse.end(), 0);

            for(int i = start; i <= end; i++) {
                fortrue[i] =
                    (fortrue[i - 1] + next[i][false]) % modme;

                forfalse[i] =
                    (forfalse[i - 1] + next[i][true]) % modme;
            }

            for(int prev = start; prev <= end; prev++) {

                curr[prev][true] =
                    (fortrue[end] - fortrue[prev] + modme) % modme;

                curr[prev][false] =
                    forfalse[prev - 1];
            }

            swap(curr, next);
        }

        for(int i = start; i <= end; i++) {

            retme = (retme + next[i][true]) % modme;
            retme = (retme + next[i][false]) % modme;
        }

        return retme;
    }
};