#ifndef COMIDA_H
#define COMIDA_H
#include <SFML/Graphics.hpp>
#include "personaje.h"
#include "colision.h"


class Comida:public sf::Drawable, public colision
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Sprite _spriteBomba;
    sf::Texture _textureBomba;

    public:
        Comida();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
        void respawn();
        sf::FloatRect getBounds()const override;
        virtual ~Comida();

    private:

};

#endif // COMIDA_H
