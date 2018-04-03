#include "Enemy.hpp"

class DungeonBoss : public Enemy{
	
	public:
		DungeonBoss(std::string type,std::string name, int health);
		
	private:
		std::string Enemytype;

};