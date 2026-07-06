class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int s = INT_MAX, e = INT_MAX;
        int cnt = 0;
        for(auto &i : intervals){
            cout<< s<<" "<<e<<endl;
            cout<<i[0]<<" "<<i[1]<<endl;
            if(s == INT_MAX && e == INT_MAX){
                s = i[0];
                e = i[1];
        
            }
            else if(s <= i[0] && i[1] <= e){
                cnt++;
            }
            else{
                s = i[0];
                e = i[1];
            }
            cout<<cnt<<endl;
        }
        return n-cnt;
    }
};