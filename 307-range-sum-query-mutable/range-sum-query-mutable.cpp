class NumArray {
public:
    //initialization
    int n;
    vector<int> segTree;
    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
            n = nums.size();
            segTree.resize(4*n);
            buildTree(nums,0,0,n-1);
        }
        else{
            return;
        }
    }
    
    void update(int index, int val) {
        updateTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
    private:
    void buildTree(vector<int>&nums,int idx,int low,int high){
        //if reaches leaf node
        if(low == high){
            segTree[idx] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        buildTree(nums,2*idx+1, low,mid);
        buildTree(nums,2*idx+2,mid+1,high);
        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx+2];
    }
    int query(int idx, int low, int high, int l, int r){
        if(r < low || high < l) return 0;
        if(l <= low && high<=r) return segTree[idx];
        int mid = (low+high)/2;
        return query(2*idx + 1,low,mid,l,r) + query(2*idx+2,mid+1,high ,l ,r);
    }
    void updateTree(int idx,int low, int high, int pos, int val){
        if(low == high){
            segTree[idx] = val;
            return;
        }
        int mid = (low + high)/2;
        if(pos<=mid){
            updateTree(2*idx+1,low,mid,pos,val);
        }
        else{
            updateTree(2*idx+2,mid+1,high,pos,val);
        }
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx + 2];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */