class ParkingSystem {
public:
    int bigCurr = 0;
    int medCurr = 0;
    int smallCurr = 0;

    int bigMax; int medMax; int smallMax;
    ParkingSystem(int big, int medium, int small) {
        bigMax = big;
        medMax = medium;
        smallMax = small;
    }
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 1 : if(bigCurr < bigMax) {bigCurr++; return true;} break;
            case 2 : if(medCurr < medMax) {medCurr++; return true;} break;
            case 3 : if(smallCurr < smallMax) {smallCurr++; return true;} break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */