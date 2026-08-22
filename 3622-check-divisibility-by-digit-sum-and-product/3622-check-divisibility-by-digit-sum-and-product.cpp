class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int num = n;

        while (num) {
            sum += num % 10;
            mul *= num % 10;
            num = num / 10;
        }

        return n % (sum + mul) == 0;
    }
};