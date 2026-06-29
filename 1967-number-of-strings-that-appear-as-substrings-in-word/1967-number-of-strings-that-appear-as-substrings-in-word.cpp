class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
      unordered_map<string,pair<int,bool>> s;
      for(auto& i:patterns){ 
        s[i].first++;
        s[i].second = false;
      }
      int res = 0;
      int size = word.size();
      for(int i=0;i<size;i++){
        string useme = "";
        for(int j=i;j<size;j++){
            useme += word[j];
            if(!s[useme].second){
                res += s[useme].first;
                s[useme].second = true;
            }
        }
      }   

      return res;
    }
};