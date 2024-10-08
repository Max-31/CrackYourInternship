/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector <int> ans;
    int i=0;

    void checklist(vector<NestedInteger> &nestedList){
        for(int i=0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                ans.push_back(nestedList[i].getInteger());
            }
            else{
                checklist(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        checklist(nestedList);
    }
    
    bool hasNext() {
        if(i<ans.size()){
            return true;
        }
        return false;
    }

    int next() {
        int nexti=-1;
        if(hasNext()==true){
            nexti= ans[i];
            i++;
        }
        return nexti;
    }
    
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */