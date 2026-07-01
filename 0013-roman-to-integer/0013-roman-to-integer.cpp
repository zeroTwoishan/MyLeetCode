class Solution {
public:
    int value(char ch){
       switch(ch){
        case 'I' :
        return 1;
        case 'V' :
        return 5;
        case 'X' :
        return 10;
        case 'L' :
        return 50;
        case 'C' :
        return 100;
        case 'D' :
        return 500;
        case 'M' :
        return 1000;
       }
       return -1;
    }
    int romanToInt(string s) {
        int n = s.size();
        int i = 0;
        int num = 0;
        while((i + 1) < n){
            int v1 = value(s[i]);
            int v2 = value(s[i + 1]);
            if(v1 < v2){
                num -= v1;
            }
            else num += v1;
            i++;
        }
       num += value(s[i]);
        return num;
    }
};