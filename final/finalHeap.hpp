//FINAL HEADER
#ifndef FINALH_H
#define FINALH_H
#include <iostream>
#include <array>
#include <vector>

using namespace std;

struct woomanH{
    string name;
    int priority;
    int treatment;
    woomanH *parent = NULL;
    woomanH *leftho = NULL;
    woomanH *rightho = NULL;
    woomanH(string n, int p, int t) : name(n), priority(p), treatment(t) {};
};

class finalH{
    public:
        finalH();
        ~finalH();
        bool compapree(woomanH *a, woomanH *b);
        void readinH(string);
        void insertwooman(woomanH *p);
        void deleteKey(int i);
        void minHeapify(int i);
        void check();
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i + 1); }
        int right(int i) { return (2*i + 2); }
        void fillHeap();
        void nukeem();
        void speakerH();
        void filePrinterH(string);

    protected:
    private:
        //SEE NOTE
        vector<woomanH> womenH;
        woomanH *harr[880]; // pointer to array of elements in heap   
        woomanH *root;
        int heapsz = 0;
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