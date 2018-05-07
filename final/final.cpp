//FINAL PROJECT FOR DATA STRUCTURES
//IT NEEDS TO READ IN A CSV

//NIKOLAAS BENDER
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include "finalLL.hpp"
#include "finalHeap.hpp"
#include "finalSTL.hpp"

using namespace std;
using namespace std::chrono;


//g++ -std=c++11 -g finalLL.cpp finalLL.hpp finalSTL.cpp finalSTL.hpp finalHeap.cpp finalHeap.hpp final.cpp -o final

int avg(int tests, int datas[]){
	int count = 0;
	for (int i = 0; i < tests; ++i)
	{
		count += datas[i];
	}
	return count/tests;

}



//THIS LACES THE DATA TOGETHER AND PUTS IT IN THE SPECIFIED FILE
void laceToFile(const char* dataFile, int datas[], int datal[], int datah[], int len){
	ofstream ootfile;
	ootfile.open(dataFile);
	ootfile << "trial number," << "STL," << "LL," << "Heap\n";
	for(int i = 0; i < len; i++){
		ootfile << to_string(i + 1) + "," << to_string(datas[i]) + "," << to_string(datal[i]) + "," << to_string(datah[i]) + "\n";
	}
	ootfile << "Averages," << to_string(avg(len, datas)) + "," << to_string(avg(len, datal)) + "," << to_string(avg(len, datah)) + "\n";
	ootfile.close();
}



int main(){
	high_resolution_clock::time_point starter = high_resolution_clock::now();
	string data = "patientData2270.csv";

	//TIMES SAVES THE TIMING DATA
	int reps = 500;
	int timeS[reps];
	int timeL[reps];
	int timeH[reps];



	//================================================
	//HEAP
	//================================================
	finalH fh;
	int duration2;
	const char* hout = "patientDataHeap.csv";
	for(int h = 0; h < reps; h++){
		duration2 = 0;
		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		
		remove(hout);
		//cout << "where you at gremlins" << endl;
		fh.readinH(data);
		//cout << "boo!" << endl;
		//fh.fillHeap();
		//fh.check();
		//cout << "i hope these gremlins are smaller then me" << endl;
		//fh.speakerH();
		//fh.filePrinterH(hout);
		//cout << "then i can easily step on them" << endl;
		fh.nukeem();

		high_resolution_clock::time_point t6 = high_resolution_clock::now();
		duration2 = duration_cast<microseconds>( t6 - t5 ).count();

		timeH[h] = duration2;	
	}

	cout << "finished heap" << endl;
	
	//================================================
	//STL
	//================================================
	finalS fs;
	int duration;
	const char* stlout = "patientDataSTL.csv";
	for(int s = 0; s < reps; s++){
		duration = 0;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		//cout << s << endl;
		remove(stlout);

		fs.reader(data);
		//fs.speaker();
		fs.daisyCutter();
		//fs.filePrinterS(stlout);
		
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration = duration_cast<microseconds>( t2 - t1 ).count();
		
		timeS[s] = duration;
	}

	cout << "finished stl" << endl;

	//================================================
	//LINKED LIST
	//================================================
	finalL fl;
	int duration1;
	const char* llout = "patientDataLink.csv";
	for(int l = 0; l < reps; l++){
		duration1 = 0;
		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		

		remove(llout);

		fl.readerL(data);
		
		fl.llbuild();
		//cout << "where are you breaking" << endl;
		//fl.filePrintL(llout);
		//fl.speakerL();
		fl.nukem();
		//cout << "stop breaking" << endl;
		
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		duration1 = duration_cast<microseconds>( t4 - t3 ).count();

		timeL[l] = duration1;
	}

	cout << "finished ll" << endl;

	const char* dout = "testData.csv";
	remove(dout);
	laceToFile(dout, timeS, timeL, timeH, reps);
	

	
	high_resolution_clock::time_point finish = high_resolution_clock::now();
	cout << "total time for the program was " << duration_cast<seconds>( finish - starter ).count() << " seconds" << endl;
	return 1;

}