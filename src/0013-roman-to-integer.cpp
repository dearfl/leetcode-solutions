class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char pc = 0;
        int val[256] = {0};
        val['M'] = 1000;
        val['D'] = 500;
        val['C'] = 100;
        val['L'] = 50;
        val['X'] = 10;
        val['V'] = 5;
        val['I'] = 1;
        for (auto& c : s) {
            switch (c) {
                case 'M':
                case 'D':
                    ans += val[c]; 
                    if (pc == 'C') {
                        ans -= 200;
                    }
                    break;
                case 'C':
                case 'L':
                    ans += val[c];
                    if (pc == 'X') {
                        ans -= 20;
                    }
                    break;
                case 'X':
                case 'V':
                    ans += val[c];
                    if (pc == 'I') {
                        ans -= 2;
                    }
                    break;
                case 'I':
                    ans += val[c];
                    break;
            }
            pc = c;
        }
        return ans;
    }
};

// ! hashmap solution
int romanToInt(string s) {
    unordered_map<char,int>mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans = 0;
    for(int i = 0;i<size(s);i++){
        if(i >0 && mp[s[i-1]] < mp[s[i]]){
            ans -= mp[s[i-1]];  // if the previous char value is less than the current one we remove it and then current my previous char value is added
            ans += mp[s[i]] - mp[s[i-1]];
        }else{
            ans += mp[s[i]];
        }
    }
    return ans;
}

// inspired by hashmap solution
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char pc = 0;
        int val[256] = {0};
        val['M'] = 1000;
        val['D'] = 500;
        val['C'] = 100;
        val['L'] = 50;
        val['X'] = 10;
        val['V'] = 5;
        val['I'] = 1;
        for (auto& c : s) {
            if (val[pc] < val[c]) {
                ans += val[c] - (val[pc] << 1);
            } else {
                ans += val[c];
            }
            pc = c;
        }
        return ans;
    }
};
