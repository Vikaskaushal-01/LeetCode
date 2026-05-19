class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        
        long long currentNumber = 0;
        long long lastNumber = 0;
        long long result = 0;
        char sign = '+';
        
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !isspace(currentChar) || i == length - 1) {
                if (sign == '+') {
                    result += lastNumber;
                    lastNumber = currentNumber;
                } else if (sign == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
};