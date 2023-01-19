#pragma once
#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, sf::Color color, float sizeX, float sizeY, float x, float y);
        bool isSelected(sf::Vector2i vector);
        sf::RectangleShape spriteButton;
        sf::Text text;

    private:
        std::string label;
        sf::Font font;
        float x;
        float y;
        float sizeX;
        float sizeY;
};