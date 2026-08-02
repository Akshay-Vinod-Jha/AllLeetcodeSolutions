class Solution {
public:
    long long  returnm(vector<int>& v,int m){

        long long retme = 0;
        for(auto& i:v){
            retme += ceil((double)i/(double)m);
        }
        return retme;

        }
    int minEatingSpeed(vector<int>& piles, int h) {
        
            int low = 1 ;
            int high =INT_MIN ;

            for(auto& i:piles) high = max(high,i);

            int retme = high;
            while(low<=high){

            int mid = low + (high-low)/2;
            if(returnm(piles,mid)<=h){
                retme = mid;
                high  = mid-1;
            }else{
                low = mid+1;
            }

            }

            return retme;


    }
};

