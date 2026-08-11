class Bitset {
public:
    vector<int> bits;
    bool isFlipped = false;
    int count1 = 0;

    Bitset(int size) {
        bits = vector<int>(size, 0);
    }

    void fix(int idx) {
        // Logical value of this bit
        int actual = bits[idx] ^ isFlipped;

        if (actual == 1)
            return;

        bits[idx] = !bits[idx];
        count1++;
    }

    void unfix(int idx) {
        // Logical value of this bit
        int actual = bits[idx] ^ isFlipped;

        if (actual == 0)
            return;

        bits[idx] = !bits[idx];
        count1--;
    }

    void flip() {
        isFlipped = !isFlipped;
        count1 = bits.size() - count1;
    }

    bool all() {
        return count1 == bits.size();
    }

    bool one() {
        return count1 > 0;
    }

    int count() {
        return count1;
    }

    string toString() {
        string result;

        for (int i : bits) {
            int actual = i ^ isFlipped;
            result += (actual ? '1' : '0');
        }

        return result;
    }
};

