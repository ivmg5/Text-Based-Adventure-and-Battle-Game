#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>

class Personaje {
    private:
        std::string nombre; // Nombre del personaje
        std::string descripcion; // Descripción del personaje

    public:
        // Constructores y destructor
        Personaje();
        Personaje(std::string nombre, std::string descripcion);
        ~Personaje(); // Destructor

        // Getters
        std::string getNombre() const;
        std::string getDescripcion() const;

        // Setters
        void setNombre(std::string nombre);
        void setDescripcion(std::string descripcion);

        // Metodos
        bool estaVivo() const;
        int porcentajeSalud() const;
        void imprimeBarraVida() const;
        virtual void imprime() const;
        virtual int juega() = 0;
        virtual void recibeInteraccion(int valor) = 0;
};

#endif