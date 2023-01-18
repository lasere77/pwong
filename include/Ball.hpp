#pragma once

class Ball {
    public:
        Ball(float speed, float x, float y);
        void colition(sf::RectangleShape player1, sf::RectangleShape player2, float height);
        void move();
        sf::CircleShape spriteBall;

    private:
        float speed;
        float originalSpeed;
        float rngSpeed;
};