#include "factory.h"

std::shared_ptr<NPC> OrcFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Orc>(x, y);
    return result;
}

std::shared_ptr<NPC> BearFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Bear>(x, y);
    return result;
}

std::shared_ptr<NPC> SquirrelFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<Squirrel>(x, y);
    return result;
}