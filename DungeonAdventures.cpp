#include "DungeonAdventures.hpp"

DungeonAdventures::DungeonAdventures(){
	std::string name;
	bool puzzleRoomOneSuccess;
	int weapon=0,playerClass=0;
	StoryIntroduction();
	Dungeon* ChapterOne_OgreAttack=new Dungeon();
	CharacterSetup();
	this->currentAdventurer->PrintStats();
	currentRoom= ChapterOne_OgreAttack->getCurrentRoom();
	currentRoom->printRoomDescription();

	while(1){
		puzzleRoomOneSuccess= PuzzleRoomOne();
		if(puzzleRoomOneSuccess==true){
			ChapterOne_OgreAttack->setPuzzleRoomOneSuccessful();
		}
		if(currentRoom->getIsEveryOneDead()==false){
			Combat(currentRoom->getEnemies());
		}
		RoomMenu();
	}
}

void DungeonAdventures::CharacterSetup(){
	std::string name;
	int weapon=0,playerClass=0;
	do{
	std::cout<<name<<"\nWhat is your name Adventurer??\n";
	std::getline (std::cin,name);
	}while(name.length()<2);
	while(playerClass>2 || playerClass<1){
		std::cout<<"Are you a Battle Mage or a Warrior?? \nPlease enter 1 for Battle Mage or 2 for Warrior\n";
		std::cin>>playerClass;
	}
	if(playerClass==1){
		while(weapon>2 || weapon<1){
			std::cout<<name<<" The BattleMage can use either a The Wand of WanderLust(1) or the Elemental Staff(2)\n";
			std::cin>>weapon;
			std::cin.get();
		}
		CreateCharacter(playerClass,name,this->battleMageHealth,weapon);
	}
	if(playerClass==2){
		while(weapon>2 || weapon<1){
			std::cout<<name<<" The Warrior can use either Two short swords, one in each hand(1) or the Battle Axe(2)\n";
			std::cin>>weapon;
			std::cin.get();
		}
		CreateCharacter(playerClass,name,this->warriorHealth,weapon);
	}

}

void DungeonAdventures::Combat(std::vector<Enemy*> enemiesInRoom){
	if(currentRoom->getEnemies().size()==0){
		currentRoom->setIsEveryOneDeadTrue();
	}
	while(!currentRoom->getIsEveryOneDead()){
		std::cin.get();
	std::cout<<"\nYou are now in combat with\n\n";
	int i =1;
	int enemyHealthTotal=1;
	for(Enemy* enemy: enemiesInRoom){
		enemy->PrintStats();
		i++;
		}
	while(enemyHealthTotal>0){
		enemyHealthTotal=0;
		CombatMenu(enemiesInRoom);
		for(Enemy* enemy: enemiesInRoom){
			if(enemy->GetHealth()!=0){
				enemy->DealDamage(currentAdventurer);
				if(currentAdventurer->GetHealth()==0){
					currentAdventurer->Die();
					
				}
			}
			enemyHealthTotal=enemy->GetHealth()+enemyHealthTotal;
		}

	}
	currentRoom->setIsEveryOneDeadTrue();
	for(Enemy* enemy:enemiesInRoom){
		CreateSearchableCorpse(enemy);
	}
	if(currentRoom->getRoomNumber()==15){
		std::cout<<"After the beating you gave Sheldon he lies on the ground near death, as you go in to deliver the final blow he raises his hand and delivers a final message\n";

		std::cout<<"He barley gets out, This isn't over...My brothers will come looking \n";
		std::cout<<"You have defeated Sheldon the Destroyer and all of his goonies\n";
		std::cout<<"CONGRATS you have successfully finished your quest for Venegence and are able to return all of the stolen goods plus alot more back to your town. We will rebuild and Im off to start a new Quest. DESTROY ALL EVIL before it takes over the land\n";
		std::cout<<"The Story will continue soon... Are You Ready?";
		exit(0);
	}else std::cout<<"You have defeated everyone in the room, you are safe, for now. \n\n";
	}
}

