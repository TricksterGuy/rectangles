#include "RectangleSet.hpp"

RectangleSet::RectangleSet() : vertices(sf::Quads)
{
}

void RectangleSet::add(const Rectangle& r)
{
    region.add(r);
}

int RectangleSet::size() const
{
    return region.size();
}

void RectangleSet::update()
{
    vertices.clear();
    vertices.resize(region.size() * 4);
    for (const Rectangle& r : region.getData())
    {
        sf::Color c(rand() & 255, rand() & 255, rand() & 255);
        vertices.append(sf::Vertex(sf::Vector2f(r.x, r.y), c));
        vertices.append(sf::Vertex(sf::Vector2f(r.x + r.width, r.y), c));
        vertices.append(sf::Vertex(sf::Vector2f(r.x + r.width, r.y + r.height), c));
        vertices.append(sf::Vertex(sf::Vector2f(r.x, r.y + r.height), c));
    }
}

void RectangleSet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(vertices);
}
