#include <bits/stdc++.h>
using namespace std;

bool maleje(vector<int> v)
{
    int roznica = 0;
    vector<int> v2;
    int ile_poprawek = 0;
    for(int i = 0; i < v.size()-1; i++)
    {
      roznica = v[i] - v[i+1];
      if(roznica <= 0 || roznica > 3)
      {

        for(int j = 0; j < v.size(); j++)
        {
          v2.clear();
          for(int k = 0; k < j; k++)
            v2.push_back(v[k]);
          for(int k = j+1; k < v.size(); k++)
            v2.push_back(v[k]);

          ile_poprawek = 1;
          for(auto x: v2)
            cout << x << " ";
          for(int k = 0; k < v2.size()-1; k++)
          {
            if(v2[0] > v2[1]) //maleje
            {
                roznica = v2[k] - v2[k+1];
                cout << '\n' << v2[k] << " " << v2[k+1] << " = " << roznica << '\n';
                if(roznica <= 0 || roznica > 3) break;
            }
            else if(v2[0] < v2[1]) //rosnie
            {
              roznica = v2[k+1] - v2[k];
              cout << '\n' << v2[k] << " " << v2[k+1] << " = " << roznica << '\n';
              if(roznica <= 0 || roznica > 3) break;
            }
            else if(v2[0] == v2[1]) break;

            if(ile_poprawek == 1 && k == v2.size()-1) return true;
          }

        }
      }
    }

    if(ile_poprawek == 0) return true;
    else return false;

}

bool rosnie(vector<int> v)
{
    int roznica = 0;
    vector<int> v2;
    int ile_poprawek = 0;
    for(int i = 0; i < v.size()-1; i++)
    {
      roznica = v[i+1] - v[i];
      if(roznica <= 0 || roznica > 3)
      {

        for(int j = 0; j < v.size(); j++)
        {
          v2.clear();
          for(int k = 0; k < j; k++)
            v2.push_back(v[k]);
          for(int k = j+1; k < v.size(); k++)
            v2.push_back(v[k]);

          ile_poprawek = 1;
          for(auto x: v2)
            cout << x << " ";
          for(int k = 0; k < v2.size()-1; k++)
          {
            if(v2[0] > v2[1]) //maleje
            {
                roznica = v2[k] - v2[k+1];
                cout << '\n' << v2[k] << " " << v2[k+1] << " = " << roznica << '\n';
                if(roznica <= 0 || roznica > 3) break;
            }
            else if(v2[0] < v2[1]) //rosnie
            {
              roznica = v2[k+1] - v2[k];
              cout << '\n' << v2[k] << " " << v2[k+1] << " = " << roznica << '\n';
              if(roznica <= 0 || roznica > 3) break;
            }
            else if(v2[0] == v2[1]) break;

            if(ile_poprawek == 1 && k == v2.size()-1) return true;
          }

        }
      }
    }

    if(ile_poprawek == 0) return true;
    else return false;

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
      if(x[0] > x[1] && maleje(x)) wynik++;
      else if(x[1] > x[0] && rosnie(x)) wynik++;
      else if(rosnie(x)) wynik++;
      cout << "wynik " <<  wynik;
      cout << "\n\n";
    }

    cout << wynik;

    return 0;
}