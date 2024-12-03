#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "7 6 4 2 1";
    string bufor;
    vector <int> macierz;

    for(int i = 0; i < s.size(); i++)
        {
            cout << bufor << ' ';
            if(s[i] == ' ')
            {
                macierz.push_back(stoi(bufor));
                bufor = "";
            }
            else bufor += s[i];
        }
}