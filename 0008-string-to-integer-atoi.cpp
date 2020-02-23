// 1st sub
class Solution {
public:
    int myAtoi(string str) {
        int idx = 0, sign = 1, res = 0, tmp;
        while (str[idx] == ' ') { idx++; }
        if (str[idx] == '-' || str[idx] == '+') {
            if (str[idx] == '-') {
                sign = -1;
            }
            idx++;
        }
        if (!isdigit(str[idx])) { return 0; }
        while (isdigit(str[idx])) {
            tmp = str[idx] - '0';
            if (res > INT_MAX / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            if (res == INT_MAX / 10) {
                if (sign == 1 && tmp > 6) return INT_MAX;
                if (sign == -1 && tmp > 7) return INT_MIN;
            }
            res = res * 10 + tmp;
            idx++;
        }
        return sign * res;
    }
};

// 2nd sub
class Solution {
public:
    int myAtoi(string str) {
        int idx = 0, sign = 1, res = 0, tmp;
        while (idx < str.length() && str[idx] == ' ') { idx++; }
        if (str[idx] == '-' || str[idx] == '+') {
            if (str[idx] == '-') {
                sign = -1;
            }
            idx++;
        }
        if (idx >= str.length() || !isdigit(str[idx])) { return 0; }
        while (idx < str.length() && isdigit(str[idx])) {
            tmp = str[idx] - '0';
            if (res > INT_MAX / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            if (res == INT_MAX / 10) {
                if (sign == 1 && tmp > 6) return INT_MAX;
                if (sign == -1 && tmp > 7) return INT_MIN;
            }
            res = res * 10 + tmp;
            idx++;
        }
        return sign * res;
    }
};


