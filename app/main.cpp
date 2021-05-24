// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include "lacze_do_gnuplota.hh"
#include "exampleConfig.h"
#include <fstream>
#include "cuboid.hpp"
#include "matrix3d.hpp"
#include "vector3d.hpp"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK // zartowalem
            << std::endl;
  std::system("cat ../LICENSE");

  char x;
  //std::ofstream FILE;
  //Cuboid cuboid = Cuboid();
  //Vector3D Przesuniecie = Vector3D();
  //Matrix3D macierz;
  PzG::LaczeDoGNUPlota  Lacze;       // Ta zmienna jest potrzebna do wizualizacji
                                    // rysunku prostokata


  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.Inicjalizuj();
  
  Lacze.UstawZakresX(-10, 10);
  Lacze.UstawZakresY(-10, 10);
  Lacze.UstawZakresZ(-4, 4);

  Lacze.DodajNazwePliku("../datasets/cuboid.dat");
  Lacze.DodajNazwePliku("../datasets/scene.dat");

  Lacze.Rysuj();

  std::cin >> x;



}
