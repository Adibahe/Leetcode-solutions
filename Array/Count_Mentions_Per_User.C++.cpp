// Solution for Count Mentions Per User in C++ 
// This file contains the code for the problem: Count Mentions Per User 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, 0);

        // Sort events to ensure offline events are processed before message events at the same timestamp
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            if (stoi(a[1]) == stoi(b[1])) {
                return a[0] == "OFFLINE"; // OFFLINE events should come before MESSAGE events
            }
            return stoi(a[1]) < stoi(b[1]);
        });

        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);

            if (eventType == "OFFLINE") {
                int userId = stoi(event[2]);
                offlineUntil[userId] = timestamp + 60;
            } else if (eventType == "MESSAGE") {
                string mentionString = event[2];
                vector<int> mentionedUsers;

                if (mentionString == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentionedUsers.push_back(i);
                    }
                } else if (mentionString == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUntil[i] <= timestamp) {
                            mentionedUsers.push_back(i);
                        }
                    }
                } else {
                    stringstream ss(mentionString);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentionedUsers.push_back(userId);
                        }
                    }
                }

                for (int userId : mentionedUsers) {
                    mentions[userId]++;
                }
            }
        }

        return mentions;
    }
};
