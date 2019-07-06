//Google coding interview questions. Daily Coding Problem: Problem #1 [Easy]
/* Good morning! Here's your coding interview problem for today.
   This problem was recently asked by Google.
   Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

   For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

   Bonus: Can you do this in one pass?
*/
#include <iostream>
using namespace std;

int main(){
    int array[ 4 ] = { 10, 15, 3, 7 }, sum = 0, ind = 0, k = 17;
    int i, j, count = 0;

            for ( i = 0; i < 3; i++) {
                for ( j = i+1 ; j <= 3; j++) {
                    sum = array[ i ] + array[ j ] ;
                    cout << sum << endl;
                    if (sum == k) {
                        cout << array[ i ] << " + " << array[ j ] << " = " << sum << endl;
                    break;
                    }
                }
            }

    return 0;
}
