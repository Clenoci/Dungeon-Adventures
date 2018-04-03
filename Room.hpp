#ifndef ROOM_HPP
#define ROOM_HPP
#include <vector>
#include <string>
#include <iostream>
#include "Enemy.hpp"
#include "CustomPlayer.hpp"
#include "Goblin.hpp"
#include "BattleMage.hpp"
#include "GoblinArcher.hpp"
#include "HellHound.hpp"
#include "Skeleton.hpp"
#include "Warrior.hpp"
#include "Cerberus.hpp"
#include "Spider.hpp"
#include "Object.hpp"
#include "HealthPotion.hpp"
#include "BossKey.hpp"
#include "Ogre.hpp"
#include "StrengthPotion.hpp"


class Room{

public:
	Room();
	Room(std::string description,int roomNumber);
	Room* getNextRoom(int direction);
	Room* getPreviousRoom();
	void printAvailableDoors();
	void setPreviousRoom(Room* previousRoom);
	void setNextRoom();
	void setWhichWallsHaveADoor(Room* north,Room* east,Room* south,Room* west);
	void EnemyStatus();
	void addMonster(Enemy* currentEnemy);
	void addObject(Object* currentObject);
	void printRoomDescription();
	void setRoomDescription(std::string description);
	std::string getRoomDescription();
	void inspectRoom(); //gives a list of all items, enemies and other objects in the room. and location of the doors.
	void printEnemiesInRoom();
	std::vector<Enemy*> getEnemies();
	void setEnemiesInRoom(std::vector<Enemy*> enemies);
	void setIsEveryOneDeadTrue();
	bool getIsEveryOneDead();
	int getRoomNumber();
	std::vector<Object*> getObjectsInRoom();



private:
	std::vector<Enemy*> enemiesInRoom; //any enemy in that room, more may be spawned by the enemies in the room.
	std::vector<Object*> ObjectsInRoom;//chests, random loot on floor, loot from dead enemies. 
	Room* whichWallsHaveADoor[4]; //array [4] of four numbers each representing a wall(n/e/s/w)
	Room* previousRoom;
	std::string roomDescription;
	std::string RoomIntroduction;
	//std::string roomName;
	int RoomNumber;
	bool IsEveryOneDead=false;


	


};

#endif