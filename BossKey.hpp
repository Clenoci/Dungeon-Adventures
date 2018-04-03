#ifndef BOSSKEY_HPP
#define BOSSKEY_HPP
#include "Item.hpp"
#include "CombatUnit.hpp"

class BossKey : public Item {
public:
	BossKey();
	void Effect(CombatUnit* target);
private:
};

#endif