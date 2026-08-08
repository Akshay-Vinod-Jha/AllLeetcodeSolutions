class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int w1_len = word1.length();
        int w2_len = word2.length();
        vector<int> w1_matched(w1_len,0);
        int matched_count = 0;
        int i = w1_len-1 , j = w2_len-1;

        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                matched_count++;
                j--;
            }
            w1_matched[i] = matched_count;
            i--;
        }

        vector<int> return_seq;
        i = 0;
        j = 0;

        bool allowed_once = true;

        while(i<w1_len && j<w2_len){
            if(word1[i]==word2[j]){
                return_seq.push_back(i);
                j++;
            }else{
                int matched_count_rem = i+1>=w1_len?0: w1_matched[i+1];
                int rem_numbers = w2_len - j - 1;
                if ( allowed_once && matched_count_rem >= rem_numbers){
                    allowed_once = false;
                    return_seq.push_back(i);
                    j++;
                }
            }
                    i++;
        }

        if(j>=w2_len) return return_seq;
        return {};

    }
};