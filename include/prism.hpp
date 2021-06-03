#pragma once

#include "block.hpp"


class Prism: public Block{

    // std::string Plik_BrylaWzorcowa;
    // std::string Plik_BrylaAnimowana;

    // Vector3D skala;

    // Vector3D Polozenie;

    // Matrix3D Macierz;

    //top[13]/top[0] ---> Pomocnicze do koperty

    Vector<double, SIZE> top[14];

public:
// Konstruktory
    Prism();

    Prism(Vector3D center, double Wysokosc, double dlugop, double szerokosc);
    
// Metody

    Vector3D Trans_do_rodzica(const Vector3D & top) const;

    void throwing_Prism(const Matrix<double, SIZE> &tmp);

    void Kicking_Prism(const Vector<double, SIZE> &tmp);

    bool ZapisWspolrzednychDoPliku();

};