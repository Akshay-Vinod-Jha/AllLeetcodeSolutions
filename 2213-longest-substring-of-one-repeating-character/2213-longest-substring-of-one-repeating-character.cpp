class Solution {
public:

    struct Node {
        char lc, rc;
        int len, pref, suff, best;

        Node() {
            lc = rc = '#';
            len = pref = suff = best = 0;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if(a.len == 0) return b;
        if(b.len == 0) return a;

        Node c;

        c.lc = a.lc;
        c.rc = b.rc;
        c.len = a.len + b.len;

        c.pref = a.pref;
        c.suff = b.suff;
        c.best = max(a.best, b.best);

        if(a.rc == b.lc) {
            c.best = max(c.best, a.suff + b.pref);

            if(a.pref == a.len)
                c.pref = a.len + b.pref;

            if(b.suff == b.len)
                c.suff = b.len + a.suff;
        }

        return c;
    }

    void build(int idx, int l, int r, string &s) {
        if(l == r) {
            seg[idx].lc = s[l];
            seg[idx].rc = s[l];
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if(l == r) {
            seg[idx].lc = ch;
            seg[idx].rc = ch;
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            s[pos] = ch;

            update(1, 0, n - 1, pos, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};