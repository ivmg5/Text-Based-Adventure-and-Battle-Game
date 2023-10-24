#include "Mundo.hpp"
#include <iostream>

// Constructor por defecto que inicializa nombre con una cadena vacía, mundoSiguiente con nullptr y item con nullptr
Mundo::Mundo(){
    nombre = " ";
    mundoSiguiente = nullptr;
    item = nullptr;
}

// Constructor que establece los atributos del mundo
Mundo::Mundo(std::string nombre, Mundo* mundoSiguiente, Item* item){
    this->nombre = nombre;
    this->mundoSiguiente = mundoSiguiente;
    this->item = item;
}

// Destructor
Mundo::~Mundo(){}

// Getter para el nombre
std::string Mundo::getNombre() const{
    return nombre;
}

// Getter para el mundo siguiente
Mundo* Mundo::getMundoSiguiente() const{
    return mundoSiguiente;
}

// Getter para el item
Item* Mundo::getItem() const{
    return item;
}

// Setter para el nombre
void Mundo::setNombre(std::string nombre){
    this->nombre = nombre;
}

// Setter para el mundo siguiente
void Mundo::setMundoSiguiente(Mundo* mundoSiguiente){
    this->mundoSiguiente = mundoSiguiente;
}

// Setter para el item
void Mundo::setItem(Item* item){
    this->item = item;
}

// Método para imprimir los atributos del mundo. Si el mundo siguiente es nullptr, imprime "No hay Mundo siguiente." y si el item es nullptr, imprime "No hay Item en este mundo."
void Mundo::imprime() const{
    std::cout << "Nombre: " << nombre << std::endl;
    if(mundoSiguiente != nullptr){
        std::cout << "Mundo siguiente: " << mundoSiguiente->getNombre() << std::endl;
    }
    else {
        std::cout << "No hay Mundo siguiente." << std::endl;
    }
    if(item != nullptr){
        std::cout << "Item: " << item->getNombre() << std::endl;
    }
    else {
        std::cout << "No hay Item en este mundo." << std::endl;
    }
}