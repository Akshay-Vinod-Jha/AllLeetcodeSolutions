class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int row = isWater.size();
        int col = isWater[0].size();

        queue< pair< pair<int,int> , int > > q;

        vector< vector<int> > vis( row , vector<int>( col , 0 ) );
        vector< vector<int> > dis( row , vector<int>( col , 0 ));

        for(int i = 0 ; i< row ;i++ ){
            for( int j=0; j< col; j++ ){
                if( isWater[i][j]==1 ){ q.push( { {i,j} , 0 } );
                    vis[i][j] = 1;
                }
            }
        }

        int coladd[] = { 0,1,0,-1 };
        int rowadd[] = { -1,0,1,0 };
        
        while( !q.empty() ){
             
            int r = q.front().first.first;
            int c = q.front().first.second;
            int depth = q.front().second;

            q.pop();

            dis[r][c] = depth ;

            for( int i=0;i<4;i++ ){
 
                int nr = r + rowadd[i];
                int nc = c + coladd[i];
                int ndepth = depth + 1;

                if(
                    nr >= 0 && nr< row 
                    &&
                    nc >= 0 && nc < col
                    &&
                    vis[nr][nc]==0
                ){
                    vis[nr][nc]=1;
                    q.push( { {nr,nc} , ndepth} );  
                }


            }


        }


        return dis;
    }
};