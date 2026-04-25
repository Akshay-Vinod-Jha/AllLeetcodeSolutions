class Solution {
public:
    typedef long long ll;

    ll getpos(int side, int x, int y){

        if(y == 0) return x;

        if(x == side) return side + y;

        if(y == side) return 3LL * side - x;

        return 4LL * side - y;
    }

    bool helper(
        vector<ll>& doubled,
        int n,
        int k,
        int side,
        int mid
    ){

        ll perimeter = 4LL * side;

        for(int i=0;i<n;i++){

            int count = 1;
            int index = i;

            ll last = doubled[index];

            for(int j=2;j<=k;j++){

                ll target = last + mid;

                auto it = lower_bound(
                    doubled.begin() + index + 1,
                    doubled.begin() + i + n,
                    target
                );

                if(it == doubled.begin() + i + n) break;

                index = it - doubled.begin();
                last = doubled[index];
                count++;
            }

            if(count == k && (doubled[i] + perimeter - last >= mid)){
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {

        int n = points.size();
        ll perimeter = 4LL * side;

        vector<ll> pos(n);

        for(int i=0;i<n;i++){
            pos[i] = getpos(side, points[i][0], points[i][1]);
        }

        sort(pos.begin(), pos.end());

        vector<ll> doubled(2*n);

        for(int i=0;i<n;i++){
            doubled[i] = pos[i];
            doubled[i+n] = pos[i] + perimeter;
        }

        int l = 0;
        int r = 2*side;

        int retme = 0;

        while(l <= r){

            long long mid = ((long long)l + (long long)r) / 2;

            if(helper(doubled, n, k, side, mid)){
                retme = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return retme;
    }
};