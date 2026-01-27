// Recurrence relation : 3 * T(n/2) + n * logn
// Time complexity : O(n power log 3 base 2)

// to count the number of operations i have use the count variable 
// using pass by reference 

#include <bits/stdc++.h>
using namespace std;
using namespace std :: chrono;


void complexRec(int n, int &count) {
      
    
   if (n <= 2) {
    count++;
       return;
   }

   

   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
          count++;
       }
       p >>= 1;
       count++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
    count++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       count++;
   } else {
       reverse(small.begin(), small.end());
       count++;

       }


   complexRec(n / 2, count); 
   complexRec(n / 2, count);
   complexRec(n / 2, count);
   
}

int main(){
    int count = 0;
    int n;
    cout<<"Enter value: ";
    cin>>n;
    complexRec(8, count);
    cout << "number of operations: " << count << endl;
    

    
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds > (end - start);
    cout << duration.count();
    
    
    
}
