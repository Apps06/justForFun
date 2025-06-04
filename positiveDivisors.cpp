// code to find the number of positive divisors and sum of the divisors of input number n
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    int count = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            sum += i;
        }
    }
    cout << "Number of positive divisors: " << count << endl;
    cout << "Sum of positive divisors: " << sum << endl;
    
    return 0;
}