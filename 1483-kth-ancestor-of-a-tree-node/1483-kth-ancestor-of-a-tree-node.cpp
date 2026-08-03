class TreeAncestor {
public:
    vector<vector<int>> refer;
    int rows;
    int cols;
    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n)+1;
        refer.resize(rows,vector<int>(cols,-1));
        for(int i=0;i<rows;i++){
            refer[i][0] = parent[i];
        }
        for(int i=1;i<cols;i++){
            for(int j=0;j<rows;j++){
                int hehe = refer[j][i-1];
                if(hehe!=-1){
                refer[j][i] = refer[hehe][i-1];

                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<cols;i++){
            if(k & (1<<i)){
                node = refer[node][i];
            }
            if(node==-1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */