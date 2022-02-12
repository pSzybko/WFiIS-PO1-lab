#pragma once

#include "File.h"

#include <vector>

class Dir final : public SysObj{
public:
	Dir(const std::string name): SysObj(name) {}
	~Dir() override{
		std::cout<<"Deleting Dir: "<<getName()<<std::endl;
		for(int i=0; i<_arr.size(); i++){
			std::cout<<"About to delete "<<_arr[i]->getName()<<std::endl;
			delete _arr[i];
		}
	}
	void print(std::ostream& s, int ind=0) const override{
		SysObj::print(s, ind);
		s<<" (DIR)"<<std::endl;
		for(int i=0; i<_arr.size(); i++)
			_arr[i]->print(s, ind+1);
	}
	void operator+=(SysObj* so){
		_arr.push_back(so);
	}
	Dir* findDir(std::string name){
		for(int i=0; i<_arr.size(); i++){
			Dir* tmp;
			if((tmp=dynamic_cast<Dir*>(_arr[i]))){
				if(tmp->getName()==name)
					return tmp;
				Dir* tmp2=tmp->findDir(name);
				if(tmp2!=nullptr)
					return tmp2;
			}
		}
		return nullptr;
	}
	void add(SysObj* so){
		_arr.push_back(so);
	}
	SysObj* get(std::string name){
		for(int i=0; i<_arr.size(); i++){
			if(_arr[i]->getName()==name)
				return _arr[i];
			Dir* tmp;
			if((tmp=dynamic_cast<Dir*>(_arr[i]))){
				SysObj* tmp2=tmp->get(name);
				if(tmp2!=nullptr)
					return tmp2;
			}
		}
		return nullptr;
	}
private:
	std::vector<SysObj*> _arr;
};