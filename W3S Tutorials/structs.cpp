#include <iostream>
#include <string>

using namespace std;

int main() {
    struct myStruct {
        int num;
        string str;
    } struct1, struct2;  // You can create multiple struct variables at once with comma separation

    // Value assignment to members of the struct
    struct1.num = 69;
    struct2.num = 420;

    struct1.str = "Hehe funny";
    struct2.str = "D O double G";

    cout << struct1.str << ", " << struct1.num << "\n";
    cout << struct2.str << ", " << struct2.num << "\n";

    myStruct struct3;  // Creating another instance of the struct (Only possible if struct is named e.g myStruct)
    

    return 0;
}