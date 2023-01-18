#include "../include/Menu.hpp"

Button::Button(std::string label, sf::Color color, float sizeX, float sizeY, float x, float y) {
    this->label = label;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->x = x;
    this->y = y;
    spriteButton.setSize(sf::Vector2(sizeX, sizeY));
    spriteButton.setPosition(x, y);
    spriteButton.setFillColor(color);
    
    if(!font.loadFromFile("assets/font/poppins.ttf")) {
        std::cerr << "error" << '\n';
    }
    text.setCharacterSize(15);
    text.setFont(font);
    text.setPosition(sf::Vector2(x + (sizeX / 2) - (label.length() * 2), y + (sizeY / 2 - 10)));
    text.setString(label);
    std::cout << "a Button has been generated." << std::endl;
}

bool Button::isSelected(sf::Vector2i vector) {
    if(x <= sf::Mouse::getPosition().x && x + 250.0f >= sf::Mouse::getPosition().x && y + 10 <= sf::Mouse::getPosition().y && y + 80.0f >= sf::Mouse::getPosition().y  && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
        spriteButton.setFillColor(sf::Color::Blue);
        return true;
    }else {
        spriteButton.setFillColor(sf::Color::Red);
    }
    return false;
}