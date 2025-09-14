class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive, vowelError;

        auto devowel = [](string w) {
            for (char &c : w) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            }
            return w;
        };

        for (string w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = w;

            string dv = devowel(lower);
            if (!vowelError.count(dv))
                vowelError[dv] = w;
        }

        vector<string> result;
        for (string q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseInsensitive.count(lower)) {
                result.push_back(caseInsensitive[lower]);
                continue;
            }

            string dv = devowel(lower);
            if (vowelError.count(dv)) {
                result.push_back(vowelError[dv]);
                continue;
            }

            result.push_back(""); // no match
        }
        return result;
    }
};
