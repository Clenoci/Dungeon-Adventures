all: DA

DA:  Dungeon.cpp Room.cpp main.cpp Enemy.cpp CombatUnit.cpp Item.cpp Weapon.cpp DungeonAdventures.cpp CustomPlayer.cpp BattleMage.cpp Goblin.cpp GoblinArcher.cpp Warrior.cpp Cerberus.cpp HellHound.cpp Skeleton.cpp Spider.cpp Object.cpp HealthPotion.cpp BossKey.cpp Ogre.cpp StrengthPotion.cpp
	g++ Dungeon.cpp Room.cpp main.cpp Enemy.cpp CombatUnit.cpp Item.cpp Weapon.cpp DungeonAdventures.cpp CustomPlayer.cpp BattleMage.cpp Goblin.cpp GoblinArcher.cpp Warrior.cpp Cerberus.cpp HellHound.cpp Skeleton.cpp Spider.cpp Object.cpp HealthPotion.cpp BossKey.cpp Ogre.cpp StrengthPotion.cpp -std=c++11 -o Dungeon
