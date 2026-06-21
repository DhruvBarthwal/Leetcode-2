class Solution {
public:
class DSU{
    public:
    vector<int> parent;
    int components;
    DSU(int n){
        parent.resize(n);
        components = n;
        for(int i =0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
            if(parent[x] != x) parent[x] = findParent(parent[x]);
            return parent[x];
        }
        void unionDFS(int a, int b){
            int x = findParent(a);
            int y = findParent(b);

            if(x == y) return;
            parent[x] = y;
            components--;
        }
};
    int isSimilar(string& a,string& b){
        int diff = 0;
        for(int i =0;i<a.size();i++){
            if(a[i] != b[i]) diff++;
        }
        return diff == 0 || diff  == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    dsu.unionDFS(i,j);
                }
            }
        }
        return dsu.components;
    }
};