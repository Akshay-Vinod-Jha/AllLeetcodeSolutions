class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
      int n = queries[0].length();
      vector<string> retme;
      for(auto& i:queries){

        bool addkaru = false;
        
        for(auto& j:dictionary){
        
          int count = 0;
          for(int k=0;k<n;k++){
            if(i[k]!=j[k]) count++;
          }
        
          if(count<=2){
            addkaru = true;
          }
        
          if(addkaru){
            retme.push_back(i);
            break;
          }
        
        }
      
      }

      return retme;
    }
};