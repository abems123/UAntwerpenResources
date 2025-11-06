//
// Created by Tim Apers on 29/10/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Room.h"

class Game {
public:
    // Deze functies niet aanpassen!
    Game(sf::RenderWindow *window);

    void update();

    std::vector<Room *> getRooms() { return rooms; }
    Room *getCurrentRoom() { return currentRoom; }

    static string correctImage(char c);

    // Deze functies zal je zelf verder moeten aanvullen
    void loadMap(const std::string &filename);

    void setCurrentRoom();

    [[nodiscard]] bool getSideRooms() const;
    void setSideRoom(bool b);
private:
    sf::RenderWindow *window;
    std::vector<Room *> rooms;
    Room *currentRoom = nullptr;
    Player *player;

    bool sideRooms;
};

inline bool Game::getSideRooms() const {
    return sideRooms;
}

inline void Game::setSideRoom(const bool b) {
    sideRooms = b;
}
#endif //GAME_H
