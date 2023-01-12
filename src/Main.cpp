#include "../include/Libs.hpp"
#include "../include/Player.hpp"
#include "../include/Ball.hpp"
#include "../include/Menu.hpp"

void checkPoint();

int player1Point = 0;
int player2Point = 0;

bool running = false;

float width = 1920;
float height = 1080;

Ball ball = Ball(4, width, height);

Player player1 = Player(20.0f, 250.0f, (width - 40.f), 100.0f, sf::Color::White, 0);
Player player2 = Player(20.0f, 250.0f, 10.0f, 100.0f, sf::Color::Red, 1);

Button btnStart = Button("start", sf::Color::Red, 250.0f, 50.0f, (width / 2 - 125.0f), 280.0f);
Button btnSetting = Button("setting", sf::Color::Red, 250.0f, 50.0f, (width / 2 - 125.0f), 360.0f);
Button btnExit = Button("exit", sf::Color::Red, 250.0f, 50.0f, (width / 2 - 125.0f), 440.0f);

int main() {
    sf::RenderWindow window(sf::VideoMode(width, height), "copy of pong", sf::Style::Fullscreen);
    window.setFramerateLimit(112);

    srand(time(nullptr));

    sf::Font font;
    if(!font.loadFromFile("assets/font/poppins.ttf")) {
        std::cerr << "error" << '\n';
    }

    sf::Text labelPointPlayer1, labelPointPlayer2;
    labelPointPlayer1.setCharacterSize(15);
    labelPointPlayer1.setFont(font);

    labelPointPlayer2.setCharacterSize(15);
    labelPointPlayer2.setFont(font);
    labelPointPlayer2.setPosition(sf::Vector2(width - 120, 0.0f));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                running = false;
            }
        }

        labelPointPlayer1.setString("player1Point: " + std::to_string(player1Point));
        labelPointPlayer2.setString("player2Point: " + std::to_string(player2Point));

        //std::cout << "x: " << sf::Mouse::getPosition().x << std::endl;
        //std::cout << "y: " << sf::Mouse::getPosition().y << std::endl;

        //btn action
        if(btnExit.isSelected(window.getPosition())) {
            return 0;
        }
        if(btnSetting.isSelected(window.getPosition())) {
            
        }
        if(btnStart.isSelected(window.getPosition())) {
            running = true;
        }

        if(running) {
            checkPoint();

            ball.move();

            ball.colition(player1.spritePlayer, player2.spritePlayer, height);

            player1.move();
            player2.move();

            player1.colition(height);
            player2.colition(height);
        }

        window.clear();
        window.draw(labelPointPlayer1);
        window.draw(labelPointPlayer2);
        window.draw(ball.spriteBall);
        window.draw(player1.spritePlayer);
        window.draw(player2.spritePlayer);
        if(!running) {
            window.draw(btnStart.spriteButton);
            window.draw(btnSetting.spriteButton);
            window.draw(btnExit.spriteButton);
            window.draw(btnStart.text);
            window.draw(btnSetting.text);
            window.draw(btnExit.text);
        }
        window.display();
    }
    return 0;
}

void checkPoint() {
    if(ball.spriteBall.getPosition().x < 0) {
        player2Point = player2Point + 1;
        ball.spriteBall.setPosition(width / 2, height / 2);
        std::cout << player2Point << std::endl;
    }
    if(ball.spriteBall.getPosition().x > width) {
        player1Point = player1Point + 1;
        ball.spriteBall.setPosition(width / 2, height / 2);
        std::cout << player1Point << std::endl;
    }
}