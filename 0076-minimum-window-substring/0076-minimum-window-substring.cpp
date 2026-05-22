class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        int targetFreq[128] = {0};
        int windowFreq[128] = {0};

        for (char c : t) {
            targetFreq[c]++;
        }
        int requiredMatches = 0;
        for (int i = 0; i < 128; i++) {
            if (targetFreq[i] > 0) requiredMatches++;
        }
        
        int formedMatches = 0;
        int left = 0, right = 0;
        
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char rChar = s[right];
            windowFreq[rChar]++;
            if (targetFreq[rChar] > 0 && windowFreq[rChar] == targetFreq[rChar]) {
                formedMatches++;
            }
            while (formedMatches == requiredMatches) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char lChar = s[left];
                windowFreq[lChar]--;
                if (targetFreq[lChar] > 0 && windowFreq[lChar] < targetFreq[lChar]) {
                    formedMatches--;
                }
                
                left++; 
            }

            right++; 
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};