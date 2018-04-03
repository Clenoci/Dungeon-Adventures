#include "Room.hpp"


Room::Room(){


}
Room::Room(std::string description,int roomNumber){

	this->roomDescription=description;
	this->RoomNumber=roomNumber;

}
Room* Room::getNextRoom(int direction){
	Room* tempRoom=whichWallsHaveADoor[direction];

	if(direction<4&&tempRoom!=NULL){
		return tempRoom;
	}
	else {
		std::cout<<"You are attempting to go through a wall that does not have a door, Lets do something different?\n";
		tempRoom=this;
		return tempRoom;
	}
}

Room* Room::getPreviousRoom(){
	return this->previousRoom;
}

void Room::setPreviousRoom(Room* currentRoom){
	previousRoom=currentRoom;
	
}

void Room::setNextRoom(){

}

void Room::addMonster(Enemy* currentEnemy){
	enemiesInRoom.push_back(currentEnemy);

}

void Room::addObject(Object* currentObject){
	ObjectsInRoom.push_back(currentObject);
}

void Room::setWhichWallsHaveADoor(Room* north,Room* east,Room* south,Room* west){

	this->whichWallsHaveADoor[0]=north;
	this->whichWallsHaveADoor[1]=east;
	this->whichWallsHaveADoor[2]=south;
	this->whichWallsHaveADoor[3]=west;
}

void Room::EnemyStatus(){

	
}

void Room::printRoomDescription(){
	if(IsEveryOneDead==true){
		std::cout<<"You've already been in this room \n";
	}
	else std::cout<<this->getRoomDescription()<<"\n";
}

std::string Room::getRoomDescription(){

	return this->roomDescription;
}
void Room::setRoomDescription(std::string description){

	this->roomDescription=description;
}

void Room::printEnemiesInRoom(){

	for(Enemy* currentEmemy: enemiesInRoom){
		currentEmemy->PrintStats();
	}
}
void Room::printAvailableDoors(){
	std::string direction;
	for(int i =0; i<4; i++){
		if(i==0){
			direction="North (0)\n";	
		}	
		else if(i==1){
			
			direction="East (1)\n";	
		}
		else if(i==2){
			direction="South (2)\n";	
		}
		else if(i==3){
			direction="West (3)\n";	
		}
		if (this->whichWallsHaveADoor[i]!=NULL){

			std::cout<<"Doorway "<<direction;
		}
		else std::cout<<"Wall "<<direction;
		
	}	
}

std::vector<Enemy*> Room::getEnemies(){
	return this->enemiesInRoom;
}

void Room::inspectRoom(){
	std::cout<<"\n In this room there is,";
	for(Object* object: ObjectsInRoom){
		std::cout<<" A "<<object->getName()<<"\n";
	}
	if(ObjectsInRoom.size()<1){
		std::cout<<" nothing of interest\n";
	}
	std::cout<<std::endl;
	printAvailableDoors();

}

void Room::setEnemiesInRoom(std::vector<Enemy*> enemies){
	enemiesInRoom=enemies;
}

void Room::setIsEveryOneDeadTrue(){
	this->IsEveryOneDead=true;

}

bool Room::getIsEveryOneDead(){
	return this->IsEveryOneDead;

}

int Room::getRoomNumber(){
	return this->RoomNumber;
}

std::vector<Object*> Room::getObjectsInRoom(){
	return this->ObjectsInRoom;
}