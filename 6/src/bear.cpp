#include "bear.h"

Bear::Bear(const int &x, const int &y) : NPC{BEAR, x, y} {}

bool Bear::accept(std::shared_ptr<NPC> defender) {
    VisitorBear v;
    return v.visit(defender);
}

bool VisitorBear::visit(std::shared_ptr<NPC> defender) {
    if (defender->type() == BEAR || defender->type() == ORC) {
        return false;
    } else {
        defender->kill();
        return true;
    }
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
    int x; int y;
    ifs >> x; ifs >> y;
    std::shared_ptr<NPC> result = std::make_shared<Bear>(x,y);
    return result;
}