#include "npc.h"
#include "battlefield.h"

int main() {
    std::ifstream file("123.txt");

    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->fillRandomly(time(NULL), 10,20,30);
    std::shared_ptr<ObserverBattlefieldOstream> obsO = std::make_shared<ObserverBattlefieldOstream>();
    std::shared_ptr<ObserverBattlefieldFile> obsF = std::make_shared<ObserverBattlefieldFile>();
    btf->attachObs(obsF);
    btf->attachObs(obsO);
    btf->battle(3,4);
    btf->removeDeadmen();
    std::cout << *btf;
}   