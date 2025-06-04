#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

// Function to express n as product of 2 primes
bool expressAsProductOfTwoPrimes(int n, int &p, int &q)
{
    for (int i = 2; i <= sqrt(n); ++i) // Changed from n/2 to sqrt(n)
    {
        if (n % i == 0) // Check if i is a factor first
        {
            int other = n / i;
            if (isPrime(i) && isPrime(other)) // Then check if both are prime
            {
                p = i;
                q = other;
                return true;
            }
        }
    }
    return false;
}

// Greatest common divisor
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate modular exponentiation
long long modPow(long long base, long long exponent, long long mod)
{ // Changed to long long
    long long result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Extended Euclidean Algorithm to find modular inverse
int extendedGCD(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
int modInverse(int e, int phi)
{
    int x, y;
    int g = extendedGCD(e, phi, x, y);
    if (g != 1)
        return -1;                // Modular inverse doesn't exist
    return (x % phi + phi) % phi; // Make sure result is positive
}

void RSAAlgo(int n, int e)
{
    int p, q;
    if (!expressAsProductOfTwoPrimes(n, p, q))
    {
        cout << n << " cannot be expressed as a product of two prime numbers." << endl;
        return;
    }

    cout << n << " = " << p << " * " << q << endl;

    int phi = (p - 1) * (q - 1);
    cout << "φ(n) value = " << phi << endl; // Added for debugging

    if (gcd(e, phi) != 1)
    {
        cout << "Public key e is not coprime with φ(n). Choose another e." << endl;
        return;
    }

    int d = modInverse(e, phi);
    if (d == -1)
    {
        cout << "No valid decryption key found." << endl;
        return;
    }

    cout << "Decryption key (d): " << d << endl;

    string s;
    cin.ignore(); // Clear leftover newline from previous input
    cout << "Enter the message to be encrypted: ";
    getline(cin, s); // supports full sentence

    vector<int> a(s.length());
    vector<long long> encrypted(s.length()); // Changed to long long

    for (int i = 0; i < s.length(); i++)
        a[i] = int(s[i]);

    // Check if any character's ASCII value is >= n
    bool validInput = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (a[i] >= n)
        {
            cout << "Error: Character '" << s[i] << "' (ASCII " << a[i] << ") is >= n (" << n << "). Choose a larger n." << endl;
            validInput = false;
        }
    }

    if (!validInput)
    {
        return;
    }

    for (int i = 0; i < s.length(); i++)
        encrypted[i] = modPow(a[i], e, n);

    cout << "Encrypted message: ";
    for (int i = 0; i < s.length(); i++)
        cout << encrypted[i] << " ";
    cout << endl;

    cout << "Decrypted message: ";
    for (int i = 0; i < s.length(); i++)
        cout << static_cast<char>(encrypted[i]) << " "; // Cast back to char for display
    cout << endl;
}

int main()
{
    int n, e;
    cout << "Enter a positive integer (n): ";
    cin >> n;
    cout << "Enter public encryption key (e): ";
    cin >> e;

    RSAAlgo(n, e);
    return 0;
}