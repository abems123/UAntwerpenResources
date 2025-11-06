//
// Created by Tim Apers on 29/10/2024.
//

#include "Entity.h"
#include <iostream>

void Entity::setSprite(const std::string &img_path) {
    if (!this->texture.loadFromFile(img_path)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    sf::Vector2u size = this->texture.getSize();
    float scaleX = 100.0f / size.x;
    float scaleY = 100.0f / size.y;
    this->sprite.setScale(scaleX, scaleY);
}

void Entity::render(sf::RenderWindow *window) {
    sprite.setPosition(position.x % 700, position.y % 700);
    window->draw(sprite);
}

void Entity::update(sf::Event *event) {
}


void Player::update(sf::Event *event) {
    setOldPosition(getPosition());

    auto newPos = getPosition();

    switch (event->key.code) {
        case sf::Keyboard::Left:
            // Move to the left
            newPos.x -= 100;
            break;
        case sf::Keyboard::Right:
            // Move to the right
            newPos.x += 100;
            break;
        case sf::Keyboard::Up:
            // Move up
            newPos.y -= 100;
            break;
        case sf::Keyboard::Down:
            // Move down
            newPos.y += 100;
            break;

        default: break;
    }

    setPosition(newPos);
}

