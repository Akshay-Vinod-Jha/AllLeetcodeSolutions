class Solution {
public:
      
    int returnlength(int firstindex,int secondindex,vector<vector<int>>& points){

      int x1 = points[firstindex][0];
      int y1 = points[firstindex][1];

      int x2 = points[secondindex][0];
      int y2 = points[secondindex][1];


      return abs(x1-x2) + abs(y1-y2);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
      int size = points.size(); 
      vector<int> visited(size,0);

      priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
      > pq;

      // weight index
      pq.push({0,0});

      int retme = 0;
      while(!pq.empty()){
        int distanceis = pq.top().first;
        int nodeis = pq.top().second;
        pq.pop();

        if(visited[nodeis]==1) continue;

        visited[nodeis]=1;
        retme += distanceis;

        for(int i=0;i<size;i++){
          if(visited[i]==0){

            pq.push({returnlength(nodeis,i,points),i});

          }
        }


      }

      return retme;

    }
};