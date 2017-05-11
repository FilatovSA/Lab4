#include <iostream>

using namespace std;

char nibble_to_hex(uint8_t i){
    char symbols[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    return symbols[i];
}

int main(){
    return 0;
}