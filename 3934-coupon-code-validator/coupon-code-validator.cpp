class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> result;
        unordered_map<string,int> values = {{"electronics",0},{"grocery",1},{"pharmacy",3},{"restaurant",4}};
        vector<pair<pair<int,string>,string>> value;
        regex validCode("^[a-zA-Z0-9_]+$");
        for(int i = 0;i<n;i++){
            if(isActive[i] && regex_match(code[i],validCode) && !code[i].empty() && values.count(businessLine[i])){
                value.push_back({{values[businessLine[i]],code[i]},code[i]});
            }
        }
        sort(value.begin(),value.end());
        for(auto entry : value){
            result.push_back(entry.second);
        }
        return result;
    }
};