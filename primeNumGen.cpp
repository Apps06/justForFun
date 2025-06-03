#include <iostream>
#include <math.h>
using namespace std;

// function to check whether prime or not (simple)
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

//function to print the prime numbers withing the given numbre of digits 
void printPrimes(int n) {
    int beg = pow(10, n - 1); 
    int end = pow(10, n) - 1;

    if(n==1) beg=1; 
    cout << "Prime numbers with " << n << " digits are: ";
    for (int i = beg; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n; //be careful with larger numbers since something might go wrong
    cout << "Enter a number (be careful with bigger numbers): ";
    cin >> n;
    printPrimes(n);
    return 0;
}