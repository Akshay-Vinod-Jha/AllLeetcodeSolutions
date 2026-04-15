class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<string> useme;

        for(auto& indword:words){
            useme.push_back(indword);
        }
        for(auto& indword:words){
            useme.push_back(indword);
        }

        int wordslength = words.size();
        startIndex += wordslength;

        int remte = INT_MAX;
        int newlength = useme.size();

        for(int i = 0; i < newlength; i++){
            if(useme[i] == target){
                int dist = abs(i - startIndex);
                dist = min(dist, wordslength - dist % wordslength);

                remte = min(remte, dist);
            }
        }

        return remte == INT_MAX ? -1 : remte;
    }
};