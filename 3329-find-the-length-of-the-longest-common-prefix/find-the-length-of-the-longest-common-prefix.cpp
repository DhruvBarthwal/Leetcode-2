class Solution {
public:
struct TrieNode{
    public:
    TrieNode* children[10];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0;i<10;i++){
            children[i] = NULL;
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
            int idx = c -'0';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node -> isEnd = true;
    }
    int search(string word){
        TrieNode* node = root;
        int cnt = 0;
        for(char &ch : word){
            int idx = ch - '0';
            if(!node -> children[idx]) break;
            node = node -> children[idx];
            cnt++;
        }
        return cnt;
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int num : arr1){
            trie.insert(to_string(num));
        }
        int ans = 0;
        for(int num : arr2){
            ans = max(ans,trie.search(to_string(num)));
        }
        return ans;
    }
};