#include "Warrior.hpp"
Warrior::Warrior(): CustomPlayer("",125,10){

}

Warrior::Warrior(std::string name, int health, int damage): CustomPlayer(name,health,damage){
}

/*weaponWeilded*/
void Warrior::chooseWeapon(int WeaponChoice){
	bool weaponSet=false;
	while(weaponSet==false){
		if (WeaponChoice==1){
			this->setWeaponWeilded(new Weapon(5,"Devils Dual Weild"));
			this->setDamage(this->getWeaponDamage());
			weaponSet=true;
		}
		else if(WeaponChoice==2){
			this->setWeaponWeilded(new Weapon(7,"Battle Axe of Rage"));
			this->setDamage(this->getWeaponDamage());
			weaponSet=true;
		}
		else{
			std::cout<<"You have made an invalid Weapon choice, Please choose again\nEnter 1 for the Wand of Wanderlust or 2 for the Elemental Staff:\n";
			std::cin>>WeaponChoice;
		}
	}
}

void Warrior::Attack1(Enemy* enemy){
	std::cout<<"\nYou charge at the targeted enemy swinging your weapon! \n";
	this->DealDamage(enemy);
} 

void Warrior::Attack2(std::vector<Enemy*> enemiesInRoom){
	std::cout<<"\nYou leap at your enemies and upon landing swing your weapon around !\n";
	this->setDamage(-5);
	for(Enemy* enemy:enemiesInRoom){
		if(enemy->GetHealth()>0){
			this->DealDamage(enemy);
			this->CheckIfEnemyDied(enemy,enemiesInRoom);
		}
	}
	this->setDamage(5);
} 

void Warrior::Attack(std::vector<Enemy*> enemiesInRoom){
		std::cout<<"Use Slash(single target) or Savage swing(multi target, less damage)?\n";
		std::string attack;
		std::getline(std::cin,attack);
		if(attack.compare("Slash")==0||attack.compare("slash")==0){
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
		else if(attack.compare("Savage swing")==0||attack.compare("savage swing")==0){
			this->Attack2(enemiesInRoom);
		}
		else{
			std::cout<<"you have made an invalid choice, please try again\n";
			Attack(enemiesInRoom);
		}
	}

	
 

