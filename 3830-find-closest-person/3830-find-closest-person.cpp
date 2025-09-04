class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(z-y) < abs(z-x) ? 2 : abs(z-x) == abs(z-y) ? 0 : 1;
    }
};