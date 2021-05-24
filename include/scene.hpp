#pragma once

#include "drone.hpp"

class Scene{

    std::vector <Drone> drony;

    std::vector <Matrix3D> macierze;

    std::vector <Vector3D> wektory;
    
    PzG::LaczeDoGNUPlota Lacze;

public:

    Drone const avtive_drone() const;
    Drone use_avtive_drone();

};