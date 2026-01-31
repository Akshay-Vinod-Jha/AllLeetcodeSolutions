class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int size = letters.size();
        sort(letters.begin(),letters.end());
        if(target<letters[0]) return letters[0];
        if(target>letters[size-1]) return letters[0];

        char toreturn = letters[0];
        for(int i=0;i<size;i++){
            if(target<letters[i]){
                toreturn = letters[i];
                break;
            }
        } 
        return toreturn;
    }
};