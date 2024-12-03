#include <bits/stdc++.h>
using namespace std;

vector<int> bubble(vector<int> tab)
{
    for(int i = 0; i < tab.size(); i++)
    {
        for(int j = 1; j < tab.size()-i; j++)
        {
            if(tab[j-1] < tab[j])
                swap(tab[j-1], tab[j]);
        }
    }

    return tab;
}

int main()
{

    int a, b;
    long long wynik = 0;
    vector <int> v1;
    vector <int> v2;
    ifstream plik("1.in");


    while(plik >> a >> b)
    {
        v1.push_back(a);
        v2.push_back(b);
    }

    
    v1 = bubble(v1);
    v2 = bubble(v2);

    for(int i = 0; i < v1.size(); i++)
        wynik += abs(v1[i] - v2[i]);


    cout << wynik;

}