#include "BattleMage.hpp"

BattleMage::BattleMage():CustomPlayer("",1,1){
	
}

BattleMage::BattleMage(std::string name, int health,int damage): CustomPlayer(name,health,damage){
	
}

/*weaponWeilded*/
void BattleMage::chooseWeapon(int WeaponChoice){
	bool weaponSet=false;
	while(weaponSet==false){
		if (WeaponChoice==1){
			this->setWeaponWeilded(new Weapon(2,"Wand of Wanderlust"));//listOfWeapons[0]//return Wand of WanderLust
			this->setDamage(this->getWeaponDamage());
			weaponSet=true;
		}
		else if(WeaponChoice==2){
			this->setWeaponWeilded(new Weapon(5,"Elemental Staff"));//listOfWeapons[1]//return Elemental Staff
			this->setDamage(this->getWeaponDamage());
			weaponSet=true;
		}
		else{
			std::cout<<"You have made an invalid Weapon choice, Please choose again\nEnter 1 for the Wand of Wanderlust or 2 for the Elemental Staff:\n";
			std::cin>>WeaponChoice;
		}
	}
}

void BattleMage::Attack1(Enemy* enemy){
	
	std::cout<<"\nA blue magical bolt shoots out of the end of your "<<this->getWeaponWeilded()->getWeaponName()<< " hurling towards the targeted enemy\n";
	this->DealDamage(enemy);
}

void BattleMage::Attack2(std::vector<Enemy*> enemiesInRoom){
	std::cout<<"\nYou send a wave of fire from your "<<this->getWeaponWeilded()->getWeaponName()<< " out in front of you hitting all enemies in the room!\n";
	this->setDamage(-5);
	for(Enemy* enemy:enemiesInRoom){
		if(enemy->GetHealth()>0){
			this->DealDamage(enemy);
			this->CheckIfEnemyDied(enemy,enemiesInRoom);
		}
	}
	this->setDamage(5);
} 

void BattleMage::Attack(std::vector<Enemy*> enemiesInRoom){
		std::cout<<"Use Magic bolt(single target) or Fire wave(multi target, less damage)?\n";
		std::string attack;
		std::getline(std::cin,attack);
		if(attack.compare("Magic bolt")==0||attack.compare("magic bolt")==0){
				std::cout<<"Which enemy would you like to attack? (enter the number)\n";
			int enemyNumber=1;
			for(Enemy* enemy: enemiesInRoom){
				std::cout<<enemyNumber<<".) ";
				enemy->PrintStats();
				enemyNumber++;
			}
			std::cin>>enemyNumber;
			this->Attack1(enemiesInRoom[enemyNumber-1]);
			this->CheckIfEnemyDied(enemiesInRoom[enemyNumber-1], enemiesInRoom);
		}
		else if(attack.compare("Fire wave")==0||attack.compare("fire wave")==0){
			this->Attack2(enemiesInRoom);
		}
		else{
			std::cout<<"you have made an invalid choice, please try again\n";
			Attack(enemiesInRoom);
		}
	}





