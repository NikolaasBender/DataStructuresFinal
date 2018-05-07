//FINAL HELPER
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include "finalLL.hpp"

using namespace std;

finalL::finalL(){}

finalL::~finalL(){
	nukem();
}




//READS IN THE FILE AND RETURNS A PRIORITY VECTOR FOR THE PATIENTS
void finalL::readerL(string file){
	ifstream infile;
	
	//cout << "cunt" << endl;

	infile.open(file);

	woomanL tmp("", 0, 0);
	if(infile.is_open()){
		//GET LINE IS IMPORTANT
		//THIS PUTS THE FILE INTO A 2D VECTOR
		//cout << "hey keaton its garbage data" << endl;
		string chopper = "";
		int index = 0;
		while (getline(infile,chopper,'\r')) {
		    stringstream iss(chopper);
            string name = "";
            string pri = "";
            string tre = ""; 
            //cout << chopper << endl;
            getline(iss, name, ',');
            getline(iss, pri, ',');
            getline(iss, tre, ',');
            if(index != 0){
            	tmp.name = name;
            	tmp.priority = stoi(pri);
            	tmp.treatment = stoi(tre);
            	womenL.push_back(tmp);
            }
            index++;
            //cout << index << endl;
		}
		size = index;
		infile.close();	
	}
}

//INSERT BEFORE IF TRUE
int finalL::compare(woomanL &a, woomanL &b){
	//cout << "they burned burned burned" << endl;
	if(a.priority != b.priority){
		if(a.priority < b.priority)
			return 0;
		else
			return 1;
	}else{
		if(a.treatment < b.treatment)
			return 0;
		else
			return 1;
	}
}



void finalL::llbuild(){

	head = &womenL[0];
	tail = &womenL[0];
	//CRWL LOOKS FOR WHERE TO INSERT
	woomanL *crwl;
	//TMP IS THE WOOMAN THAT HAS TO BE ADDED
	woomanL *tmp;

	//cout << "fire fire fire" << endl;
	crwl = head;
	//DO IT WITH A FOR LOOP TO AVOIDINFINITE LOOP AND DONT HAVE TO DELETE
	for(int i = 1; i < size; i++){
		tmp = &womenL[i];
		//cout << tmp -> name << endl;
		while(crwl != NULL){
			//cout << crwl << endl;
			if(compare(*crwl, *tmp) == 1){
				//THIS IS IF WE HAVE TO REPLACE THE HEAD
				if(crwl == head){
					//cout << "inserting at head: " << tmp -> name << " " << tmp -> priority << endl;
					tmp -> next = crwl;
					crwl -> previous = tmp;
					head = tmp;
					crwl = head;
					break;
				//THIS IS IF WE HAVE TO INSERT IN THE MIDDLE
				}else{
					//cout << "inserting at middle: " << tmp -> name << " " << tmp -> priority << endl;
					crwl -> previous -> next = tmp;
					tmp -> next = crwl;
					tmp -> previous = crwl -> previous;
					crwl -> previous = tmp;
					crwl = head;
					break;
				}
			//THIS IS IF TMP IS > CRWL WE NEED TO KEEP SEARCHING
			}else{
				//cout << "moving" << endl;
				//cout << tail << " " << head << " " << crwl << endl;
				if(crwl == tail){
					//cout << "changing tail" << endl;
					crwl -> next = tmp;
					tmp -> previous = crwl;
					tail = tmp;
					crwl = head;
					break;
					//cout << crwl << endl;
				}else{
					//cout << "crwl forwad" << endl;
					crwl = crwl -> next;
					//cout << crwl << endl;
				}
				
			}
		}
		
	}
}



void finalL::speakerL(){
	woomanL *crwl = head -> next;
	int counter = 0;
	while(crwl != tail){
		cout  << crwl -> name << " " << crwl -> priority << endl;
		crwl = crwl -> next;
		counter++;
	}
	cout << tail -> name << " " << tail -> priority << endl;
	cout << counter + 1 << endl; 
}



void finalL::filePrintL(string filename){
	ofstream ootfile;
	ootfile.open(filename);
	ootfile << "Starting to print sorted linked list \n";
	woomanL *crwl = head -> next;
	int counter = 0;
	while(crwl != tail){
		ootfile << crwl -> name + "," << to_string(crwl -> priority) + "," << to_string(crwl -> treatment) << "\n";
		crwl = crwl -> next;
		counter++;
	}
	ootfile << tail -> name + "," << to_string(tail -> priority) + "," << to_string(tail -> treatment) << "\n";
	ootfile << "The number of items printed " << counter + 1 << "\n";
	ootfile << "End of sorted linked list print" << endl;
	ootfile.close();
	nukem();
}



void finalL::nukem(){

	head = NULL;
	tail = NULL;
	womenL.clear();
}