void DungeonAdventures::CombatMenu(std::vector<Enemy*> enemiesInRoom){//std::vector<Enemy*> enemiesInRoom
	std::string menuChoice;
		std::cout<<std::endl;
		currentAdventurer->PrintStats();
		std::cout<<"What do you want to do next?(Attack,Use Item,Enemy Status,RUN)\n";
		std::getline (std::cin,menuChoice);
		if(menuChoice.compare("Attack")==0||menuChoice.compare("attack")==0){
			currentAdventurer->Attack(enemiesInRoom);
		}
		else if(menuChoice.compare("Use Item")==0||menuChoice.compare("use item")==0||menuChoice.compare("Use item")==0||menuChoice.compare("use Item")==0){
			currentAdventurer->setInventory(UseItem());
			CombatMenu(enemiesInRoom);
		}
		else if(menuChoice.compare("Enemy Status")==0||menuChoice.compare("enemy status")==0||menuChoice.compare("Enemy status")==0||menuChoice.compare("enemy Status")==0){

			currentRoom->printEnemiesInRoom();
			CombatMenu(enemiesInRoom);
		}
		else if(menuChoice.compare("Run")==0||menuChoice.compare("run")==0){
			std::cout<<"You can't run from your destiny!\n";
		}
		else{
			 std::cout<<"You have made an invalid selection, please try again"<<std::endl;
			 CombatMenu(enemiesInRoom);
		}
}

void DungeonAdventures::StoryIntroduction(){
	std::cout<<"Welcome to Dungeon Adventures!!!\n\n\n";
	std::cout<<"As you and the rest of your village sleep peacefully in. A Ogre named Sheldon and his followers surround your villiage, ready to attack...\n";
	std::cin.get();
	std::cout<<"You wake up to screams and choas as your village is under attack. You barely have time to realize what is happening before three goblins knock down your door and charge at you...\n";
	std::cin.get();
	std::cout<<"Under Normal circumstances you would be able to defend yourself but before you can even get out of bed a goblin clubs you over the head with a club he had stolen from you. Unwillingly you fall back to sleep.....\n";
	std::cin.get();
	std::cout<<"You awake hours later, bruised but still in decent shape for the most part. Unfortunately your village wasn't so lucky. Much of the village destroyed, some buildings still buring, everything valuable looted\n";
	std::cin.get();
	std::cout<<"Enraged that these hooligans have managed to catch him and the entire village off guard, You scream I WILL GET REVENGE!! ";
	std::cin.get();
	std::cout<<"Out of the rubble of a nearby house you see the town blacksmith badly injured, he calls you over...\n";
	std::cin.get();
	std::cout<<"The black smith manages to get out If you want revenge, I want to help you!\n The Ogre who calls himself Sheldon ransacked my house personally...He brutally murdered my family when I tried to stop him.\n Somehow I managed to make it out alive. I dont have much left, the goblins took most of it, but they missed my secret weapon stash. Feel free to take whatever you need under one condition, you kill that OGRE!. Sheldon needs to pay \n";
	std::cin.get();
	std::cout<<"And with that your adventure for revenge has begun...\n";
	std::cin.get();

}


void DungeonAdventures::CreateCharacter(int playerClass,std::string name,int health,int weapon){
	if (playerClass==1){
		BattleMage* mage =new BattleMage(name,health,7);
		mage->chooseWeapon(weapon);
		this->currentAdventurer = mage;
	}
	if(playerClass==2){
		Warrior* warrior = new Warrior(name,health,4);
		warrior->chooseWeapon(weapon);
		this->currentAdventurer= warrior;	
	}
}

void DungeonAdventures::loadCharacter(){

}

void DungeonAdventures::saveCharacter(){

}

