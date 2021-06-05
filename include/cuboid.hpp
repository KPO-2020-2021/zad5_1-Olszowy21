#pragma once

#include "prism.hpp"



class Cuboid: public Block{

    // std::string Plik_BrylaWzorcowa;
    // std::string Plik_BrylaAnimowana;

    // Vector3D skala;

    // Vector3D Polozenie;

    // Matrix3D Macierz;

    // top[0] i top[9] odpowiadaja za pubkty kopertowe
    
    Vector<double, SIZE> top[10];

    friend class Drone;

public:

// Konstruktory 

    Cuboid();

    // Cuboid(Vector<double, SIZE> first, Vector<double, SIZE> second, Vector<double, SIZE> third, Vector<double, SIZE> fourth,
    //         Vector<double, SIZE> fifth, Vector<double, SIZE> sixth,  Vector<double, SIZE> seventh, Vector<double, SIZE> eigth, Vector3D centrum);

    Cuboid(Vector3D centrum, double dlugosc, double szerokosc, double wysokosc);
    
// Metody

    Vector3D Trans_do_rodzica(const Vector3D & top) const;

    const Vector<double, SIZE> &operator [] (unsigned int index) const;

    void throwing_Cuboid(const Matrix<double, SIZE> &tmp);

    void Kicking_Cuboid(const Vector<double, SIZE> &tmp);

    bool Zapis_do_pliku_wzorcowego(std::ofstream &out);

    bool Zapis_do_pliku_animowanego(std::ofstream &out);

    Vector<double, SIZE> &operator [] (unsigned int index);

    bool operator == (const Cuboid &tmp) const;

    void length_of_the_sides(int index);
};


