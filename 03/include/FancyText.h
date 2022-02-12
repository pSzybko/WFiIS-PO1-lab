#pragma once

#include <iostream>
#include <cstring>

class FancyText{
public:
	FancyText():_str(nullptr){}
	FancyText(const char* str);
	FancyText(const FancyText& other);
	FancyText(FancyText&& other);
	~FancyText();
	void operator+=(FancyText&& ft);
	int size() const;
	const char* str() const{return _str;}
	int fragments() const;
	friend std::ostream& operator<<(std::ostream& s, const FancyText& ft);
	void operator =(FancyText&& other);
	const FancyText& fragment(int index) const;
	void remove();
private:
	char* _str;
	FancyText* _next=nullptr;
};

std::ostream& operator<<(std::ostream& s, const FancyText& ft){
	if(ft._str==nullptr)
		return s;
	const FancyText* ptr=&ft;
	while(ptr->_next!=nullptr){
		s<<ptr->_str;
		ptr=ptr->_next;
	}
	s<<ptr->_str;
	return s;
}