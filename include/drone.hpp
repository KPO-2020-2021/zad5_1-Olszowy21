#pragma once

#include "cuboid.hpp"

class Drone{
protected:

    Vector3D Polozenie;

    Cuboid Korpus;

    Prism Rotor[4];

    Matrix3D Macierz;

    double kat_do_globalnego;
    
public:

    void inicjalizuj_drona(std::string name_oryginal_cuboid, std::string name_oryginal_prism  ,Vector3D skala, Vector3D polozenie);

    Cuboid get_cuboid() const {return *&Korpus;};
    
    Prism get_prism(unsigned int index) const {return Rotor[index];};

    void zmlucenie_drona_do_animacji();

    void ze_wzora_rotora_do_animatora( const Prism &rotorek );

    void ze_wzora_cuboida_do_animatora();

    Vector3D Skrobanie_do_rodzica(const Vector3D & top) const;

    Vector3D Trans_do_rodzica(const Vector3D & top) const;
    bool up_down(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool forward_backward(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);
    bool Oblicz_wsp_glb_korpusu() const;
    bool Oblicz_wsp_glb_rotora() const;
    bool Oblicz_wsp_glb_drona() const;

    
};

bool Drone::Oblicz_wsp_glb_korpusu() const{

}