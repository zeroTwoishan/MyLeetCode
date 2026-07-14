class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (k > 0 && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        
        // If k still > 0, remove from the end
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int i = 0;
        while (i < (int)stack.size() - 1 && stack[i] == '0') i++;
        stack = stack.substr(i);
        
        return stack.empty() ? "0" : stack;
    }
};