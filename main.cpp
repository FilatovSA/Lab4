#include <iostream>

using namespace std;

char nibble_to_hex(uint8_t i){
    char symbols[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    return symbols[i];
}

void print_byte( uint8_t byte){
    uint8_t low = (byte & 0b00001111);
    uint8_t high = (byte & 0b11110000) >>  4;
    cout << nibble_to_hex(high) << nibble_to_hex(low);
}

int main(){
    uint32_t byte;
    cin >> byte;
    print_byte(byte);
    cout << "\n";
    return 0;
}