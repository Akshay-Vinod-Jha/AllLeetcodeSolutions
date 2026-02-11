class Solution {
public:

    struct segg {
        int n;
        vector<int> ss, lo, hi;
        vector<int> lz;
        vector<int> tag;

        segg(int x){
            n = x;
            ss.assign(4*n+5, 0);
            lo.assign(4*n+5, 0);
            hi.assign(4*n+5, 0);
            lz.assign(4*n+5, 0);
            tag.assign(4*n+5, 0);
        }

        void pullu(int v){
            ss[v] = ss[v<<1] + ss[v<<1|1];
            lo[v] = min(lo[v<<1], ss[v<<1] + lo[v<<1|1]);
            hi[v] = max(hi[v<<1], ss[v<<1] + hi[v<<1|1]);
        }

        void laga(int v, int l, int r, int val){
            int len = r - l + 1;
            ss[v] = val * len;

            if(val == 0){
                lo[v] = hi[v] = 0;
            }
            else if(val > 0){
                lo[v] = val;
                hi[v] = val * len;
            }
            else{
                lo[v] = val * len;
                hi[v] = val;
            }

            tag[v] = 1;
            lz[v] = val;
        }

        void dhakka(int v, int l, int r){
            if(!tag[v] || l == r) return;
            int m = (l + r) >> 1;
            laga(v<<1, l, m, lz[v]);
            laga(v<<1|1, m+1, r, lz[v]);
            tag[v] = 0;
        }

        void upd(int pos, int val){
            upd(1, 0, n-1, pos, pos, val);
        }

        void upd(int v, int l, int r, int ql, int qr, int val){
            if(ql <= l && r <= qr){
                laga(v, l, r, val);
                return;
            }
            dhakka(v, l, r);
            int m = (l + r) >> 1;
            if(ql <= m) upd(v<<1, l, m, ql, qr, val);
            if(qr >  m) upd(v<<1|1, m+1, r, ql, qr, val);
            pullu(v);
        }

        int get(int want){
            if(want == 0) return -1;
            if(want < lo[1] || want > hi[1]) return n;
            int pref = 0;
            return get(1, 0, n-1, want, pref);
        }

        int get(int v, int l, int r, int want, int &pref){
            if(l == r){
                if(pref + ss[v] == want) return l;
                return n;
            }

            dhakka(v, l, r);

            int m = (l + r) >> 1;
            int L = v<<1, R = v<<1|1;

            int mn = pref + lo[L];
            int mx = pref + hi[L];

            if(want >= mn && want <= mx){
                return get(L, l, m, want, pref);
            }
            else{
                pref += ss[L];
                return get(R, m+1, r, want, pref);
            }
        }
    };

    int longestBalanced(vector<int>& a) {
        int n = a.size();
        int mxv = 0;
        for(auto x : a) mxv = max(mxv, x);
        mxv++;

        vector<int> last(mxv, -1);
        segg st(n);

        int bal = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(last[a[i]] != -1){
                st.upd(last[a[i]], 0);
            }
            else{
                if(a[i] & 1) bal++;
                else bal--;
            }

            last[a[i]] = i;

            if(a[i] & 1) st.upd(i, +1);
            else st.upd(i, -1);

            int p = st.get(bal);
            ans = max(ans, i - p);
        }

        return ans;
    }
};
