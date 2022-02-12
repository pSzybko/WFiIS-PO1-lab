#pragma once

#include <iostream>
#include <string>

class SysObj{
public:
	SysObj(const std::string name):_name(name){}
	virtual ~SysObj()=default;
	std::string getName() const{return _name;}
	virtual void print(std::ostream& s, int ind=0) const{
		for(int i=0; i<ind; i++)
			s<<"	";
		s<<_name;
	}
private:
	std::string _name;
};

std::ostream& operator<<(std::ostream& s, const SysObj& so){
	so.print(s);
	return s;
}

class File : public SysObj{
public:
	File(std::string name): SysObj(name) {}
	~File() override=default;
	void print(std::ostream& s, int ind=0) const override{
		SysObj::print(s, ind);
		s<<" (FILE)"<<std::endl;
	}
};