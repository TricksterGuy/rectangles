#ifndef RECTANGLE_SET_HPP
#define RECTANGLE_SET_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdio>
#include "Rectangle.hpp"
#include "Region.hpp"

class RectangleSet : public sf::Drawable
{
    public:
        RectangleSet();
        void add(const Rectangle& r);
        int size() const;
        void update();
        Region region;
    private:
        sf::VertexArray vertices;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates renderer) const;
};

#endif // RECTANGLE_SET_HPP
