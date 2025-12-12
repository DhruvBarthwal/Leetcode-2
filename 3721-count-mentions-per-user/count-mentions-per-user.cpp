class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [&](const vector<string>& lth, const vector<string>& rth) {
                 int lth_timestamp = stoi(lth[1]);
                 int rth_timestamp = stoi(rth[1]);
                 if (lth_timestamp != rth_timestamp) {
                     return lth_timestamp < rth_timestamp;
                 }
                 if (rth[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });
        vector<int> mention(numberOfUsers, 0);
        vector<int> online(numberOfUsers, 0);
        for (auto event : events) {
            int timeStamp = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "HERE") {
                    for (int i = 0; i < online.size(); i++) {
                        if (online[i] <= timeStamp)
                            mention[i]++;
                    }
                } else if (event[2] == "ALL") {
                    for (int i = 0; i < mention.size(); i++)
                        mention[i]++;
                } else {
                    int idx = 0;
                    for (int i = 0; i < event[2].size(); i++) {
                        if (isdigit(event[2][i])) {
                            idx = idx * 10 + (event[2][i] - '0');
                        }
                        if (i + 1 == event[2].size() ||
                            event[2][i + 1] == ' ') {
                            mention[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else if (event[0] == "OFFLINE") {
                int id = stoi(event[2]);
                online[id] = 60 + timeStamp;
            }
            cout << mention[0] << " ";
        }
        return mention;
    }
};