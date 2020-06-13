
class UnusualAdd {
public:
    int addAB(int A, int B) {
    while(B){
        auto carry = ((unsigned int) (A & B))<<1;
        A ^= B;
        B = carry;
    }
    return A;
    }
}; 
