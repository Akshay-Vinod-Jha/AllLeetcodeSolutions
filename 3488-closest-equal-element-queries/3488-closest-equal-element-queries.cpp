class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        unordered_map<int, vector<int>> iammap;
        unordered_map<int, unordered_map<int,int>> pos; 

        int size = nums.size();

        for(int i=0;i<size;i++){
            iammap[nums[i]].push_back(i);
        }
        for(auto &it : iammap){
            vector<int> &v = it.second;
            for(int i=0;i<v.size();i++){
                pos[it.first][v[i]] = i;
            }
        }

        vector<int> retme;
        size = queries.size();
        int n = nums.size();

        for(int i=0;i<size;i++){
            int consider = queries[i];
            int number = nums[consider];

            if(iammap[number].size() <= 1){
                retme.push_back(-1);
            }
            else{
                vector<int>& cons = iammap[number]; 
                int lastindex = cons.size() - 1;

                int ind = pos[number][consider]; 

                if(ind == 0){
                    retme.push_back(
                        min(
                            abs(cons[ind] - cons[ind+1]),
                            n - abs(cons[ind] - cons[lastindex])
                        )
                    );
                }
                else if(ind == lastindex){
                    retme.push_back(
                        min(
                            abs(cons[ind] - cons[ind-1]),
                            n - abs(cons[ind] - cons[0])
                        )
                    );
                }
                else{  
                    retme.push_back(
                        min(
                            abs(cons[ind] - cons[ind+1]),
                            abs(cons[ind] - cons[ind-1])
                        )
                    );
                }   
            }
        }

        return retme;
    }
};