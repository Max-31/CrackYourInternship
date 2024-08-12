class twoStacks {
    
  public:
    vector<int> v;
    int f1;
    int f2;

    twoStacks():v(202) {
        f1= -1, f2=202;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        f1++;
        v[f1]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        f2--;
        v[f2]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(f1==-1) return f1;
        int ele= v[f1];
        f1--;
        return ele;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(f2==202) return -1;
        int ele= v[f2];
        f2++;
        return ele;
    }
};