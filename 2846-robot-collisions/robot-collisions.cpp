class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> s;
        unordered_map<int,int> mp;
        int n = positions.size();
        //mapping robot no. with positions
        for(int i = 0;i<n;i++){
            mp[positions[i]] = i;
        }
        //sorting the robots in the position
        sort(positions.begin(),positions.end());
        vector<bool> alive(n, true);

        for(int i = 0;i<n;i++){
            int idx = mp[positions[i]];
            if(directions[idx] == 'R') s.push(idx);
            else{
                while(!s.empty()){
                    int top = s.top();
                    if(healths[top] > healths[mp[positions[i]]]){
                        alive[mp[positions[i]]] = false;
                        healths[top]--;
                        break;
                    }
                    else if(healths[top] < healths[mp[positions[i]]]){
                        alive[top] = false;
                        s.pop();
                        healths[mp[positions[i]]]--;
                    }
                    else{
                        alive[mp[positions[i]]] = false;
                        alive[top] = false;
                        s.pop();
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i =0 ;i<n;i++){
            if(alive[i]) ans.push_back(healths[i]);
        }
        return ans;
    }
};