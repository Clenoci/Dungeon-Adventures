#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include "Room.hpp"



class Dungeon{

	public:
		Dungeon();
		Room* getCurrentRoom();
		void setPuzzleRoomOneSuccessful();
		bool getPuzzleRoomOneSuccessful();
	private:	
		Room* currentRoom=new Room();
		bool isPuzzleRoomOneSuccessful=false;
		int  PuzzleRoom2NumberActivated=3;
		int  GoblinHealth=20;
		int	 GoblinArcherHealth=15;
		int  SkeletonHealth=30;
		int	 SpiderHealth=10;
		int  CerberusHealth=50;
		int  HellHoundHealth=25; 
		int  GoblinDamage=3;
		int	 GoblinArcherDamage=5;
		int  SkeletonDamage=7;
		int	 SpiderDamage=1;
		int  CerberusDamage=10;
		int  HellHoundDamage=6;

};

#endif