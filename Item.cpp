#include "Item.hpp"
#include <iostream>

// Constructor por defecto que inicializa nombre con una cadena vacía y puntosOtorgados con 0
Item::Item(){
    nombre = " ";
    puntosOtorgados = 0;
}

// Constructor que establece los atributos del item
Item::Item(std::string nombre, int puntosOtorgados){
    this->nombre = nombre;
    this->puntosOtorgados = puntosOtorgados;
}

// Destructor
Item::~Item(){}

// Getter para el nombre
std::string Item::getNombre() const{
    return nombre;
}

// Getter para los puntos otorgados
int Item::getPuntosOtorgados() const{
    return puntosOtorgados;
}

// Setter para el nombre
void Item::setNombre(std::string nombre){
    this->nombre = nombre;
}

// Setter para los puntos otorgados
void Item::setPuntosOtorgados(int puntosOtorgados){
    this->puntosOtorgados = puntosOtorgados;
}

// Método para imprimir los atributos del item
void Item::imprime() const{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Puntos otorgados: " << puntosOtorgados << std::endl;
}