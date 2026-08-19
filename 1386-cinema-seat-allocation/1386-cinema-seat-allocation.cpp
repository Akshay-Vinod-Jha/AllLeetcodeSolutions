class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, long long> a;

        for(auto& i : reservedSeats) {
            int row = i[0];
            int seat = i[1];

            a[row] = a[row] | (1LL << (seat - 1));
        }

        int count = (n - a.size()) * 2;

        long long for2 = 0;
        for2 |= (1LL << 1);
        for2 |= (1LL << 2);
        for2 |= (1LL << 3);
        for2 |= (1LL << 4);

        long long for4 = 0;
        for4 |= (1LL << 3);
        for4 |= (1LL << 4);
        for4 |= (1LL << 5);
        for4 |= (1LL << 6);

        long long for6 = 0;
        for6 |= (1LL << 5);
        for6 |= (1LL << 6);
        for6 |= (1LL << 7);
        for6 |= (1LL << 8);

        for(auto& [row, mask] : a) {

            bool passed2 = ((mask & for2) == 0);
            bool passed4 = ((mask & for4) == 0);
            bool passed6 = ((mask & for6) == 0);

            if(passed2 && passed6)
                count += 2;
            else if(passed2 && passed4)
                count += 1;
            else if(passed4 && passed6)
                count += 1;
            else if(passed2)
                count += 1;
            else if(passed4)
                count += 1;
            else if(passed6)
                count += 1;
        }

        return count;
    }
};