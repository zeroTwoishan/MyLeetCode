class Solution {
public:
    char processStr(string s, long long k) {

        // ── FORWARD PASS ──────────────────────────────────────────────────
        // Simulate all operations to get the final virtual string length.
        // We never build the actual string (can be astronomically large).
        long long len = 0;
        for(char c : s){
            if(islower(c))  len++;
            else if(c == '*') { if(len > 0) len--; }  // can't delete from empty
            else if(c == '#') len *= 2;
            // '%' reverses → no length change
        }

        if(k >= len) return '.';   // k is out of bounds of final string

        // ── BACKWARD PASS ─────────────────────────────────────────────────
        // Walk backwards through operations, undoing each one.
        // We maintain `len` as the virtual length at each step (no extra array).
        // Goal: remap k backwards until we hit the letter it originated from.
        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];

            if(islower(c)){
                // This letter occupies the last index (len-1) of the current string.
                // If k points here → found our answer.
                // Either way, undo the append (len--).
                if(k == len - 1) return c;
                len--;
            }
            else if(c == '*'){
                // Undo deletion: the string was one longer before this op.
                // The restored character is at index len (the new last position),
                // but since we don't know what it was, we just extend len and
                // let the backward pass find it earlier in the string.
                len++;
            }
            else if(c == '#'){
                // Undo doubling: string was [ original | original ] each of size len/2.
                // Step 1 → shrink len back to pre-double size.
                // Step 2 → k % len maps both copies into the same position in original:
                //          k in 1st copy (k < len) : k % len = k        (unchanged)
                //          k in 2nd copy (k >= len): k % len = k - len  (remapped)
                len /= 2;
                k %= len;
            }
            else if(c == '%'){
                // Undo reverse: position k mirrors to (len-1-k) in the original order.
                // Applying the same formula twice gets back to original → self-inverse.
                k = len - 1 - k;
            }
        }

        return '.';
    }
};