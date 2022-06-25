#include "DrawAll.hpp"

Window::Window(int size_of_screen) {
    this-> size_of_screen = size_of_screen;
}
void Window::draw() {
        sf::RenderWindow window(sf::VideoMode(size_of_screen, size_of_screen), "SFML works!");
        sf::CircleShape shape(200.f);
        shape.setFillColor(sf::Color::Black);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
}

