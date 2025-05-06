// #include "BrickWall.hpp"
// #include "Dummy.hpp"
// #include "Fireball.hpp"
// #include "Fwoosh.hpp"
// #include "Polymorph.hpp"
// #include "TargetGenerator.hpp"
// #include "Warlock.hpp"

// int main() {
//   Warlock richard("Richard", "foo");
//   richard.setTitle("Hello, I'm Richard the Warlock!");
//   BrickWall model1;

//   Polymorph *polymorph = new Polymorph();
//   TargetGenerator tarGen;

//   tarGen.learnTargetType(&model1);
//   richard.learnSpell(polymorph);

//   Fireball *fireball = new Fireball();

//   richard.learnSpell(fireball);

//   ATarget *wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

//   richard.introduce();
//   richard.launchSpell("Polymorph", *wall);
//   richard.launchSpell("Fireball", *wall);

//   delete polymorph;
//   delete fireball;
//   delete wall;
// }

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic Warlock Tests ===" << std::endl;
    Warlock richard("Richard", "Mistress of Chaos");
    richard.introduce();
    richard.setTitle("Master of Shadows");
    richard.introduce();

    std::cout << "\n=== Basic Spell and Target Tests ===" << std::endl;
    Dummy target;
    Fwoosh* fwoosh = new Fwoosh();
    richard.learnSpell(fwoosh);
    richard.launchSpell("Fwoosh", target);
    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", target); // Should do nothing

    std::cout << "\n=== Multiple Spells Test ===" << std::endl;
    Fireball* fireball = new Fireball();
    Polymorph* polymorph = new Polymorph();
    richard.learnSpell(fwoosh);
    richard.learnSpell(fireball);
    richard.learnSpell(polymorph);
    
    std::cout << "Launching learned spells:" << std::endl;
    richard.launchSpell("Fwoosh", target);
    richard.launchSpell("Fireball", target);
    richard.launchSpell("Polymorph", target);
    
    std::cout << "Launching non-existent spell:" << std::endl;
    richard.launchSpell("Invisibility", target); // Should do nothing

    std::cout << "\n=== SpellBook Tests ===" << std::endl;
    // SpellBook 내부 테스트는 Warlock을 통해 간접적으로 테스트됩니다
    richard.forgetSpell("Fireball");
    std::cout << "After forgetting Fireball:" << std::endl;
    richard.launchSpell("Fireball", target); // Should do nothing
    
    // 다시 배우기
    richard.learnSpell(fireball);
    std::cout << "After re-learning Fireball:" << std::endl;
    richard.launchSpell("Fireball", target);

    std::cout << "\n=== BrickWall Target Tests ===" << std::endl;
    BrickWall wall;
    richard.launchSpell("Fwoosh", wall);
    richard.launchSpell("Fireball", wall);
    richard.launchSpell("Polymorph", wall);

    std::cout << "\n=== TargetGenerator Tests ===" << std::endl;
    TargetGenerator tarGen;
    
    // 타겟 학습
    tarGen.learnTargetType(&target);
    tarGen.learnTargetType(&wall);
    
    // 타겟 생성 및 주문 시전
    ATarget* genDummy = tarGen.createTarget("Target Practice Dummy");
    ATarget* genWall = tarGen.createTarget("Inconspicuous Red-brick Wall");
    
    if (genDummy) {
        std::cout << "Created target: " << genDummy->getType() << std::endl;
        richard.launchSpell("Polymorph", *genDummy);
    } else {
        std::cout << "Failed to create Dummy target" << std::endl;
    }
    
    if (genWall) {
        std::cout << "Created target: " << genWall->getType() << std::endl;
        richard.launchSpell("Fireball", *genWall);
    } else {
        std::cout << "Failed to create Wall target" << std::endl;
    }
    
    // 타겟 타입 삭제
    tarGen.forgetTargetType("Target Practice Dummy");
    ATarget* shouldBeNull = tarGen.createTarget("Target Practice Dummy");
    if (shouldBeNull) {
        std::cout << "Error: Target was not forgotten properly" << std::endl;
    } else {
        std::cout << "Successfully forgot Dummy target" << std::endl;
    }

    std::cout << "\n=== Memory Management Test ===" << std::endl;
    // 메인 함수 끝에서 생성한 객체들 삭제
    delete fwoosh;
    delete fireball;
    delete polymorph;
    delete genDummy;
    delete genWall;
    
    std::cout << "\n=== Assignment Example Test ===" << std::endl;
    // 과제에서 주어진 예제
    Warlock richard2("Richard", "foo");
    richard2.setTitle("Hello, I'm Richard the Warlock!");
    BrickWall model1;

    Polymorph* polymorph2 = new Polymorph();
    TargetGenerator tarGen2;

    tarGen2.learnTargetType(&model1);
    richard2.learnSpell(polymorph2);

    Fireball* fireball2 = new Fireball();

    richard2.learnSpell(fireball2);

    ATarget* wall2 = tarGen2.createTarget("Inconspicuous Red-brick Wall");

    richard2.introduce();
    richard2.launchSpell("Polymorph", *wall2);
    richard2.launchSpell("Fireball", *wall2);
    
    delete polymorph2;
    delete fireball2;
    delete wall2;

    return 0;
}