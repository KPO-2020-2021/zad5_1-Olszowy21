#pragma once


#include "matrix3d.hpp"

/*!
 * \file  block.hh
 *  
 *  Plik zawiera klasę bryla oraz
 *  jest ojcem dla wszystkich bibliotek wbudowanych.
 *  
 */

class Block{
protected:
    std::string Plik_BrylaWzorcowa;
    std::string Plik_BrylaAnimowana;

    Vector3D skala;

    Vector3D Polozenie;

    Matrix3D Macierz;

public:

    void set_skala(Vector3D &tmp) { skala = tmp; };
    Vector3D skaluj( const Vector3D top);
    const std::string& get_filename_standard() const {return Plik_BrylaWzorcowa ;};
    const std::string& get_filename_anime() const {return Plik_BrylaAnimowana ;};

    void set_katOX(double kat);
    void set_katOZ(double kat);
    void set_katOY(double kat);
};