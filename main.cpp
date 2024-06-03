#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "personaje.h"
#include "Comida.h"
#include "muro.h"
#include "bomba.h"


using namespace std;


int main()
{
    std::srand((unsigned)std::time(0));
    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    //Obligamos al juego a ir en un limite de 60fps
    window.setFramerateLimit(60);


     //Dibuja puntaje por pantalla
    sf::Font font;
    font.loadFromFile("Fuentes/Gameplay.ttf");
    sf::Text text;
    sf::Text vidas; // vida
    text.setFont(font);
    vidas.setFont(font); // vida

    //Declaramos
    muro limite;
    personaje snake;
    Comida apple;
    bomba Bomba;
    apple.respawn();
    Bomba.respawn();

    int puntos = 0;
    int cont = 0;
    int life = snake.getLife(life);
    //snake.getLife(life);


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
                Bomba.respawn();
                puntos = puntos +10;
                cont ++;
               // life = snake.getLife(life);
                if (cont == 5)
                    {
                        snake.aumentoVelocidad();
                        cont=0;
                    }
            }
        text.setString(std::to_string(puntos));


        //si snake choca con Bomba esta reaparece aleatoriamente
        if(snake.colisionEnCurso(Bomba))
            {
                Bomba.respawn();
                puntos = puntos -20;
            }


        // Si life es diferente de 4 se iran mostrando las vidas
        if (life !=4 && puntos > -1)
            {
                life = snake.getLife(life);
                vidas.setString(std::to_string(life));
                vidas.setPosition(770,0);
                    //Si life es 0 se bloquea y se muestrta Game Over
                    if(life == 0)
                        {
                            vidas.setString("Game Over");
                            vidas.setPosition(300,300);
                        }


            }


        window.clear();

        window.draw(limite);
        window.draw(snake);
        window.draw(apple);
        window.draw(text); //Dibuja puntaje por pantallalife
        window.draw(vidas); //Dibuja las vidas por pantalla
        window.draw(Bomba);

        //Draw


        //Display
        window.display();
    }

    //Liberacion del juego
    return 0;
}
