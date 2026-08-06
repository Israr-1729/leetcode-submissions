class SmallestInfiniteSet {
public:

    unordered_set<int> no;
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        int i;
        for(i = 1; i>0; i++)
        {
            if(!no.contains(i))
            break;
        }
        no.insert(i);
        return i;
    }
    
    void addBack(int num) {
        no.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */