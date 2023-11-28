#include "npc.h"
#include "factory.h"

int main() {
    std::cout << "hi" << std::endl;
    std::shared_ptr<Factory> factory = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> orcNPC = factory->create(10, 20);
    std::cout << *orcNPC;
}