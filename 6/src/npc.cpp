#include "npc.h"

NPC::NPC() : _coords{0,0} {}

NPC::NPC(TypeNPC type, const std::pair<int,int> &coords) : _coords{coords}, _type(type), alive(true) {}

NPC::NPC(TypeNPC type, const int &x, const int &y) : _coords{x,y}, _type(type), alive(true) {}

TypeNPC NPC::type() const{
    return this->_type;
}

std::pair<int,int> NPC::coords() const{
    return this->_coords;
}

void NPC::save(std::ofstream &ofs) {
    ofs << this->_coords.first << ' ' << this->_coords.second << ' ' << this->type();
}

void NPC::load(std::ifstream &ifs) {
    int x,y,type;
    ifs >> x;
    ifs >> y;
    ifs >> type;
    _coords.first = x;
    _coords.second = y;
    _type = TypeNPC(type);
    alive = true;
}

bool NPC::is_alive() const{
    return this->alive;
}

void NPC::kill(){
    this->alive = false;
}

double NPC::distance(const std::shared_ptr<NPC> other) const{
    return pow((pow(_coords.first - other->_coords.first, 2) + pow(_coords.second - other->_coords.second, 2)), 0.5);
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    switch (npc._type) {
        case ORC:
            os << "Orc: ";
            break;
        case SQUIRREL:
            os << "Squirrel: ";
            break;
        case BEAR:
            os << "Bear: ";
            break;
        default:
            throw std::logic_error("Unknown NPC type");
            break;
        }
    os << "{x = " << npc._coords.first << ", y = " << npc._coords.second << "} ";
    if (npc.alive) {
        os << "alive" << std::endl;
    } else {
        os << "dead" << std::endl;
    }
    return os;
}
