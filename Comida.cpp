#include "Comida.h"
#include <stdlib.h>

Comida::Comida()
{
    _texture.loadFromFile("Assets/apple.bmp");

    _sprite.setTexture(_texture);

    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

}


 sf::FloatRect Comida::getBounds()const
{
    return _sprite.getGlobalBounds();
}

void Comida::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

void Comida::respawn()
{
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}
Comida::~Comida()
{
    //dtor
}
