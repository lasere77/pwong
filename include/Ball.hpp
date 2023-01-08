#pragma once

class Ball {
    public:
        Ball(float speed);
        void colition(sf::RectangleShape player1, sf::RectangleShape player2);
        void move();
        sf::CircleShape spriteBall;

    private:
        float speed;
};