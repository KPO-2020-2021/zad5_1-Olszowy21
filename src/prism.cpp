#include "prism.hpp"






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
