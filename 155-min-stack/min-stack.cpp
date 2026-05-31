class MinStack {
public:

    vector<int> v;
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int lowest = v[0];
        int size = v.size();
        for(int i = 0; i<size; i++)
        {
            if(lowest>v[i])
            lowest = v[i];
        }
        return lowest;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */