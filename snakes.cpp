#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 500), "Snakes and Ladders");                 // x = 700 til að fá smá pláss til hliðar (500 default)
	srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    
    // PLAYFIELD CONSTRUCTION
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

    // NUMBERS INSERTED TO PLAYFIELD
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text numbers[numSquares];
    
    int board_numb = 100;          //bætti við
    bool board_number_switch = true;

    for (int i = 0; i < numSquares; i++) {
        numbers[i].setFont(font);
        if(board_number_switch){
            numbers[i].setString(std::to_string(board_numb - i)); 
        }
        else{
            numbers[i].setString(std::to_string(board_numb - 10 + (i % 10)));
        }

        if(i % 10 == 0){
            board_number_switch = !board_number_switch;
        }

        //numbers[i].setString(std::to_string(board_numb - i));           // í staðinn fyrir i + 1
        numbers[i].setFillColor(sf::Color::Black);
        numbers[i].setCharacterSize(20);
        
        // Center text
        sf::FloatRect bounds = numbers[i].getGlobalBounds();
        numbers[i].setOrigin(bounds.left + bounds.width / 2.f,
                             bounds.top + bounds.height / 2.f);
        numbers[i].setPosition(squares[i].getPosition().x + squareSize / 2.f,
                                squares[i].getPosition().y + squareSize / 2.f);
    }


    // SNAKES AND LADDERS
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


    // INFORMATION WINDOW ON THE SIDE

    // PLAYER ICON POSITION VARIABLES
    float player1posx = 1.6;
    float player1posy = 1.5;
    float player2posx = 3.2;      // þarf að skoða
    float player2posy = 1.5; 

    // PLAYER ICON SETUP
    sf::CircleShape playerDot(squareSize / 8.f);
    playerDot.setFillColor(sf::Color::Black);
    // playerDot.setPosition(squares[0].getPosition().x + squareSize / player1posx,                   //1.6f      upprunalega 2.f
    //                        squares[0].getPosition().y + squareSize /player1posy);                 //1.5f      upprunalega 2.f
    playerDot.setPosition(squares[99].getPosition().x + squareSize / player1posx,                   //0 í 99
                           squares[99].getPosition().y + squareSize /player1posy);                 // 0 í 99

    // PLAYER2 ICON SETUP
    sf::CircleShape playerDot2(squareSize / 8.f);
    playerDot2.setFillColor(sf::Color::Yellow);
    playerDot2.setPosition(squares[99].getPosition().x + squareSize / player2posx,                   
                           squares[99].getPosition().y + squareSize /player2posy);                 
    

    // PLAYER POSTIION INITIAL
    int playerPosition = 99;
    int player2Position = 99;

    bool Player1Turn = true;
    while (window.isOpen())
    {


        sf::Event event;     
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Move the player (player1)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && Player1Turn) {
                int diceRoll = std::rand() % 6 + 1; 
                cout << "Player 1 rolled: " << diceRoll << endl;
                playerPosition -= diceRoll;        
                sf::Vector2f newPosition = squares[playerPosition].getPosition() + sf::Vector2f(squareSize /  player1posx, squareSize / player1posy);        //upprunalega 2.f á báðum stöðum
                playerDot.setPosition(newPosition);
                
                if (playerPosition <= 0){           // ein leið til að stoppa leikinn
                    window.close();
                }
                Player1Turn = false;
            }
            // Move the player (player2)
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && !Player1Turn) {
                int diceRoll = std::rand() % 6 + 1; 
                cout << "Player 2 rolled: " << diceRoll << endl;
                player2Position -= diceRoll;        
                sf::Vector2f newPosition = squares[player2Position].getPosition() + sf::Vector2f(squareSize /  player2posx, squareSize / player2posy);        
                playerDot2.setPosition(newPosition);
                
                if (player2Position <= 0){           // ein leið til að stoppa leikinn
                    window.close();
                }
                Player1Turn = true;
            }
            
        }


        window.clear();
        
        for (int i = 0; i < numSquares; i++) {
            window.draw(squares[i]);
            window.draw(numbers[i]);
        }
        window.draw(lines);
        window.draw(playerDot);
        window.draw(playerDot2);
        window.display();
    }

    return 0;
}
