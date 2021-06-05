#pragma once

#include "block.hpp"


class Prism: public Block{

    // std::string Plik_BrylaWzorcowa;
    // std::string Plik_BrylaAnimowana;

    // Vector3D skala;

    // Vector3D Polozenie;

    // Matrix3D Macierz;

    // double kat_do_globalnego;

    //top[13]/top[0] ---> Pomocnicze do koperty

    Vector<double, SIZE> top[14];

    friend class Drone;

public:
// Konstruktory

    Prism();

    Prism(Vector3D skala, Vector3D center, double promien, int index);

// Metody

    Vector3D Trans_do_rodzica(const Vector3D & top) const;

    void throwing_Prism(const Matrix<double, SIZE> &tmp);

    void Kicking_Prism(const Vector<double, SIZE> &tmp);

    void Zapis_do_pliku_wzorcowego(std::ofstream &out);

    void Zapis_do_pliku_animowanego(std::ofstream &out);

};