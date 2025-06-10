#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
ll modular_inv(ll n, ll mod)
{
    // Assuming gcd(n, mod) == 1
    ll e = 1;
    while (true)
    {
        if (((e%mod)*(n%mod))%mod == 1)
        {
            return e;
        }
        e++;
        if (e == LLONG_MAX) return -1;
    }
}
ll modular_power(ll n, ll p, ll mod)
{
    ll ans = 1;
    for (int i=0; i<p; ++i)
    {
        ans *= n;
        ans %= mod;
    }
    return ans;
}
void encrypt(string str, ll e, ll n, ofstream &fp)
{
    string newstring = "";
    for (int i=0; i<str.length(); ++i)
    {
        int asc = str[i]; // Gets the ascii value of ch
        asc = modular_power(asc, e, n);
       fp << asc;
       if (i < str.length() - 1) fp << '.';
    }
    fp << ' ';
}
int main()
{
    const ll lim = 5e8;
    ll p, q;
    // Set p & q to be two large primes
    srand(time(NULL));
    p = rand()%lim;
    while (!isPrime(p)) p++;
    q = rand()%lim;
    while (!isPrime(q)) q++;
    ll n = p*q;
    ll phi_n = (p-1)*(q-1);
    ll e = 65537; // Encryption key is typically set to 65537
    ll d = modular_inv(e, phi_n); // Find out decryption key
    // Storing the private key (for future purposes)
    ofstream priv("private.txt", ios::out);
    priv << d << endl;
    priv.close();
    // We'll take plaintext from inputfile, encrypt it and send it to outputfile
    ifstream fp("inputfile.txt", ios::in);
    ofstream fp2("outputfile.txt", ios::out);
    string str = "";
    fp2 << n << ' ' << e << endl;
    while (!fp.eof())
    {
        fp >> str;
        // Assume we're dealing with only uppercase alphabets (+ symbols)
        encrypt(str, e, n, fp2);
    }
    fp.close();
    fp2.close();
    return 0;
}