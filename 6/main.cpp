#include "npc.h"
#include "battlefield.h"

int main() {
    std::ifstream file("123.txt");
    std::shared_ptr<Factory> factoryB = std::make_shared<BearFactory>();
    std::shared_ptr<Factory> factoryO = std::make_shared<OrcFactory>();
    std::shared_ptr<Factory> factoryS = std::make_shared<SquirrelFactory>();

    std::shared_ptr<NPC> bearNPC = factoryB->create(10, 20);
    std::shared_ptr<NPC> orcNPC = factoryO->create(20, 30);
    std::shared_ptr<NPC> squirrelNPC = factoryS->create(30, 40);
    std::shared_ptr<NPC> orcNPC1 = factoryS->create(std::cin);
    std::shared_ptr<NPC> squirrelNPC1 = factoryS->create(file);
    std::shared_ptr<NPC> squirrelNPC2 = factoryS->create(file);

    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->placeHero(bearNPC);
    btf->placeHero(orcNPC);
    btf->placeHero(squirrelNPC);
    btf->placeHero(orcNPC1);
    btf->placeHero(squirrelNPC1);
    btf->placeHero(squirrelNPC2);
    std::cout << *btf;

    std::shared_ptr<ObserverBattlefieldOstream> obsO = std::make_shared<ObserverBattlefieldOstream>();
    std::shared_ptr<ObserverBattlefieldFile> obsF = std::make_shared<ObserverBattlefieldFile>();
    btf->attachObs(obsF);
    btf->battle(3,4);
}   