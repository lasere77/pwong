#include "../include/Libs.hpp"
#include "../include/Ball.hpp"

void changeDirection(int id);

bool up = false;
bool down = true;
bool right = true;
bool left = false;

Ball::Ball(float speed) {
    std::cout << "a ball has been generated." << std::endl; 
    this->speed = speed;
    spriteBall.setFillColor(sf::Color::White);
    spriteBall.setRadius(5.0f);
    spriteBall.setPosition(540.0f, 360.0f);
}

void Ball::move() {
    if(down) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y + speed );
    }
    if(up) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y - speed);
    }
    if(left) {
        spriteBall.setPosition(spriteBall.getPosition().x - speed, spriteBall.getPosition().y);
    }
    if(right) {
        spriteBall.setPosition(spriteBall.getPosition().x + speed, spriteBall.getPosition().y);
    }

    /*
    //controlled the ball
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y - 1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y + 1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        spriteBall.setPosition(spriteBall.getPosition().x - 1.0f, spriteBall.getPosition().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        spriteBall.setPosition(spriteBall.getPosition().x + 1.0f, spriteBall.getPosition().y);
    }
    std::cout << std::endl;
    */

    //debug
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "up {" << up << "}" << std::endl;
        std::cout << "down {" << down << "}" << std::endl;
        std::cout << "left {" << left << "}" << std::endl;
        std::cout << "right {" << right << "}" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        spriteBall.setPosition(540.0f, 360.0f);
    }
}


void Ball::colition(sf::RectangleShape player1, sf::RectangleShape player2) {
    //border colition
    if(spriteBall.getPosition().y <= 0) {
        std::cout << "colition" << std::endl;
        if(up) {
            up = false;
            down = true;
        }
    }
    if(spriteBall.getPosition().y >= 710) {
        std::cout << "colition" << std::endl;
        if(down) {
            up = true;
            down = false;
        }
    }
    //player colition
    if(spriteBall.getPosition().y >= player2.getPosition().y && spriteBall.getPosition().y <= player2.getPosition().y + 250 && spriteBall.getPosition().x >= player2.getPosition().x && spriteBall.getPosition().x <= player2.getPosition().x + 20) {
        changeDirection(1);
        std::cout << "colition" << std::endl;
    }
    if(spriteBall.getPosition().y >= player1.getPosition().y && spriteBall.getPosition().y <= player1.getPosition().y + 250 && spriteBall.getPosition().x >= player1.getPosition().x - 20 && spriteBall.getPosition().x <= player1.getPosition().x) {
        changeDirection(0);
        std::cout << "colition" << std::endl;
    }
 }


void changeDirection(int id) {
    if(id == 1){ 
        if(&up && &left) {
            up = false;
            left = false;
            down = true;
            right = true;
        }else if(&down && &right) {
            up = true;
            left = true;
            down = false;
            right = false;
        }
    }
    if(id == 0) {
        if(&up && &left) {
            up = true;
            left = true;
            down = false;
            right = false;
        }else if(&down && &right) {
            up = false;
            left = false;
            down = true;
            right = true;
        }
    }
}