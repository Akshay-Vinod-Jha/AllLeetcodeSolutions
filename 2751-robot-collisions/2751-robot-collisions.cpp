class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector< pair<int,pair<int,char>> > considerme;
        int size = positions.size();

        for(int i=0;i<size;i++){
            considerme.push_back({positions[i],{healths[i],directions[i]}});
        }

        sort(considerme.begin(),considerme.end());

        stack< pair<int,pair<int,char>> > iamstack;

        for(auto& i:considerme){
            int positionIs = i.first;
            int healthIs = i.second.first;
            char directionIs = i.second.second;

            while(!iamstack.empty() && (iamstack.top().second.second=='R' && directionIs=='L')){
                int stackPosition = iamstack.top().first;
                int stackHealth = iamstack.top().second.first;
                char stackDirection = iamstack.top().second.second;

                if(stackHealth==healthIs){
                    iamstack.pop();
                    healthIs = 0;
                    break;
                }
                else if(stackHealth>healthIs){
                    iamstack.pop();
                    iamstack.push({stackPosition,{stackHealth-1,stackDirection}}); 
                    healthIs=0;
                    break;
                }
                else{
                    iamstack.pop();
                    healthIs--;
                }
            }

            if(healthIs!=0){
                iamstack.push({positionIs,{healthIs,directionIs}});
            }
        }

        map<int,int> considerme2;

        while(!iamstack.empty()){
            auto i = iamstack.top(); 
            iamstack.pop();
            considerme2[i.first] = i.second.first; 
        }

        vector<int> retme;

        for(int i=0;i<size;i++){
            if(considerme2.find(positions[i])!=considerme2.end()){
                retme.push_back(considerme2[positions[i]]);
            }
        }

        return retme;
    }
};