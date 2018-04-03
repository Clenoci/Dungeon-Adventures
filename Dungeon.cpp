#include "Dungeon.hpp"
//#include <iostream>
Dungeon::Dungeon(){
	
	//ROOMS IN THE DUNGEON
	Room* CaveEntry= new Room("\n After your grab your weapon you follow the miscreants footsteps back to the opening of a Cave\nAs you walk in the the Cave Entrance you quickly notice two Goblin Archers and a Goblin sitting around a fire.\nThe Cave Entry is very larger and empty other than the fire and the three Goblins in front of you.\nThere is only one doorway in this room on the south wall. The Goblins notice you enter and stand up facing you with their weapons drawn\n",1);
	Room* PuzzleRoom= new Room("\nThis room is much smaller than the last, just a narrow hallway lined with torches leading to a single door on the east wall. Standing in front of this door is a single Goblin that seems to be unarmed. As you approach you notice he has an unsettling grin upon his face",2);
	Room* DungeonRoom3= new Room("\nAs you walk through the door you think to yourself this is going to be easy, that Ogre is going to regret attacking my town...The Door slams shut behind you. As your eyes adjust to the dim light you see Goblins at the ready to kill you",3);
	Room* DungeonRoom4= new Room("\nAt first glance you believe this room is empty other than two piles of bones along both sides of the room. As you walk into the middle of the room you hear the bones start to move. The bones build up into skeleton warriors and start to  surround you",4);
	Room* DungeonRoom5= new Room("\nAHHH the floor is absolutely covered in spiders the size of a small dog (maybe a shitzu or mini schnauzer). You think to yourself, how bad to I actually want revenege? ",5);
	Room* DungeonRoom6= new Room("\nIts uhhh... just an empty room? ",6);
	Room* DungeonRoom7= new Room("\nANOTHER ROOM WITH GOBLINS?! come on... you know what to do",7);
	Room* PuzzleRoom2= new Room("\nYou walk into the room and this is unlike most other rooms in the dungeon as it is well lit with a red carpet cover most of the floor. In the Middle of the room sits three stone Goblin Statues all holding glowing red orbs",8);
	Room* DungeonRoom9= new Room("\nANOTHER ROOM WITH GOBLINS?! come on... you know what to do",9);
	Room* SecretRoom=new Room("\nSome how you just walked through the wall, it leaves you feeling a little bit strange. That goblin wasn't lying about the weird walls.... Once you get over how weird that just was you realize your standing in a small dark room with a single light coming from the ceiling down onto a pedistal in the center of the room. On this pedistal you see A Golden Gauntlet With 6 brightly colored glowing stones. It looks as though it does not belong in this game, never mind this dungeon. How did this Ogre get his hands on this tech? Immediately you can feel the imense power eminating from it.",10);
	Room* DungeonKeyHallway= new Room("\nYou walk into a long brightly lit hallway at the end you see two large doors",11);
	Room* DungeonKeyRoom= new Room("\nThe room is pitch black, you cautiously, slowly walk into the room. Within a few steps into the room, you can hear what sounds like deep breathing, from multiple sources. Cautiously you continue to walk into the room, as you get further in you can tell the room is very large by the echos of your footsteps. As your slowly working your way into the room you take a step and the floor underneath you shifts slightly. This causes the all the torches lining the room to light and fill the room with light. At the end of the Room you see a Cerberus!!! all three heads visably very upset with your presence, It charges at you... ",12);
	Room* TreasureRoom= new Room("\nThis is my kind of room, no Monsters and lots of treasure!",13);
	Room* BossRoomHallway= new Room("\nIn the backround you faintly hear ominous music playing",14);
	Room* BossRoom= new Room("\nAs you walk in the door slams shut behind you and locks. There is no way out... You see this large room filled with treasure, but also enemies! There in the middle of the room is Sheldon the Destroyer playing with a childs toy, trying to figure out what it does\nYou sit and watch for a moment amused at his struggles with such a simple toy before Sheldon notices you have entered his lair. Upon noticing you he is furious. Sheldon Exclaims HOW DID YOU GET IN HERE?? WHO DO YOU THINK YOU ARE?!?\n Your only response.... TO KILL YOU!! I will have my revenge. Tired and pissed off you don't let him get off another word before you launch your first attack",15);

	//CREATE ALL ENEMIES//
	//Create all objects in Rooms
	//Populate Rooms
	Object* desk=new Object("Wooden Desk");
	desk->addItemToObject(new HealthPotion());
	Goblin* goblin1Room1 = new Goblin("Michael",GoblinHealth,GoblinDamage);
	Goblin* goblin2Room1 = new Goblin("Pichael",GoblinHealth,GoblinDamage);
	GoblinArcher* goblinArcher1Room1= new GoblinArcher("Ranger Rick",GoblinArcherHealth,GoblinArcherDamage);\
	goblinArcher1Room1->AddItemToInventory(new HealthPotion());
	CaveEntry->addObject(desk);
	CaveEntry->addMonster(goblin1Room1);
	CaveEntry->addMonster(goblin2Room1);
	CaveEntry->addMonster(goblinArcher1Room1);
	//puzzle Room 1
	Goblin* goblinPuzzleRoom2 = new Goblin("Smerll",30,GoblinDamage); //has a riddle for you
	PuzzleRoom->addMonster(goblinPuzzleRoom2);
	//Third room
	Goblin* goblin2Room3 = new Goblin("Randy",GoblinHealth,GoblinDamage);
	GoblinArcher* goblinArcher1Room3= new GoblinArcher("Robin Hood",GoblinArcherHealth,GoblinArcherDamage);
	GoblinArcher* goblinArcher2Room3= new GoblinArcher("Oliver Queen",GoblinArcherHealth,GoblinArcherDamage);
	DungeonRoom3->addMonster(goblin2Room3);
	DungeonRoom3->addMonster(goblinArcher1Room3);
	DungeonRoom3->addMonster(goblinArcher2Room3);
	// fourth  room, no enemies few things to search
	Object* deskp=new Object("Wooden Desk");
	Skeleton* skeleton1Room4=new Skeleton("Brent",SkeletonHealth,SkeletonDamage); 
	Skeleton* skeleton2Room4=new Skeleton("Trent",SkeletonHealth,SkeletonDamage);
	DungeonRoom4->addMonster(skeleton1Room4);
	DungeonRoom4->addMonster(skeleton2Room4);
	DungeonRoom4->addObject(deskp);
	//Treasure Room :2 hell hounds
	Object* Chest=new Object("Treasure Chest");
	Chest->addItemToObject(new StrengthPotion());
	Chest->addItemToObject(new HealthPotion());
	HellHound* hellHound1RoomT=new HellHound("Spot",HellHoundHealth,HellHoundDamage);
	HellHound* hellHound2RoomT=new HellHound("YBOOCS DOO",HellHoundHealth,HellHoundDamage);
	TreasureRoom->addObject(Chest);
	TreasureRoom->addMonster(hellHound1RoomT);
	TreasureRoom->addMonster(hellHound2RoomT);
	//Fifth Room
	Spider* spider1Room5=new Spider("Charlette",SpiderHealth,SpiderDamage);
	Spider* spider2Room5=new Spider("Chuck",SpiderHealth,SpiderDamage);
	Spider* spider3Room5=new Spider("Charles",SpiderHealth,SpiderDamage);
	Spider* spider4Room5=new Spider("Chucky",SpiderHealth,SpiderDamage);
	Spider* spider5Room5=new Spider("Christine",SpiderHealth,SpiderDamage);
	DungeonRoom5->addMonster(spider1Room5);
	DungeonRoom5->addMonster(spider2Room5); 
	DungeonRoom5->addMonster(spider3Room5);
	DungeonRoom5->addMonster(spider4Room5);
	DungeonRoom5->addMonster(spider5Room5); 
	//sixth room
	//Empty room? 
	//dungeon key hallway
	Object* desk1=new Object("Wooden Desk");
	Object* desk2=new Object("Old Handbag");
	HellHound* hellHound1RoomKH=new HellHound("Lassie",HellHoundHealth,HellHoundDamage);
	HellHound* hellHound2RoomKH=new HellHound("Scrappy Doo",HellHoundHealth,HellHoundDamage);
	DungeonKeyHallway->addMonster(hellHound1RoomKH);
	DungeonKeyHallway->addObject(desk1);
	DungeonKeyHallway->addObject(desk2);

	DungeonKeyHallway->addMonster(hellHound2RoomKH);
	//dungeon key room
	Object* chest= new Object("Large Treasure Chest");
	BossKey* Key= new BossKey();
	chest->addItemToObject(Key);
	Cerberus* cerberus1RoomK=new Cerberus("Fluffy",CerberusHealth,CerberusDamage);//has dungeon key around his neck.
	DungeonKeyRoom->addObject(chest);
	DungeonKeyRoom->addMonster(cerberus1RoomK);
	//seventh room
	Goblin* goblin1Room7 = new Goblin("Roblin",GoblinHealth,GoblinDamage);
	Goblin* goblin2Room7 = new Goblin("Scout",GoblinHealth,GoblinDamage);
	DungeonRoom7->addMonster(goblin1Room7);
	DungeonRoom7->addMonster(goblin2Room7); 

	//puzzle room 2
	Object* StoneGoblin1=new Object("Stone Goblin");
	Object* StoneGoblin2=new Object("Stone Goblin");
	Object* StoneGoblin3=new Object("Stone Goblin");
	
	PuzzleRoom2->addObject(StoneGoblin1);
	PuzzleRoom2->addObject(StoneGoblin2);
	PuzzleRoom2->addObject(StoneGoblin3);

	//Three stone goblin objects
	//ninth room
	Spider* spider1Room9=new Spider("Mister Spider",SpiderHealth,SpiderDamage);
	Skeleton* skeleton1Room9=new Skeleton("Bones",SkeletonHealth,SkeletonDamage);
	Skeleton* skeleton2Room9=new Skeleton("Fat Joe",SkeletonHealth,SkeletonDamage);
	DungeonRoom9->addMonster(spider1Room9);
	DungeonRoom9->addMonster(skeleton1Room9);
	DungeonRoom9->addMonster(skeleton2Room9);
	//Boss hallway

	Object* wardrobe=new Object("Wardrobe");
	Object* table=new Object("Banquet Table");
	Object* pileofRocks=new Object("Pile of Rocks");
	BossRoomHallway->addObject(wardrobe);
	BossRoomHallway->addObject(table);
	BossRoomHallway->addObject(pileofRocks);

	//Full of items and objects to search

	//Boss Room
	GoblinArcher* goblinArcher1RoomB= new GoblinArcher("Bucky",GoblinArcherHealth,GoblinArcherDamage);
	GoblinArcher* goblinArcher2RoomB= new GoblinArcher("Steve",GoblinArcherHealth,GoblinArcherDamage);
	HellHound* hellHound1RoomB=new HellHound("Fido",HellHoundHealth,HellHoundDamage);
	HellHound* hellHound2RoomB=new HellHound("Milo",HellHoundHealth,HellHoundDamage); 
	Ogre* Boss=new Ogre();
	BossRoom->addMonster(goblinArcher1RoomB);
	BossRoom->addMonster(goblinArcher2RoomB);
	BossRoom->addMonster(hellHound1RoomB);
	BossRoom->addMonster(hellHound2RoomB);
	BossRoom->addMonster(Boss);
	//BossRoom->addMonster(goblin1Room7);
	//BOSS


	//Secret room is a wall that must be attacked and destroyed before being used. Shortcut with awesome hidden item
	//Secret it is infinity Guantlet "In the middle of the room sitting on a pedistal lies a Golden Guantlet with six colored stones embedded into it. Its looks as though it does not belong in this game, never mind this dungeon. Immediately you can feel the imense power eminating from it."
	CaveEntry->setWhichWallsHaveADoor(NULL,NULL,PuzzleRoom,NULL);
	PuzzleRoom->setWhichWallsHaveADoor(NULL,DungeonRoom3,NULL,NULL);
	DungeonRoom3->setWhichWallsHaveADoor(NULL,DungeonRoom4,NULL,NULL);
	DungeonRoom4->setWhichWallsHaveADoor(NULL,TreasureRoom,DungeonRoom5,DungeonRoom3);
	TreasureRoom->setWhichWallsHaveADoor(NULL,NULL,NULL,DungeonRoom4);
	DungeonRoom5->setWhichWallsHaveADoor(DungeonRoom4,NULL,DungeonRoom6,NULL);
	DungeonRoom6->setWhichWallsHaveADoor(DungeonRoom5,DungeonRoom7,SecretRoom,DungeonKeyHallway);
	DungeonKeyHallway->setWhichWallsHaveADoor(NULL,DungeonRoom6,NULL,DungeonKeyRoom);
	DungeonRoom7->setWhichWallsHaveADoor(NULL,NULL,PuzzleRoom2,DungeonRoom6);
	PuzzleRoom2->setWhichWallsHaveADoor(DungeonRoom7,NULL,DungeonRoom9,SecretRoom);
	DungeonRoom9->setWhichWallsHaveADoor(PuzzleRoom2,NULL,NULL,BossRoomHallway);
	BossRoomHallway->setWhichWallsHaveADoor(SecretRoom,DungeonRoom9,NULL,BossRoom);
	DungeonKeyRoom->setWhichWallsHaveADoor(NULL,DungeonKeyHallway,NULL,NULL);
	SecretRoom->setWhichWallsHaveADoor(DungeonRoom6,PuzzleRoom2,BossRoomHallway,NULL);

	currentRoom=CaveEntry;
}

Room* Dungeon::getCurrentRoom(){
	return this->currentRoom;

}

void Dungeon::setPuzzleRoomOneSuccessful(){
	this->isPuzzleRoomOneSuccessful=true;
}

bool Dungeon::getPuzzleRoomOneSuccessful(){
	return this->isPuzzleRoomOneSuccessful;
}