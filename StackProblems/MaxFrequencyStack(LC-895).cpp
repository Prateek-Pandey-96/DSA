class FreqStack {
public:
    unordered_map<int, int> hashmap;
    unordered_map<int, stack<int>> stackmap;
    int maxf;
    
    FreqStack() {
        hashmap.clear();
        stackmap.clear();
        maxf = 0;
    }
    
    void push(int val) {
        hashmap[val]++;
        if(hashmap[val] > maxf)
            maxf = hashmap[val];
        stackmap[hashmap[val]].push(val);
    }
    
    int pop() {
        if(stackmap[maxf].size() == 0)
            maxf--;
        int val = stackmap[maxf].top();
        stackmap[maxf].pop();
        hashmap[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */