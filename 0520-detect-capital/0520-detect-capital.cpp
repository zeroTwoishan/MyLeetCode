class Solution {
public:
    bool detectCapitalUse(string word) {
/*
        bool allSmall = (islower(word[0])) ? true : false;
        bool allBig  = !(allSmall);
        bool firstBig = !(allSmall);
        int i = 1;
        int n = word.size();
        while(allSmall && i < n){
            if(isupper(word[i])) return false;
            i++;
        }
        while(allBig && i < n){
            if(islower(word[i])) allBig = false;
            else i++;
        }
        if(!allBig && i > 1) return false;
        while(firstBig && i < n){
            if(isupper(word[i])) return false;
            i++;
        }
        return true;
*/
        int n = word.size();
        if (n <= 1) return true;

        bool firstUpper = isupper(word[0]);
        bool secondUpper = isupper(word[1]);

        if (!firstUpper && secondUpper) return false; 

        for (int i = 2; i < n; i++) {
            if ((bool)isupper(word[i]) != secondUpper) return false;
        }
        return true;
    }
};