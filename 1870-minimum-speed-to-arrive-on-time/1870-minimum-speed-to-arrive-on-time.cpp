class Solution {
public:

    // speed = dis/time ... time = dis/speed

    double returntime(vector<int>& dist,int speed){

        double retme = 0;
       
        int size  = dist.size();
        for(int i=0;i<size-1;i++){
            retme += ceil( (double)dist[i]/ (double)speed);
        }

        retme += (double) dist[size-1]/ (double)speed;
        return retme;

    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int returnres = -1;
        while(low<=high){

            int midis = low + (high-low)/2;
            if(returntime(dist,midis)<=hour){
                returnres = midis;
                high = midis-1;
            }else{
                low = midis + 1;
            }

        }

        return returnres;
    }
};