class Solution {
public:
    int tellone(int number){
        int count = 0;
        while(number){
            if( number%2==1 ) count++;
            number = number/2;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> returnme;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                if( tellone(i)+tellone(j) == turnedOn ){
                    string addme = "";
                    addme += to_string(i);
                    addme += ":";
                    if(j<10){
                        addme += "0";
                        addme += to_string(j);
                    }else{
                        addme += to_string(j);
                    }

                    returnme.push_back(addme);
                }
            }
        }
        return returnme;
    }
};