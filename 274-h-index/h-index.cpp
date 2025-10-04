class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        sort(citations.begin(), citations.end());
        for(int i = n;i>0;i--){
            int count = 0;
            if(ans != 0){
                break;
            }
            for(int j = n-1;j>=0;j--){
                if(citations[j] >= i){
                    count++;
                    if(count == i){
                        ans = i;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};