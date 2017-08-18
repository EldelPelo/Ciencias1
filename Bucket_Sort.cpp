#include <iostream>
using namespace std;
 
void b_sort(int sarray[], int array_size) {
    const int max = array_size;
    // use bucket[x][max] to hold the current count
    int bucket[10][max+1];
    // init bucket counters
    for(int x=0;x<10;x++)
		bucket[x][max] = 0;
    // main loop for each digit position
    for(int digit = 1; digit <= 100; digit += 10) {
        // array to bucket
        for(int i = 0; i < max; i++) {
            // get the digit 0-9
            int dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
        }
    }
}
 
int main() {
    int i, a[] = {29,25,3,49,9,37,21,43}, n = 8;
    int SIZE=10;
    cout<<"Before sorting:\n";
    for(i = 0; i < n; ++i)
        cout << a[i] << " ";
    
    b_sort(a,n);
    
    cout<< "\n\nAfter sorting:\n";
    for(i = 0; i < n; ++i)
        cout<< a[i] << " ";
    
    return 0;
}
