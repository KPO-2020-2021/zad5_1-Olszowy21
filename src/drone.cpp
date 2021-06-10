#include "drone.hpp"


void Drone::inicjalizuj_drona(std::string name_oryginal_cuboid, std::string name_oryginal_prism, Vector3D skala, Vector3D polozenie){
    
    this->Polozenie = polozenie;

    Vector3D Pozycja_rotora0(-3, -6, 2.5);
    Vector3D Pozycja_rotora1(3, -6, 2.5);
    Vector3D Pozycja_rotora2(3, 6, 2.5);
    Vector3D Pozycja_rotora3(-3, 6, 2.5);

    Vector3D skala_cuboida(6, 12, 4);
    Vector3D skala_prisma(4, 4, 1);

    Korpus.inicjuj_cuboida(name_oryginal_cuboid, skala_cuboida, polozenie);

    Rotor[0].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora0, 0);
    Rotor[1].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora1, 1);
    Rotor[2].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora2, 2);
    Rotor[3].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora3, 3);

}

bool Drone::up_down(double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    
    zmlucenie_drona_do_animacji();

    if(dlugosc_lotu < 0){
        Vector3D step_brother(0, 0, -2);
        step_brother = step_brother + Polozenie;
        double droga = step_brother[2];

        for(int i = 0; i < droga; i+=2){
            
            if( ((i <= droga) <= MIN_DIFF ) && ((( i+2 ) >= droga) <= MIN_DIFF) ){
                droga = droga - i;
                Vector3D dokladka(0, 0, droga);
                Polozenie = Polozenie + dokladka;
                return true;
            }
            else{
                Polozenie = Polozenie + step_brother;
            }
        }

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

    for(int i = 0; i < 4; ++i){

        ze_wzora_rotora_do_animatora(Rotor[i]);

    }

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
            for(int j = 1; j < 3; ++j){
                broker = rotorek[j + i*2];
                broker = rotorek.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
            }
            broker = rotorek[13];
            broker = rotorek.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
        }
        broker = rotorek[0];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = rotorek[1];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = rotorek[2];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = rotorek[13];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;

        rotorek.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku");
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
            for(int j = 1; j < 3; ++j){
                broker = Korpus[j + i*2];
                broker = Korpus.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
            }
            broker = Korpus[9];
            broker = Korpus.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
        }
        broker = Korpus[0];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = Korpus[1];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = Korpus[2];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        broker = Korpus[9];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;

        Korpus.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku");
    }
}