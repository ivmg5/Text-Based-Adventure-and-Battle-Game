---

# Juego de Aventura y Combate a Consola

## Descripción

Este juego es una simulación textual de aventura y combate que combina elementos de estrategia con interacciones básicas entre personajes. Está diseñado para ser jugado en la consola y utiliza extensamente los conceptos de programación orientada a objetos como herencia, polimorfismo, clases abstractas, sobrecarga de operadores y manejo de excepciones.

## Planteamiento del Problema

Los videojuegos son, en su esencia, simulaciones de diversos escenarios y actividades. Ya sea que estemos hablando de juegos de estrategia, aventuras o combate, la programación orientada a objetos ofrece herramientas poderosas para implementar estas simulaciones. En este juego, el jugador interactuará con diferentes personajes, ya sean amistosos o guerreros, mientras navega a través de diversos mundos.

## Cómo Jugar

1. Al iniciar el juego, se te pedirá que ingreses el nombre de tu personaje. Asegúrate de que el nombre no esté vacío y no tenga más de 15 caracteres.
2. Una vez que hayas ingresado tu nombre, presiona la letra "c" para comenzar.
3. En cada mundo, te enfrentarás a un personaje, ya sea un Amistoso o un Guerrero.
   - Si el personaje es amistoso, interactuarás con él y recibirás ayuda o consejos.
   - Si el personaje es un Guerrero, deberás luchar contra él. La batalla continúa hasta que uno de los dos pierda toda su salud.
4. Luego de cada interacción o batalla, podrás avanzar al siguiente mundo presionando la letra "s".
5. El juego continúa hasta que superes todos los mundos o hasta que tu personaje muera en batalla.

## Características Técnicas

- **Herencia**: Las clases `Amistoso` y `Guerrero` heredan de la clase `Personaje`.
- **Polimorfismo**: Los métodos `juega` y `recibeInteraccion` están sobrescritos en las clases `Amistoso` y `Guerrero`.
- **Clases Abstractas**: `Personaje` es una clase abstracta.
- **Sobrecarga de Operadores**: Se sobrecarga el operador `<` para comparar la salud de dos Guerreros.
- **Excepciones**: Se usan para validar el nombre del jugador.

## Compilación y Ejecución

Para compilar y ejecutar el juego, asegúrate de tener todas las dependencias (`Personaje.hpp`, `Amistoso.hpp`, `Guerrero.hpp`, `Mundo.hpp`, y `Item.hpp`) en el mismo directorio y usa un compilador compatible con C++ (por ejemplo, g++). El siguiente comando puede ser útil:

```
g++ main.cpp -o juego
./juego
```

## Colaboración

Si tienes alguna idea para mejorar el juego o encuentras algún bug, no dudes en abrir un issue o enviar un pull request. ¡Toda colaboración es bienvenida!

---
