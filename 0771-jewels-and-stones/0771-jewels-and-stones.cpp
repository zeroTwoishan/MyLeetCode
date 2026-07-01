class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int seen[128] = {0};
        for(auto c : jewels) seen[c]++;
        int count = 0;
        for(auto c : stones) if(seen[c] > 0) count++;
        return count;
    }
};