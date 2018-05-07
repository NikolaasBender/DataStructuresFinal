//FINAL HEADER
#ifndef FINALL_H
#define FINALL_H
#include <iostream>
#include <array>
#include <vector>

using namespace std;

struct woomanL{
	string name;
	int priority;
	int treatment;
	woomanL *next = NULL;
	woomanL *previous = NULL;
	woomanL(string n, int p, int t) : name(n), priority(p), treatment(t){};
};

class finalL{
	public:
        finalL();
        ~finalL();
        void readerL(string);
        void llbuild();
        void speakerL();
        void filePrintL(string);
        void nukem();

    protected:
    private:
        //SEE NOTE
        vector<woomanL> womenL;
        int compare(woomanL&, woomanL&);
        woomanL *head;
        woomanL *tail;
        int size = 0;
        int index = 0;

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