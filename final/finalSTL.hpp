//FINAL HEADER
#ifndef FINALS_H
#define FINALS_H
#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

struct wooman{
	string name;
	int priority;
	int treatment;
	wooman(string n, int p, int t) : name(n), priority(p), treatment(t){};
};


//YOU MIGHT NEED TO FLIP THE INEQUALITY SIGNS
struct comapre{
	bool operator()(const wooman &a, const wooman &b){
		if(a.priority != b.priority){
			return a.priority > b.priority;
		}else{
			return a.treatment > b.treatment;
		}
	}
};

class finalS{
	public:
        finalS();
        ~finalS();
        void reader(string);
        void speaker();
        void daisyCutter();
        void filePrinterS(string);

    protected:
    private:
    	//SEE NOTE
    	vector<wooman> women;   
       	priority_queue<wooman, vector<wooman>, comapre> pq;
       	//int index = 0;
       	int size;

};

#endif //FINAL

/*
I originally made this to work with a vector
for reading out of the file a week ago. I tried
to change it to an array and it broke everything.
In the interist of time and demonstrating that 
I know how to do everything else that you want
me to do I changed it back to the vector. I know
how to do it with array but I don't have the 
time to fix it now. 
*/