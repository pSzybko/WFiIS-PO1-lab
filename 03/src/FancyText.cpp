#include "FancyText.h"

FancyText::FancyText(const char* str){
	_str=new char[strlen(str)+1];
	strcpy(_str, str);
}

FancyText::FancyText(const FancyText& other){
	if(this==&other) 
		return;
	_str=new char [strlen(other._str)+1];
	strcpy(_str, other._str);
}

FancyText::FancyText(FancyText&& other):_str(std::__exchange(other._str ,nullptr)), _next(std::__exchange(other._next, nullptr))
{}

FancyText::~FancyText(){
	remove();
}

void FancyText::operator+=(FancyText&& ft){
	FancyText* ptr=this;
	while(ptr->_next!=nullptr){
		ptr=ptr->_next;
	}
	ptr->_next=new FancyText(std::move(ft));
}

int FancyText::size() const{
	if(_str==nullptr and _next==nullptr)
		return 0;
	int tmp=0;
	const FancyText* ptr=this;
	while(ptr->_next!=nullptr){
		tmp+=strlen(ptr->_str);
		ptr=ptr->_next;
	}
	tmp+=strlen(ptr->_str);
	return tmp;
}

int FancyText::fragments() const{
	int tmp=0;
	const FancyText* ptr=this;
	while(ptr->_next!=nullptr){
		ptr=ptr->_next;
		tmp++;
	}
	tmp++;
	return tmp;
}

void FancyText::operator =(FancyText&& other){
	
  	remove();
  	_str=std::__exchange(other._str, nullptr);
  	_next=std::__exchange(other._next, nullptr);
}

const FancyText& FancyText::fragment(int index) const{
	const FancyText* ptr=this;
	for(int i=0; i<index; i++)
		ptr=ptr->_next;
	return *ptr;
}

void FancyText::remove(){
	if(_str == nullptr) return;
	delete[] _str;
	delete _next;
}