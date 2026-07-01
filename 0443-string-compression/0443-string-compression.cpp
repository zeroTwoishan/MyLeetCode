class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index  = 0;
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && chars[j] == chars[i]) j++;
            chars[index++] = chars[i];
            if(j - i > 1){
                string len = to_string(j - i);
                for(auto ch : len){
                    chars[index++] = ch;
                }
            }
            i = j;
        }
        return index;
    /*    string s = "";
        int count = 0;
        int i = 0, j = 1;
        while(j < n){
            if(chars[i] == chars[j]) j++;
            else{
                s += chars[i];
                if(j - i != 1) s += to_string(j - i);
                i = j;
                j++;
            }
        } 
        s += chars[i];
        if(n - i != 1) s += to_string(n - i); 
        i = 0;
        while(i < s.size()){
            chars[i] = s[i];
            i++;
        }
        return s.size();
    */
    }
};