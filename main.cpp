#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdio>
#include "Rectangle.hpp"
#include "Region.hpp"
#include "RectangleSet.hpp"

using namespace std;

int xa = 0;
int ya = 0;
bool valid = false;
int mode = 0;

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    app.setFramerateLimit(60);

    RectangleSet rectangles;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::I)
                {
                    mode = 1;
                }
                else if (event.key.code == sf::Keyboard::U)
                {
                    mode = 0;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    mode = 2;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    xa = event.mouseButton.x;
                    ya = event.mouseButton.y;
                    valid = true;
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    valid = false;
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                int x2, y2;
                x2 = event.mouseButton.x;
                y2 = event.mouseButton.y;

                if (valid && (x2 != xa || y2 != ya))
                {
                    int x, y, width, height;

                    width = abs(x2 - xa) + 1;
                    height = abs(y2 - ya) + 1;
                    x = min(xa, x2);
                    y = min(ya, y2);
                    if (mode == 0)
                        rectangles.add(Rectangle(x, y, width, height));
                    else if (mode == 1)
                       rectangles.region.intersect(Rectangle(x, y, width, height));
                    else if (mode == 2)
                       rectangles.region.subtract(Rectangle(x, y, width, height));
                    printf("%d\n", rectangles.size());
                    valid = false;
                }
            }
        }

        // Clear screen
        app.clear();
        rectangles.update();

        app.draw(rectangles);

        if (valid)
        {
            sf::Vector2i vec = sf::Mouse::getPosition(app);
            int x2 = vec.x;
            int y2 = vec.y;
            int x, y, width, height;

            width = abs(x2 - xa) + 1;
            height = abs(y2 - ya) + 1;
            x = min(xa, x2);
            y = min(ya, y2);
            Rectangle r(x, y, width, height);
            sf::RectangleShape tmprect;
            tmprect.setSize(sf::Vector2f(width, height));
            tmprect.setFillColor(sf::Color::Blue);
            tmprect.setPosition(x, y);
            app.draw(tmprect);
        }
        // Update the window
        app.display();
    }
    return EXIT_SUCCESS;
}
