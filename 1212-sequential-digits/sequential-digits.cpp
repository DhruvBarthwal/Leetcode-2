class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string num = "123456789";
        string l = to_string(low);
        string r = to_string(high);

        for(int i = l.size();i<=r.size();i++){
            for(int j =0;j<=9-i;j++){
                string temp = num.substr(j,i);
                int x = stoi(temp);
                if(x >= low && x <= high) ans.push_back(x);
            }
        }
        return ans;
    }
};