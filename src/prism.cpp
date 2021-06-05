#include "prism.hpp"

Prism::Prism(){

       for(int i = 0; i < 14; ++i ){
              top[i] = 0;
       }
       kat_do_globalnego = 0;
       skala = Vector3D(1, 1, 1);

}

Prism::Prism(Vector3D skala, Vector3D center, double promien, int index){

       Vector3D x(1.5*skala[0], 0, 0);
       Vector3D y(0, (6-sqrt(3))/2 * skala[1], 0);
       Vector3D z(0, 0, 1.125 * skala[2]);

       Vector3D x1(1*skala[0], 0, 0);
       Vector3D y1(0, sqrt(3)/2 * skala[1], 0);
       Vector3D z1(0, 0, 0.125 * skala[2]);

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

       top[0] = top[13] - z1;
       top[13] = z1;

       top[1] = top[1] - x1 - z1;
       top[2] = top[2] - x1*(1/2) - y1 - z1;
       top[3] = top[3] + x1*(1/2) - y1 - z1;
       top[4] = top[4] + x1 - z1;
       top[5] = top[5] + x1*(1/2) + y1 - z1;
       top[6] = top[6] - x1*(1/2) + y1 - z1;

       top[7] = top[7] - x1 + z1;
       top[8] = top[8] - x1*(1/2) - y1 + z1;
       top[9] = top[9] + x1*(1/2) - y1 + z1;
       top[10] = top[10] + x1 + z1;
       top[11] = top[11] + x1*(1/2) + y1 + z1;
       top[12] = top[12] - x1*(1/2) + y1 + z1;
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
void Prism::Zapis_do_pliku_wzorcowego(std::ofstream &out){
       
       out << top[0] + Polozenie << std::endl;
       out << top[1] + Polozenie << std::endl;
       out << top[2] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[3] + Polozenie << std::endl;
       out << top[4] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[5] + Polozenie << std::endl;
       out << top[6] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[7] + Polozenie << std::endl;
       out << top[8] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[9] + Polozenie << std::endl;
       out << top[10] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[11] + Polozenie << std::endl;
       out << top[12] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[1] + Polozenie << std::endl;
       out << top[2] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;
           

       // Jeszcze raz zapisujemy pierwszy punkt,
       // aby gnuplot narysowal zamkniętą linię.

       }

void Prism::Zapis_do_pliku_animowanego(std::ofstream &out){

       out << top[0] + Polozenie << std::endl;
       out << top[1] + Polozenie << std::endl;
       out << top[2] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[3] + Polozenie << std::endl;
       out << top[4] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[5] + Polozenie << std::endl;
       out << top[6] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[7] + Polozenie << std::endl;
       out << top[8] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[9] + Polozenie << std::endl;
       out << top[10] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[11] + Polozenie << std::endl;
       out << top[12] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;

       out << top[0] + Polozenie << std::endl;
       out << top[1] + Polozenie << std::endl;
       out << top[2] + Polozenie << std::endl
           << top[13] + Polozenie << std::endl << std::endl;
       
       // Jeszcze raz zapisujemy pierwszy punkt,
       // aby gnuplot narysowal zamkniętą linię.

}
