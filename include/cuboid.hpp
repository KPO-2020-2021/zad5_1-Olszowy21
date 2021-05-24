#pragma once

#include "prism.hpp"



class Cuboid: public Block{

    Vector3D Polozenie;
    double Degree;

public:

    Vector3D Trans_do_rodzica(const Vector3D & top) const;
};

