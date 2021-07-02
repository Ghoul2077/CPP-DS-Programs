#include<iostream>
using namespace std;

int factorialReccursive( int num ) {
    // Time complexity Q(n) and auxillary space is Q(n) and causes extra overhead
    if( num == 1 ) return 1;
    return num * factorialReccursive( num - 1 );
}

int factorialTailReccursion(int n, int fac = 1) {
    if(n <= 1)
        return fac;
    else
        fac*=n;
        return factorialTailReccursion(n - 1, fac);
}

int factorial( int num ){
    // Time complexity Q(n) and auxillary space is Q(1) hence better than reccursive
    int result = 1;
    while(num != 1) result = result * num-- ;
    return result;
}

int main() {
    int input;
    cout<<"Enter Number : ";
    cin>>input;
    cout<<factorial(input);
    // cout<<factorialReccursive(input);
}

