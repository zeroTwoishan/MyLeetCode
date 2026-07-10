class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        int i = 0;
        int j = 0;
        int maxV = -1;
        int V = 0;

        for(j = 0; j < k; j++){
            if(isVowel(s[j])) V++;
        }
        maxV = max(V, maxV);
        if(maxV == k) return maxV;

        while(j < s.size()){
            if(isVowel(s[j])) V++;
            j++;
            if(isVowel(s[i])) V--;
            i++;
            maxV = max(V, maxV);
            if(maxV == k) return maxV;
        }
        return maxV;
    }
};