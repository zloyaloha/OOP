
#include "battlefield.h"

int main() {
    std::ifstream file("123.txt");
    std::ofstream file1("out.txt");
    std::shared_ptr<BearFactory> fB = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fB->create(10,20);
    bear->save(file1);
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