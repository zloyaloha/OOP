#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <mutex>

namespace RangeMove {
    const int ATTACK_RANGE_BEAR = 10
    const int ATTACK_RANGE_ORC = 10
    const int ATTACK_RANGE_SQUIRREL = 5
    const int MOVE_RANGE_BEAR = 5
    const int MOVE_RANGE_ORC = 20
    const int MOVE_RANGE_SQUIRREL = 5
}
enum TypeNPC {
    UNKNOWN = 0,
    ORC = 1,
    BEAR = 2,
    SQUIRREL = 3
};

class Orc;
class Bear;
class Squirrel;

class Visitor {
    friend class NPC;
    public: 
        virtual bool visit(std::shared_ptr<Orc> defender) = 0;
        virtual bool visit(std::shared_ptr<Bear> defender) = 0;
        virtual bool visit(std::shared_ptr<Squirrel> defender) = 0;
};

class NPC : public std::enable_shared_from_this<NPC>{
    protected:
        TypeNPC _type;
        std::pair<int, int> _coords;
        bool alive;
        int _rangeAttack;
        int _rangeMove;
    private:
        std::mutex mtx;
    public:
        NPC();
        NPC(TypeNPC type, const std::pair<int,int> &coords);
        NPC(TypeNPC type, const int &x, const int &y);

        TypeNPC type() const;
        std::pair<int, int> coords() const;
        bool is_alive() const;

        virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) = 0;
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

