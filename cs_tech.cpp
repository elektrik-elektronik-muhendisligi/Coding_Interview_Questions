// CS-TECH APPLICANT ASSESMENT TEST 1
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int rand_number( void );
bool is_valid( int );
void move_to_array( int, int, int[], int[] );
void same_digit( int[], int[], int[] );
void diff_digit( int [], int [], int [] );
void print( int[] );

int main(){

    srand(time ( 0 ));

    cout << "---------------------GENERATING INITIAL VALUES ---------------------- \n";
    int user1, software1, user2, software2;
    int u1[ 4 ] = { 0 }, s1[ 4 ] = { 0 }, u2[ 4 ] = { 0 }, s2[ 4 ] = { 0 };
    int comp1[ 4 ] = { 0 }, comp2[ 4 ] = { 0 };
    cout << "\n Computer is generating a number for user..\n";
    do{
        software1 = rand_number();
    } while (!is_valid ( software1 ));

    cout << "\n\n User is generating a number for computer.. \n";
    do{
        cout << " User's generated number : ";
        cin >> user2;
    } while (!is_valid ( user2 ));

    cout << "\n\n ------------------- GUESSING & INFORMATION --------------------- ";
    while ( 1 ){

        cout << "\n\n User is guessing computers number..\n";
        do{
           cout << " User's valid number : ";
           cin >> user1;
        } while ( !is_valid ( user1) );

        cout << " Users information code : ";
        move_to_array( software1, user1 , s1, u1 );
        diff_digit( s1, u1, comp1 );
        same_digit( s1, u1, comp1 );
        print ( comp1 );

        cout << " \n software1 : ";
        print( s1 );
        cout << " \n user1 : ";
        print( u1 );

        if ( software1 == user1 ){
           cout << "\n\n ------ THE NUMBER IS => " << user1 << " ------> " << " USER WIN THE GAME!"<< endl;
           break;
        }

        cout << "\n\n Computer is guessing users number..\n";
        do{
            software2 = rand_number();
            cout << " Computer valid number : " << software2 << endl;
        } while (!is_valid ( software2 ));

        cout << " Computers information code :";
        move_to_array( software2, user2 , s2, u2 );
        diff_digit( u2, s2, comp2 );
        same_digit( s2, u2, comp2 );
        print ( comp2 );

        cout << " \n software2 : ";
        print( s2 );
        cout << " \n user2: ";
        print( u2 );

        if ( software2 == user2 ){
           cout << "\n\n ------ THE NUMBER IS => " << software2 << " ------> " << " COMPUTER WIN THE GAME!"<< endl;
           break;
        }
    }
    return 0;
}

/*
Function that generates random numbers between 1000 and 9999
*/
int rand_number(void){
   return rand() % 9000 + 1000;
}

/*
This test function is the check whether the number sent to it is a conditional
number that does not repeat steps. If it is valid returned 1 value, 0  if not .
*/
bool is_valid(int number){
   int temp, i, j;
   for (i = 0; i < 10; i++) {
      j = 0;
      temp = number;
      while (temp > 0) {
         if (temp % 10 == i)
            j++;
         if (j > 1)
            return 0;
         temp /= 10;
      }
   }
   return 1;
}

void move_to_array( int num1, int num2, int n1[], int n2[] ){
    for (int i = 3; i >= 0;  i--) {
        int x = pow( 10, i );
        n1[ i ] = num1 / x;
        n2[ i ] = num2 / x;
        num1 = num1 % x;
        num2 = num2 % x;
    }
}

void same_digit( int num1[], int num2[], int comp[] ){
     for (int i = 3; i >= 0;  i--) {
             if ( num1[ i ] == num2[ i ] )
                comp[ i ] = 1;
     }
}
void diff_digit( int num2[], int num1[], int diff[] ){
     for (int i = 3; i >= 0;  i--){
         for (int j = 3; j >= 0; j--) {
             if ( num1[ i ] == num2[ j ] )
                diff[ i ] = -1;
         }
     }
}

void print( int arr[] ){
    for (int i = 3;  i >= 0;  i--)
        cout << arr[ i ];
}
