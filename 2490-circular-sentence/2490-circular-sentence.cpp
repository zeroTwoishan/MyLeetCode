/*
class Solution {
public:
    vector<string> getWords(string s) {
    vector<string> words;
    int n = s.size(), i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++; 
        int start = i;
        while (i < n && s[i] != ' ') i++; 
        if (start < i)
            words.push_back(s.substr(start, i - start));
    }
    return words;
    }
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0] != sentence[n-1]) return false;
        
        vector<string> words = getWords(sentence);

        for(int i = 0; i < (words.size() - 1); i++){
            int n = words[i].size();
            if(words[i][n - 1] != words[i + 1][0]) return false;
        }

        return true;
    }
};
*/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (sentence[0] != sentence[n - 1]) return false;

        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        }
        return true;
    }
};