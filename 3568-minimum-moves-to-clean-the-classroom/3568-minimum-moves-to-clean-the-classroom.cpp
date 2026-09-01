class Solution {  
public:  
    int minMoves(vector<string>& classroom, int energy) {  
         
        int rows = classroom.size();  
        int cols = classroom[0].size();  
         
        int starti = -1;  
        int startj = -1;  
         
        vector<pair<int,int>> litters;  
         
        for(int i=0;i<rows;i++){  
            for(int j=0;j<cols;j++){  
                 
                if(classroom[i][j]=='S'){  
                    starti = i;  
                    startj = j;  
                }  
                 
                if(classroom[i][j]=='L'){  
                    litters.push_back({i,j});  
                }  
            }  
        }  
         
        int count_kitne = litters.size();  
         
        vector<vector<int>> litterindex( 
            rows, 
            vector<int>(cols,-1) 
        );  
         
        for(int i=0;i<count_kitne;i++){  
            litterindex[litters[i].first][litters[i].second] = i;  
        }  
         
        int allmask = (1<<count_kitne)-1;  
         
        queue<tuple<int,int,int,int,int>> q;  
         
        vector<vector<vector<int>>> visited( 
            rows, 
            vector<vector<int>>( 
                cols, 
                vector<int>((1<<count_kitne),-1) 
            ) 
        );  
         
        q.push({ 
            starti, 
            startj, 
            0, 
            energy, 
            0 
        });  
         
        visited[starti][startj][0] = energy;  
         
        vector<int> xdir = {0,1,0,-1};  
        vector<int> ydir = {1,0,-1,0};  
         
        while(!q.empty()){  
             
            auto [xfornow,yfornow,mask,energyleft,steps] = q.front();  
            q.pop();  
             
            if(mask==allmask) return steps;  
             
            if(energyleft==0){  
                continue;  
            }  
             
            for(int i=0;i<4;i++){  
                 
                int updated_x = xfornow+xdir[i];  
                int updated_y = yfornow+ydir[i];  
                 
                if( 
                    updated_x<0 ||  
                    updated_x>=rows ||  
                    updated_y<0 ||  
                    updated_y>=cols 
                ){  
                    continue;  
                }  
                 
                if(classroom[updated_x][updated_y]=='X'){  
                    continue;  
                }  
                 
                int newenergy = energyleft-1;  
                int newmask = mask;  
                 
                if(litterindex[updated_x][updated_y]!=-1){  
                    int index = litterindex[updated_x][updated_y];  
                    newmask = newmask | (1<<index);  
                }  
                 
                if(classroom[updated_x][updated_y]=='R'){  
                    newenergy = energy;  
                }  
                 
                if(visited[updated_x][updated_y][newmask] >= newenergy){  
                    continue;  
                }  
                 
                visited[updated_x][updated_y][newmask] = newenergy;  
                 
                q.push({  
                    updated_x,  
                    updated_y,  
                    newmask,  
                    newenergy,  
                    steps+1  
                });  
            }  
        }  
         
        return -1;  
    }  
};