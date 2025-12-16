class Solution {
public:
    int minOperations(int n) {
    int target = n;  
    int steps = 0;
    for (int i = 0; i < n / 2; i++) {
        int val = (2 * i) + 1; 
        steps += (target - val);
    }
    return steps;
    }
};