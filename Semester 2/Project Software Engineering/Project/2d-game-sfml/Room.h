//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

using namespace std;

class Room {
public:
    // Deze functie niet aanpassen!
    void render(sf::RenderWindow *window) const;

    // Deze functie zal je zelf verder moeten aanvullen
    void update(sf::Event *event);


private:
    vector<Entity *> entities;

public:
    [[nodiscard]] vector<Entity *> getEntities() const;

    void addEntity(Entity *e);

    void removeEntity(const Entity *e);
};

inline vector<Entity *> Room::getEntities() const {
    return entities;
}

inline void Room::addEntity(Entity *const e) {
    entities.push_back(e);
}

inline void Room::removeEntity(const Entity *e) {
    for (auto p = entities.begin(); ; ++p) {
        if (*p == e) {
            // make a new floor to replace the removed entity
            Entity *ee = new Floor();
            ee->setSprite("resources/floor.png");
            ee->setPosition(e->getPosition());

            addEntity(ee);
            entities.erase(p);
            break;
        }
    }
}

#endif //ROOM_H
