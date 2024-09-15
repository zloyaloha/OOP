#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
enum TypeNPC {
    UNKNOWN = 0,
    ORC = 1,
    BEAR = 2,
    SQUIRREL = 3
};

class Visitor;

class NPC {
    private:
        TypeNPC _type;
        std::pair<int, int> _coords;
        bool alive;
    public:

        NPC();
        NPC(TypeNPC type, const std::pair<int,int> &coords);
        NPC(TypeNPC type, const int &x, const int &y);

        TypeNPC type() const;
        std::pair<int, int> coords() const;
        bool is_alive() const;

        virtual bool accept(std::shared_ptr<NPC> other) = 0;
        friend std::ostream &operator<<(std::ostream &os, NPC &npc);

        void kill();
        double distance(const std::shared_ptr<NPC> other) const;
        void save(std::ofstream &ofs);
        void load(std::ifstream &ifs);
};

class Factory {
    public:
        virtual std::shared_ptr<NPC> create(int x, int y) = 0;
        virtual std::shared_ptr<NPC> create(std::istream &is) = 0;
        virtual std::shared_ptr<NPC> create(std::ifstream &ifs) = 0;
        ~Factory() = default;
};

class Visitor {
    friend class NPC;
    public: 
        virtual bool visit(std::shared_ptr<NPC> defender) = 0;
};
