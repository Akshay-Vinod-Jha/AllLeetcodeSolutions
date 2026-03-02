class NumArray {
public:
    vector<int> a;
    int size;
    vector<int> segmenttree;
    void buildsegmenttree(int start,int end,int yahape){

        if(start==end){
            segmenttree[yahape] = a[start];
            return;
        }

        int mid = (start+end)/2;
        buildsegmenttree(start,mid,2*yahape+1);
        buildsegmenttree(mid+1,end,2*yahape+2);

        segmenttree[yahape] = segmenttree[2*yahape+1] + segmenttree[2*yahape+2];

    }
    NumArray(vector<int>& nums) {
        a = nums;
        size = a.size();
        for(int i=0;i<size*4;i++){
            segmenttree.push_back(0);
        }
        buildsegmenttree(0,size-1,0);
    }

    int sumrangehelper(int start,int end,int left,int right,int segmenttreeindex){

        if( end<left || right<start ) return 0;

        if(start>=left && end<=right) return segmenttree[segmenttreeindex];

        int mid = (start+end)/2;
        return sumrangehelper(start,mid,left,right,2*segmenttreeindex+1) + sumrangehelper(mid+1,end,left,right,2*segmenttreeindex+2);
    }
    
    int sumRange(int left, int right) {
       return sumrangehelper(0,size-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */