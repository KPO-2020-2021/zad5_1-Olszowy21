#pragma once

#include "drone.hpp"

class Scene{

    std::vector<Drone> Pudlo_z_dronami;

    PzG::LaczeDoGNUPlota Lacze;

    unsigned int Numer_drona;

public:

    Scene();

    ~Scene();

    void Dodaj_drona(Drone dron, Vector3D skala, Vector3D polozenie, std::string Tablica_wzorcowych_plikow, std::string Tablica_animowanych_plikow );

    Drone const avtive_drone() const;

    Drone use_avtive_drone();

};