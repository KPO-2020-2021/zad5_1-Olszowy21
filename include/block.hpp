#pragma once


#include "matrix3d.hpp"

/*!
 * \file  block.hpp
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

    double kat_do_globalnego;

public:

    void set_skala(Vector3D &tmp) { skala = tmp; };
    Vector3D skaluj( const Vector3D top);

    const std::string& get_filename_standard() const {return Plik_BrylaWzorcowa ;};
    const std::string& get_filename_anime() const {return Plik_BrylaAnimowana ;};
    
    bool Otworz_Plik_animowany(std::ofstream &out, std::string File_name);
    bool Otworz_Plik_wzorcowy(std::ofstream &out, std::string File_name);

    void Zamknij_Plik_animowany(std::ofstream &out);
    void Zamknij_Plik_wzorcowy(std::ofstream &out);

    void set_kat(double kat) { kat_do_globalnego = kat;};

};