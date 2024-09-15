#include <gtest/gtest.h>
#include <vector>
#include "battlefield.h"

TEST(FactoryTest, TEST_01) {
    std::shared_ptr<BearFactory> fB = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fB->create(10,20);
    ASSERT_TRUE(bear->type() == BEAR && bear->coords().first == 10 && bear->coords().second == 20);
}

TEST(FactoryTest, TEST_02) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    ASSERT_TRUE(orc->type() == ORC && orc->coords().first == 10 && orc->coords().second == 20);
}

TEST(FactoryTest, TEST_03) {
    std::shared_ptr<Factory> fB = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fB->create(10,20);
    ASSERT_TRUE(squirrel->type() == SQUIRREL && squirrel->coords().first == 10 && squirrel->coords().second == 20);
}

TEST(BattleCheck, TEST_01) {
    std::shared_ptr<Factory> fB = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fO->create(10,20);
    std::shared_ptr<VisitorOrc> v = std::make_shared<VisitorOrc>();
    ASSERT_NO_THROW(!squirrel->accept(v, orc));
}

TEST(BattleCheck, TEST_02) {
    std::shared_ptr<Factory> fB = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fO->create(10,20);
    std::shared_ptr<VisitorOrc> v1 = std::make_shared<VisitorOrc>();
    std::shared_ptr<VisitorSquirrel> v2 = std::make_shared<VisitorSquirrel>();
    ASSERT_NO_THROW(!squirrel->accept(v1, orc) && !orc->accept(v2, squirrel));
}

TEST(BattleCheck, TEST_03) {
    std::shared_ptr<Factory> fB = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<VisitorSquirrel> v1 = std::make_shared<VisitorSquirrel>();
    std::shared_ptr<VisitorBear> v2 = std::make_shared<VisitorBear>();
    ASSERT_NO_THROW(bear->accept(v1, squirrel) && !squirrel->accept(v2, bear));
}

TEST(BattleCheck, TEST_04) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<VisitorOrc> v1 = std::make_shared<VisitorOrc>();
    std::shared_ptr<VisitorBear> v2 = std::make_shared<VisitorBear>();
    ASSERT_NO_THROW(!bear->accept(v1, orc) && orc->accept(v2, bear));
}

TEST(Kill, TEST_01) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(10,20);
    orc->kill(); bear->kill(); squirrel->kill();
    ASSERT_TRUE(!orc->is_alive() && !bear->is_alive() && !squirrel->is_alive());
}

TEST(Distance, TEST_01) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(30,20);
    ASSERT_TRUE(fabs(squirrel->distance(bear) - 20) < ESPILON);
}

TEST(Distance, TEST_02) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(-30,-20);
    ASSERT_TRUE(fabs(squirrel->distance(bear) - 56.568) < ESPILON);
}

TEST(BattlefieldTEST, TEST_01) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(-30,-20);
    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->placeHero(orc);
    btf->placeHero(bear);
    btf->placeHero(squirrel);
    ASSERT_TRUE(btf->npc().size() == 3);
}

TEST(BattlefieldTEST, TEST_02) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(10,20);
    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->placeHero(orc);
    btf->placeHero(bear);
    btf->placeHero(squirrel);
    ASSERT_NO_THROW(btf->battle());
}

// TEST(BattlefieldTEST, TEST_03) {
//     std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
//     std::shared_ptr<NPC> orc = fB->create(10,20);
//     std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
//     std::shared_ptr<NPC> bear = fO->create(10,20);
//     std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
//     std::shared_ptr<NPC> squirrel = fS->create(10,20);
//     std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
//     btf->placeHero(orc);
//     btf->placeHero(bear);
//     btf->placeHero(squirrel);
//     btf->battle();
//     btf->removeDeadmen();
//     ASSERT_TRUE(btf->npc().size() == 2);
// }

TEST(BattlefieldTEST, TEST_04) {
    std::shared_ptr<Factory> fB = std::make_shared<OrcFactory>();
    std::shared_ptr<NPC> orc = fB->create(10,20);
    std::shared_ptr<Factory> fO = std::make_shared<BearFactory>();
    std::shared_ptr<NPC> bear = fO->create(10,20);
    std::shared_ptr<Factory> fS = std::make_shared<SquirrelFactory>();
    std::shared_ptr<NPC> squirrel = fS->create(10,20);
    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->fillRandomly(1,10,10,10);
    ASSERT_TRUE(btf->npc().size()==30);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}