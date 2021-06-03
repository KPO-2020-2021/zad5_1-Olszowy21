#include "cuboid.hpp"


/*!
 * Przeciazenie operatora wypisywania na ekran.
 * \param[in] out - strumien wyjsciowy, z ktorego maja zostac wpisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Cuboid z ktorej bedzie wypisywane
 *                     wspolrzedne na ekran.
 * 
 */
std::ostream &operator << (std::ostream &out, Cuboid const &tmp){

    for(unsigned int i = 0; i < SIZE+7; ++i){
        out << i + 1 << " Wiechołek prostokąta - " << tmp[i] << std::endl;
    }
    return out;
}

/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector<double, SIZE>& Cuboid::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector<double, SIZE>& Cuboid::operator [] (unsigned int index) const{
    return top[index];
}

/*!
 * Konstruktor dla prostopadłościanu z przypadkowymi wartościami.
 *
 * 
 * 
 */
// Cuboid::Cuboid(){

//     Polozenie = Vector<double, SIZE>(2, 3, 1);

//     top[0] = Vector<double, SIZE>(2, 3, 3);
//     top[1] = Vector<double, SIZE>(2, 3, 3);
//     top[2] = Vector<double, SIZE>(22, 3, 3);
//     top[3] = Vector<double, SIZE>(2, 18, 3);
//     top[4] = Vector<double, SIZE>(22, 18, 3);
//     top[5] = Vector<double, SIZE>(2, 18, 28);
//     top[6] = Vector<double, SIZE>(22, 18, 28);
//     top[7] = Vector<double, SIZE>(2, 3, 28);
//     top[8] = Vector<double, SIZE>(22, 3, 28);
//     top[9] = Vector<double, SIZE>(2, 3, 3);

// }

Cuboid::Cuboid(double dlugosc, double szerokosc, double wysokosc, Vector3D centrum){
    
    Polozenie = centrum;
    Vector3D x(dlugosc*(1/2), 0, 0);
    Vector3D y(0, szerokosc*(1/2), 0);
    Vector3D z(0, 0, wysokosc*(1/2));

    top[0] = centrum - x;
    top[9] = centrum + x;

    top[1] = centrum - x - y - z;
    top[2] = centrum + x - y - z;

    top[3] = centrum - x + y - z;
    top[4] = centrum + x + y - z;

    top[5] = centrum - x + y + z;
    top[6] = centrum + x + y + z;


    top[7] = centrum - x - y + z;
    top[8] = centrum + x - y + z;

}

/*!
 * Konstruktor dla prostopadłościanu z przychodzącymi wartościami.
 * \param[in] first - wektor 1 dla prostopadłościanu. 
 * \param[in] second - wektor 2 dla prostopadłościanu. 
 * \param[in] third - wektor 3 dla prostopadłościanu. 
 * \param[in] fourth - wektor 4 dla prostopadłościanu. 
 * \param[in] fifth - wektor 5 dla prostopadłościanu. 
 * \param[in] sixth - wektor 6 dla prostopadłościanu. 
 * \param[in] seventh - wektor 7 dla prostopadłościanu. 
 * \param[in] eigth - wektor 8 dla prostopadłościanu. 
 * 
 */
// Cuboid::Cuboid( Vector<double, SIZE> first, Vector<double, SIZE> second, Vector<double, SIZE> third, Vector<double, SIZE> fourth,
//                 Vector<double, SIZE> fifth, Vector<double, SIZE> sixth,  Vector<double, SIZE> seventh, Vector<double, SIZE> eigth, Vector3D centrum ){
    
//     top[0] = first;
//     top[1] = second;
//     top[2] = third;
//     top[3] = fourth;
//     top[4] = fifth;
//     top[5] = sixth;
//     top[6] = seventh;
//     top[7] = eigth;

//     Polozenie = centrum;

// }


