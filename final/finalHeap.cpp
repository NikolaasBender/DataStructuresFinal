//FINAL HELPER
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include "finalHeap.hpp"

using namespace std;

finalH::finalH(){}

finalH::~finalH(){
}

void finalH::check(){
    for (int i = 0; i < size; ++i){
        cout << womenH[i].name << "  " << womenH[i].priority << "  " << womenH[i].treatment << endl;
    }
    cout << size << endl;
}


void mic(woomanH *node){
    if(node == NULL) return;
    mic(node->leftho);
    cout << node -> name << " " << node -> priority << endl;
    mic(node->rightho);
}

void finalH::speakerH(){
    mic(root);
    nukeem();
}



string pen(woomanH *node){
    if(!node) return "";
    string lefty = pen(node->leftho);
    string dat = lefty + node -> name + "," + to_string(node -> priority) + "," + to_string(node -> treatment) + "\n";
    string righty = pen(node->rightho);
    return dat + righty;
}

void finalH::filePrinterH(string outfile){
    ofstream ootfile;
    ootfile.open(outfile);
    ootfile << "Starting to print sorted womenH \n";
    string master = pen(root);
    ootfile << master;
    ootfile.close();
    nukeem();
}



 bool finalH::compapree(woomanH *a, woomanH *b){
 	if(a -> priority < b -> priority){
        return true;
    }else if(a -> priority > b -> priority){
        return false;
    }else if(a -> treatment < b -> treatment ){
        return true;
    }
    return false;
 }

void finalH::readinH(string file){
    ifstream infile;
    
    //cout << "cunt" << endl;

    infile.open(file);

    woomanH tmp("", 0, 0);
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
                womenH.push_back(tmp);
            }
            index++;
            //cout << index << endl;
        }
        size = index - 1;
        infile.close(); 
    }
}
 
void finalH::insertwooman(woomanH *p){
    heapsz++;
    int i = heapsz - 1;
    harr[i] = p;
    while(i != 0 && compapree(harr[parent(i)], harr[i]))
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
 

void finalH::deleteKey(int i){
    root = harr[0];
    harr[0] = harr[heapsz-1];
    heapsz--;
    minHeapify(0);
}
 

void finalH::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smol = i;
    if (l < heapsz && compapree(harr[l], harr[i]))
        smol = l;
    if (r < heapsz && compapree(harr[r], harr[smol]))
        smol = r;
    if (smol != i)
    {
        swap(harr[i], harr[smol]);
        minHeapify(smol);
    }
}
 

void swap(woomanH *x, woomanH *y){
    woomanH tmp = *x;
    *x = *y;
    *y = tmp;
}

void finalH::fillHeap(){
	for(int i = 0; i < womenH.size(); i++){
		insertwooman(&womenH[i]);
	}
}

void finalH::nukeem(){
	while(heapsz !=0){
		deleteKey(0);
	}
}