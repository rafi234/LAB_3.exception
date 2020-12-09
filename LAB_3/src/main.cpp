#include <iostream>
#include <fstream>
#include "Matrix/matrix.hpp"

using namespace std;

void my_exception(int i);

int main()
{
     try
     {
          cout << "\nTworzymy macierz A o wymiarach 7x7\n\n";
          Matrix A(7, 7);
          cout << " Przed zainicjowaniem wartosci: \n";
          A.print();
          A.CreateMatrix_1();
          cout << " Po zainicjowaniu wartosci wedlug przypadkowego wzoru: \n";
          A.print();
          cout << "\n\nTworzymy macierz B o wymiarach 7x7\n\n";
          Matrix B(7);
          cout << " Przed zainicjowaniem wartosci: \n";
          B.print();
          B.CreateMatrix_2();
          cout << " Po zainicjowaniu wartosci wedlug przypadkowego wzoru: \n";
          B.print();

          cout << "\n\nW macierzy A znajduja sie " << A.cols() << " kolumn i " << A.rows() << " wierszy" << endl
               << endl;
          try
          {
               cout << "Teraz sprawdzimy jaka wartosc znajduje sie w komurce o wspolrzednych (1, 3) w macierzy A\n";
               cout << "Wartosc w tej komurce jest rowna: " << A.get(1, 3) << endl
                    << endl;
          }
          catch (int er)
          {
               my_exception(er);
          }
         
          try
          {
               double x = B.get(2, 3);

               cout << "Nastepnie  zmienimy warosc komurki (2, 3) w macierzy B na 10\n";
               B.set(2, 3, 10);

               cout << "Przed zamiana: " << x << "\nPo zamianie: " << B.get(2, 3) << endl
                    << endl;
          }
          catch (int er)
          {
               my_exception(er);
          }

          cout << "Teraz dodajmy do siebie te macierze.\n\nPrzed dodaniem A wyglada nastepujaco:\n";
          A.print();

          cout << "\n\nNatomiast B wyglada tak:\n";
          B.print();

          try
          {
               cout << "\n\nPo dodaniu:\n";
               Matrix C = A.add(B);
               C.print();
          }
          catch (int er)
          {
               my_exception(er);
          }

          try
          {
               cout << "\n\nTeraz odejmiemy macierz B od macierzy A \n\n";
               Matrix D = A.substract(B);
               D.print();
          }
          catch (int er)
          {
               my_exception(er);
          }
          try
          {
               cout << "\n\nNa koncu pomnozmy macierz A przez B  \n\n";
               Matrix E = A.multiply(B);
               E.print();
          }
          catch (int er)
          {
               my_exception(er);
          }

          string filename = "plik.txt", path = "./";
          cout << "\n\nTeraz zapiszymy macierz A do pliku\n\n";
          A.store(filename, path);

          cout << "Nastepnie wczytamy macierz A z pliku do innego obiektu\n\n";
          Matrix f(filename, path);

          cout << "Powstala macierz wyglada nastepujaco:\n\n";

          f.print();
     }
     catch (int er)
     {
          my_exception(er);
     }
     return 0;
}

void my_exception(int i)
{
     if (i == -1)
          cout << "\nWARNING: Nie mozna wykonac dzialania z powodu nie odpowiednich rozmiarow macierzy!\n";
     else if (i == -2)
          cout << "\nWARNING: Podana komurka nie istnieje w danej macierzy!\n";
     else if (i == -3)
          cout << "\nERROR: Blad alokacji pamieci!!!";
     else if (i == -4)
          cout << "\nERROR: Dostep do pliku zostal zabroniony!" << endl;
}