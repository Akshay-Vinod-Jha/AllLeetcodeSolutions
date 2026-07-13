class Solution {
public:

    int digitlen(int& number){

        if(number == 0) return 1;

        int temp = number;
        int count = 0;
        while(temp){
            count++;
            temp = temp/10;
        }
        return count;

    }

    vector<int> sequentialDigits(int low, int high) {

        string useme = "123456789";

        int lowlen = digitlen(low);
        int highlen = digitlen(high);

        int usemelen = useme.length();

        vector<int> retme;

        for(int len = lowlen; len <= highlen; len++){

            int left = 0;
            int right = len - 1;

            while(right < usemelen){

                int curnum = 0;

                for(int i = left; i <= right; i++){
                    curnum = curnum * 10 + (useme[i] - '0');
                }

                if(curnum >= low && curnum <= high){
                    retme.push_back(curnum);
                }

                left++;
                right++;
            }
        }

        return retme;
    }
};