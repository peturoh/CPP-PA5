#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

using namespace std;


int snakes(int position){
    if(position == 97){
    	sf::sleep(sf::milliseconds(500));
        return 60;
    }
    else if(position == 75){
    	sf::sleep(sf::milliseconds(500));
        return 2;
    }
    else if(position == 67){
    	sf::sleep(sf::milliseconds(500));
        return 47;
    }
    else if(position == 59){
    	sf::sleep(sf::milliseconds(500));
        return 17;
    }
    return position;
}

int ladders(int position){
    if(position == 21){
    	sf::sleep(sf::milliseconds(500));
        return 99;
    }
    else if(position == 14){
    	sf::sleep(sf::milliseconds(500));
        return 46;
    }
    else if(position == 30){
    	sf::sleep(sf::milliseconds(500));
        return 71;
    }
    return position;
}

void drawPlayer(sf::RenderWindow& window, sf::CircleShape& playerDot, sf::RectangleShape* squares, const int squareSize, int playerPosition) {
    sf::Vector2f newPosition = squares[playerPosition].getPosition() + sf::Vector2f(squareSize / 2.f, squareSize / 2.f);
    playerDot.setPosition(newPosition);
    window.draw(playerDot);
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 600), "Snakes and Ladders");
	srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    const int numRows = 10;
    const int numCols = 10;
    const int numSquares = numRows*numCols;
    const int squareSize = 50;
	
    sf::RectangleShape squares[numSquares];
    for (int i = 0; i < numSquares; i++) {
        int row = numRows - 1 - i / numCols; 
        int col = (row % 2 == 0) ? numCols - 1 - i % numCols : i % numCols; 
        squares[i].setSize(sf::Vector2f(squareSize, squareSize));
        squares[i].setPosition(col * squareSize, row * squareSize);
        if ((row + col) % 2 == 0) {
            squares[i].setFillColor(sf::Color::White);
        } else {
            squares[i].setFillColor(sf::Color(200, 200, 200));
        }
    }

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
    
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setString("Press R to roll for Player 1\nPress P to roll for Player 2");
    instructions.setCharacterSize(16);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(10, 500);
    
    sf::Text lastTurnText("", font, 16);
	lastTurnText.setPosition(10, 536);
	lastTurnText.setFillColor(sf::Color::White);
	
	sf::Text teleportText("", font, 16);
	teleportText.setPosition(10, 552);
	teleportText.setFillColor(sf::Color::White);

    sf::VertexArray lines(sf::Lines, 14); 
    lines[0].position = sf::Vector2f(squares[2].getPosition().x + squareSize / 2.f,
                                     squares[2].getPosition().y + squareSize / 2.f);
    lines[1].position = sf::Vector2f(squares[75].getPosition().x + squareSize / 2.f,
                                     squares[75].getPosition().y + squareSize / 2.f);
    lines[2].position = sf::Vector2f(squares[21].getPosition().x + squareSize / 2.f,
                                     squares[21].getPosition().y + squareSize / 2.f);
    lines[3].position = sf::Vector2f(squares[99].getPosition().x + squareSize / 2.f,
                                     squares[99].getPosition().y + squareSize / 2.f);
    lines[4].position = sf::Vector2f(squares[47].getPosition().x + squareSize / 2.f,
                                     squares[47].getPosition().y + squareSize / 2.f);
    lines[5].position = sf::Vector2f(squares[67].getPosition().x + squareSize / 2.f,
                                     squares[67].getPosition().y + squareSize / 2.f);
    lines[6].position = sf::Vector2f(squares[17].getPosition().x + squareSize / 2.f,
                                     squares[17].getPosition().y + squareSize / 2.f);
    lines[7].position = sf::Vector2f(squares[59].getPosition().x + squareSize / 2.f,
                                     squares[59].getPosition().y + squareSize / 2.f);
    lines[8].position = sf::Vector2f(squares[60].getPosition().x + squareSize / 2.f,
                                     squares[60].getPosition().y + squareSize / 2.f);
    lines[9].position = sf::Vector2f(squares[97].getPosition().x + squareSize / 2.f,
                                     squares[97].getPosition().y + squareSize / 2.f);
    lines[10].position = sf::Vector2f(squares[14].getPosition().x + squareSize / 2.f,
                                     squares[14].getPosition().y + squareSize / 2.f);
    lines[11].position = sf::Vector2f(squares[46].getPosition().x + squareSize / 2.f,
                                     squares[46].getPosition().y + squareSize / 2.f);
    lines[12].position = sf::Vector2f(squares[30].getPosition().x + squareSize / 2.f,
                                     squares[30].getPosition().y + squareSize / 2.f);
    lines[13].position = sf::Vector2f(squares[71].getPosition().x + squareSize / 2.f,
                                     squares[71].getPosition().y + squareSize / 2.f);
    //red lines.
    lines[0].color = sf::Color::Red;
    lines[1].color = sf::Color::Red;
    lines[4].color = sf::Color::Red;
    lines[5].color = sf::Color::Red; 
    lines[6].color = sf::Color::Red;
    lines[7].color = sf::Color::Red; 
    lines[8].color = sf::Color::Red;
    lines[9].color = sf::Color::Red; 
    
    //green lines.
    lines[2].color = sf::Color::Green;
    lines[3].color = sf::Color::Green;
    lines[10].color = sf::Color::Green;
    lines[11].color = sf::Color::Green;
    lines[12].color = sf::Color::Green;
    lines[13].color = sf::Color::Green;

    sf::CircleShape playerDot(squareSize / 6.f);
    playerDot.setFillColor(sf::Color::Blue);
    playerDot.setPosition(squares[0].getPosition().x + squareSize / 2.f,
                           squares[0].getPosition().y + squareSize / 2.f);
    int playerPosition = 0;

    sf::CircleShape playerDot2(squareSize / 4.f);
    playerDot2.setFillColor(sf::Color::Black);
    playerDot2.setPosition(squares[0].getPosition().x + squareSize / 2.f,
                           squares[0].getPosition().y + squareSize / 2.f);
    int player2Position = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
        	string lastTurnInfo;
        	string teleportInfo;
            if (event.type == sf::Event::Closed)
                window.close();

            // Move the player1
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                int diceRoll = std::rand() % 6 + 1; 
                cout << "DICEROLL: " << diceRoll << endl;
                playerPosition += diceRoll; 
                lastTurnInfo = "Player 1 rolled a " + to_string(diceRoll) + " and landed on square " + to_string(playerPosition+1) + ".";
                if(playerPosition > 99){
                    playerPosition = 99;
                }
                else if(playerPosition == 97 ||playerPosition == 75 ||playerPosition == 67 ||playerPosition == 59){
                    cout << "SNAKES: " << playerPosition +1 << endl;
					drawPlayer(window, playerDot, squares, squareSize, playerPosition);
                    playerPosition = snakes(playerPosition);   
                    teleportInfo = "OOPS! Player 1 slid down a snake and ended up on square " + to_string(playerPosition+1) + ".";
                }
                else if(playerPosition == 14 ||playerPosition == 21 ||playerPosition == 30){
                    cout << "LADDERS: " << playerPosition +1 << endl;
                    drawPlayer(window, playerDot, squares, squareSize, playerPosition);
                    playerPosition = ladders(playerPosition); 
                    teleportInfo = "YAY! Player 1 hit a ladder and climbed up to square " + to_string(playerPosition+1) + ".";  
                }
                if(playerPosition == 99){
                	drawPlayer(window, playerDot, squares, squareSize, playerPosition);
                	sf::Text message("Player 1 won!", font, 36);
					message.setFillColor(sf::Color::Red);
					message.setPosition(150,220);
					window.draw(message);
					window.display();
					sf::sleep(sf::milliseconds(3000));
                    window.close();
                }
				lastTurnText.setString(lastTurnInfo);
				teleportText.setString(teleportInfo);
                sf::Vector2f newPosition = squares[playerPosition].getPosition() + sf::Vector2f(squareSize / 2.f, squareSize / 2.f);
                playerDot.setPosition(newPosition);
            }
            //move player2
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                int diceRoll2 = std::rand() % 6 + 1; 
                player2Position += diceRoll2;
                lastTurnInfo = "Player 2 rolled a " + to_string(diceRoll2) + " and landed on square " + to_string(player2Position+1) + ".";
                if(player2Position > 99){
                    player2Position = 99;
                }
                else if(player2Position == 97 ||player2Position == 75 ||player2Position == 67 ||player2Position == 59){
                    cout << "SNAKES p2: " << player2Position +1 << endl;
                    drawPlayer(window, playerDot2, squares, squareSize, player2Position);
                    player2Position = snakes(player2Position);
                    teleportInfo = "OOPS! Player 2 slid down a snake and ended up on square " + to_string(player2Position+1) + ".";
                }
                else if(player2Position == 14 || player2Position == 21 ||player2Position == 30){
                    cout << "LADDERS p2: " << playerPosition +1 << endl;
                    drawPlayer(window, playerDot2, squares, squareSize, player2Position);
                    player2Position = ladders(player2Position);   
                    teleportInfo = "YAY! Player 2 hit a ladder and climbed up to square " + to_string(player2Position+1) + ".";  
                }
                if(player2Position == 99){
                	drawPlayer(window, playerDot2, squares, squareSize, player2Position);
                	sf::Text message("Player 2 won!", font, 36);
					message.setFillColor(sf::Color::Red);
					message.setPosition(150, 220);
					window.draw(message);
					window.display();
                    window.close();
                }
				lastTurnText.setString(lastTurnInfo);
				teleportText.setString(teleportInfo);
                sf::Vector2f new2Position = squares[player2Position].getPosition() + sf::Vector2f(squareSize / 2.f, squareSize / 2.f);
                playerDot2.setPosition(new2Position);
            }
        }
        
        window.clear();
        
        for (int i = 0; i < numSquares; i++) {
            window.draw(squares[i]);
            window.draw(numbers[i]);
        }
        window.draw(instructions);
        window.draw(lines);
        window.draw(playerDot);
        window.draw(playerDot2);
        window.draw(lastTurnText);
        window.draw(teleportText);
        window.display();
    }

    return 0;
}
