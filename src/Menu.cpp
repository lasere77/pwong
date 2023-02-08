#include "../include/Menu.hpp"

bool respectDelay = true;
int delay = 0;

void setDelay(int delayRequest) {
    delay++;
    if(delay >= delayRequest) {
        respectDelay = true;
    }
}
void resetDelay() {
    respectDelay = false;
    delay = 0;
}

Button::Button(std::string label, float sizeX, float sizeY, float x, float y, bool split, bool onScene) {
    this->x = x;
    this->y = y;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->onScene = onScene;
    spriteButton.setSize(sf::Vector2(sizeX, sizeY));
    spriteButton.setPosition(x, y);
    
    if(!font.loadFromFile("assets/font/poppins.ttf") || !texture.loadFromFile("assets/Button/Texture/button.jpg") || !bufferSound.loadFromFile("assets/Button/Sound/onClick.wav")) {
        std::cerr << "error to load font, texture or sound, please check your assets" << std::endl;
    }
    sound.setBuffer(bufferSound);
    spriteButton.setTexture(&texture);
    
    text.setCharacterSize(15);
    text.setFont(font);
    if(split) {
        text.setPosition(sf::Vector2(x + (sizeX / 2) - (label.length() * 4), y + (sizeY / 2 - 10)));
    }else {
        text.setPosition(sf::Vector2(x + (sizeX / 2) - (label.length() * 2), y + (sizeY / 2 - 10)));
    }
    text.setString(label);
    std::cout << "a Button has been generated." << std::endl;
}

bool Button::isSelected(sf::Vector2i vector) {
    setDelay(180);
    if(respectDelay && onScene && x <= (sf::Mouse::getPosition().x - vector.x) && x + sizeX >= (sf::Mouse::getPosition().x - vector.x) && y <= (sf::Mouse::getPosition().y - vector.y) && y + sizeY >= (sf::Mouse::getPosition().y - vector.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
        resetDelay();
        sound.play();
        return true;
    }
    return false;
}


sf::Text Button::getText() {
    return text;
}

void Button::setOnScene(bool onScene) {
    this->onScene = onScene;
}

/*
Entry
*/
Entry::Entry(float sizeX, float sizeY, float x, float y, bool onScene) {
    this->x = x;
    this->y = y;
    spriteEntry.setSize(sf::Vector2(sizeX, sizeY));
    spriteEntry.setPosition(x, y);
    spriteEntry.setFillColor(sf::Color::Black);
    spriteEntry.setOutlineColor(sf::Color::Red);
    spriteEntry.setOutlineThickness(5.0f);

    if(!bufferSound.loadFromFile("assets/Button/Sound/onClick.wav") || !font.loadFromFile("assets/font/poppins.ttf")) {
        std::cerr << "error to load font or sound, please check your assets" << std::endl;
    }
    sound.setBuffer(bufferSound);
    text.setCharacterSize(15);
    text.setFont(font);
    text.setString("4");
    text.setPosition(sf::Vector2(x + 10, y + 15));
    std::cout << "a Entry has been generated." << std::endl; 
}

bool Entry::isSelected(sf::Vector2i vector) {
    setDelay(180);
    if(checkKeyboard) {
        spriteEntry.setOutlineColor(sf::Color::Blue);
    }else {
        spriteEntry.setOutlineColor(sf::Color::Red);
    }
    if(respectDelay && onScene && x <= (sf::Mouse::getPosition().x - vector.x) && x + 250.0f >= (sf::Mouse::getPosition().x - vector.x) && y <= (sf::Mouse::getPosition().y - vector.y) && y + 50.0f >= (sf::Mouse::getPosition().y - vector.y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        resetDelay();
        sound.play();
        if(checkKeyboard) {
            checkKeyboard = false;
        }else {
            checkKeyboard = true;
        }
        return true;
    }
    return false;
}

void Entry::setOnScene(bool onScene) {
    this->onScene = onScene;
}

sf::Text Entry::getText() {
    return text;
}

bool Entry::getCheckKeyboard() {
    return checkKeyboard;
}
void Entry::setCheckKeyboard(bool checkKeyboard) {
    this->checkKeyboard = checkKeyboard;
}

void Entry::setText(char text) {
    this->text.setString(this->text.getString() + text);
}
void Entry::BackSpaceText() {
    std::string str = text.getString();
    if(!str.empty()) {
        str.pop_back();
        text.setString(str);
    }
}

std::string Entry::getKey() {
    //converte entry String to int
    std::string entryOutput = text.getString();
    std::string output;
    for(int i = 0; i != entryOutput.length(); i++) {
        for(int j = 0;  j != 10; j++) {
            std::cout << (int)entryOutput.at(i) - 48 << std::endl;
            if((int)entryOutput.at(i) - 48 == j) {
                output += entryOutput.at(i);
            }
        }
    }
    return output;
}