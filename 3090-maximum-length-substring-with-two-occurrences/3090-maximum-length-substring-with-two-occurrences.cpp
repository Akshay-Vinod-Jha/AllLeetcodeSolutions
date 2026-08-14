class Solution {
public:
    int maximumLengthSubstring(string s) {

        set<int> hehe;
        for(auto& i : s)
            hehe.insert(i);

        int limit_size = hehe.size();

        int size = s.length();

        int ans = 0;

        for(int i = 0; i < size; i++) {

            vector<int> f(26, 0);

            for(int j = i; j < size; j++) {

                int char_to_int = s[j] - 'a';

                f[char_to_int]++;

                if(f[char_to_int] > 2)
                    break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};