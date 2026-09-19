class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearx = max(x1,min(xCenter,x2));
        int neary = max(y1,min(yCenter,y2));
        int disx = abs(xCenter-nearx);
        int disy = abs(yCenter-neary);
        return pow(disx,2)+pow(disy,2) <= pow(radius,2);
    }
};