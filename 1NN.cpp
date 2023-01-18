// 1NN.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "DaneZKlasami.h"
#include "Klasyfikator1NN.h"
#include "MetrykaEuklidesa.h"
#include "MacierzKonfuzji.h"
using namespace std;

//float MetrykaEuklidesa(const vector<float>& d1, const vector<float>& d2)
//{
//}

void PorownajKlasy(Klasy k1, Klasy k2)
{
    MacierzKonfuzji m(k1, k2);

    for (int i = 0; i < m.LiczbaKlas(); i++)
        cout << "\t" << m.Klasa(i);
    cout << endl;

    for (int i = 0; i < m.LiczbaKlas(); i++)
    {
        cout << setw(15) << m.Klasa(i) << "\t";
        for (int j = 0; j < m.LiczbaKlas(); j++)
            cout << m.Wpis(i, j) << "\t";
        cout << endl;
    }

    float poprawne = 0, suma = 0;
    for (int i = 0; i < m.LiczbaKlas(); i++)
    {
        poprawne += m.Wpis(i, i);
        for (int j = 0; j < m.LiczbaKlas(); j++)
            suma += m.Wpis(i, j);
    }

    cout << "Dokładność klasyfikacji: " << poprawne/suma*100 << "%" << endl;
}

int main()
{
    DaneRnZKlasami dtrn;
    DaneRnZKlasami dtst;
    ifstream f1("iris-trn.dat");
    f1 >> dtrn;
    ifstream f2("iris-tst.dat");
    f2 >> dtst;

    MetrykaEuklidesa metryka;
    Klasyfikator1NN<vector<float>> oneNN(&metryka);
    oneNN.Naucz(&dtrn);

    Klasy klasy = oneNN.Klasyfikuj(dtst);
    PorownajKlasy(klasy, dtst.Klasy());

    klasy = oneNN.Klasyfikuj(dtrn);
    PorownajKlasy(klasy, dtrn.Klasy());
}
