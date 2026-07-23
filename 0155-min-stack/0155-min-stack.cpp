class MinStack {
public:
    vector<int> st;
    vector<int> minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
        if(minSt.empty() || value <= minSt.back()) minSt.push_back(value);
    }
    
    void pop() {
        if(!st.empty()){
            int val = st.back();
            st.pop_back();
            if(!minSt.empty() && minSt.back() == val) minSt.pop_back();
        }

    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */