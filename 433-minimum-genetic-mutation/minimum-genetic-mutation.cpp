class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        vector<char> choices = {'A','C','G','T'};
        if(dict.find(endGene) == dict.end()){
            return -1;
        }
        queue<pair<string,int>>q;
        q.push({startGene, 0});
        while(!q.empty()){
            auto [string, level] = q.front();
            q.pop();
            if(string == endGene){
                return level;
            }
            for(int i = 0;i<string.length();i++){
                char orignalString = string[i];
                for(char ch : choices){
                    string[i] = ch;
                    if(dict.find(string) != dict.end()){
                        q.push({string,level+1});
                        dict.erase(string);
                    }
                }
                string[i] = orignalString;
            }
        }
        return -1;
    }
};