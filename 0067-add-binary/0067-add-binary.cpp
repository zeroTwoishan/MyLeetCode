class Solution {
public:
/*int binaryToDecimal(string binary) {
    return stoi(binary, nullptr, 2);
    }
    string decimalToBinary(int n) {
    if (n == 0) return "0";
    string s = bitset<32>(n).to_string();
    return s.substr(s.find('1'));
    } 
    string addBinary(string a, string b) {
        return decimalToBinary(binaryToDecimal(a)+binaryToDecimal(b));
    }*/
        string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        int C = 0;
        while(i>=0 and j >=0){
            int sum = int(a[i]-'0') ^ int(b[j]-'0') ^ C;
            C=(int(a[i]-'0') & int(b[j]-'0'))| (C & (int(a[i]-'0') ^ int(b[j]-'0')));
            ans.push_back('0'+sum);
            i--;
            j--;
        }
        while(i>=0){
            int sum = int(a[i]-'0') ^ 0 ^ C;
            C=(int(a[i]-'0') & 0 )| (C & (int(a[i]-'0') ^ 0));
            ans.push_back('0'+sum);
            i--;
        }
        while(j>=0){
            int sum = 0 ^ int(b[j]-'0') ^ C;
            C=(0 & int(b[j]-'0'))| (C & (0 ^ int(b[j]-'0')));
            ans.push_back('0'+sum);
            j--;
        }
        if(C)ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }

};