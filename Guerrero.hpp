#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include <string>
#include "Personaje.hpp"

// Clase Guerrero que hereda de la clase Personaje
class Guerrero : public Personaje {
    private:
        int puntosSaludTotales; // Puntos de salud total que tiene un Guerrero
        int puntosSaludActuales; // Puntos de salud que le quedan al Guerrero
        int maximoValorAtaque; // Valor máximo que puede tener un ataque del Guerrero
        
    public:
        // Constructores y destructor
        Guerrero();
        Guerrero(std::string nombre, std::string descripcion, int puntosSaludTotales, int puntosSaludActuales, int maximoValorAtaque);
        ~Guerrero();

        // Getters
        int getPuntosSaludTotales() const;
        int getPuntosSaludActuales() const;
        int getMaximoValorAtaque() const;

        // Setters
        void setPuntosSaludTotales(int puntosSaludTotales);
        void setPuntosSaludActuales(int puntosSaludActuales);
        void setMaximoValorAtaque(int maximoValorAtaque);

        // Métodos específicos de la clase Guerrero
        bool estaVivo() const;
        int porcentajeSalud() const;
        void imprimeBarraVida() const;
        virtual void imprime() const override;
        int juega() override;
        void recibeInteraccion(int valor) override;
        void recibeSalud(int valor);

        // Sobrecarga de operadores
        bool operator< (const Guerrero& g) const;
};

#endif