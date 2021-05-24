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
    std::string NazwaPliku_BrylaWzorcowa;
    std::string NazwaPliku_BrylaFinalna;
    Vector3D skala;

public:
    Vector3D skaluj( const Vector3D top);
    const std::string& get_filename_standard() const;
    const std::string& get_filename_final() const;
};