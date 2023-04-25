#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
int main()
{
    srand(time(NULL));
    const int o = 1600;//Границы создаваемого окна
    const int p = 900;
    sf::RenderWindow window(sf::VideoMode(o, p), "SFML Line");

    const int numLines = 100;
    sf::VertexArray lines(sf::Lines, numLines * 2);

    for (int i = 0; i < numLines; i++)
    {
        int x1 = rand() % o;
        int x2 = rand() % o;
        int y1 = rand() % o;
        int y2 = rand() % o;
        lines[i * 2].position = sf::Vector2f(x1, y1);
        lines[i * 2].color = sf::Color::White;
        lines[i * 2 + 1].position = sf::Vector2f(x2, y2);
        lines[i * 2 + 1].color = sf::Color::White;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(lines);
        window.display();

    }

    return 0;
}