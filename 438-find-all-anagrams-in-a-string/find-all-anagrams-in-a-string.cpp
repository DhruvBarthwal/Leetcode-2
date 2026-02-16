class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m  = p.size();
        if(m > n) return ans;

        vector<int> freqS(26,0) , freqP(26,0);

        for(int i =0;i<m;i++){
            freqS[s[i] - 'a']++;
            freqP[p[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0;i<26;i++){
            if(freqS[i] == freqP[i]) matches++;
        }
        if(matches == 26) ans.push_back(0);
        
        for(int i = m;i<n;i++){
            int right = s[i] - 'a';
            int left = s[i-m] - 'a';

            if(freqS[right] == freqP[right]) matches--;
            freqS[right]++;

            if(freqS[right] == freqP[right]) matches++;

            if(freqS[left] == freqP[left]) matches--;
            freqS[left]--;

            if(freqP[left] == freqS[left]) matches++;

            if(matches == 26){
                ans.push_back(i - m + 1);
            }
        }   
        return ans;
    }
};