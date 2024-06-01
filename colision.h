#ifndef COLISION_H
#define COLISION_H
#pragma once
#include <SFML/Graphics.hpp>

class colision
{
    public:
        colision();
        virtual sf::FloatRect getBounds() const = 0; // Corrected: virtual function returning sf::FloatRect
        bool colisionEnCurso(colision& obj) const;

    protected:

    private:
};

#endif // COLISION_H
