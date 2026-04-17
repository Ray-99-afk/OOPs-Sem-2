//          ------- Text
//          |
// File -----
//          |
//          ------- Binary
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     std::ofstream file("data.bin", std::ios::out | std::ios::binary);
//     if (!file) {
//         std::cerr << "Error opening file!" << std::endl;
//         return 1;
//     }
//     int arr[5] = {1, 2, 3, 4, 5};
//     file.write((char*)arr, sizeof(arr));
//     file.close();
//     return 0;
// }


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file ("Data.bin", ios::binary);
int num[5];
file.read((char*)&num, sizeof(num));
for(int i =0; i<5; i++)
cout<< *(num+i)<<endl;
return 0;
}


// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     ifstream file("Data.bin", ios::binary);

//     if (!file) {
//         cerr << "Could not open file!" << endl;
//         return 1;
//     }

//     int arr[5];

//     file.read(reinterpret_cast<char*>(arr), sizeof(arr));

//     for(int i = 0; i < 5; i++) {
//         cout << arr[i] << endl;
//     }

//     file.close();
//     return 0;
// }