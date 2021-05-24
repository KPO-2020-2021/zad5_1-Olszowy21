#pragma once

#include "block.hpp"


class Prism: public Block{

    Vector3D Polozenie;
    double Degree;

public:

    Vector3D Trans_do_rodzica(const Vector3D & top) const;
};