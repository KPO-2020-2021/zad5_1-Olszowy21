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

void add_file_names(std::string *anime){
  
  anime[0][0] = (char)"../datasets/cuboid1.dat";
  anime[0][1] = (char)"../datasets/rotor1.dat";
  anime[0][2] = (char)"../datasets/rotor2.dat";
  anime[0][3] = (char)"../datasets/rotor3.dat";
  anime[0][4] = (char)"../datasets/rotor4.dat";

  
}

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
  std::string File_name_anime[2][5];                    // [] pierwsze to dane do poszczególnego drona

  std::string Cuboid_oryginal = "../datasets/cuboid_oryginal.dat";
  std::string Prism_oryginal = "../datasets/prism_oryginal.dat";
  
  add_file_names( *File_name_anime );
  
  Vector3D polozenie1(4, 4, 0);
  Vector3D polozenie2(30, 20, 0);

  Vector3D skala(1, 1, 1);
  Drone dron(skala, polozenie1);
  Scene Scena;

  Scena.drony.push_back(dron);

  dron.get_cuboid().Otworz_Plik_animowany(FILE, File_name_anime[0][0] );
  if (dron.get_cuboid().Zapis_do_pliku_animowanego(FILE) == false){
    return 1;
  }
  dron.get_cuboid().Zamknij_Plik_animowany(FILE);

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
