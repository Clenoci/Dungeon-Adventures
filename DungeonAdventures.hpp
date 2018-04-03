#ifndef DUNGEONADVENTURES_H
#define DUNGEONADVENTURES_H
#include "Dungeon.hpp"

class DungeonAdventures{
	
	public:
		DungeonAdventures();
		void Combat(std::vector<Enemy*> enemiesInRoom);
		void StoryIntroduction();
		void CreateCharacter(int playerClass,std::string name,int health,int weapon);
		void loadCharacter();
		void saveCharacter();
		void CharacterSetup();
		void CombatMenu(std::vector<Enemy*> enemiesInRoom);
	 	void moveToNextRoom(int roomDirection);
	 	void RoomMenu();
	 	void moveToNextRoom();
	 	void SearchObjects();
	 	bool PuzzleRoomOne();
	 	void CreateSearchableCorpse(Enemy* enemy);
	 	void EnemyMove(std::vector<Enemy*> enemiesInRoom);
	 	std::vector<Item*> UseItem();


	private:
		bool hasBossKey=true;
		bool killedPuzzleGoblin=false;
		int howManyStoneGoblinsActive=3;
		CustomPlayer* currentAdventurer;
		int warriorHealth=250;
		int battleMageHealth=150;
		int north=0;
		int south=2;
		int east=1;
		int west=3;
		Room* currentRoom;
		bool InCombat;
		bool GameOver;
		

};

#endif