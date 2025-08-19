class NumArray {
private:
    vector<int> segTree;
    int n;

    void buildTree(vector<int>&nums, int i, int l, int r){
        //base case (leaf nodes)
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        //mid
        int mid = l+(r-l)/2;
        //left child
        buildTree(nums,2*i+1,l,mid);
        //right child
        buildTree(nums,2*i+2,mid+1,r);
        //range sum
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    void updateTree(int i,int l ,int r, int pos,int val){
        //base case
        if(l==r){
            segTree[i] = val;
            return;
        }
        //mid
        int mid = l+(r-l)/2;
        if(pos<=mid){
            //left child
            updateTree(2*i+1,l,mid,pos,val);
        }
        else{
            //right child
            updateTree(2*i+2,mid+1,r,pos,val);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int i, int l, int r,int ql, int qr){
        //base case
        if(ql>r || qr < l){
            return 0;
        }
        if(ql<=l && r<= qr){
            return segTree[i];
        }
        //mid
        int mid = l+(r-l)/2;
        return query(2*i+1,l,mid,ql,qr) + query(2*i+2,mid+1,r,ql,qr);
    } 

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n,0);
        //buildTree
        buildTree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        //update the value
        updateTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        //sum range
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */