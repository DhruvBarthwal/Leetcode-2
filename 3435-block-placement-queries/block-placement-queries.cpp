class Solution {
public:
    class SegmentTree {
        vector<int> tree;
        int n;

    public:
        SegmentTree(int size) {
            n = size;
            tree.assign(4 * n, 0);
        }
        void update(int idx, int value){
            update(1, 0, n - 1, idx, value);
        } 
        int query(int left, int right){
            return query(1, 0, n - 1, left, right); 
        }
    private:
        void update(int node, int s, int e, int idx, int value){
            if(s == e){
                tree[node] = value;
                return;
            }

            int mid = s + (e-s)/2;
            if(idx <= mid) update(2*node,s,mid,idx,value);
            else update(2*node+1,mid+1,e,idx,value);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }   
        int query(int node, int s,int e, int left, int right){
            if(right < s || e < left) return 0;
            if(left <= s && e <= right) return tree[node];

            int mid = s + (e-s)/2;
            return max(
                query(2*node,s,mid,left,right),
                query(2*node+1,mid+1,e,left,right)
            );
        }
    }; 
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int M = 50001;
        SegmentTree seg(M);
        set<int> obstacles = {0};

        for(auto &q : queries){
            if(q[0] == 1) obstacles.insert(q[1]);
        }
        vector<int> pos(obstacles.begin(),obstacles.end());

        for(int i =1;i<pos.size();i++){
            int gap = pos[i] - pos[i-1];
            seg.update(pos[i],gap);
        }
        vector<bool> ans;
        for(int i = queries.size()-1;i>= 0;i--){
            if(queries[i][0] == 2){
                int x = queries[i][1];
                int blocksize = queries[i][2];

                auto it = prev(obstacles.upper_bound(x));

                int leftObstacle = *it;
                int largestGap = seg.query(0,leftObstacle);
                largestGap = max(largestGap, x - leftObstacle);
                ans.push_back(largestGap >= blocksize);
            }
            else{
                int obstacle = queries[i][1];
                auto curr = obstacles.find(obstacle);
                int leftObstacle = *prev(curr);
                seg.update(obstacle,0);

                auto right = next(curr);
                if(right != obstacles.end()){
                    int rightObstacle = *right;
                    int gap = rightObstacle - leftObstacle;
                    seg.update(rightObstacle,gap);
                }
                obstacles.erase(curr);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};