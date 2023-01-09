// 1NN.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "DaneZKlasami.h"
#include "Klasyfikator1NN.h"
using namespace std;

//float MetrykaEuklidesa(const vector<float>& d1, const vector<float>& d2)
//{
//}

int main()
{
    DaneZKlasami dtrn;
    DaneZKlasami dtst;
    ifstream f1("iris-trn.dat");
    f1 >> dtrn;
    ifstream f2("iris-tst.dat");
    f2 >> dtst;
    MetrykaEuklidesa metryka;
    Klasyfikator1NN<MetrykaEuklidesa> oneNN(metryka);
    oneNN.Naucz(&dtrn);
    Klasy klasy = oneNN.Klasyfikuj(dtst);
    PorownajKlasy(klasy, dtst.Klasy);
}
