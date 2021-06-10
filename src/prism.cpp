#include "prism.hpp"


Prism::Prism(){

       kat_do_globalnego = 0;

       skala = Vector3D(1, 1, 1);

}

/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector<double, SIZE>& Prism::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector<double, SIZE>& Prism::operator [] (unsigned int index) const{
    return top[index];
}


void Prism::inicjuj_prism(std::string Filename_oryginal, Vector3D skala, Vector3D Polozenie, int index ){
    
    Vector3D broker;

    std::ifstream oryginal;

    const char* WSK_FILE = Filename_oryginal.c_str();

    set_skala(skala);

    oryginal.open(WSK_FILE, std::ios::in );

    if(oryginal.is_open()){
        while(true){
            int licznik = 1;                        // zmienna pomagająca poprawnie dodać dane do wiechrzołków
            for(int j = 0; j < 1; ++j){
                oryginal >> broker;
                if (oryginal.eof()) return;
                broker = skaluj(broker);
                top[j] = broker;

                for(int i = 0; i < 2; ++i){
                    oryginal >> broker;
                    broker = skaluj(broker);
                    top[licznik] = broker;
                }

                oryginal >> broker;
                broker = skaluj(broker);
                top[13] = broker;

                ++licznik;
            }

        }
    }


}