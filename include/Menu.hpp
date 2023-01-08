#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, sf::Color color, float sizeX, float sizeY, float x, float y);
        bool isSelected();
        sf::RectangleShape spriteButton;

    private:
        std::string label;
        float x;
        float y;
        float sizeX;
        float sizeY;
};