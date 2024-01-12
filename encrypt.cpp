#include "encrypt.h"
#include <fstream>
#include <sstream>

std::string Encrypt::plain() const {
    return _plain;
}

std::string Encrypt::cipher() const {
    return _cipher;
}

void Encrypt::read(std::string file, FileContent content) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        if(content==PLAIN){
          _plain = buffer.str();
        }
        else if(content==CIPHER){
          _cipher = buffer.str();
        }
        else{
          std::cerr << "Error: Valeur du contenu non valide." << file << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file for reading - " << file << std::endl;
    }
}

void Encrypt::write(std::string file, FileContent content) {
    std::ofstream outputFile(file);
    if (outputFile.is_open()) {
        if(content==PLAIN){
          outputFile << _plain;
        }
        else if(content==CIPHER){
          outputFile << _cipher;
        }
        else{
          std::cerr << "Error: Valeur du contenu non valide." << file << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing - " << file << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Encrypt& enc){
  os << "Valeur a encrypte: " << enc.plain() << std::endl;
  os << "Valeur a encrypte: " << enc.cipher() << std::endl;
  return os;
}