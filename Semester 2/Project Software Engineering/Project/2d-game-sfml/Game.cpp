//
// Created by Tim Apers on 29/10/2024.
//

#include <SFML/Graphics.hpp>
#include<fstream>

#include "Game.h"

#include <iostream>


Game::Game(sf::RenderWindow* window)
{
    this->window = window;
}

void Game::update()
{
    setCurrentRoom();
    this->window->clear();
    if (currentRoom) { currentRoom->render(this->window); }

    this->window->display();
    while (window->isOpen())
    {
        sf::Event event;

        // Wait for event to fire
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                currentRoom->update(&event);
                setCurrentRoom();
                this->window->clear();
                currentRoom->render(this->window);

                this->window->display();
            }
        }
    }
}

string Game::correctImage(const char c)
{
    switch (c)
    {
    case '=':
        return "resources/lane.png";

    case 'A':
        return "resources/auto.png";

    case 'B':
        return "resources/bus.png";

    case 'P': return "resources/politiecombi.png";

    case 'I': return "resources/brandweerwagen.png";

    case 'Z': return "resources/ziekenwagen.png";

    default: return "resources/player.png";
    }
}

void Game::loadMap(const std::string& filename)
{
    rooms.push_back(new Room());

    // Load a texture from an image file
    ifstream contents{filename};

    if (!contents.is_open())
    {
        // An error happened while trying to open the file!
        return;
    }

    // The lines of the file resources/map.txt will be saved in this variable
    string line;
    int roomIndex = 0;
    int playersRoom = 0;

    int y = 0;
    while (getline(contents, line))
    {
        if (line.size() > 7) setSideRoom(true);
        int x = 0;

        for (int n = line.size(); x < n; x++)
        {
            roomIndex = x / 7 + y / 7; // 0: the enemy's room, 1: the player's room, 2: the sword's room

            // add a new room
            if (roomIndex >= rooms.size())
                rooms.push_back(new Room());

            Entity* entity; // make a new entity
            sf::Sprite s; // make a new sprite

            switch (line[x])
            {
            case '#':
                entity = new Wall();
                break;
            case '%':
                entity = new Enemy();
                break;
            case '!':
                entity = new Weapon();
                break;
            case '_':
                entity = new Floor();
                break;
            default:
                entity = new Player();

            // ================ setting a floor behind the player =================
                Entity* fl = new Floor();
                Position fp{};
                fp.x = x * 100;
                fp.y = y * 100;
                fl->setSprite(correctImage('_'));
                fl->setPosition(fp);
                rooms[roomIndex]->addEntity(fl);
            // ================ setting a floor behind the player =================

            // saving the entity of the player
                player = dynamic_cast<Player*>(entity);

            // save the index of the room where the player exists, I could only use 1 but this will work for any map
                playersRoom = roomIndex;


                break;
            }


            // loading the textures that we will need in the textures map
            entity->setSprite(correctImage(line[x]));
            Position p{};
            p.x = x * 100;
            p.y = y * 100;
            entity->setPosition(p);
            rooms[roomIndex]->addEntity(entity);
        }
        y++;
    }

    // adding the player to the other rooms so that the player gets rendered when the room is changed
    for (int i = 0, n = rooms.size(); i < n; i++)
    {
        if (i != playersRoom)
        {
            rooms[i]->addEntity(player);
        }
    }
    setCurrentRoom();
}

void Game::setCurrentRoom()
{
    Position p = player->getPosition();
    currentRoom = rooms[p.x / 700 + p.y / 700];
}
