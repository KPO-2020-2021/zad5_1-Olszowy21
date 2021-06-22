#include "drone.hpp"



void Drone::inicjalizuj_drona(std::string anime_files[], std::string name_oryginal_cuboid, std::string name_oryginal_prism, Vector3D polozenie){
    
    this->Korpus.set_filename_anime(anime_files[0]);
    this->Rotor[0].set_filename_anime(anime_files[1]);
    this->Rotor[1].set_filename_anime(anime_files[2]);
    this->Rotor[2].set_filename_anime(anime_files[3]);
    this->Rotor[3].set_filename_anime(anime_files[4]);
    
    this->Polozenie = polozenie;

    Vector3D Pozycja_rotora0(-3, -6, 2.5);
    Vector3D Pozycja_rotora1(3, -6, 2.5);
    Vector3D Pozycja_rotora2(3, 6, 2.5);
    Vector3D Pozycja_rotora3(-3, 6, 2.5);

    Vector3D skala_cuboida(6, 12, 4);
    Vector3D skala_prisma(4, 4, 1);

    Korpus.inicjuj_cuboida(name_oryginal_cuboid, skala_cuboida, polozenie);

    Rotor[0].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora0);
    Rotor[1].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora1);
    Rotor[2].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora2);
    Rotor[3].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora3);

}

bool Drone::up_down(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    
    zmlucenie_drona_do_animacji();
    Lacze.Rysuj();
    int stan_bool = 0;
    Vector3D step_brother(0, 0, -2);

    if(dlugosc_lotu > 0){
        step_brother = step_brother + Polozenie;
        double droga = step_brother[2];

        for(int i = 0; i < droga; i+=2){
            
            if( ((i <= droga) <= MIN_DIFF ) && ((( i+2 ) >= droga) <= MIN_DIFF) ){
                droga = droga - i;
                Vector3D dokladka(0, 0, droga);
                Polozenie = Polozenie + dokladka;
                zmlucenie_drona_do_animacji();
                Lacze.Rysuj();
                stan_bool = 1;
            }
            else{
                Polozenie = Polozenie + step_brother;
            }
            usleep(100000);
            zmlucenie_drona_do_animacji();
            Lacze.Rysuj();
        }
        return stan_bool;
    
    }
    else{
        return stan_bool;
    }
    
}

bool Drone::forward_backward(double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){


    for(int i = 0; i < kat_obrotu; i+=2){
        
        Rotor[0].Miotaj(2);
        Rotor[1].Miotaj(-2);
        Rotor[2].Miotaj(2);
        Rotor[3].Miotaj(-2);
        kat_do_globalnego += 5;

        usleep(100000);
        zmlucenie_drona_do_animacji();
        Lacze.Rysuj();
    }

    Vector3D step_sister(0, 0, 5);

    for(int i = 0; i < dlugosc_lotu; i+=2){
    
        Rotor[0].Miotaj(2);
        Rotor[1].Miotaj(-2);
        Rotor[2].Miotaj(2);
        Rotor[3].Miotaj(-2);

        Polozenie = Polozenie + step_sister;

        usleep(100000);
        zmlucenie_drona_do_animacji();
        Lacze.Rysuj();
  }
}

void Drone::Maluj_rozklad_lotu(Vector3D sciezka_lotu[], std::string nazwa_pliku[], double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    
    double kaciwo = (kat_obrotu + kat_do_globalnego) * M_PI / 180;
    Vector3D wysokosc(0, 0, 100);
    Vector3D kierunek(cos(kaciwo)*dlugosc_lotu, sin(kaciwo)*dlugosc_lotu, 0);
    
    sciezka_lotu[0] = Polozenie;
    sciezka_lotu[1] = Polozenie + wysokosc;
    sciezka_lotu[2] = Polozenie + wysokosc + kierunek;
    sciezka_lotu[3] = Polozenie + kierunek;
    
    std::ofstream File_lot;
    File_lot.open(nazwa_pliku[5].c_str() , std::ios::trunc );

    if(File_lot.is_open()){
        for(int i =0; i < 4; ++i){
            File_lot << sciezka_lotu[i];
            Lacze.DodajNazwePliku(nazwa_pliku[5].c_str());
            Lacze.Rysuj();
        }
    }
    else{
        throw std::runtime_error("Plik nie istnieje / błąd pliku");
    }


}



Vector3D Drone::Skrobanie_do_rodzica(const Vector3D & top) const{
    
    Vector3D Wynik;
    Matrix3D macierz;

    macierz.obrot_z(kat_do_globalnego);

    Wynik = macierz * top;
    Wynik = Wynik + Polozenie;

    return Wynik;
}

void Drone::zmlucenie_drona_do_animacji(){
   
    ze_wzora_cuboida_do_animatora();
    ze_wzora_rotora_do_animatora(Rotor[0]);
    ze_wzora_rotora_do_animatora(Rotor[1]);
    ze_wzora_rotora_do_animatora(Rotor[2]);
    ze_wzora_rotora_do_animatora(Rotor[3]);

}


void Drone::ze_wzora_rotora_do_animatora( const Prism &rotorek ){
      
    Vector3D broker;

    std::ofstream anime;

    if(rotorek.Otworz_Plik_animowany(anime)){
        for(int i = 0; i < 6; ++i){
            broker = rotorek[0];
            broker = rotorek.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = rotorek[j + i*2];
                broker = rotorek.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
            }
            broker = rotorek[13];
            broker = rotorek.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = rotorek[0];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[1];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[2];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[13];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        rotorek.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("Plik nie istnieje / błąd pliku");
    }
}



void Drone::ze_wzora_cuboida_do_animatora(){

    Vector3D broker;

    std::ofstream anime;

    if(Korpus.Otworz_Plik_animowany(anime)){
        for(int i = 0; i < 4; ++i){
            broker = Korpus[0];
            broker = Korpus.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = Korpus[j + i*2];
                broker = Korpus.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
            }
            broker = Korpus[9];
            broker = Korpus.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = Korpus[0];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[1];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[2];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[9];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        Korpus.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku");
    }
}