void DungeonAdventures::moveToNextRoom(){
		std::string room;
		currentRoom->printAvailableDoors();
		std::cout<<"\nWhere would you like to go?(north/south/east/west)\n";
		std::getline (std::cin,room);
		if(room.compare("North")==0||room.compare("north")==0){
			std::cout<<"North\n";
			currentRoom=currentRoom->getNextRoom(north);
			if (currentRoom->getIsEveryOneDead()==false){
				currentRoom->printRoomDescription();
				std::cin.get();
			}
		}
		else if(room.compare("South")==0||room.compare("south")==0){
			std::cout<<"South\n";
			currentRoom=currentRoom->getNextRoom(south);
			if (currentRoom->getIsEveryOneDead()==false){
				currentRoom->printRoomDescription();
				std::cin.get();
			}
		}
		else if(room.compare("East")==0||room.compare("east")==0){
			std::cout<<"East\n";
			currentRoom=currentRoom->getNextRoom(east);
			if (currentRoom->getIsEveryOneDead()==false){
				currentRoom->printRoomDescription();
				std::cin.get();
			}
		}
		else if(room.compare("West")==0||room.compare("west")==0){
			std::cout<<"West\n";
			if(currentRoom->getNextRoom(west)->getRoomNumber()!=15){
				currentRoom=currentRoom->getNextRoom(west);
				if (currentRoom->getIsEveryOneDead()==false){
					currentRoom->printRoomDescription();
					std::cin.get();
				}
			}else {
				if(hasBossKey==false){
					std::cout<<"Looks like you need a really big key to open this reeaaaalllly big door. Im sure its in the dungeon somehwere, hopefully not gaurded by something scary....\n";
					RoomMenu();
				}else{
					currentRoom=currentRoom->getNextRoom(west);
					currentRoom->printRoomDescription();
					std::cin.get();
				}
			}	
		}
		else moveToNextRoom();
		
		
}

void DungeonAdventures::RoomMenu(){
	std::string menuChoice;
	std::cout<<"What do you want to do next?(Move,Search,Stats,Inspect Room, Inventory,)\n";
	std::getline(std::cin,menuChoice);
	if(menuChoice.compare("Move")==0||menuChoice.compare("move")==0){
		moveToNextRoom();
	}
	else if(menuChoice.compare("Inventory")==0||menuChoice.compare("inventory")==0){
		currentAdventurer->LookThroughInventory();
	}
	else if(menuChoice.compare("Inspect Room")==0||menuChoice.compare("inspect room")==0||menuChoice.compare("Inspect room")==0||menuChoice.compare("inspect Room")==0){
		currentRoom->inspectRoom();
	}
	else if(menuChoice.compare("Search")==0||menuChoice.compare("search")==0){
		SearchObjects();
	}
	else if(menuChoice.compare("Stats")==0||menuChoice.compare("stats")==0){
		currentAdventurer->PrintStats();
	}
	else{
		std::cout<<"You have made an invalid selection, please try again";
		RoomMenu();
	}
}

bool DungeonAdventures::PuzzleRoomOne(){
	if(currentRoom->getRoomNumber()==2&&currentRoom->getIsEveryOneDead()==false){
		std::cout<<"As you approach the goblin he does not move at all or say a word.\n When you are about ten feet away from the goblin he opens his mouth wide and yells at the top of his little goblin lungs\nANSWER MY RIDDLE AND YOU MAY PASS  \n";
		std::cin.get();
		std::cout<<"Do you answer want to try to answer the riddle or just kill the Goblin and be done with it? (yes, answer the riddle or no, kill the goblin)\n";
		std::string answerTheRiddle;
		do{
			std::getline(std::cin,answerTheRiddle);
		}while(answerTheRiddle.compare("yes")!=0&&answerTheRiddle.compare("no")!=0);
		if (answerTheRiddle.compare("yes")==0){
			std::cout<<"The Goblin acknowleges, then screams WHAT IS THE MEANING OF LIFE?(integer answers only)\n";
			std::string riddleAnswer;
			std::getline(std::cin,riddleAnswer);
			if(riddleAnswer.compare("43")==0){
				std::cout<<"The Goblin Shouts THAT IS RIGHT!! YOU UNDERSTOOND THE REFERENCE! CONGRATS! YOU MAY PASS!\n";
				std::cout<<"Then in a normal voice the goblin says You have freed me from the curse the Ogre, who has a weird love for Hitchhikers Guide to the Galaxy, had placed on me to gaurd this door. I am enternally grateful, I will help you when you need it most, later.... OHHH! and a friendly tip not every wall is what it may seem, the Ogre is a tricky guy\n";
				currentRoom->setIsEveryOneDeadTrue();
				std::cin.get();
				return true;
			}
			else{ std::cout<<"The Goblin Shouts NO!!! YOU ARE WRONG!!! YOU SHALL NOT PASS!\n";
				currentRoom->setRoomDescription("");
				std::cin.get();
				return false;
			}

		}
		else if(answerTheRiddle.compare("no")==0){
			std::cout<<"You yell I DON'T HAVE TIME FOR THIS , then just charge straight at the goblin initiating combat\n";
			std::cin.get();
			std::cout<<"The Goblin pulls out a dagger from his boot and yells, YOU WILL LIVE TO REGRET THIS DECISION IF NOT NOW, YOU WILL LATER!\n";
			std::cin.get();
			currentRoom->setRoomDescription("");
			std::cin.get();
			return false;
		}

	}
}

void DungeonAdventures::CreateSearchableCorpse(Enemy* enemy){
	Object* temp = new Object(enemy->GetName()+"'s corpse");
	for(Item* item:enemy->getInventory()){
		temp->addItemToObject(item);
	}
	currentRoom->addObject(temp);
}

void DungeonAdventures::SearchObjects(){
	int count = 1;
	//std::string input;
	std::vector<Object*> currentRoomsObjects=currentRoom->getObjectsInRoom();
	Object* objectToSearch;
	std::vector<Item*> itemsInObject;
	if(currentRoomsObjects.size()>0){
		std::cout<<"What would you like to search? (Number)"<<std::endl;
		for(Object* object:currentRoomsObjects){
			std::cout<<count<<".) "<<object->getName()<<std::endl;
			count++;
		};
		count=0;
		while(count<1||count>currentRoomsObjects.size()){
			std::cin>>count;
		}
		objectToSearch=currentRoomsObjects[count-1];
		itemsInObject =objectToSearch->getItemsInObject();

		if(itemsInObject.size()>0){
			for(Item* item:itemsInObject){
				currentAdventurer->AddItemToInventory(item);
				if(item->GetName().compare("Boss Key")==0){
					hasBossKey=true;
				}
				std::cout<<item->GetName()<<" has been added to your inventory"<<std::endl;
				itemsInObject.erase(itemsInObject.begin());
			}	

		}else std::cout<<objectToSearch->getName()<<" had nothing interesting to take"<<std::endl;

	}else std::cout<<"Nothing to search";
}

std::vector<Item*> DungeonAdventures::UseItem(){
	int count = 1;
	std::vector<Item*> inventory=currentAdventurer->getInventory();
	if(inventory.size()>0){
		for(Item* item:inventory){
			std::cout<<count<<".) "<<inventory[count-1]->GetName()<<std::endl;
			count++;
		}
		count=0;
		while(count<1||count>inventory.size()){
			std::cout<<"What Item would you like to use?(enter number of item)"<<std::endl;
			std::cin>>count;
		}
		currentAdventurer->UseItem(inventory[count-1],currentAdventurer);
		inventory.erase(inventory.begin()-(count-1));
		return inventory;
	}else{
		std::cout<<"You have nothing left to use"<<std::endl;
		return currentAdventurer->getInventory();
		}
}
