#pragma once

#include "cuboid.hpp"

class Drone{

    Vector3D Polozenie;
    double KatOrientacji;
    Cuboid Korpus;
    Prism Rotor;
    
public:

    Vector3D Trans_do_rodzica(const Vector3D & top) const;
    bool Lot_pionowy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool Lot_pioziomy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool Oblicz_wsp_korpusa() const;
    bool Oblicz_wsp_rotora() const;
    bool Oblicz_wsp_drona() const;
    
};