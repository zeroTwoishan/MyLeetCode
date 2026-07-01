class Solution {
public:
    int strStr(string haystack, string needle) {
        int s =haystack.size();
        int n = needle.size();
        for(int i = 0;i+n<=s;i++){
            if (haystack.compare(i,n, needle) == 0) return i;
        }
        return -1;
    }
};