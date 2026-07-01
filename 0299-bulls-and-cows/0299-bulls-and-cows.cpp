class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> freqS(10,0),freqG(10,0);
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) bull++;
            else{
                freqS[secret[i] - '0']++;
                freqG[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            cow += min(freqS[i], freqG[i]); 
        }
        return (to_string(bull) + "A" + to_string(cow) + "B");
    }
};