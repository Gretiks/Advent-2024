#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a, b;
    long long wynik = 0;
    vector <int> v1;
    vector <int> v2;
    int tab [100000] = {0};
    ifstream plik("1.in");



    while(plik >> a >> b)
    {
        v1.push_back(a);
        v2.push_back(b);
    }


    for(auto x: v2)
        tab[x]++;


    for(auto x: v1)
        if(tab[x])
        {
            wynik += x*tab[x];
        }

    cout << wynik;

}