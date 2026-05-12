class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](const vector<int>&a, vector<int>&b){
            return a[1] - a[0] > b[1] - b[0];
        });
        int start = tasks[0][1];
        int rem = tasks[0][1] - tasks[0][0];
        int loan = 0;
        int n = tasks.size();
        for(int i = 1;i<n;i++){
            int val = tasks[i][0];
            int thresh = tasks[i][1];
            if(rem < thresh){
                loan += thresh - rem;
                rem = thresh;
            }
            rem -= val;
        }
        return start + loan;
    }
};