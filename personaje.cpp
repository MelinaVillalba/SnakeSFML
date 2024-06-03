#include "personaje.h"
#include <SFML/Graphics.hpp>
#include <iostream> // Funciones de salida
#include <conio.h> // Tiempos
#include <stdlib.h>
#include <windows.h>

personaje::personaje() : currentDirection(Direction::None)
{
    _texture.loadFromFile("Assets/cabeza.bmp");

    _sprite.setTexture(_texture);
    //posicionamos a la serpiente en medio de la pantalla
    _sprite.setPosition(400, 300);
//    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,  _sprite.getGlobalBounds().height);
}

void personaje::update()
{

//Movimiento del personaje

    //Guardamos el valor de la tecla presionada
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            //Si snake va hacia abajo no puede ir hacia arriba
            if(currentDirection != Direction::Down)
                {
                    currentDirection = Direction::Up;
                }

        }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            //Si snake va hacia  arriba no puede ir hacia abajo
            if (currentDirection !=Direction::Up)
                {
                    currentDirection = Direction::Down;
                }

        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            //Si snake va hacia la derecha no puede ir hacia la izquierda
            if(currentDirection !=Direction::Right)
                {
                    currentDirection = Direction::Left;
                }

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                //Si snake va hacia la izquierda no puede ir hacia la derecha
                if(currentDirection !=Direction::Left)
                    {
                        currentDirection = Direction::Right;
                    }

            }


  // Snake se mueve en base a currentDirection
    switch (currentDirection)
        {
            case Direction::Up:
                _sprite.move(0, -_velocidad);
                break;
            case Direction::Down:
                _sprite.move(0, _velocidad);
                break;
            case Direction::Left:
                _sprite.move(-_velocidad, 0);
                break;
            case Direction::Right:
                _sprite.move(_velocidad, 0);
                break;
            default:
                break;
        }


        //La imagen se orienta segun la direccion que se tome
        if (currentDirection==Direction::Left)
            {
                    _sprite.setScale(-1, 1);
            }
          else if (currentDirection==Direction::Right)
            {
                    _sprite.setScale(1, 1);
            }

          else if (currentDirection==Direction::Up)
            {
                    _sprite.setScale(1, -1);
            }

            else if (currentDirection==Direction::Down)
            {
                    _sprite.setScale(1, 1);
            }



        //limites LEFT del personaje
       if(_sprite.getPosition().x<65)
            {
                _sprite.setPosition(65, _sprite.getPosition().y);
            }
        //limites UP del personaje
        if(_sprite.getPosition().y<65)
            {
                _sprite.setPosition( _sprite.getPosition().x,65);
            }
        //limites  RIGHT del personaje
        if(_sprite.getPosition().x>740)
            {
               _sprite.setPosition(740, _sprite.getPosition().y);
            }
       //limites  DOWN del personaje
       if(_sprite.getPosition().y>540)
            {
                _sprite.setPosition(_sprite.getPosition().x, 540);
            }


        // si choca con el muro de abajo
        if(_sprite.getPosition().y==540)
            {
                 _sprite.setPosition(400, 300);
                 currentDirection= Direction::None;
                    if (life > 0 )
                        {
                            life--;
                            getLife(life);

                            if (life == 0)
                            {
                                _velocidad = 0;
                                _sprite.setScale(1, 1);
                            }
                        }

            }

            // si choca con el muro de arriba
            if(_sprite.getPosition().y==65)
                {
                     _sprite.setPosition(400, 300);
                     currentDirection= Direction::None;
                        if (life > 0 )
                            {
                                life--;
                                getLife(life);
                                if (life == 0)
                                {
                                    _velocidad = 0;
                                    _sprite.setScale(1, 1);
                                }
                            }

                }

            //si choca con el muro de la izquierda
             if(_sprite.getPosition().x==65)
                {
                     _sprite.setPosition(400, 300);
                     currentDirection= Direction::None;
                        if (life > 0 )
                            {
                                life--;
                                getLife(life);
                                if (life == 0)
                                {
                                    _velocidad = 0;
                                    _sprite.setScale(1, 1);
                                }
                            }
                }

                //si choca con el muro de la derecha
                if(_sprite.getPosition().x==740)
                    {
                         _sprite.setPosition(400, 300);
                         currentDirection= Direction::None;
                            if (life > 0 )
                                {
                                    life--;
                                    getLife(life);
                                    if (life == 0)
                                    {
                                        _velocidad = 0;
                                    }
                                }

                    }

}


int personaje::getLife(int life)
{
    return this->life;
}

//Sirve para las colisiones
 sf::FloatRect personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

//Aumenta la velocidad
void personaje::aumentoVelocidad()
{
    _velocidad += 0.5;
}




//const porque no modifica el estado actual del personaje
void personaje::draw(sf::RenderTarget& target, sf:: RenderStates states) const
{
    //como se va a dibujar el personaje
    target.draw(_sprite, states);
}



personaje::~personaje()
{
    //dtor
}
