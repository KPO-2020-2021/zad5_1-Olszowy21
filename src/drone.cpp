#include "drone.hpp"


Drone::Drone(Vector3D skala){
    
    Polozenie = Vector3D(4, 4, 1);
    Korpus.set_skala(skala);
    Korpus = Cuboid(Polozenie, 4*skala[0], 6*skala[1], 2*skala[2]);
    for(int i=0; i < 4; ++i){
        Rotor[i] = Prism(skala, Polozenie, 1*skala[0], i);
    }
    Rotor->set_skala(skala);
    
    Macierz = Matrix3D();

}

bool otworz_pliki_zapisu() const{
    
}

bool Lot_pionowy(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    




}