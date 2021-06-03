#include "drone.hpp"


Drone::Drone(Vector3D skala){
    
    Polozenie = Vector3D(4, 4, 1);
    Korpus.set_skala(skala);
    Korpus = Cuboid(Polozenie, 4*skala[0], 6*skala[1], 2*skala[2]);
    Rotor[4] = Prism();
    Macierz = Matrix3D();

}

bool Lot_pionowy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    




}