#include <iostream>
using namespace std;

void towerOfHanoi(string from, string to, string other, int count) {
   if (count == 1) {
      cout << "Moved 1 Disc from " << from << " to " << to << endl;
   }else  {
      towerOfHanoi(from, other, to, count - 1);
      towerOfHanoi(from, to, other, 1);
      towerOfHanoi(other, to, from, count - 1);
   }
}

int main() {
   towerOfHanoi("A", "C", "B", 3);
}
