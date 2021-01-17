// https://leetcode.com/problems/design-parking-system/
// Easy
// Mock

using namespace std;

class ParkingSystem {
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small): big{big}, medium{medium}, small{small} { }
    
    bool addCar(int carType) {
        if (carType == 1 && big-- > 0) {
        } else if (carType == 2 && medium-- > 0) {
        } else if (carType == 3 && small-- > 0) {
        } else {
            return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */