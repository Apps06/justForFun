#include <iostream>
using namespace std;

// function to convert binary to decimal
void decToBinary(int binary)
{
    int decimal = 0, base = 1, rem;

    while (binary > 0)
    {
        rem = binary % 10;
        decimal = decimal + rem * base;
        binary = binary / 10;
        base = base * 2;
    }

    cout << "Decimal equivalent: " << decimal << endl;
}

int main()
{
    int binary;
    cout << "Enter the number in binary form: ";
    cin >> binary;
    decToBinary(binary);
    return 0;
}