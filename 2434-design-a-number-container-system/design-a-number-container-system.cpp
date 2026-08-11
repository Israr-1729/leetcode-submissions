class NumberContainers {
public:
    unordered_map<int, int> indicesToNum;
    unordered_map<int, set<int>> numToIndices;
    NumberContainers() {
        
    }
    
void change(int index, int number) {
    if (indicesToNum.contains(index)) {
        int oldNumber = indicesToNum[index];
        numToIndices[oldNumber].erase(index);
    }

    indicesToNum[index] = number;
    numToIndices[number].insert(index);
}
    
int find(int number) {
    if (numToIndices.contains(number) && !numToIndices[number].empty())
        return *numToIndices[number].begin();

    return -1;
}
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */