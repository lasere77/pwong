#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, sf::Color color, float sizeX, float sizeY, float x, float y);
        bool isSelected(sf::Vector2i vector);
        std::string label;
        sf::RectangleShape spriteButton;
        sf::Text text;

    private:
        sf::Font font;
        float x;
        float y;
        float sizeX;
        float sizeY;
};