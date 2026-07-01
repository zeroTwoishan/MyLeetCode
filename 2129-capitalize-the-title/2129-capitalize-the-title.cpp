class Solution {
public:
    string capitalizeTitle(string t) {
        int n = t.size();
        int i = 0;

        while (i < n) {
            int start = i;
            while (i < n && t[i] != ' ') i++;
            int len = i - start;
            for (int j = start; j < i; j++) t[j] = tolower(t[j]);
            if (len > 2) t[start] = toupper(t[start]);
            i++; 
        }

        return t;
    }
};