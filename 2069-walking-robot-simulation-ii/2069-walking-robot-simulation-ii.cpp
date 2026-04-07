class Robot {
    int xcord;
    int ycord;
    int widthis;
    int heightis;
    string directionis;

public:
    Robot(int width, int height) {
        xcord = 0;
        ycord = 0;
        directionis = "East";
        widthis = width;
        heightis = height;
    }
    
    void step(int num) {
        int perimeter = 2*(widthis-1) + 2*(heightis-1);
        num %= perimeter;
        if(num == 0) num = perimeter;

        while(num > 0){
            int oldx = xcord;
            int oldy = ycord;

            if(directionis == "East"){
                int maxreach = min(xcord + num, widthis - 1);
                int moved = maxreach - xcord;
                num -= moved;

                xcord = maxreach;

                if(num > 0){
                    directionis = "North";
                }
            }
            else if(directionis == "North"){
                int maxreach = min(ycord + num, heightis - 1);
                int moved = maxreach - ycord;
                num -= moved;

                ycord = maxreach;

                if(num > 0){
                    directionis = "West";
                }
            }
            else if(directionis == "West"){
                int minreach = max(xcord - num, 0);
                int moved = xcord - minreach;
                num -= moved;

                xcord = minreach;

                if(num > 0){
                    directionis = "South";
                }
            }
            else{
                int minreach = max(ycord - num, 0);
                int moved = ycord - minreach;
                num -= moved;

                ycord = minreach;

                if(num > 0){
                    directionis = "East";
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {xcord, ycord};
    }
    
    string getDir() {
        return directionis;
    }
};