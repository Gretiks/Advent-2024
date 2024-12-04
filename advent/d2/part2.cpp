#include <bits/stdc++.h>
using namespace std;

bool rosnie(vector<int> v)
{
    int roznica = 0;
    vector<int> v2;
    for(int i = 0; i < v.size()-1; i++)
    {
        roznica = v[i+1] - v[i];
        if(roznica < 0 || roznica == 0 || roznica > 3)
        {
            for(int j = 0; j < i; j++)
                v2.push_back(v[j]);

            for(int j = i+1; j < v.size(); j++)
                v2.push_back(v[j]);

            roznica = 0;
            if(v2.size() == v.size())
            {
                v2.clear();
                for(int j = 1; j < v.size(); j++)
                    v2.push_back(v[j]);
            }
            else if(i == v.size()-2)
            {
                v2.clear();
                for(int j = 0; j < v.size()-1; j++)
                    v2.push_back(v[j]);
            }


            for(int j = 0; j < v2.size()-1; j++)
            {
                roznica = v2[j+1] - v[j];
                if(roznica < 0 || roznica == 0 || roznica > 3) return false;
            }
        }
    }

    return true;
}

bool maleje(vector<int> v)
{
    int roznica = 0;
    vector<int> v2;
    for(int i = 0; i < v.size()-1; i++)
    {
        roznica = v[i] - v[i+1];
        if(roznica < 0 || roznica == 0 || roznica > 3)
        {
            for(int j = 0; j < i; j++)
                v2.push_back(v[j]);
;
            for(int j = i+1; j < v.size(); j++)
                v2.push_back(v[j]);

            roznica = 0;
            if(v2.size() == v.size())
            {
                v2.clear();
                for(int j = 1; j < v.size(); j++)
                    v2.push_back(v[j]);
            }
            else if(i == v.size()-2)
            {
                v2.clear();
                for(int j = 0; j < v.size()-1; j++)
                    v2.push_back(v[j]);
            }


            for(int j = 0; j < v2.size()-1; j++)
            {
                roznica = v2[j] - v2[j+1];
                if(roznica < 0 || roznica == 0 || roznica > 3) return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> macierz;
    vector<int> wektor;
    string s, bufor;
    long long wynik = 0;

    ifstream plik("test.in");

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

    }

    cout << wynik;

    return 0;
}