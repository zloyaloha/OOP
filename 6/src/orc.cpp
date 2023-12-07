#include "orc.h"

Orc::Orc(const int &x, const int &y) : NPC{ORC, x, y} {}

bool Orc::accept(std::shared_ptr<NPC> defender) {
    VisitorOrc v;
    return v.visit(defender);
}

bool VisitorOrc::visit(std::shared_ptr<NPC> defender) {
    if (defender->type() == ORC || defender->type() == BEAR) {
        defender->kill();
        return true;
    } else {
        return false;
    }
}

std::shared_ptr<NPC> OrcFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Orc>(x, y);
    return result;
}

std::shared_ptr<NPC> OrcFactory::create(std::istream &is) {
    std::pair<int,int> tmp;
    is >> tmp.first; is >> tmp.second;
    std::shared_ptr<NPC> result = std::make_shared<Orc>(tmp.first, tmp.second);
    return result;
}

std::shared_ptr<NPC> OrcFactory::create(std::ifstream &ifs) {
    int x; int y; int type;
    ifs >> x; ifs >> y; ifs >> type;
    std::shared_ptr<NPC> result = std::make_shared<Orc>(x,y);
    return result;
}