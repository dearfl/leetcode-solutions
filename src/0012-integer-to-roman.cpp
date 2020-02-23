class Solution {
public:
    string intToRoman(int num) {
        int digit;
        string res, tmp;
        string digits = "IVXLCDM ";
        for (int i = 0; num; i++) {
            digit = num % 10;
            tmp = "";
            if (digit == 9) {
                tmp = digits.substr(2 * i, 1) + digits.substr(2 * i + 2, 1);
            } else if (digit == 4) {
                tmp = digits.substr(2 * i, 2);
            } else {
                if (digit > 4) {
                    digit -= 5;
                    tmp += digits.substr(2 * i + 1, 1);
                }
                while (digit--) {
                    tmp += digits.substr(2 * i, 1);
                }
            }
            res = tmp + res;
            num /= 10;
        }
        return res;
    }
};
