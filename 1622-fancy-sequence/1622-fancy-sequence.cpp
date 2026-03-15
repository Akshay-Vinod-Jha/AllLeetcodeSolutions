class Fancy {
public:

    long long modme = 1e9 + 7;

    vector<long long> a;

    long long addme = 0;
    long long multme = 1;

    long long power(long long base, long long exp){

        if(exp == 0) return 1;

        long long half = power(base, exp/2);

        long long retme = (half * half) % modme;

        if(exp % 2 == 1){
            retme = (retme * base) % modme;
        }

        return retme;
    }

    Fancy() {
        
    }
    
    void append(int val) {

        long long number = ((val - addme) % modme + modme) % modme;

        number = (number * power(multme , modme-2)) % modme;

        a.push_back(number);
    }
    
    void addAll(int inc) {

        addme = (addme + inc) % modme;
    }
    
    void multAll(int m) {

        multme = (multme * m) % modme;

        addme = (addme * m) % modme;
    }
    
    int getIndex(int idx) {

        if(idx >= a.size()) return -1;

        long long retme = (a[idx] * multme) % modme;

        retme = (retme + addme) % modme;

        return retme;
    }
};