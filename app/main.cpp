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
#include "scene.hpp"
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
  std::ofstream FILE;
  std::string File_name_anime[6];                    // 0 dla korpusu od 1 do 4 dla rotorów oraz 5 dla pliku do rysowania ścieżki lotu
  File_name_anime[0] = "../datasets/cuboid1.dat";
  File_name_anime[1] = "../datasets/rotor1.dat";
  File_name_anime[2] = "../datasets/rotor2.dat";
  File_name_anime[3] = "../datasets/rotor3.dat";
  File_name_anime[4] = "../datasets/rotor4.dat";
  File_name_anime[5] = "../datasets/rozklad_lotu.dat";

  std::string Cuboid_oryginal;
  std::string Prism_oryginal;
  Cuboid_oryginal = "../datasets/cuboid_oryginal.dat";
  Prism_oryginal = "../datasets/prism_oryginal.dat";
  
  Vector3D polozenie1(4, 4, 0);
  Vector3D polozenie2(30, 20, 0);

  Vector3D sciezka_lotu[4];

  Drone dron;
  dron.inicjalizuj_drona(File_name_anime, Cuboid_oryginal, Prism_oryginal, polozenie1);

  Scene Scena;

  //Scena.drony.push_back(dron);


  PzG::LaczeDoGNUPlota  Lacze;        // Ta zmienna jest potrzebna do wizualizacji
                                      // rysunku drona


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
