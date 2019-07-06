// Google coding interview questions.Daily Coding Problem: Problem #18 [Hard]

/* Good morning! Here's your coding interview problem for today.This problem was asked by Google.
   Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum
   values of each subarray of length k.

   For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

   10 = max(10, 5, 2)
   7 = max(5, 2, 7)
   8 = max(2, 7, 8)
   8 = max(7, 8, 7)

   Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store
   the results. You can simply print them out as you compute them.
*/

#include <iostream>
using namespace std;

int max( int arr[ 3 ] ){
    int max = arr[ 0 ];
    for ( int i = 0; i < 3; i++) {
        if ( arr[ i ] > max ){
            max = arr[ i ];
        }
    }
    return max;
}

void print( int arr[ 3 ] ){
    for ( int i = 0; i < 3; i++) {
        cout << arr[ i ] << " ";
    }
}

int main(){
    int array[ 6 ] = { 9, 5, 2, 7, 8, 7 }, top[ 3 ] = { 0 };

    for ( int i = 0; i < 4; i++ ){
        int x = 0;
        for ( int j = i; j <= i+2; j++){
            top[ x ] = array[ j ];
            x++;
        }
        print( top );
        cout << "  max --> " << max ( top ) << endl;
    }
    return 0;
}
