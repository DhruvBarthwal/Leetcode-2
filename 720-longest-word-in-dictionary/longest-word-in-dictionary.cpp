class Solution {
public:
struct TrieNode{
    TrieNode*children[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            children[i] = nullptr;
        }
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(char &c : word){
            int idx = c -'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};
string ans ="";
void dfs(TrieNode* node, string&path){
    //base case
    if(path.size() > ans.size() ||(path.size() == ans.size() && path < ans)){
        ans = path;
    }
    for(int i = 0;i<26;i++){
        if(node->children[i] && node->children[i]->isEnd){
            path += i + 'a';
            dfs(node->children[i],path);
            path.pop_back();
        }
    }
}

    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto &word : words){
            trie.insert(word);
        }
        string path="";
        dfs(trie.root,path);
        return ans;
    }
};