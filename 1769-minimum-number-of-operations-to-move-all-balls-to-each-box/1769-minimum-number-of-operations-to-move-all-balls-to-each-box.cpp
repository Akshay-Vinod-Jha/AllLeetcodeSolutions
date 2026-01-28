class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int size = boxes.length();
        vector<int> returnme(size);


        for(int i=0;i<size;i++){

            int count = 0;

            for(int j=0;j<i;j++){
                if(boxes[j]=='1') count += abs(j-i);
            }

            for(int j=i+1;j<size;j++){

                if(boxes[j]=='1') count+= abs(j-i);

            }

            returnme[i] = count;

        }   
        
        return returnme;
    }
};