class Solution {
public:
    bool isValid(string s) {
        int lenght = s.size();
        if(lenght % 2 != 0) return false;
        else{
            string open;
            for(int i = 0;i<lenght;i++){
                char ch=s[i];
                if(ch=='(' || ch == '{' || ch == '[') open.push_back(ch);
                else{
                    if(open.size() == 0) return false;
                    if((open.back()=='(' && ch==')') ||(open.back()=='{' && ch=='}')||
                    (open.back()=='[' && ch==']') ) {
                        open.pop_back();
                    }
                    else return false;
                    
                }
            }
            if(open.size()!= 0)return false;
            return true;           
        }
    }
};