#pragma once
#include <iostream>
#include <memory>

enum TypeNPC {
    UNKNOWN = 0,
    ORC = 1,
    BEAR = 2,
    SQUIRREL = 3
};

class NPC {
    private:
        TypeNPC _type;
        std::pair<int, int> _coords;
    public:
        NPC();
        NPC(TypeNPC type, const std::pair<int,int> &coords);
        NPC(TypeNPC type, const int &x, const int &y);

        // virtual void print() = 0;
        friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};


