#pragma once

#include "drone.hpp"

class Scene{

    std::vector <Drone> drony;

    PzG::LaczeDoGNUPlota Lacze;

public:

    Scene();

    ~Scene();

    Drone const avtive_drone() const;

    Drone use_avtive_drone();

};