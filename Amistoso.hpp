#ifndef AMISTOSO_HPP
#define AMISTOSO_HPP

#include <string>
#include "Personaje.hpp"
#include "Item.hpp"

// Clase Amistoso que hereda de la clase Personaje
class Amistoso : public Personaje {
    private:
        bool estatus; // Indica el estatus del personaje amistoso
        std::string historia; // Una cadena que describe la historia del personaje amistoso
        Item* item; // Puntero al objeto item que el personaje amistoso puede dar
        
    public:
        // Constructores y destructor
        Amistoso();
        Amistoso(std::string nombre, std::string descripcion, bool estatus, std::string historia, Item* item);
        ~Amistoso();

        //Getters
        bool getEstatus() const;
        std::string getHistoria() const;
        Item* getItem() const;

        //Setters
        void setEstatus(bool estatus);
        void setHistoria(std::string historia);
        void setItem(Item* item);

        //Metodos especificos de la clase Amistoso
        int juega() override;
        void recibeInteraccion(int valor) override;
};

#endif