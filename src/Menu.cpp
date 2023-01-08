#include "../include/Menu.hpp"

Button::Button(std::string lable, sf::Color color, float sizeX, float sizeY, float x, float y) {
    this->label = label;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->x = x;
    this->y = y;
    spriteButton.setSize(sf::Vector2(sizeX, sizeY));
    spriteButton.setPosition(x, y);
    spriteButton.setFillColor(color);
    std::cout << "a Button has been generated." << std::endl;
}

bool Button::isSelected() {
    
    return false;
}