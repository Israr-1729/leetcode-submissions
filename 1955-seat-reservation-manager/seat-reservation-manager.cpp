class SeatManager {
public:

    set<int> openSeats;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
        openSeats.insert(i);
    }
    
    int reserve() {
        int x = *openSeats.begin();
openSeats.erase(openSeats.begin());
return x;
    }
    
    void unreserve(int seatNumber) {
        openSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */