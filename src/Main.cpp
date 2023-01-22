#include "../include/Libs.hpp"
#include "../include/Game.hpp"

void checkPoint();
void activateScene0(); //scene game
void activateScene1(); //home scene
void activateScene2(); //setting scene

int main() {
    window.setFramerateLimit(112);

    sf::Font font;
    if(!font.loadFromFile("assets/font/poppins.ttf")) {
        std::cerr << "error to load font, please check your assets" << '\n';
    }

    sf::Text labelPointPlayer1, labelPointPlayer2, labelBot;
    labelPointPlayer1.setCharacterSize(15);
    labelPointPlayer1.setFont(font);

    labelPointPlayer2.setCharacterSize(15);
    labelPointPlayer2.setFont(font);
    labelPointPlayer2.setPosition(sf::Vector2(width - 120, 0.0f));

    labelBot.setCharacterSize(15);
    labelBot.setFont(font);
    labelBot.setFillColor(sf::Color::Red);
    labelBot.setPosition(sf::Vector2(width / 2 - 90, 0.0f));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                running = false;
                activateScene1();
            }
        }

        labelPointPlayer1.setString("player1Point: " + std::to_string(player1Point));
        labelPointPlayer2.setString("player2Point: " + std::to_string(player2Point));
        labelBot.setString("mode Solo Player1 VS Bot");

        //btn action
        if(btnExit.isSelected(window.getPosition())) {
            return 0;
        }
        if(btnSetting.isSelected(window.getPosition())) {
            activateScene2();
        }
        if(btnStart.isSelected(window.getPosition())) {
            running = true;
            activateScene0();
        }
        if(btnBack.isSelected(window.getPosition())) {
            activateScene1();
        }
        if(btnSolo.isSelected(window.getPosition())) {
            if(modeSolo) {
                modeSolo = false;
            }else {
                modeSolo = true;
            }
        }
        if(modeSolo) {
            player1.bot(ball.spriteBall.getPosition().y);
        }

        if(running) {
            checkPoint();
            
            ball.move();

            ball.colition(player1.spritePlayer, player2.spritePlayer, height);

            if(!modeSolo) {
                player1.move();
                player1.colition(height);
            }

            player2.move();
            player2.colition(height);
        }

        window.clear();
        window.draw(labelPointPlayer1);
        window.draw(labelPointPlayer2);
        window.draw(ball.spriteBall);
        window.draw(player1.spritePlayer);
        window.draw(player2.spritePlayer);
        if(scene1) {
            window.draw(btnStart.spriteButton);
            window.draw(btnSetting.spriteButton);
            window.draw(btnExit.spriteButton);
            window.draw(btnStart.text);
            window.draw(btnSetting.text);
            window.draw(btnExit.text);
        }
        else if(scene2){
            window.draw(btnBack.spriteButton);
            window.draw(btnBack.text);
            window.draw(btnSolo.spriteButton);
            window.draw(btnSolo.text);
        }
        if(modeSolo) {
            window.draw(labelBot);
        }
        window.display();
    }
    return 0;
}


void checkPoint() {
    if(ball.spriteBall.getPosition().x < 0) {
        player2Point++;
        ball.spriteBall.setPosition(width / 2, height / 2);
    }
    if(ball.spriteBall.getPosition().x > width) {
        player1Point++;
        ball.spriteBall.setPosition(width / 2, height / 2);
    }
}

void activateScene0() {
    btnBack.setOnScene(false);
    btnStart.setOnScene(false);
    btnSetting.setOnScene(false);
    btnExit.setOnScene(false);
    btnSolo.setOnScene(false);
    scene0 = true;
    scene1 = false;
    scene2 = false;
}
void activateScene1() {
    btnBack.setOnScene(false);
    btnStart.setOnScene(true);
    btnSetting.setOnScene(true);
    btnExit.setOnScene(true);
    btnSolo.setOnScene(false);
    scene0 = false;
    scene1 = true;
    scene2 = false;
    
}
void activateScene2() {
    btnStart.setOnScene(false);
    btnSetting.setOnScene(false);
    btnExit.setOnScene(false);
    btnBack.setOnScene(true);
    btnSolo.setOnScene(true);
    scene0 = false;
    scene1 = false;
    scene2 = true;
}