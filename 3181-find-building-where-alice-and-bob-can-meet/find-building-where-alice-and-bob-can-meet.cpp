class Solution {
public:
class SegmentTree{
    public:
    int n;
    vector<long long>tree;
    SegmentTree(int size){
        n = size;
        tree.resize(4*n);
    }
    void build(int idx, int l, int r, vector<int>&arr){
        //base case
        if(l == r){
            tree[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*idx,l,mid,arr);
        build(2*idx+1,mid+1,r,arr);
        tree[idx] = max(tree[2*idx], tree[2*idx + 1]);
    }
    long long query(int ql,int target, int idx,int l, int r){
        //base case
        if(r < ql || tree[idx] <= target) return -1;
        if(l == r) return l;

        int mid = (l+r)/2;
        int left = query(ql,target,2*idx,l,mid);
        if(left != -1) return left;
        return query(ql,target,2*idx+1,mid+1,r);
    }
};
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree st(n);
        st.build(1,0,n-1,heights);
        vector<int> ans;
        for(auto &it : queries){
            int a = it[0], b = it[1];
            int l = min(a,b);
            int r = max(a,b);
            if(l == r || heights[r] > heights[l]){
                ans.push_back(r);
                continue;
            }
            else{
                ans.push_back(st.query(r+1,heights[l],1,0,n-1));
            }
        }
        return ans;
    }
};