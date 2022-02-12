#pragma once

#include <iostream>
#include <string>

class HP{
public:
  HP(int hp): _hp(hp) {}
  std::string print() const {return "["+std::to_string(_hp)+" HP]";}
private:
  int _hp;
};

class GameObj{
public:
  GameObj()=default;
  GameObj(std::string id) : _id(id) {}
  virtual ~GameObj() {}
  std::string id() const {return _id;}
  virtual std::string print() const=0;
  friend std::ostream& operator<<(std::ostream& s, const GameObj& go){
    s<<go.print();
    return s;
  }
private:
  std::string _id;
};

class Character : virtual public GameObj{
public:
  Character(HP hp, std::string name) : _name(name), _hp(hp) {}
  std::string hp() const {return _hp.print();}
  std::string name() const {return _name;}
private:
  std::string _name;
  HP _hp;
};

class Hurting : virtual public GameObj{
public:
  Hurting(HP hp) : _hp(hp) {}
  std::string hp() const {return _hp.print();}
  std::string print() const override {return "Jego uderzenie odbiera: "+_hp.print();}
private:
  HP _hp;
};

class Player : public Character{
public:
  Player(HP hp, std::string name, std::string id) : GameObj(id), Character(hp, name) {}
  std::string print() const override {return "Player "+name()+", ma: "+hp();}
};

class Boss : public Character, public Hurting{
public:
  //konstruktor
  Boss(HP hp1, std::string name, HP hp2, std::string id) : GameObj(id), Character(hp1, name), Hurting(hp2) {}
  //nadpisane wypisywanie zawierajace dodatkowo imie, ilosc posiadanego hp i hp odbieranego
  std::string print() const override {return "Bad guy: "+name()+", ma: "+Character::hp()+"\n"+Hurting::print();}
};

class Bomb : public Hurting{
public:
  Bomb(HP hp, std::string id) : GameObj(id), Hurting(hp) {}
};