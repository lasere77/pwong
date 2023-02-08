#include "../include/Libs.hpp"
#include "../include/Player.hpp"
#include "../include/Ball.hpp"
#include "../include/Menu.hpp"
#include "../include/Time.hpp"
#include <thread>

void checkPoint();
void activateScene0(); //scene game
void activateScene1(); //home scene
void activateScene2(); //setting scene

bool scene0 = false;
bool scene1 = true;
bool scene2 = false;

bool soloMode = false;
bool hardMode = false;

sf::RenderWindow window(sf::VideoMode(0, 0), "copy of pong", sf::Style::Fullscreen);

float width = window.getSize().x;
float height = window.getSize().y;

bool running = false;

int player1Point = 0;
int player2Point = 0;

Ball ball = Ball(4, width / 2, height / 2);

Player player1 = Player(20.0f, 250.0f, (width - 40.f), 100.0f, "player1.jpg", 0);
Player player2 = Player(20.0f, 250.0f, 10.0f, 100.0f, "player2.jpg", 1);

Button btnStart = Button("start", 250.0f, 50.0f, (width / 2 - 125.0f), 280.0f, false, true);
Button btnSetting = Button("setting", 250.0f, 50.0f, (width / 2 - 125.0f), 360.0f, false, true);
Button btnExit = Button("exit", 250.0f, 50.0f, (width / 2 - 125.0f), 440.0f, false, true);

Button btnBack = Button("back", 250.0f, 50.0f, (width / 2 - 125.0f), 360.0f, false, false);
Button btnSolo = Button("solo mode", 120.0f, 50.0f, (width / 2 - 125.0f), 440.0f, true, false);
Button btnHard = Button("hard mode", 120.0f, 50.0f, (width / 2), 440.0f, true, false);

Entry entrySpeedBall = Entry(250.0f, 50.0f, (width / 2 - 125.0f), 280.0f, false);

int main() {
    window.setFramerateLimit(112);
    srand(time(nullptr));
    sf::Font font;
    if(!font.loadFromFile("assets/font/poppins.ttf")) {
        std::cerr << "error to load font, please check your assets" << '\n';
    }

    std::thread timerThread(timer);

    sf::Text labelPointPlayer1, labelPointPlayer2, labelTime, labelBot, labelHard;
    labelPointPlayer1.setCharacterSize(15);
    labelPointPlayer1.setFont(font);

    labelPointPlayer2.setCharacterSize(15);
    labelPointPlayer2.setFont(font);
    labelPointPlayer2.setPosition(sf::Vector2(width - 120, 0.0f));

    labelTime.setCharacterSize(15);
    labelTime.setFont(font);
    labelTime.setPosition(sf::Vector2(width / 2, height - 20));

    labelBot.setCharacterSize(15);
    labelBot.setFont(font);
    labelBot.setFillColor(sf::Color::Red);
    labelBot.setPosition(sf::Vector2(width / 2 - 150, 0.0f));

    labelHard.setCharacterSize(15);
    labelHard.setFont(font);
    labelHard.setFillColor(sf::Color::Red);
    labelHard.setPosition(sf::Vector2(width / 2 + 97.5f, 0.0f));

    bool respectDelay = true;
    int delay = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            delay++;
            if(delay >= 5) {
                respectDelay = true;
            }
            if(entrySpeedBall.getCheckKeyboard()) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && respectDelay) {
                    entrySpeedBall.BackSpaceText();
                    respectDelay = false;
                    delay = 0;
                }
                else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode < 128)
                            entrySpeedBall.setText(static_cast<char>(event.text.unicode));
                    }
                }
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                running = false;
                setThreadAction(false);
                activateScene1();
            }
        }
        
        labelPointPlayer1.setString("player1Point: " + std::to_string(player1Point));
        labelPointPlayer2.setString("player2Point: " + std::to_string(player2Point));
        labelTime.setString("time: " + std::to_string(getTime()));
        labelBot.setString("mode Solo Player1 VS Bot");
        labelHard.setString("mode Hard!!!!");

        //btn action
        if(btnExit.isSelected(window.getPosition())) {
            killThread();
            timerThread.join();
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
            if(soloMode) {
                soloMode = false;
            }else {
                soloMode = true;
            }
        }
        if(btnHard.isSelected(window.getPosition())) {
            if(hardMode) {
                hardMode = false;
            }else {
                hardMode = true;
            }
        }
        if(entrySpeedBall.isSelected(window.getPosition())) {
            try {
                int desiredSpeed = stoi(entrySpeedBall.getKey());
                ball.setSpeed(desiredSpeed);
                player1.setSpeed(desiredSpeed);
                player2.setSpeed(desiredSpeed);
            } catch(const std::exception& e) {
                ball.setSpeed(ball.getSpeed());
                player1.setSpeed(player1.getSpeed());
                player2.setSpeed(player2.getSpeed());
                std::cout << "the ball speed is maximum 16." << std::endl;
            }
            std::cout << "the speed of the ball is: " << ball.getSpeed() << std::endl;
        }

        if(running) {
            setThreadAction(true);
            checkPoint();
            
            ball.move();

            ball.colition(player1.spritePlayer, player2.spritePlayer, height);

            if(!soloMode) {
                player1.move();
                player1.colition(height);
            }else {
                player1.bot(ball.spriteBall.getPosition().y);
            }

            player2.move();
            player2.colition(height);

            if(hardMode && getTime() != 0 && getTime() % 10 == 0 && player1.spritePlayer.getSize().y > 100.0f) {
                player2.changeSize(player2.spritePlayer.getSize().y - 0.2f);
                player1.changeSize(player2.spritePlayer.getSize().y - 0.2f);
            }
        }

        window.clear();
        window.draw(labelPointPlayer1);
        window.draw(labelPointPlayer2);
        window.draw(labelTime);
        window.draw(ball.spriteBall);
        window.draw(player1.spritePlayer);
        window.draw(player2.spritePlayer);
        if(scene1) {
            window.draw(btnStart.spriteButton);
            window.draw(btnSetting.spriteButton);
            window.draw(btnExit.spriteButton);
            window.draw(btnStart.getText());
            window.draw(btnSetting.getText());
            window.draw(btnExit.getText());
        }
        else if(scene2){
            window.draw(btnBack.spriteButton);
            window.draw(btnBack.getText());
            window.draw(btnSolo.spriteButton);
            window.draw(btnSolo.getText());
            window.draw(btnHard.spriteButton);
            window.draw(btnHard.getText());
            window.draw(entrySpeedBall.spriteEntry);
            window.draw(entrySpeedBall.getText());
        }
        if(soloMode) {
            window.draw(labelBot);
        }
        if(hardMode) {
            window.draw(labelHard);
        }
        window.display();
    }
    killThread();
    timerThread.join();
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
    btnHard.setOnScene(false);
    entrySpeedBall.setOnScene(false);
    entrySpeedBall.setCheckKeyboard(false);
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
    btnHard.setOnScene(false);
    entrySpeedBall.setOnScene(false);
    entrySpeedBall.setCheckKeyboard(false);
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
    btnHard.setOnScene(true);
    entrySpeedBall.setOnScene(true);
    scene0 = false;
    scene1 = false;
    scene2 = true;
}