class MyStack 
{
    public:
    MyStack() {}
    
    void push(int x) 
    {
        q.push(x);
        // flip the sequence
        // notice the q.size()-1
        for (int i=0; i<q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() 
    {
        int toPop = q.front();
        q.pop();
        return toPop;
    }
    
    int top() 
    {
        return q.front();
    }
        
    bool empty() 
    {
        return q.empty();
    }

    private:
    queue<int> q;
};
    
    