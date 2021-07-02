#include <iostream>
using namespace std;

int main() {
   int i = 10, *pointer, *pointer2;

   pointer  = &i;
   pointer2 = pointer;

   cout << *pointer2 << endl;

   cout << pointer << endl;
   cout << sizeof(pointer) << endl;
   cout << *pointer << endl;

   i++;
   cout << i << endl;
   cout << *pointer << endl;
}
