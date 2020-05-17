#include <vector>

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The window");
    window.setFramerateLimit(60);

    std::vector<sf::RectangleShape> squares;
    const int num { 100 };
    const float size { 10.f };
    for (int i { 0 }; i < num; ++i) {
        for (int j { 0 }; j < num; ++j) {
            if ((i % 2) && (j % 2)) {
                sf::RectangleShape square(sf::Vector2<float>(size, size));
                square.setPosition(j * size, i * size);
                square.setFillColor(sf::Color::White);
                squares.push_back(square);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        for (sf::RectangleShape square : squares) {
            window.draw(square);
        }
        window.display();
    }

    return 0;
}
