#ifndef MURO_H
#define MURO_H
#include <SFML/Graphics.hpp>

class muro : public sf::Drawable
{
     private:

    sf::Sprite _sprite;
    sf::Texture _texture;

    public:
        muro();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override ;
        virtual ~muro();

    protected:

};

#endif // MURO_H
