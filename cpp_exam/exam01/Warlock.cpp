#include "Warlock.hpp"

Warlock::Warlock(const std::string &_name, const std::string &_title)
    : _name(_name), _title(_title) 
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
};

Warlock::~Warlock() { std::cout << _name << ": My job here is done !" << std::endl; 
    for (std::unordered_map<std::string, ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
    {
        delete it->second;
    }
    // for (auto& pair : _spellBook)
    //     delete pair.second;
    _spellBook.clear();//delete the trash value inside perfectly
};

const std::string& Warlock::getName() const{
    return _name;
};
const std::string& Warlock::getTitle() const{
    return _title;
};

void Warlock::setTitle(const std::string& newTitle){
    _title = newTitle;
}

void Warlock::introduce() const{
    std::cout << _name << ": I am " << _name << ", " << _title << std::endl;
};

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
    {
      // operator[] will check if there is no key in the map then create new one
      // if there is then do nothing
      // so that is why if there is then update
        forgetSpell(spell->getName());
        _spellBook[spell->getName()] = spell->clone(); // map key = value
    }
}

void Warlock::forgetSpell(const std::string &spellName){

  //   std::unordered_map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
  auto it = _spellBook.find(spellName);
  if (it != _spellBook.end()) {
    delete it->second;
    _spellBook.erase(it);
  }
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target) {
    std::unordered_map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
    {
        it->second->launch(target);    
    }
}