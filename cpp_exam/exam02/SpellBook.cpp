#include "SpellBook.hpp"

SpellBook::SpellBook(){};
SpellBook::~SpellBook(){
    //erase all the map
    for(auto& maps : _spellbook)
    {
        delete maps.second;
    }
    _spellbook.clear(); //delete the map without pointer
};
void SpellBook::learnSpell(ASpell *spell){
    if(spell)
    {
      auto it = _spellbook.find(spell->getName()); 
      if (it != _spellbook.end()) {
        delete it->second;
        it->second = spell->clone();
      }
    else{
        _spellbook.emplace(spell->getName(), spell->clone());
    }
    }
}

void SpellBook::forgetSpell(const std::string &spellName)
{ 
    auto it = _spellbook.find(spellName);
    if(it != _spellbook.end())
    {
        delete it->second;//new
        _spellbook.erase(it);
    } 
}

ASpell* SpellBook::createSpell(const std::string& spellName){
    auto it = _spellbook.find(spellName);
    if (it != _spellbook.end())
        return it->second->clone();
    else 
        return nullptr;
}