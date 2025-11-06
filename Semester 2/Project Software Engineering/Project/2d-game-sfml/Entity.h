//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Player;

struct Position {
    int x;
    int y;
};

class Entity {
public:
    virtual void update(sf::Event *event);

    // Onderstaande functies niet aanpassen!
    void setSprite(const std::string &img_path);

    void render(sf::RenderWindow *painter);

    ~Entity() = default;

private:
    Position position;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // get the position of the entity
    [[nodiscard]] Position getPosition() const;

    // set the position of the entity
    void setPosition(const Position &position);

    // get the position of the entity
    bool standsOn(const Entity *e) const;

    virtual Entity *interacts(Player *player);
};

inline Entity *Entity::interacts(Player *player) {
    return nullptr;
}

class Player : public Entity {
    Position oldPosition = {};
    int attackPower = 0;

public:
    void update(sf::Event *event) override;

    [[nodiscard]] int getAttackPower() const;

    void setAttackPower(int attack_power);

    void setOldPosition(Position p);

    Position getOldPosition() const;
};

inline Position Player::getOldPosition() const {
    return oldPosition;
}

inline void Player::setOldPosition(Position p) {
    oldPosition = p;
}


inline int Player::getAttackPower() const {
    return attackPower;
}

inline void Player::setAttackPower(const int attack_power) {
    attackPower = attack_power;
}

inline Position Entity::getPosition() const {
    return position;
}

inline void Entity::setPosition(const Position &position) {
    this->position = position;
    sprite.setPosition(position.x, position.y);
}



inline bool Entity::standsOn(const Entity *e) const {
    return e->getPosition().x == this->getPosition().x && e->getPosition().y == this->getPosition().y;
}

class Weapon : public Entity {
public:
    Entity *interacts(Player *player) override;
};

inline Entity *Weapon::interacts(Player *player) {
    player->setAttackPower(1);
    return this;
}

class Wall : public Entity {
public:
    Entity *interacts(Player *player) override;
};

inline Entity *Wall::interacts(Player *player) {
    // set the position of the player to the old one
    player->setPosition(player->getOldPosition());
    return nullptr;
}

class Floor : public Entity {
};

class Enemy : public Entity {
public:
    Entity *interacts(Player *player) override;
};

inline Entity *Enemy::interacts(Player *player) {
    // if the attack power is not 0 then return the Enemy Instance
    if (player->getAttackPower()) {
        return this;
    }

    // set the position of the player to the old one
    player->setPosition(player->getOldPosition());
    return nullptr;
}
#endif //ENTITY_H
