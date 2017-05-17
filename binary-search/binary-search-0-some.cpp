/*#include "binsearch.h"
#include "printarray.h"

//c++ header include
#ifdef DEBUG
 #include <iostream>
 #include <iomanip>
#endif*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "pliny_fill.h"
using namespace std;

int binsearch(int a[], int x, int n){
    int l, r, i;        //n = Gr ??e of array of main ?Mountain just
    l=0;
    r=n-1;
    
    while (l <= r){
      __pliny_fill__(ALLOW_EARLY_RETURN, USE_VARS, l, r, i, x, a);
    }
    return -1;                //not found

}

int main(int argc, char** argv) {
    int search = atoi(argv[1]);
    int len = argc - 2;
    int arr[len];
    for(int i=0; i<len && i < argc - 2; ++i) {
        arr[i] = atoi(argv[i+2]);
    }
    cout << binsearch(arr, search, len) << endl;
    return 0;
}
