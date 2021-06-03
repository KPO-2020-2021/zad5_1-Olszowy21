#include "prism.hpp"


Prism::Prism(Vector3D skala, Vector3D center, double promien, int index){

       Vector3D x(1.5*skala[0], 0, 0);
       Vector3D y(0, (6-sqrt(3))/2 * skala[1], 0);
       Vector3D z(0, 0, 1 * skala[2]);

       if(index == 0){
              Polozenie = center - x - y + z;
              
       }

       else if(index == 1){
              Polozenie = center + x - y + z;
              
       }

       else if(index == 2){
              Polozenie = center - x + y + z;
              
       }

       else if(index == 3){
              Polozenie = center + x + y + z;
              
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
bool Prism::ZapisWspolrzednychDoPliku()
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
  
    Vector3D krzyz1, krzyz2;

    krzyz1;
    krzyz2 = (top[1] + top[5]) * 0.5;

    StrmWy << krzyz1 << std::endl;
    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl
           << krzyz2 << std::endl << std::endl;

    StrmWy << krzyz1 << std::endl;
    StrmWy << top[2] << std::endl;
    StrmWy << top[3] << std::endl
           << krzyz2 << std::endl << std::endl;

    StrmWy << krzyz1 << std::endl;
    StrmWy << top[4] << std::endl;
    StrmWy << top[5] << std::endl
           << krzyz2 << std::endl << std::endl;

    StrmWy << krzyz1 << std::endl;
    StrmWy << top[6] << std::endl;
    StrmWy << top[7] << std::endl
           << krzyz2 << std::endl << std::endl;

    StrmWy << krzyz1 << std::endl;
    StrmWy << top[0] << std::endl;
    StrmWy << top[1] << std::endl
           << krzyz2 << std::endl << std::endl;

                                // Jeszcze raz zapisujemy pierwszy punkt,
                                // aby gnuplot narysowal zamkniętą linię.

    StrmWy.close();
    return !StrmWy.fail();
}
