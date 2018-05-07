//FINAL HELPER
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include "finalSTL.hpp"

using namespace std;

finalS::finalS(){}

finalS::~finalS(){
	daisyCutter();
}

// struct comapre{
// 	bool operator()(const wooman &a, const wooman &b){
// 		if(a.priority != b.priority){
// 			return a.priority < b.priority;
// 		}else{
// 			return a.treatment < b.treatment;
// 		}
// 	}
// };


//READS IN THE FILE AND RETURNS A PRIORITY VECTOR FOR THE PATIENTS
void finalS::reader(string file){
	ifstream infile;
	
	//cout << "cunt" << endl;

	infile.open(file);

	wooman tmp("", 0, 0);
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
            	women.push_back(tmp);
            }
            index++;
            //cout << index << endl;
		}
		size = index;
		infile.close();	
	}

	for (int p = 0; p < size; p++){
		pq.push(women[p]);
	}
}

void finalS::speaker(){
	int count = 0;
	while(!pq.empty()){
		wooman g = pq.top();
		cout << g.name << " " << g.priority << endl;
		pq.pop();
		count++;
	}
	cout << count << endl;
	women.clear();
}

void finalS::daisyCutter(){
	int count = 0;
	while(!pq.empty()){
		pq.pop();
		count++;
	}
	//cout << count << "deleted"<< endl;
	women.clear();
}

void finalS::filePrinterS(string filename){
	ofstream ootfile;
	ootfile.open(filename);
	ootfile << "Starting to print sorted list \n";
	int count = 0;
	while(!pq.empty()){
		wooman g = pq.top();
		ootfile << g.name + "," << to_string(g.priority) + "," << to_string(g.treatment) + "\n";
		pq.pop();
		count++;
		//cout << count << endl;
	}
	ootfile << "The number of items printed " << count << "\n";
	ootfile << "End of sorted linked list print" << endl;
	ootfile.close();
	daisyCutter();
}
