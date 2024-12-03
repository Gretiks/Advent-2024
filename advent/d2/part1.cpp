#include <bits/stdc++.h>
using namespace std;

bool rosnie(vector<int> v)
{
    int roznica = 0;
    for(int i = 0; i < v.size()-1; i++)
    {
        roznica = v[i+1] - v[i];
        // cout << "rosnie " <<roznica << " ";
        if(roznica < 0 || roznica == 0 || roznica > 3) return false;   
    }
    return true;
}

bool maleje(vector<int> v)
{
    int roznica = 0;
    for(int i = 0; i < v.size()-1; i++)
    {
        roznica = v[i] - v[i+1];
        // cout << "maleje " << roznica << " ";
        if(roznica < 0 || roznica == 0 || roznica > 3) return false;    
    }
    return true;
}

int main()
{
    vector<vector<int>> macierz;
    vector<int> wektor;
    string s, bufor;
    long long wynik = 0;

    ifstream plik("2.in");

    while(getline(plik, s))
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                wektor.push_back(stoi(bufor));
                bufor = "";
            }
            else bufor += s[i];

        }
        wektor.push_back(stoi(bufor));
        macierz.push_back(wektor);
        wektor.clear();
        bufor = "";

    }

    int ite = 0;
    for(auto x: macierz)
    {
        // cout << '\n' << ite << '\n';
        if(x[0] > x[1])
        {
            if(maleje(x))
                wynik++;
        }
        else if(rosnie(x))wynik++;

        ite++;

    }

    cout << wynik;

    return 0;
}