class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        unordered_map<int,int> m;
        for(auto& numberis:nums){
            for(int j=1;j*j<=numberis;j++){
                if(numberis%j==0){
                    int quotient = numberis/j;
                    m[j]++;
                    if(quotient!=j) m[quotient]++;
                }
            }
        }

        vector< pair<int,int> > hehe;
        for(auto& i:m){
            hehe.push_back({i.first,i.second});
        }
        sort(hehe.begin(),hehe.end());
        
        map<int,long long> o;
        int size = hehe.size();
        int maxlimit = hehe[size-1].first;

        for(int i=size-1;i>=0;i--){
            int number = hehe[i].first;
            int occ = hehe[i].second;
            long long combination = ((long long)occ*(long long)(occ-1))/(long long)2;
            long long finalis = combination;
            for(long long j=number*2;j<=maxlimit;j+=number){
                if(o.count(j)){
                    finalis -= o[j];
                } 
            }
            o[number] = finalis;
        }

        vector<int> number;
        vector<long long> cap;
        long long start = 0;
        for(auto& i:o){
            start += i.second; 
            number.push_back(i.first);
            cap.push_back(start);
        }

        vector<int> retme;
        for(auto& i:queries){
          int index =  lower_bound(cap.begin(),cap.end(),i+1) - cap.begin();
         retme.push_back(number[index]); 
        }
        return retme;
        


    }
};