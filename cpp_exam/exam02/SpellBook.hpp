#pragma once

#include <string>
#include <unordered_map>
#include "ASpell.hpp"

class SpellBook{
    private:
        SpellBook(const SpellBook& other);
        SpellBook& operator=(const SpellBook& other);

        std::unordered_map<std::string, ASpell*> _spellbook;

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell*);
        void forgetSpell(const std::string& spellName);
        ASpell *createSpell(const std::string &spellName);
};
