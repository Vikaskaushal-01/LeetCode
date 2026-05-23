#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; 
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool foundValidAtThisLevel = false;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string current = q.front();
                q.pop();
                if (isValid(current)) {
                    result.push_back(current);
                    foundValidAtThisLevel = true;
                }
                if (foundValidAtThisLevel) continue;
                for (int j = 0; j < current.length(); ++j) {
                    if (current[j] != '(' && current[j] != ')') continue;
                    string nextState = current.substr(0, j) + current.substr(j + 1);
                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }
            if (foundValidAtThisLevel) {
                break;
            }
        }
        return result;
    }
};