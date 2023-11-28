#include "npc.h"

NPC::NPC() : _coords{0,0} {}

NPC::NPC(TypeNPC type, const std::pair<int,int> &coords) : _coords{coords}, _type(type) {}

NPC::NPC(TypeNPC type, const int &x, const int &y) : _coords{x,y}, _type(type) {}

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
    os << "{x = " << npc._coords.first << ", y = " << npc._coords.second << "} " << std::endl;
    return os;
}