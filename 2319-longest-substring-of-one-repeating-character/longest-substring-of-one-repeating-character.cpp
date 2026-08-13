class Solution {
public:

    class Node {
        public:
            char lc, rc;
            int len;
            int pref, suff , best;

        Node(){
            lc = rc = '#';
            len = pref = suff = best = 0;
        }
    };
    class Tree {
        public:
        vector<Node> tree;
        int n;

        Tree(int val){
            n = val;
            tree.resize(4*n);
        }
        Node merge(Node L, Node R){
            //base case
            if(L.len == 0) return R;
            if(R.len == 0) return L;

            Node res;
            res.len = L.len + R.len;
            res.lc = L.lc;
            res.rc = R.rc;

            res.pref = L.pref;
            if(L.len == L.pref && L.rc == R.lc) res.pref = L.len + R.pref;

            res.suff = R.suff;
            if(R.len == R.suff && R.lc == L.rc) res.suff = R.len + L.suff;

            res.best = max(L.best,R.best);
            if(L.rc == R.lc) res.best = max(res.best, L.suff + R.pref);

            return res;
        }
        void build(int node, int l, int r,string &s){
            if(l == r){
                tree[node].lc = tree[node].rc = s[l];
                tree[node].len = 1;
                tree[node].pref = 1;
                tree[node].suff = 1;
                tree[node].best = 1;
                return;
            }

            int mid = l + (r-l)/2;
            build(2*node,l,mid,s);
            build(2*node + 1, mid+1, r, s);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }

        void update(int node,int l, int r, int pos, char c){
            if(l == r){
                tree[node].lc = tree[node].rc = c;
                return;
            }

            int mid = l+(r-l)/2;

            if(pos <= mid){
                update(2*node,l,mid,pos,c);
            }
            else{
                update(2*node+1,mid+1,r,pos,c);
            }
            tree[node] = merge(tree[2*node],tree[2*node+1]);
        }
    };
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryCharacters.length();
        vector<int> len;

        Tree* t = new Tree(n);

        t->build(1,0,n-1,s);

        for(int i =0;i<k;i++){
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            t->update(1,0,n-1,idx,c);
            len.push_back(t-> tree[1].best);
        }
        return len;
    }
};