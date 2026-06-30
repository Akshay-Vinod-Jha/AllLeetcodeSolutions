class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> vmap(3,0);
        int left = 0 , right = 0;
        int size = s.length();
        int retme = 0;
        while(right<size){
            vmap[s[right]-'a']++;
            while(vmap[0]>0 && vmap[1]>0 && vmap[2]>0){
                retme +=( size-right );
                vmap[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return retme;
    }
};