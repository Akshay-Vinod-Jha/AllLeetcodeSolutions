class Solution {
public:

    bool isPrimeOrNot(int number){

        if(number==1) return false;

        for(int i=2;i*i<=number;i++){
            if(number%i==0) return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int size = nums.size();

        vector<bool> isprime_array(size,false);

        for(int i=0;i<size;i++){
            isprime_array[i]=isPrimeOrNot(nums[i]);
        }
        unordered_map<int,vector<int>> divisibles;

        for(int i=0;i<size;i++){

            if(!isprime_array[i]) continue;

            for(int j=0;j<size;j++){

                if(i==j) continue;

                if(nums[j]%nums[i]==0){
                    divisibles[nums[i]].push_back(j);
                }
            }
        }

        vector<bool> visited(size,false);
        unordered_set<int> doneprime;

        queue<pair<int,int>> q;

        q.push({0,0});

        visited[0]=true;

        while(!q.empty()){

            int sizeis = q.size();

            for(int i=0;i<sizeis;i++){

                int topis = q.front().first;
                int level = q.front().second;

                q.pop();

                if(topis==size-1) return level;
                if(topis-1>=0 && !visited[topis-1]){
                    visited[topis-1]=1;
                    q.push({topis-1,level+1});
                }
                if(topis+1<size && !visited[topis+1]){
                    visited[topis+1]=1;
                    q.push({topis+1,level+1});
                }

                if(
                    isprime_array[topis] &&
                    doneprime.find(nums[topis])==doneprime.end()
                ){

                    for(auto& a : divisibles[nums[topis]]){

                        if(!visited[a]){

                            visited[a]=1;

                            q.push({a,level+1});
                        }
                    }

                    doneprime.insert(nums[topis]);
                }

            }
        }

        return -1;
    }
};