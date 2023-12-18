#include "bear.h"

Bear::Bear(const int &x, const int &y) : 
    NPC(BEAR, x, y, RangeMove::ATTACK_RANGE_BEAR, RangeMove::MOVE_RANGE_BEAR) {}

int Bear::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Bear> defender = std::dynamic_pointer_cast<Bear>(npc_ptr);
    int result;
    return result = attacker_visitor->visit(defender);
}

bool VisitorBear::visit(std::shared_ptr<Bear> defender) {
    return false;
}
bool VisitorBear::visit(std::shared_ptr<Orc> defender) {
    return false;
}
bool VisitorBear::visit(std::shared_ptr<Squirrel> defender) {
    return true;
}


std::shared_ptr<NPC> BearFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Bear>(x, y);
    return result;
}

std::shared_ptr<NPC> BearFactory::create(std::istream &is) {
    std::pair<int,int> tmp;
    is >> tmp.first; is >> tmp.second;
    std::shared_ptr<NPC> result = std::make_shared<Bear>(tmp.first, tmp.second);
    return result;
}

std::shared_ptr<NPC> BearFactory::create(std::ifstream &ifs) {
    int x; int y; int type;
    ifs >> x; ifs >> y; ifs >> type;
    std::shared_ptr<NPC> result = std::make_shared<Bear>(x,y);
    return result;
}