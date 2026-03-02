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
    
    void updatehelper(int start,int end,int iskobadlo,int valuereplace,int segtreeindex){

        if(start==end){
            segmenttree[segtreeindex] = valuereplace;
            return;
        }

        int mid = (start+end)/2;
        if(iskobadlo<=mid){
            updatehelper(start,mid,iskobadlo,valuereplace,2*segtreeindex+1);
        }else{
            updatehelper(mid+1,end,iskobadlo,valuereplace,2*segtreeindex+2);
        }

        segmenttree[segtreeindex] = segmenttree[2*segtreeindex+1] + segmenttree[2*segtreeindex+2];
    }
    void update(int index, int val) {
        a[index] = val;
        updatehelper(0,size-1,index,val,0);
    }
    

    int sumrangehelper(int start,int end,int left,int right,int segmenttreeindex){

        if(end<left || start>right) return 0;
        if(start>=left && end<=right) return segmenttree[segmenttreeindex];

        int mid = (start+end)/2;
        return sumrangehelper(start,mid,left,right,2*segmenttreeindex+1)+sumrangehelper(mid+1,end,left,right,2*segmenttreeindex+2);

    }
    int sumRange(int left, int right) {
        return sumrangehelper(0,size-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */