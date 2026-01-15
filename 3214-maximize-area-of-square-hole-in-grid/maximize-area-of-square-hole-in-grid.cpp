class Solution {
public:
int countLines(vector<int>&temp){
    sort(temp.begin(),temp.end());
    int maxLen = 1;
    int n = temp.size();
    int len = 1;
    for(int i = 0;i<n-1;i++){
        if(temp[i]+1 == temp[i+1]) len += 1;
        else len = 1;
        maxLen = max(maxLen,len);
    }
    return maxLen;
}
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hCount = countLines(hBars);
        int vCount = countLines(vBars);
        int length = 1+min(hCount,vCount);
        return length*length;
    }
};