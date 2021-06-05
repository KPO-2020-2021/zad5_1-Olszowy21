#include "block.hpp"


bool Block::Otworz_Plik_wzorcowy(std::ofstream &out, std::string File_name){

        File_name = get_filename_standard();

        const char* WSK_FILE = File_name.c_str();

        out.open(WSK_FILE, std::ios::trunc);

        if (!out.is_open())  {
            std::cerr << ":(  Operacja otwarcia do zapisu \"" << WSK_FILE << "\"" << std::endl
            << ":(  nie powiodla sie." << std::endl;
            return false;
        }
        return true;
    }

void Block::Zamknij_Plik_wzorcowy(std::ofstream &out){

    out.close();

}

bool Block::Otworz_Plik_animowany(std::ofstream &out, std::string File_name){

       File_name = get_filename_anime();


       const char* WSK_FILE = File_name.c_str();

       out.open(WSK_FILE, std::ios::trunc);

       if (!out.is_open())  {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << WSK_FILE << "\"" << std::endl
              << ":(  nie powiodla sie." << std::endl;
              return false;
       }
}

void Block::Zamknij_Plik_animowany(std::ofstream &out){

    out.close();

}