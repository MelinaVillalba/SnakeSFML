#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <colision.h>
using namespace std;

enum class Direction { None, Up, Down, Left, Right, Null };

class personaje:public sf::Drawable, public colision
{
    private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Sprite _spriteBody;
    sf::Texture _textureBody;
    Direction currentDirection = Direction::None;

    float _velocidad = 5;
    int life = 3;
    int cont =3;


    public:
        personaje();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override ;
        sf::FloatRect getBounds() const override;
        void aumentoVelocidad();
        virtual ~personaje();

    protected:


};

#endif// PERSONAJE_H
