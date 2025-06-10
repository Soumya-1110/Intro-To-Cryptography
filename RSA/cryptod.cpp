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
void decrypt(ll e, ll d, ll n, ifstream &fp)
{
    string str;
    int k; char ch;
    fp >> k;
    do
    {
        int dc = modular_power(k, d, n);
        str.push_back(dc);
        fp >> ch;
        if (ch == '.')
        {
            fp >> k;
            continue;
        }
        else
        {
            fp.seekg(-1, ios::cur);
            break;
        }
    }   while (ch == '.' && !fp.eof());
    cout << str << ' ';
}
int main()
{
    const ll lim = 5e8;
    ll d; // Assign the value of 'd' using the value you get in encryption program
    ifstream p("private.txt", ios::in);
    p >> d;
    p.close();
    ll n,e;
    // We'll take plaintext from inputfile, encrypt it and send it to outputfile
    ifstream fp("outputfile.txt", ios::in);
    fp >> n;
    fp >> e;
    while (!fp.eof())
    {
        // Assume we're dealing with only uppercase alphabets (+ symbols)
        decrypt(e, d, n, fp);
    }
    fp.close();
    return 0;
}