#include "Guerrero.hpp"
#include <random>
#include <iostream>

// Constructor por defecto que inicializa los atributos de Guerrero a 0
Guerrero::Guerrero() : Personaje(){
    puntosSaludTotales = 0;
    puntosSaludActuales = 0;
    maximoValorAtaque = 0;
}

// Constructor con todos los atributos que llama al constructor de Personaje y establece los atributos de Guerrero
Guerrero::Guerrero(std::string nombre, std::string descripcion, int puntosSaludTotales, int puntosSaludActuales, int maximoValorAtaque) : Personaje(nombre, descripcion){
    this->puntosSaludTotales = puntosSaludTotales;
    this->puntosSaludActuales = puntosSaludActuales;
    this->maximoValorAtaque = maximoValorAtaque;
}

// Destructor
Guerrero::~Guerrero(){}

// Getter para los puntos de salud totales
int Guerrero::getPuntosSaludTotales() const{
    return puntosSaludTotales;
}

// Getter para los puntos de salud actuales
int Guerrero::getPuntosSaludActuales() const{
    return puntosSaludActuales;
}

// Getter para el máximo valor de ataque
int Guerrero::getMaximoValorAtaque() const{
    return maximoValorAtaque;
}

// Setter para los puntos de salud totales
void Guerrero::setPuntosSaludTotales(int puntosSaludTotales){
    this->puntosSaludTotales = puntosSaludTotales;
}

// Setter para los puntos de salud actuales
void Guerrero::setPuntosSaludActuales(int puntosSaludActuales){
    this->puntosSaludActuales = puntosSaludActuales;
}

// Setter para el máximo valor de ataque
void Guerrero::setMaximoValorAtaque(int maximoValorAtaque){
    this->maximoValorAtaque = maximoValorAtaque;
}

// Método para determinar si el guerrero está vivo
bool Guerrero::estaVivo() const{
    if(puntosSaludActuales > 0){
        return true;
    }else{
        return false;
    }
}

// Método para obtener el porcentaje de salud del guerrero
int Guerrero::porcentajeSalud() const{
    int porcentaje = (puntosSaludActuales * 100) / puntosSaludTotales;
    return porcentaje;
}

// Método para imprimir la barra de vida del guerrero
void Guerrero::imprimeBarraVida() const{
    int porcentaje = porcentajeSalud();
    int vida = porcentaje / 5;
    int perdida = 20 - vida;
    std::cout << "Vida de " << getNombre() << ": ";
    for (int i = 0; i < vida; ++i) {
        std::cout << "%";
    }
    for (int i = 0; i < perdida; ++i) {
        std::cout << "=";
    }
    std::cout << " " << porcentaje << "%" << std::endl;
}

// Método para imprimir los atributos del guerrero
void Guerrero::imprime() const{
    Personaje::imprime();
    std::cout << "Puntos de salud totales: " << puntosSaludTotales << std::endl;
    std::cout << "Puntos de salud actuales: " << puntosSaludActuales << std::endl;
    std::cout << "Maximo valor de ataque: " << maximoValorAtaque << std::endl;
    imprimeBarraVida();
}

// Método para realizar un ataque. Genera un valor de ataque aleatorio y lo imprime.
int Guerrero::juega(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, maximoValorAtaque);
    int ataque = distrib(gen);
    std::cout << getNombre() << " ataca con " << ataque << " puntos de ataque" << std::endl;
    return ataque;
}

// Método para recibir daño. Resta el valor de daño a los puntos de salud actuales.
void Guerrero::recibeInteraccion(int valor){
    puntosSaludActuales -= valor;
    if (puntosSaludActuales < 0) {
        puntosSaludActuales = 0;
    }
    std::cout << getNombre() << " recibió " << valor << " de daño" << std::endl;
    if (estaVivo()) {
        imprimeBarraVida();
    } else {
        imprimeBarraVida();
        std::cout << getNombre() << " ha muerto" << std::endl;
    }
}

// Método para recibir salud. Suma el valor de salud a los puntos de salud actuales, sin superar los puntos de salud totales.
void Guerrero::recibeSalud(int valor){
    puntosSaludActuales += valor;
    if (puntosSaludActuales > puntosSaludTotales) {
        puntosSaludActuales = puntosSaludTotales;
    }
    std::cout << getNombre() << " recibió " << valor << " de salud" << std::endl;
    imprimeBarraVida();
}

// Sobrecarga del operador < para comparar si los puntos de salud actuales de este Guerrero son menores que los del otro Guerrero
bool Guerrero::operator< (const Guerrero& g) const {
    return puntosSaludActuales < g.puntosSaludActuales;
}