class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> ln(n, 0);
        vector<int> rn(n, 0); 
        int cntN = 0;
        for (int i = 0; i < n; i++) {
            ln[i] = cntN;
            if (customers[i] == 'N') cntN++;
        }
        int cntY = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') cntY++;
            rn[i] = cntY;
        }
        int best = INT_MAX;
        int index = 0;
        for (int i = 0; i < n; i++) {
            int penalty = ln[i] + rn[i];
            if (penalty < best) {
                best = penalty;
                index = i;
            }
        }
        if (cntN < best) index = n;
        return index;
    }
};
