class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i =0 , j = n-1;
        int ans = 0;
        while(colors[i] == colors[j]){
            j--;
        }
        ans = max(ans,j);
        i = 0, j = n-1;
        while(colors[i] == colors[j]){
            i++;
        }
        ans = max(ans,n-i-1);
        return ans;
    }
};