/*!
 * Realizuje porownanie dwoch prostokatow ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa prostokata sprawdzanego z prostokatem zawartym wewnatrz klasy
 * 
 * \retval true - gdy oba sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
bool Cuboid::operator == (const Cuboid &tmp) const{

    for(unsigned int i = 0; i < SIZE+7; ++i){
        if(!(this->top[i] == tmp.top[i])){
            return false;
        }
    }
    return true;
}


/*!
 * Metoda przesuwania punktow szczegolnych figury o zadany wektor.
 * \param[in] tmp - nazwa wektora która przysluzy się do przesuniecia punktow prostokata
 *                         
 */
void Cuboid::Kicking_Cuboid(const Vector<double, SIZE> &tmp){
    
    for(unsigned int i=0; i<SIZE+7; ++i){

        top[i] = top[i] + tmp;

    }

    Polozenie = Polozenie + tmp;
}

/*!
 * Metoda obracania punktow szczegolnych figury.
 * \param[in] tmp - nazwa macierzy która przysłuży się do obracania punktow prostokata
 *                         
 */
void Cuboid::throwing_Cuboid(const Matrix<double, SIZE> &tmp){
    
    for(unsigned int i=0; i<SIZE+7; ++i){

        top[i] = tmp * top[i];

    }
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] File_name - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * 
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Cuboid::Zapis_Do_Pliku_wzorcowego()
{
    std::ofstream  StrmWy;
    std::string File_name;

    File_name = get_filename_standard();


    const char* WSK_FILE = File_name.c_str();

    StrmWy.open(WSK_FILE, std::ios::trunc);

    if (!StrmWy.is_open())  {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << WSK_FILE << "\"" << std::endl
        << ":(  nie powiodla sie." << std::endl;
        return false;
    }
  
    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl;
    StrmWy << top[2] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[3] << std::endl;
    StrmWy << top[4] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[5] << std::endl;
    StrmWy << top[6] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[7] << std::endl;
    StrmWy << top[8] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl;
    StrmWy << top[2] << std::endl
           << top[9] << std::endl << std::endl;

                                // Jeszcze raz zapisujemy pierwszy punkt,
                                // aby gnuplot narysowal zamkniętą linię.

    StrmWy.close();
    return !StrmWy.fail();
}

bool Cuboid::Zapis_Do_Pliku_animowanego()
{
    std::ofstream  StrmWy;
    std::string File_name;

    File_name = get_filename_anime();


    const char* WSK_FILE = File_name.c_str();

    StrmWy.open(WSK_FILE, std::ios::trunc);

    if (!StrmWy.is_open())  {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << WSK_FILE << "\"" << std::endl
        << ":(  nie powiodla sie." << std::endl;
        return false;
    }
  
    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl;
    StrmWy << top[2] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[3] << std::endl;
    StrmWy << top[4] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[5] << std::endl;
    StrmWy << top[6] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[7] << std::endl;
    StrmWy << top[8] << std::endl
           << top[9] << std::endl << std::endl;

    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl;
    StrmWy << top[2] << std::endl
           << top[9] << std::endl << std::endl;

                                // Jeszcze raz zapisujemy pierwszy punkt,
                                // aby gnuplot narysowal zamkniętą linię.

    StrmWy.close();
    return !StrmWy.fail();
}



/*!
 * Metoda sprawdzania dlugosci przeciwleglych bokow aktualnej figury
 * znajdujacej sie w klasie cuboid ( prostopadłościanu ).
 *  
 * \retval pozytywne lub negatywne emotki z wiadomością o długościach boków.                
 */
