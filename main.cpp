#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "personaje.h"
#include "Comida.h"
#include "muro.h"


using namespace std;


int main()
{
    std::srand((unsigned)std::time(0));
    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    //Obligamos al juego a ir en un limite de 60fps
    window.setFramerateLimit(60);

    //Declaramos
    muro limite;
    personaje snake;
    Comida apple;
    apple.respawn();


    //Game Loop
    while (window.isOpen())
    {
        // Read  Input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Actualizar los datos del juego
        snake.update();
        //si snake choca con apple esta reaparece aleatoriamente
        if(snake.colisionEnCurso(apple))
        {
            apple.respawn();

        }

        window.clear();

        window.draw(limite);
        window.draw(snake);
        window.draw(apple);
        //Draw


        //Display
        window.display();
    }

    //Liberacion del juego
    return 0;
}
