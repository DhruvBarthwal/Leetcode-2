class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        //initialization
        int n = points.size();
        int count = 0;

        //sorting on the basis of x axis
        sort(points.begin(), points.end(),[](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        //traversing the array
        for(int i =0;i<n;i++){
            int top = points[i][1];
            int prev = INT_MIN;
            for(int j =i+1;j<n;j++){
                int curr = points[j][1];
                if(prev < curr && curr<=top){
                    count++;
                    prev = curr;
                    if(prev == top){
                        break;
                    }
                }
            }
        }
        return count;
    }
};