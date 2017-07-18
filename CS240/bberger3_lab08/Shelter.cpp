/*
	Questions to ask!
	1) why does my menu not work if i put in a non int
	2) I added a cancel. Is that ok?
	3) why does woof 2 go to the thing


*/



#include "Shelter.h"
#include <sstream>

using namespace std;


Shelter::Shelter(){
}

void Shelter::menu(){
	int val = 0;
	int men;
	while(val < 1){
		cout << "What would you like to do?" << endl;
		cout << "1. Add an animal." << endl;
		cout << "2. Remove an animal" << endl;
		cout << "3. Exit." << endl;
		men = -1;
		cin >> men;
		if(men < 4 && men > 0){
			cout << endl;
			if(men == 1){
				add();
			}			
			if(men == 2){
				remove();
			}
			if(men == 3){
//				exit();
				val++;
			}
		} else {
			cout << "That option is unavailable." << endl << endl;
			cin.clear();
			cin.ignore(10000,'\n');
		}
	}
}

void Shelter::add(){
	cout << "Would you like to add a dog or a cat?" << endl;
	cout << "1. Dog" << endl;
	cout << "2. Cat" << endl;
	int men;
	cin >> men;
	if(men > 0 && men < 3){
		if(men == 1){
			cout << "Provide the animal's name: ";
			string name;
			cin >> name;
			cout << "Added a dog named " << name << endl;
			dogNames.push (name);
			order.push_back (1);
			cout << endl;
		}
		if(men == 2){
			cout << "Provide the animal's name: ";
			string name;
			cin >> name;
			cout << "Added a cat named " << name << endl;
			order.push_back (2);
			catNames.push (name);
			cout << endl;
		}
	} else {
		cout << "Invalid Entry!" << endl << endl;
	}
}

void Shelter::remove(){
	cout << "Would you like to adopt a dog or a cat?" << endl;
        cout << "1. Dog" << endl;
        cout << "2. Cat" << endl;
	cout << "3. Either One." << endl;
        int men;
        cin >> men;
        if(men > 0 && men < 4){
		if(men == 1){
			if(dogNames.empty() == false){
				cout << "Provide the first name of the customer: ";
				string cust;
				cin >> cust;
				list<int>::iterator it;
				cout << cust << " adopted a dog named " << dogNames.front()<< endl;
				for(it = order.begin(); it != order.end() ; it++){
					if(*it == 1){
						order.erase(it);
						break;
					}
				}
				dogNames.pop();
				cout << endl;	
			} else {
				cout << "That option is unavailable." << endl << endl;
			}
		} else if(men == 2){
                        if(catNames.empty() == false){
                                cout << "Provide the first name of the customer: ";
                                string cust;
                                cin >> cust;
                                cout << cust << " adopted a cat named " << catNames.front()<< endl;
                          	list<int>::iterator it;
				 for(it = order.begin(); it != order.end() ; it++){
                                        if(*it == 2){
                                                order.erase(it);
                                                break;
                                        }
                                }
                                catNames.pop();
				cout << endl;
                        } else {
                                cout << "That option is unavailable." << endl << endl;
                        }
		} else if(men == 3){
                        if(order.empty() == false){
                                cout << "Provide the first name of the customer: ";
                                string cust;
                                cin >> cust;
				string mal;
				string nam;
				if(order.front() == 1){
					mal = "dog";
					nam = dogNames.front();
					dogNames.pop();
				} else {
					mal = "cat";
					nam = catNames.front();
					catNames.pop();
				}
                                cout << cust << " adopted a " << mal << " named " << nam  << endl;
                                order.pop_front();
				cout << endl;
                         } else {
                                cout << "That option is unavailable." << endl << endl;
                         }
		} else {
			cout << "Invalid Entry!" << endl << endl;
		}
	}
}
/* realized i dont need this! not on the heap!
void Shelter::exit(){
	while(order.empty() == false){
		order.pop_back();
	}
	while(dogNames.empty() == false){
		dogNames.pop();
	}
	while(catNames.empty() == false){
		catNames.pop();
	}
}*/
