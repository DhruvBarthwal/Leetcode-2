class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;
        for(auto &seat : reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }
        int result = n*2;
        for(auto &[row, seats] : mp){
            bool left = true, mid = true, right = true;
            for(auto &s : seats){
                if(s>=2 && s<=5) left = false;
                if(s>=4 && s<=7) mid = false;
                if(s>=6 && s<=9) right = false;
            }
            if(left && right) result -= 0;
            else if(left || right || mid) result -= 1;
            else result -= 2;
        }
        return result;
    }
};