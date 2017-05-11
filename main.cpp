#include <iostream>
#include <cstring>

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

void print_in_hex(const void* data, size_t size){
    const char* p = reinterpret_cast<const char*>(data);
    for(size_t i = 0; i < size; i++ ){
        print_byte(p[i]);
        cout << " ";
    }
}

struct Student{
    char name[17];
    int year;
    float av_score;
    int sex:1;
    int courses;
    Student* str;
};


int main(){
    Student s[3];
    strcpy(s[0].name, "Ivan");
    s[0].year = 2016;
    s[0].av_score = 4.3;
    s[0].sex = 1;
    s[0].courses = 2;
    s[0].str = &s[1];
    strcpy(s[1].name, "Artem");
    s[1].year = 2016;
    s[1].av_score = 5;
    s[1].sex = 1;
    s[1].courses = 2;
    s[1].str = nullptr;
    strcpy(s[2].name, "Nikolai");
    s[2].year = 2016;
    s[2].av_score = 3.9;
    s[2].sex = 1;
    s[2].courses = 2;
    s[2].str = &s[1];
    cout << "Address of array = " << &s;
    cout << "\nSize of array = " << sizeof(s) << "\n\n";

    cout << "Address 'name' " << &s[0].name;

    for(int i = 0; i < 3; i++){
        cout << "\nAddress of el of array = " << &s[i];
        cout << "\nSize of el of array = " << sizeof(s[i]) << "\n";
        print_in_hex(&s[i], sizeof(s[i]));
        cout << "\n";
    }
    return 0;
}