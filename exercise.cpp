#include <iostream>
#include <vector>
#include <random>
#include "Personaje.hpp"
#include "Amistoso.hpp"
#include "Guerrero.hpp"
#include "Mundo.hpp"
#include "Item.hpp"
using namespace std;

int main()
{
    // Crear objetos de tipo Item para ser utilizados por los personajes
    Item *item1 = new Item("Espada ⚔", 10);
    Item *item2 = new Item("Escudo 🛡 ", 20);
    Item *item3 = new Item("Poción 🧪", 30);
    Item *item4 = new Item("Arco 🏹", 40);
    vector<Item*> items = {item1, item2, item3, item4};
    
    // Generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, items.size() - 1);

    // Crear personajes que serán parte del juego, algunos son Amistosos y otros son Guerreros
    Personaje* p2 = new Amistoso("April", "Amistoso", false, "Hola!", items[distr(gen)]);
    Personaje* p3 = new Amistoso("Ana", "Amistoso", true, "Hola! Que gusto verte por aquí, tienes que tener mucho cuidado al navegar por estos mundos, no sabes contra quien puedes batallar, te voy a regalar algo que creo que te puede servir :)", items[distr(gen)]);
    Personaje* p1 = new Guerrero("Noe", "Guerrero", 100, 100, 10);
    Personaje* p4 = new Guerrero("Marco", "Guerrero", 100, 100, 10);
    vector<Personaje*> personajes = {p1, p2, p3, p4};

    // Crear distintos mundos donde se desarrollará el juego, cada uno tiene un objeto de Item
    Mundo* mundo1 = new Mundo("la tierra del terror", nullptr, items[distr(gen)]);
    Mundo* mundo2 = new Mundo("en los prados del valle", mundo1, items[distr(gen)]);
    Mundo* mundo3 = new Mundo("el lago encantado", mundo2, items[distr(gen)]);
    Mundo* mundo4 = new Mundo("atrapado en el ultimo mundo", mundo3, items[distr(gen)]);
    vector<Mundo*> mundos = {mundo1, mundo2, mundo3, mundo4};

    cout << "Bienvenido al juego" << endl;

    // Pedir al usuario que ingrese el nombre del personaje principal, usando un bucle do-while para la validación del nombre
    string nombreDelJugador;
    string next;
    bool nombreValido = false;

    do {
        try {
            cout << "Introduce el nombre de tu personaje: ";
            getline(cin, nombreDelJugador);

            if (nombreDelJugador.empty()) {
                throw runtime_error("El nombre del jugador no puede estar vacío");
            }
            if (nombreDelJugador.length() > 15) {
                throw runtime_error("El nombre del jugador no puede ser más largo de 15 caracteres");
            }
            // Si no se lanza ninguna excepción, el nombre es válido
            nombreValido = true;
        }
        // Captura de cualquier excepción lanzada y mostrar el mensaje de error
        catch (const std::exception& e) {
            cerr << "Se produjo un error: " << e.what() << endl;
        }
    } while (!nombreValido); // repetir hasta que se introduzca un nombre válido

    Guerrero jugador(nombreDelJugador, "Guerrero", 100, 100, 60);

    // Recorrer cada mundo, enfrentando al jugador con un personaje en cada uno
    string comienzo;

    do {
    cout << "Teclea la letra c para comenzar: ";
    getline (cin, comienzo);

        if (comienzo == "c"){

            jugador.imprimeBarraVida();

            for (int i = 0; i < mundos.size(); ++i){
                Mundo* mundoActual = mundos[i];
                Personaje* personajeActual = personajes[i];
                cout << "-----------------------------------------" << endl;
                cout << "Estás en " << mundoActual->getNombre() << endl;
                personajeActual->imprime();

                // Verificar si el personaje actual es un Guerrero
                Guerrero* guerreroActual = dynamic_cast<Guerrero*>(personajeActual);
                if (guerreroActual){
                    // Si el personaje es un Guerrero, iniciar una batalla con el jugador
                    // La batalla continúa mientras ambos, el jugador y el Guerrero, estén vivos
                    while (jugador.estaVivo() && guerreroActual->estaVivo()){
                        int valorInteraccion = guerreroActual->juega();
                        jugador.recibeInteraccion(valorInteraccion);

                        // Comprobar la salud del jugador y del Guerrero actual después de cada interacción
                        if(jugador < *guerreroActual) {
                            cout << "Tienes menos salud que " << guerreroActual->getNombre() << endl;
                            cout << "-----------------------------------------" << endl;
                        } else {
                            cout << "Tienes más salud que " << guerreroActual->getNombre() << endl;
                            cout << "-----------------------------------------" << endl;
                        }
                        cout << "Teclea cualquier letra para atacar: ";
                        getc(stdin);
                        // Si el jugador muere, terminar el juego
                        if (!jugador.estaVivo()){
                            cout << "Has muerto en una batalla contra " << guerreroActual->getNombre() << " en el " << mundoActual->getNombre() << endl;
                            return 0;
                        }
                        // Si el Guerrero muere, terminar la batalla y avanzar al próximo mundo
                        getc(stdin);
                        valorInteraccion = jugador.juega();
                        guerreroActual->recibeInteraccion(valorInteraccion);
                        if (!guerreroActual->estaVivo()){
                            cout << "Has ganado la batalla contra " << guerreroActual->getNombre() << " en " << mundoActual->getNombre() << endl;
                            break;
                        }
                    }
                }
                else{
                    // Si el personaje es Amistoso, interactuar normalmente
                    uniform_int_distribution<> distrInteraccion(1, 5);
                    int valorInteraccion = distrInteraccion(gen);
                    personajeActual->recibeInteraccion(valorInteraccion);
                    jugador.recibeSalud(valorInteraccion);
                }

                if (i<3){
                    cout << "Teclea la letra s para pasar al siguiente mundo: ";
                    cin >> next;
                }
                
                if (next != "s"){
                    cout << "Tenias que teclear s para seguir, perdiste :(" << endl;
                    return 0;
                }
            }
            // Si el jugador supera todos los mundos, ganará el juego
            cout << "¡Felicidades! Has ganado el juego" << endl;
            return 0;
        } else {
            cout << "No puedes comenzar el juego si no tecleas la letra c" << endl;
        }
    } while (comienzo != "c");
}