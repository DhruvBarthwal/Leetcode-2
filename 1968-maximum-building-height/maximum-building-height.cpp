class Solution {
public:
int ycap(vector<int> &a, vector<int> &b){
    int x1 = a[0], x2 = b[0], y1 = a[1], y2 = b[1];
    return min(y2,y1 + abs(x1 - x2));
}
int ypeak(vector<int> &a, vector<int> &b){
    int x1 = a[0], x2 = b[0], y1 = a[1], y2 = b[1];
    return (x2 + y2 - x1 + y1) >> 1;
}
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int m = restrictions.size();
        for(int i = 1;i<m;i++){
            restrictions[i][1] = ycap(restrictions[i-1],restrictions[i]); 
        }
        for(int i =m-2;i>=0;i--){
            restrictions[i][1] = ycap(restrictions[i+1], restrictions[i]);
        }
        int ans = 0;
        for(int i =1;i<m;i++){
            ans = max(ans,ypeak(restrictions[i-1],restrictions[i]));
        }
        return max(ans,restrictions[m-1][1] + n - restrictions[m-1][0]);
    }
};