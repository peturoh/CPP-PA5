#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snakes and Ladders");

    // Create the squares
    const int numSquares = 100;
    const int squareSize = 50;
    sf::RectangleShape squares[numSquares];
    for (int i = 0; i < numSquares; i++) {
        int row = i / 10;
        int col = i % 10;
        squares[i].setSize(sf::Vector2f(squareSize, squareSize));
        squares[i].setPosition(col * squareSize, row * squareSize);
        if ((row + col) % 2 == 0) {
            squares[i].setFillColor(sf::Color::White);
        } else {
            squares[i].setFillColor(sf::Color(200, 200, 200));
        }
    }

    // Create the font and text objects
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text numbers[numSquares];
    for (int i = 0; i < numSquares; i++) {
        numbers[i].setFont(font);
        numbers[i].setString(std::to_string(i+1));
        numbers[i].setFillColor(sf::Color::Black);
        numbers[i].setCharacterSize(20);
        
        // Center text
        sf::FloatRect bounds = numbers[i].getGlobalBounds();
        numbers[i].setOrigin(bounds.left + bounds.width / 2.f,
                             bounds.top + bounds.height / 2.f);
        numbers[i].setPosition(squares[i].getPosition().x + squareSize / 2.f,
                                squares[i].getPosition().y + squareSize / 2.f);
    }

    sf::VertexArray lines(sf::Lines, 4);
    lines[0].position = sf::Vector2f(squares[2].getPosition().x + squareSize / 2.f,
                                     squares[2].getPosition().y + squareSize / 2.f);
    lines[1].position = sf::Vector2f(squares[75].getPosition().x + squareSize / 2.f,
                                     squares[75].getPosition().y + squareSize / 2.f);
    lines[2].position = sf::Vector2f(squares[21].getPosition().x + squareSize / 2.f,
                                     squares[21].getPosition().y + squareSize / 2.f);
    lines[3].position = sf::Vector2f(squares[99].getPosition().x + squareSize / 2.f,
                                     squares[99].getPosition().y + squareSize / 2.f);
    lines[0].color = sf::Color::Red;
    lines[1].color = sf::Color::Red;
    lines[2].color = sf::Color::Green;
    lines[3].color = sf::Color::Green;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for (int i = 0; i < numSquares; i++) {
            window.draw(squares[i]);
            window.draw(numbers[i]);
        }
        window.draw(lines);
        window.display();
    }

    return 0;
}
