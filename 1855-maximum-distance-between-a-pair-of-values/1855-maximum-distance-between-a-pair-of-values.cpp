class Solution {
public:

    int binarysearch(int low,int high,int comparewith,vector<int>& nums1){
      int retindex = INT_MAX;
      while(low<=high){
        int mid = (low+high)/2; 

        if(nums1[mid]==comparewith){
          retindex = min(retindex,mid);
          high = mid-1;
        }else if(nums1[mid]<comparewith){
          retindex = min(retindex,mid);
          high = mid-1;
        }else{
          low = mid+1;
        }

      }

      return retindex==INT_MAX?-1:retindex; 

    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
      // num1 nums2
      // i<=j
      // nums[i]<=nums[j]
 
      // ek ek karke form nums2
      // low = 0 , high = j
      // find as smallest as can on left


      int nums1len = nums1.size();
      int nums2len = nums2.size();

      int retme = 0;
      for(int i=0;i<nums2len;i++){

        int low = 0;
        int high = min(i,nums1len-1);
        int bsresult = binarysearch(low,high,nums2[i],nums1);
        if(bsresult==-1) continue;


        int dis = (i-bsresult);
        retme = max(retme,dis);

      }
      return retme;


    }
};