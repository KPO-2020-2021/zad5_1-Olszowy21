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
  //std::system("cat ../LICENSE");


  Drone *dronePtr;
  std::ofstream FILE;
  std::string File_name_anime[6];                    // 0 dla korpusu od 1 do 4 dla rotorów oraz 5 dla pliku do rysowania ścieżki lotu
  File_name_anime[0] = "../datasets/cuboid1.dat";
  File_name_anime[1] = "../datasets/rotor1.dat";
  File_name_anime[2] = "../datasets/rotor2.dat";
  File_name_anime[3] = "../datasets/rotor3.dat";
  File_name_anime[4] = "../datasets/rotor4.dat";
  File_name_anime[5] = "../datasets/rozklad_lotu.dat";

  std::string File_name_anime1[6];
  File_name_anime[0] = "../datasets/cuboid11.dat";
  File_name_anime[1] = "../datasets/rotor11.dat";
  File_name_anime[2] = "../datasets/rotor21.dat";
  File_name_anime[3] = "../datasets/rotor31.dat";
  File_name_anime[4] = "../datasets/rotor41.dat";
  File_name_anime[5] = "../datasets/rozklad_lotu.dat";

  std::string Cuboid_oryginal;
  std::string Prism_oryginal;
  Cuboid_oryginal = "../datasets/cuboid_oryginal.dat";
  Prism_oryginal = "../datasets/prism_oryginal.dat";
  
  Vector3D polozenie1(4, 4, 0);
  Vector3D polozenie2(30, 20, 0);

  Vector3D sciezka_lotu[4];

  PzG::LaczeDoGNUPlota  Lacze;        // Ta zmienna jest potrzebna do wizualizacji
                                      // rysunku drona

  Drone dron1, dron2;
  dron1.inicjalizuj_drona(File_name_anime, Cuboid_oryginal, Prism_oryginal, polozenie1, Lacze);
  //dron2.inicjalizuj_drona(File_name_anime1, Cuboid_oryginal, Prism_oryginal, polozenie2, Lacze);

  Scene Scena;

  Scena.Dodaj_drona(dron1);
  Scena.Dodaj_drona(dron2);
  dronePtr = Scena.use_avtive_drone();


  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.Inicjalizuj();

  Lacze.UstawZakresX(-10, 100);
  Lacze.UstawZakresY(-10, 100);
  Lacze.UstawZakresZ(0, 20);

  Lacze.Rysuj();

  std::cout<<"\n\t**********************MENU***********************"<<std::endl;
  std::cout<<"\ta - Wybierz aktywnego drona"<<std::endl;
  std::cout<<"\tp - zadaj parametry przelotu"<<std::endl;
  std::cout<<"\tm - wyswietl menu"<<std::endl<<std::endl;

  std::cout<<"\tk - koniec dzialania programu"<<std::endl;

  char x;
  std::cin >> x;

  while(x != 'k'){
      double kat;
      double odleglosc;
      Vector3D sciezka_lotu[4];
      std::cout<<"\nPolozenie aktywnego drona " << (*dronePtr).Get_polozeniex() << " " << (*dronePtr).Get_polozeniey() << std::endl << std::endl;

      std::cout<<"\tAktualna ilosc obiektow Wektor3D:"<< Vector3D::zwroc_aktywna_ilosc_wektorow() << std::endl;
      std::cout<<"\t  laczna ilosc obiektow Wektor3D:"<< Vector3D::zwroc_ogolna_ilosc_wektorow() <<  std::endl;

      std::cout<<"\nWybieram : ( m - menu ) > " << std::endl;


      std::cin>>x;
      switch (x){
      case 'm':
            std::cout<<"\n\t**********************MENU***********************"<<std::endl;
            std::cout<<"\ta - Wybierz aktywnego drona"<<std::endl;
            std::cout<<"\tp - zadaj parametry przelotu"<<std::endl;
            std::cout<<"\tm - wyswietl menu"<<std::endl<<std::endl;

            std::cout<<"\tk - koniec dzialania programu"<<std::endl;

            std::cin.ignore(10000, '\n');
            break;
      case 'a':

            std::cout<<"\tJaki dron wariacie"<<std::endl;

            std::cout<<"\t1 - Polozenie (x,y): " << (*dronePtr).Get_polozeniex() << " " << (*dronePtr).Get_polozeniey();
            if( Scena.index_aktywnego_drona() == 0){

              std::cout << "<---- aktywny dron\n";

            }

            std::cout<<"\t2 - Polozenie (x,y): " << (*dronePtr).Get_polozeniex() << " " << (*dronePtr).Get_polozeniey();
            if( Scena.index_aktywnego_drona() == 1){

              std::cout << "<---- aktywny dron\n";

            }

            std::cout << std::endl << "Wprowadź numer aktywnego drona>";
            int index;
            std::cin >> index;

            if(index > 0 && index <= ( Scena.index_aktywnego_drona() + 1)){
              Scena.avtive_drone(index);
              dronePtr = Scena.use_avtive_drone();
            }
            else{
              std::cout << std::endl << "Wprowadzano zły numer proszę podać poprawny";
              std::cin >> index;
              if(index > 0 && index <= ( Scena.index_aktywnego_drona() + 1)){
                Scena.avtive_drone(index);
                dronePtr = Scena.use_avtive_drone();
              }
              else{
                std::cout << std::endl << "";
              }
            }

            break;
      case 'p':
            std::cout << "Podaj kierunek lotu (kat w stopniach) > ";
            std::cin >> kat;
            std::cout  << "Podaj długość lotu > ";
            std::cin >> odleglosc;
            std::cout << "Rysuje zaplanowana sciezke lotu ..." << std::endl;
            (*dronePtr).Maluj_rozklad_lotu(sciezka_lotu, File_name_anime, kat, odleglosc, Lacze);

            break;
      case 'k':
            std::cout<<" Dziękuję za używanie mojego programu ;)"<<std::endl;

            break;
      default:
            std::cout<<" Niepoprawna operacja, symbol m to MENU"<<std::endl;

            break;
      }
  }
}