void Cuboid::length_of_the_sides(int index){
    


    double side1;   //
                    //
    double side2;   //                                  side7                 
                    //          top7 ---> *------------------------------* <--- top5                ----|          
    double side3;   //                    |                              |                              |
                    //                   ||                             ||                              |  
    double side4;   //                  | | <--- side9                 | |                              | <--- side12 
                    //      side4 ---> |  |                side3 ---> |  |                              |
    double side5;   //                |   |           side5          |   |                              |
                    //         top1 -|--> *-------------------------|----* <--- top3                ----|
    double side6;   //              |    |        side8            |    |                             
                    //   top8 ---> *----|-------------------------* <--|- top6                      ----|
    double side7;   //             |   | <--- side1               |   | <--- side2                      |
                    // side10 ---> |  |                           |  |                                  | <--- side11
    double side8;   //             | |                            | |                                   |
                    //             ||                             ||                                    |
    double side9;   //   top2 ---> *------------------------------* <--- top4                       ----|
                    //                          side6
    double side10;  //
                    //
    double side11;  //
                    //
    double side12;  //


    side1 = sqrt( pow( std::abs(top[1][0] - top[0][0]),2)  +  pow( std::abs(top[1][1] - top[0][1]),2) + pow( std::abs(top[1][2] - top[0][2]),2));

    side2 = sqrt( pow( std::abs(top[3][0] - top[2][0]),2)  +  pow( std::abs(top[3][1] - top[2][1]),2) + pow( std::abs(top[3][2] - top[2][2]),2));

    side3 = sqrt( pow( std::abs(top[5][0] - top[4][0]),2)  +  pow( std::abs(top[5][1] - top[4][1]),2) + pow( std::abs(top[5][2] - top[4][2]),2));

    side4 = sqrt( pow( std::abs(top[7][0] - top[6][0]),2)  +  pow( std::abs(top[7][1] - top[6][1]),2) + pow( std::abs(top[7][2] - top[6][2]),2));

    side5 = sqrt( pow( std::abs(top[2][0] - top[0][0]),2)  +  pow( std::abs(top[2][1] - top[0][1]),2) + pow( std::abs(top[2][2] - top[0][2]),2));

    side6 = sqrt( pow( std::abs(top[3][0] - top[1][0]),2)  +  pow( std::abs(top[3][1] - top[1][1]),2) + pow( std::abs(top[3][2] - top[1][2]),2));

    side7 = sqrt( pow( std::abs(top[6][0] - top[4][0]),2)  +  pow( std::abs(top[6][1] - top[4][1]),2) + pow( std::abs(top[6][2] - top[4][2]),2));

    side8 = sqrt( pow( std::abs(top[7][0] - top[5][0]),2)  +  pow( std::abs(top[7][1] - top[5][1]),2) + pow( std::abs(top[7][2] - top[5][2]),2));

    side9 = sqrt( pow( std::abs(top[6][0] - top[0][0]),2)  +  pow( std::abs(top[6][1] - top[0][1]),2) + pow( std::abs(top[6][2] - top[0][2]),2));

    side10 = sqrt( pow( std::abs(top[7][0] - top[1][0]),2)  +  pow( std::abs(top[7][1] - top[1][1]),2) + pow( std::abs(top[7][2] - top[1][2]),2));

    side11 = sqrt( pow( std::abs(top[5][0] - top[3][0]),2)  +  pow( std::abs(top[5][1] - top[3][1]),2) + pow( std::abs(top[5][2] - top[3][2]),2));

    side12 = sqrt( pow( std::abs(top[4][0] - top[2][0]),2)  +  pow( std::abs(top[4][1] - top[2][1]),2) + pow( std::abs(top[4][2] - top[2][2]),2));


    if((std::abs(side5 - side8) <= MIN_DIFF) && (std::abs(side6 - side7) <= MIN_DIFF)){
        std::cout <<"\n :)  Krotsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side8 << std::endl;
    }
    else{
        std::cout <<"\n :/  Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side8 << std::endl;
    }

    if((std::abs(side1 - side3) <= MIN_DIFF) && (std::abs(side2 - side4) <= MIN_DIFF)){
        std::cout <<"\n :)  Poprzeczne przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side4 << std::endl;
    }
    else{
        std::cout <<"\n :/   Poprzeczne przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side4 << std::endl;
    }

    if((std::abs(side9 - side11) <= MIN_DIFF) && (std::abs(side10 - side12) <= MIN_DIFF)){
        std::cout <<"\n :)  Dluzsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }
    else{
        std::cout <<"\n :/  Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }
}
