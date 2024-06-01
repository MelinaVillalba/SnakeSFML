#include "muro.h"
#include <SFML/Graphics.hpp>

muro::muro()
{

     _texture.loadFromFile("Assets/fondo.jpg");

    //_texture.setRepeated(true); // esto hace que la imagen se repita
    _sprite.setTexture(_texture);

  //  _sprite.setOrigin(_sprite.getGlobalBounds().width/2,  _sprite.getGlobalBounds().height/10);
 //_sprite.setPosition(0, 400);


}

void muro::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

        target.draw(_sprite, states);
}


muro::~muro()
{
    //dtor
}
