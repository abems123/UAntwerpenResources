//
// Created by Tim Apers on 29/10/2024.
//

#include "Room.h"

#include <iostream>

void Room::render(sf::RenderWindow *window) const {
    Player *player = nullptr;
    std::vector<Entity *> others = {};
    for (Entity *entity: entities) {
        if (auto *floor = dynamic_cast<Floor *>(entity)) { floor->render(window); } else if (auto *p = dynamic_cast<
            Player *>(entity)) { player = p; } else { others.push_back(entity); }
    }
    for (Entity *e: others) { e->render(window); }
    if (player) { player->render(window); }
}

void Room::update(sf::Event *event) {
    Player *player = nullptr;
    Enemy *enemy = nullptr;
    Weapon *weapon = nullptr;

    vector<Wall *> walls;

    for (Entity *entity: entities) {
        entity->update(event);

        if (auto *p = dynamic_cast<Player *>(entity)) player = p;
        else if (auto *e = dynamic_cast<Enemy *>(entity)) enemy = e;
        else if (auto *we = dynamic_cast<Weapon *>(entity)) weapon = we;
        else if (auto *w = dynamic_cast<Wall *>(entity)) walls.push_back(w);
    }

    // if the enemy is not null and the player stands on the enemy, and the interacts function doesn't return
    // a nullpointer, remove the entity
    if (enemy && player->standsOn(enemy) && enemy->interacts(player)) {
        removeEntity(enemy);
    }


    // if there exists a weapon in the room and the player stands on it, then call the interacts function
    // and the attackpower will be increased with 1, then remove the weapon
    if (weapon && player->standsOn(weapon) && weapon->interacts(player))
        removeEntity(weapon);


    // check for each wall
    for (auto *w: walls)
        // if the player stands on a wall
        if (player->standsOn(w)) w->interacts(player);
}
