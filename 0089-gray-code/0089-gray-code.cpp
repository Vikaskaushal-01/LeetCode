class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int numElements = 1 << n; 
        result.reserve(numElements);
        
        for (int i = 0; i < numElements; i++) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};