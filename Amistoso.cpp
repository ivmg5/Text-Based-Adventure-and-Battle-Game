#include "Amistoso.hpp"
#include "Item.hpp"
#include <iostream>

// Constructor por defecto que inicializa estatus en falso, historia en blanco e item en nullptr
Amistoso::Amistoso() : Personaje(){
    estatus = false;
    historia = " ";
    item = nullptr;
}

// Constructor con todos los atributos que llama al constructor de Personaje y establece los atributos de Amistoso
Amistoso::Amistoso(std::string nombre, std::string descripcion, bool estatus, std::string historia, Item* item) : Personaje(nombre, descripcion){
    this->estatus = estatus;
    this->historia = historia;
    this->item = item;
}   

// Destructor
Amistoso::~Amistoso(){}

// Getter para el estatus
bool Amistoso::getEstatus() const{
    return estatus;
}   

// Getter para la historia
std::string Amistoso::getHistoria() const{
    return historia;
}

// Getter para el item
Item* Amistoso::getItem() const{
    return item;
}

// Setter para el estatus
void Amistoso::setEstatus(bool estatus){
    this->estatus = estatus;
}

// Setter para la historia
void Amistoso::setHistoria(std::string historia){
    this->historia = historia;
}

// Setter para el item
void Amistoso::setItem(Item* item){
    this->item = item;
}

// Implementación del método juega(). Si el estatus es verdadero, imprime la historia y detalles del item. Si no, imprime un mensaje de que el personaje no está dispuesto a hablar
int Amistoso::juega(){
    if(estatus) {
        std::cout << getNombre() << ": " << getHistoria() << std::endl;
        std::cout << "Item: " << getItem()->getNombre() << ", Puntos de Salud: " << getItem()->getPuntosOtorgados() << std::endl;
        return getItem()->getPuntosOtorgados();
    }
    else {
        std::cout << getNombre() << ": No estoy dispuesto a hablar" << std::endl;
        return 0;
    }
}

void Amistoso::recibeInteraccion(int valor){
    if (valor > 3){
        juega();
    } else {
        std::cout << getNombre() << " dormido" << std::endl;
    }
}