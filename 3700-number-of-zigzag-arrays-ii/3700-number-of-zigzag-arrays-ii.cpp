class Solution {
public:

    long long MOD = 1000000007;

    vector<vector<long long>> multiply(
        vector<vector<long long>>& A,
        vector<vector<long long>>& B
    ) {
        int sz = A.size();

        vector<vector<long long>> C(
            sz,
            vector<long long>(sz,0)
        );

        for(int i=0;i<sz;i++){
            for(int k=0;k<sz;k++){

                if(A[i][k]==0) continue;

                for(int j=0;j<sz;j++){

                    if(B[k][j]==0) continue;

                    C[i][j] =
                    (
                        C[i][j]
                        +
                        A[i][k]*B[k][j]
                    ) % MOD;
                }
            }
        }

        return C;
    }

    vector<vector<long long>> power(
        vector<vector<long long>> base,
        long long exp
    ){

        int sz = base.size();

        vector<vector<long long>> result(
            sz,
            vector<long long>(sz,0)
        );

        for(int i=0;i<sz;i++){
            result[i][i]=1;
        }

        while(exp){

            if(exp&1){
                result = multiply(result,base);
            }

            base = multiply(base,base);

            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r-l+1;

        int states = 2*m;

        vector<vector<long long>> T(
            states,
            vector<long long>(states,0)
        );

        for(int x=0;x<m;x++){

            for(int y=x+1;y<m;y++){

                T[y][m+x] = 1;
            }

            for(int y=0;y<x;y++){

                T[m+y][x] = 1;
            }
        }

        vector<long long> start(states,0);

        for(int x=0;x<m;x++){

            start[x] = x;

            start[m+x] =
            (m-1-x);
        }

        auto P = power(T,n-2);

        vector<long long> finalState(
            states,
            0
        );

        for(int i=0;i<states;i++){

            for(int j=0;j<states;j++){

                finalState[i] =
                (
                    finalState[i]
                    +
                    P[i][j]*start[j]
                ) % MOD;
            }
        }

        long long ans = 0;

        for(auto x:finalState){

            ans =
            (
                ans+x
            ) % MOD;
        }

        return ans;
    }
};