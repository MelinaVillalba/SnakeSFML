#include "bomba.h"
#include <stdlib.h>

bomba::bomba()
{
    _texture.loadFromFile("Assets/bomba.png");

    _sprite.setTexture(_texture);
    _sprite.setPosition(300,300);

}

sf::FloatRect bomba::getBounds()const
{
    return _sprite.getGlobalBounds();
}

void bomba::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

void bomba::respawn()
{
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}
bomba::~bomba()
{
    //dtor
}
