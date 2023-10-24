#ifndef MUNDO_HPP
#define MUNDO_HPP

#include <string>
#include "Personaje.hpp"
#include "Item.hpp"

class Mundo {
    private:
        std::string nombre; // Nombre del mundo
        Mundo* mundoSiguiente; // Puntero al siguiente mundo
        Item* item; // Puntero al item del mundo

    public:
        // Constructores y destructor
        Mundo();
        Mundo(std::string nombre, Mundo* mundoSiguiente, Item* item);
        ~Mundo();

        //Getters
        std::string getNombre() const;
        Mundo* getMundoSiguiente() const;
        Item* getItem() const;

        //Setters
        void setNombre(std::string nombre);
        void setMundoSiguiente(Mundo* mundoSiguiente);
        void setItem(Item* item);

        //Metodos
        void imprime() const;
};

#endif