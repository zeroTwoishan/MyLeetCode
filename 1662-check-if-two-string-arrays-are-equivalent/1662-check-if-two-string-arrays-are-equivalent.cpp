class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;   
        int p = 0, q = 0;   
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][p] != word2[j][q]) return false;
            p++; q++;
            if (p == word1[i].size()) { i++; p = 0; }  
            if (q == word2[j].size()) { j++; q = 0; }
        }
        return i == word1.size() && j == word2.size();
    }
};
/*class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int j = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        string s1 = "",s2 = "";
        while(i < n1 || j < n2){
            if(i < n1){
                s1 += word1[i];
                i++;
            }
            if(j < n2){
                s2 += word2[j];
                j++;
            }
            if(i >= n1 && j >= n2) break;
        }
        return (s1 == s2);
    }
};*/