#include "Bag.h"

using namespace std;


//Default constructer.
Bag::Bag(){

	items = nullptr;
	itemCapacity = 0;
	itemSize = 0;
}

//explicit constructer
Bag::Bag(int cap){
	if(cap > 0){
		itemCapacity = cap;
		itemSize = 0;
		items = new Element[cap];

	} else {
		itemCapacity = 0;
		itemSize = 0;
		items = nullptr;
	}
}


Bag::Bag(const Bag& rhs){
	itemSize = rhs.itemSize;
	itemCapacity = rhs.itemCapacity;
	if(itemCapacity > 0){
		items = new Element[itemCapacity];
		for(int i = 0; i < rhs.itemSize; i++){
			items[i] = rhs.items[i];
		}
	} else {
		items = nullptr;
	}
}


Bag& Bag::operator=(const Bag &rhs){
	if(this!=&rhs){

		if(items != nullptr){
			delete[] items;
		}

		itemSize = rhs.itemSize;
		itemCapacity = rhs.itemCapacity;

		if(itemCapacity > 0){
			items = new Element[itemCapacity];

			for(int i = 0; i < itemCapacity; i++){
				items[i] = rhs.items[i];
			}
		} else {
			items = nullptr;
		}
	}
	return *this;

}



Bag::~Bag(){
	delete[] items;

}



void Bag::push_back(Element e){
	if(itemSize == itemCapacity){
		if(itemCapacity == 0){
			itemCapacity++;
		} else {
			itemCapacity = itemCapacity * 2;
		}
		
		Element *hold = new Element[itemCapacity];
		for(int i = 0; i < itemSize; i++){
			hold[i] = items[i];
		}
		delete[] items;
		items = hold;
		items[itemSize] = e;
		itemSize++;
	}else{
		items[itemSize] = e;
		itemSize++;
	}
}
Element Bag::pop_back(){
	if(items == nullptr || itemSize == 0){
		throw std::out_of_range("Cant get anything from empty Bag.");
	} else {
		itemSize--;
		return items[itemSize];
	}
//i know this is bad form but I am not sure what to return if its NULL
}

Element& Bag::operator[](int i){
	if(i < 0 || i >= itemSize){
		throw std::out_of_range("Cant Access Bag");
	} else {
		return items[i];;
	}
}


int Bag::find(Element e){
	int hold = -1;
	
	for(int i = 0; i < itemSize; i++){
		if(items[i] == e){
			hold = i;
			return hold;
		}
	}
	return hold;
}


int Bag::size(){
	return itemSize;
}

int Bag::capacity(){
	return itemCapacity;
}

void Bag::clear(){
	itemSize = 0;
}

bool Bag::empty(){
	return (itemSize == 0);
}

bool Bag::operator==(const Bag &b) const{
	bool size = false, cap = false, item = true, ret = false;
	if(itemSize == b.itemSize){
		size = true;
	}
	if(itemCapacity == b.itemCapacity){
		cap = true;
	}
	for(int i = 0; i < itemSize && cap; i++){
		if(items[i] != b.items[i]){
			item = false;
		}
	}
	
	if(size && cap && item){
		ret = true;
	}
	return ret;
}

bool Bag::operator!=(const Bag &b) const{
	bool size = false, cap = false, item = false, ret = false;
	if(itemSize != b.itemSize){
		size = true;
	}
	if(itemCapacity != b.itemCapacity){
		cap = true;
	}
	for(int i = 0; i < itemSize; i++){
		if(items[i] != b.items[i]){
			item = true;
		}
	}
	
	if(size && cap && item){
		ret = true;
	}
	return ret;	
}





ostream& operator<<(ostream &os, const Bag& b){

	os << b.itemSize << " items: ";
	for(int i = 0; i<b.itemSize; i++){
		os << b.items[i] << " ";
	}
	return os;
}
