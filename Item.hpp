#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
    private:
        std::string nombre; // Nombre del item
        int puntosOtorgados; // Puntos de salud que otorga el item
        
    public:
        // Constructores y destructor
        Item();
        Item(std::string nombre, int puntosOtorgados);
        ~Item();

        //Getters
        std::string getNombre() const;
        int getPuntosOtorgados() const;

        //Setters
        void setNombre(std::string nombre);
        void setPuntosOtorgados(int puntosOtorgados);

        //Metodos
        void imprime() const;
};

#endif