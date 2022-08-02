class MinStack {
    public:
   vector<int> stack;
    vector<int> minstack;
    void push(int val) {
        stack.push_back(val);
        if(minstack.size() == 0 || val <= minstack.back())
        {
            minstack.push_back(val);
        }   
    }
 
    void pop() {
        if(minstack.back() == stack.back())
            minstack.pop_back();
        stack.pop_back();
        return;
    }
 
    int top() {
        return stack.back();
    }
 
    int getMin() {
        return minstack.back();   
    }
};