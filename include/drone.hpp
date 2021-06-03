#pragma once

#include "cuboid.hpp"

class Drone{
protected:

    Vector3D Polozenie;

    Cuboid Korpus;

    Prism Rotor[4];

    Matrix3D Macierz;
    
public:

    Drone(Vector3D skala);

    Vector3D Trans_do_rodzica(const Vector3D & top) const;
    bool Lot_pionowy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool Lot_pioziomy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool Oblicz_wsp_glb_korpusa() const;
    bool Oblicz_wsp_glb_rotora() const;
    bool Oblicz_wsp_glb_drona() const;
    
};

bool Drone::Oblicz_wsp_glb_korpusa() const{
    
}