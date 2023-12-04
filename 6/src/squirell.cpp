#include "squirrel.h"

Squirrel::Squirrel(const int &x, const int &y) : NPC{SQUIRREL, x, y} {}

bool Squirrel::accept(std::shared_ptr<NPC> defender) {
    VisitorSquirrel v;
    return v.visit(defender);
}

bool VisitorSquirrel::visit(std::shared_ptr<NPC> defender) {
    return false;
}

std::shared_ptr<NPC> SquirrelFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Squirrel>(x, y);
    return result;
}

std::shared_ptr<NPC> SquirrelFactory::create(std::istream &is) {
    std::pair<int,int> tmp;
    is >> tmp.first; is >> tmp.second;
    std::shared_ptr<NPC> result = std::make_shared<Squirrel>(tmp.first, tmp.second);
    return result;
}

std::shared_ptr<NPC> SquirrelFactory::create(std::ifstream &ifs) {
    int x; int y;
    ifs >> x; ifs >> y;
    std::shared_ptr<NPC> result = std::make_shared<Squirrel>(x,y);
    return result;
}