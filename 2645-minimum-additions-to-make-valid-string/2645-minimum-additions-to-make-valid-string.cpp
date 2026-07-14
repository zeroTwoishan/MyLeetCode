class Solution {
public:
    // Checks whether character c matches the letter expected at this point in the "abc" cycle.
    // cyclePos represents position in the cycle: 1 -> 'a', 2 -> 'b', 0 -> 'c'
    bool matchesExpected(char c, int cyclePos){
        if(cyclePos == 1 && c == 'a') return true;
        else if(cyclePos == 2 && c == 'b') return true;
        else if(cyclePos == 0 && c == 'c') return true;
        return false;
    }

    int addMinimum(string word) {
        int insertions = 0;
        int n = word.size();

        // Tracks our position in the repeating a-b-c cycle.
        // We take (cycleCounter % 3) to get the actual expected letter:
        // 1 -> expecting 'a', 2 -> expecting 'b', 0 -> expecting 'c'
        int cycleCounter = 1;
        int i = 0; // pointer into word

        while(i < n){
            if(matchesExpected(word[i], cycleCounter % 3)){
                // current character fits the expected slot in the cycle — consume it
                i++;
            } else {
                // current character doesn't fit — we'd need to insert a letter here instead,
                // so just record that insertion and try the next expected slot
                insertions++;
            }
            cycleCounter++; // move to the next slot in the a-b-c cycle
        }

        // After processing all of word, we may be mid-cycle (mid "abc" block).
        // Figure out how many more letters are needed to complete that final block.
        int nextExpected = cycleCounter % 3;
        if(nextExpected == 2){
            // we've only placed 'a' so far in this block — need 'b' and 'c'
            insertions += 2;
        } else if(nextExpected == 0){
            // we've placed 'a' and 'b' — just need 'c'
            insertions += 1;
        }
        // if nextExpected == 1, the last block was completed cleanly — nothing more needed

        return insertions;
    }
};