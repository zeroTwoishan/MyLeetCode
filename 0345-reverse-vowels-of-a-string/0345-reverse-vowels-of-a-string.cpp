class Solution {
public:
    string reverseVowels(string s) {
        /*int n = s.size();
        vector<char> temp;
        for(int i = 0; i < n ; i++){
            if(s[i]== ('a' | 'A' | 'e' | 'E' | 'i' | 'I' | 'o' | 'O' | 'u' | 'U')){
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        int j = 0;
        for(int i = 0; i<n;i++){
            if(s[i]== ('a' | 'A' | 'e' | 'E' | 'i' | 'I' | 'o' | 'O' | 'u' | 'U')){
                s[i] = temp[j];
                j++;
            }
        }
        return s;*/
   
    int n = s.size();
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int l = 0, r = n - 1;
    
    while (l < r) {
        while (l < r && !vowels.count(s[l])) l++;
        while (l < r && !vowels.count(s[r])) r--;
        if (l < r) swap(s[l++], s[r--]);
    }
    
    return s;
    }
};