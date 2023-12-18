#include "npc.h"

NPC::NPC() : _coords{0,0} {}

NPC::NPC(TypeNPC type, const std::pair<int,int> &coords, const int &attackRange, const int &movementRange) : 
    _coords{coords}, _type{type}, alive{true}, _rangeAttack{attackRange}, _rangeMove{movementRange} {}

NPC::NPC(TypeNPC type, const int &x, const int &y, const int &attackRange, const int &movementRange) : 
    _coords{x,y}, _type(type), alive(true), _rangeAttack{attackRange}, _rangeMove{movementRange} {}

TypeNPC NPC::type() const{
    return this->_type;
}

std::pair<int,int> NPC::coords() const{
    return this->_coords;
}

void NPC::save(std::ofstream &ofs) {
    ofs << this->_coords.first << ' ' << this->_coords.second << ' ' << this->type();
}

int NPC::attack_range() const {
    return _rangeAttack;
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

void NPC::move(const int& moveX, const int& moveY) {
    if (_coords.first + moveX > BTF_SIZE) {
        _coords.first = BTF_SIZE;
    } else if (_coords.first + moveX < 0){
        _coords.first = 0;
    } else {
        _coords.first += moveX;
    }
    if (_coords.first + moveY > BTF_SIZE) {
        _coords.second = BTF_SIZE;
    } else if (_coords.first + moveY < 0) {
        _coords.second = 0;
    } else {
        _coords.second += moveY;
    }
}

void NPC::kill(){
    this->alive = false;
}

double NPC::distance(const std::shared_ptr<NPC> other) const{
    return pow((pow(_coords.first - other->_coords.first, 2) + pow(_coords.second - other->_coords.second, 2)), 0.5);
}

int NPC::move_range() const{
    return _rangeMove;
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
