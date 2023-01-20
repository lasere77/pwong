#include "../include/Menu.hpp"

int delayBtn = 0;

Button::Button(std::string label, float sizeX, float sizeY, float x, float y) {
    this->label = label;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->x = x;
    this->y = y;
    spriteButton.setSize(sf::Vector2(sizeX, sizeY));
    spriteButton.setPosition(x, y);
    
    if(!font.loadFromFile("assets/font/poppins.ttf") || !texture.loadFromFile("assets/Button/Texture/button.jpg") || !bufferSound.loadFromFile("assets/Button/Sound/onClick.wav")) {
        std::cerr << "error to load font, texture or sound, please check your assets" << std::endl;
    }
    sound.setBuffer(bufferSound);
    spriteButton.setTexture(&texture);
    
    text.setCharacterSize(15);
    text.setFont(font);
    text.setPosition(sf::Vector2(x + (sizeX / 2) - (label.length() * 2), y + (sizeY / 2 - 10)));
    text.setString(label);
    std::cout << "a Button has been generated." << std::endl;
}

bool Button::isSelected(sf::Vector2i vector) {
    if(x <= (sf::Mouse::getPosition().x - vector.x) && x + 250.0f >= (sf::Mouse::getPosition().x - vector.x) && y <= (sf::Mouse::getPosition().y - vector.y) && y + 50.0f >= (sf::Mouse::getPosition().y - vector.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
        sound.play();
        return true;
    }
    return false;
}