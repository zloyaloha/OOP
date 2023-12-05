#include "battlefield.h"

std::ostream &operator << (std::ostream &os, Battlefield &btf) {
    os << "This is a battlefield" << std::endl;
    os << "There are " << btf._npcList.size() << " fighters." << std::endl;
    for (auto npc: btf._npcList) {
        os << *npc;
    }
    return os;
}

Battlefield::Battlefield() : _size(500,500), _npcList(), _observers() {}

void Battlefield::attachObs(std::shared_ptr<Observer> obs) {
    _observers.push_back(obs);
}

void Battlefield::detachObs(std::shared_ptr<Observer> obs) {
    if (!_observers.remove(obs)) {
        throw std::logic_error("Observer not in observer list");
    }
}

void Battlefield::fillRandomly(size_t seed, size_t orcs, size_t squirrels, size_t bears) {
    srand(seed);
    std::shared_ptr<Factory> factoryB = std::make_shared<BearFactory>();
    std::shared_ptr<Factory> factoryO = std::make_shared<OrcFactory>();
    std::shared_ptr<Factory> factoryS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> orcNPC;
    std::shared_ptr<NPC> squirrelNPC;
    std::shared_ptr<NPC> bearNPC;
    size_t c_sq = 0, c_b = 0, c_o = 0;
    while(c_b < bears || c_sq < squirrels || c_o < orcs) {
        switch (rand() % 3 + 1) {
            case BEAR:
                if (c_b < bears) {
                    bearNPC = factoryB->create(rand() % 500, rand() % 500);
                    this->placeHero(bearNPC);
                    c_b++;
                }
                break;
            case SQUIRREL:
                if (c_sq < squirrels) {
                    squirrelNPC = factoryS->create(rand() % 500, rand() % 500);
                    this->placeHero(squirrelNPC);
                    c_sq++;
                }
                break;
            case ORC:
                if (c_o < orcs) {
                    orcNPC = factoryO->create(rand() % 500, rand() % 500);
                    this->placeHero(orcNPC);
                    c_o++;
                }
                break;
            default:
                break;
        }
    }
}

void Battlefield::notify(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender, int cmd) {
    switch (cmd) {
        case Commands::LOSE:
            for (auto obs: _observers) {
                obs->fight(attacker, defender, cmd);
            }
            break;
        case Commands::WIN:
            for (auto obs: _observers) {
                obs->fight(attacker, defender, cmd);
            }
            break;
        case Commands::BATTLE_START:
            for (auto obs: _observers) {
                obs->battleStart(this->_size, this->_npcList);
            }
            break;
        case Commands::BATTLE_END:
            for (auto obs: _observers) {
                obs->battleEnd(this->_size, this->_npcList);
            }
            break;
        default:
            throw std::logic_error("Unknown notify");
        }
}

void Battlefield::placeHero(std::shared_ptr<NPC> npc) {
    if (npc->coords().first < 500 && npc->coords().first < 500) _npcList.push_back(npc);
}

void Battlefield::removeDeadmen() {
    _npcList.erase(std::remove_if(_npcList.begin(), _npcList.end(), [](std::shared_ptr<NPC> npc) {return !npc->is_alive(); }), _npcList.end());
    // for (auto iter = _npcList.begin(); iter != _npcList.end(); ++iter) {
    //     if (!(*iter)->is_alive()) {
    //         _npcList.erase(iter);
    //     }
    // }
}

void Battlefield::removeHero(std::shared_ptr<NPC> npc) {
    if (!_npcList.remove(npc)) {
        throw std::logic_error("NPC not on battlefield");
    }
}

void Battlefield::battle(size_t rounds, double distance) {
    this->notify(nullptr, nullptr, Commands::BATTLE_START);
    for (size_t i = 0; i < rounds; ++i) {
        for (auto attacker : _npcList) {
            bool success1;
            bool success2;
            for (auto defender : _npcList) {
                if (attacker != defender && attacker->is_alive() && defender->is_alive() && distance > defender->distance(attacker)) {
                    success1 = attacker->accept(defender);
                    this->notify(attacker, defender, success1);
                    success2 = defender->accept(attacker);
                    this->notify(defender, attacker, success2);
                }
            }
        }
        distance+=distance;
    }
    this->notify(nullptr, nullptr, Commands::BATTLE_END);
}

void ObserverBattlefieldOstream::battleStart(const std::pair<int,int> &size, const std::list<std::shared_ptr<NPC>> npcList) {
    std::cout << std::endl << "-------- Battle started --------" << std::endl;
    std::cout << "There are " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        std::cout << *npc;
    }
    std::cout << std::endl;
}

void ObserverBattlefieldOstream::battleEnd(const std::pair<int,int> &size, const std::list<std::shared_ptr<NPC>> npcList) {
    std::cout << std::endl << "-------- Battle ended --------" << std::endl;
    std::cout << "There was " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        std::cout << *npc;
    }
    std::cout << std::endl;
}


void ObserverBattlefieldOstream::fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (win) {
        std::cout << std::endl << "Murder --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    } else {
        std::cout << std::endl << "Failed attack attempt --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    }
}

ObserverBattlefieldFile::ObserverBattlefieldFile() {
    const time_t tm = time(nullptr);
    char buf[64];
    strftime(buf, std::size(buf), "%d.%m.%Y-%H.%M.%S", localtime(&tm));
    file.open("../log/log_" + std::string(buf) + ".txt");
}

ObserverBattlefieldFile::~ObserverBattlefieldFile() {
    file.close();
}

void ObserverBattlefieldFile::fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (win) {
        file << '\n' << "Murder --------" << '\n';
        file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    } else {
        file << '\n' << "Failed attack attempt --------" << '\n';
        file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    }
}

void ObserverBattlefieldFile::battleStart(const std::pair<int,int> &size, const std::list<std::shared_ptr<NPC>> npcList) {
    file << std::endl << "-------- Battle started --------" << std::endl;
    file << "There are " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        file << *npc;
    }
    file << std::endl;
}

void ObserverBattlefieldFile::battleEnd(const std::pair<int,int> &size, const std::list<std::shared_ptr<NPC>> npcList) {
    file << std::endl << "-------- Battle ended --------" << std::endl;
    file << "There was " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        file << *npc;
    }
    file << std::endl;
}