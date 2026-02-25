#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define MAX 100

int heap[MAX];
int heapSize=0;



void heapifyUp(int i) {

while(i>0 && heap[(i-1)/2] > heap[i]) {


swap(heap[(i-1)/2], heap[i]);
i = (i-1)/2;
} 

}
void insert(int val) {

if(heapSize == MAX) 
{
cout<<"full";
return;
}
heap[heapSize] = val;
heapSize++;
heapifyUp(heapSize-1);
}

int main() {

insert(3);
insert(12);
insert(9);
insert(2);

for(int i =0;i<heapSize;i++) cout<<heap[i]<< " ";


}

