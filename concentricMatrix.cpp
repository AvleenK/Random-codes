#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>

using namespace std;

vector<vector<int> > prettyPrint(int A) {
    /*
    the outermost rectangle is formed by A, this number
    decreases as we go near the center of the matrix.
    */
    int r = 2*A-1;
    int c = 2*A-1;
    vector< vector<int> > arr(r);
    for(int i = 0; i < r; i++) {
        arr[i] = vector<int>(c);
    }
    int c1 = A-1;
    int c2 = A-1;
    int m;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            m = max(abs(c1-i), abs(c2-j));
            arr[i][j] = m+1;
        }
    }
    return arr;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector< vector<int> > arr;
    arr = prettyPrint(n);
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
