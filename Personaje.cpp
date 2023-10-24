#include "Personaje.hpp"
#include <iostream>

// Constructor por defecto que nicializa nombre y descripción con cadenas vacías
Personaje::Personaje(){
    nombre = " ";
    descripcion = " ";
}

// Constructor que establece los atributos del personaje
Personaje::Personaje(std::string nombre, std::string descripcion){
    this->nombre = nombre;
    this->descripcion = descripcion;
}

// Destructor
Personaje::~Personaje(){}  

// Getter para el nombre
std::string Personaje::getNombre() const{
    return nombre;
}

// Getter para la descripción
std::string Personaje::getDescripcion() const{
    return descripcion;
}

// Setter para el nombre
void Personaje::setNombre(std::string nombre){
    this->nombre = nombre;
}

// Setter para la descripción
void Personaje::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
}

// Método para determinar si el personaje está vivo. Como la clase base no tiene un atributo de salud, se sobrecarga en clases derivadas que tengan salud.
bool Personaje::estaVivo() const{
    return true;
}

// Método para obtener el porcentaje de salud del personaje. Como la clase base no tiene un atributo de salud, se sobrecarga en clases derivadas que tengan salud.
int Personaje::porcentajeSalud() const{
    return 0;
}

// Método para imprimir la barra de vida del personaje. Como la clase base no tiene un atributo de salud, se sobrecarga en clases derivadas que tengan salud.
void Personaje::imprimeBarraVida() const{
    std::cout << "No hay barra de vida" << std::endl;
}

// Método para imprimir la información del personaje. Imprime el nombre y la descripción del personaje.
void Personaje::imprime() const{
    std::cout << "Nombre del personaje de este mundo: " << nombre << std::endl;
    std::cout << "Descripcion del personaje: " << descripcion << std::endl;
}