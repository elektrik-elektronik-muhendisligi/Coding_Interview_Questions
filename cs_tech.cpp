// CS-TECH APPLICANT ASSESMENT TEST 1
// SAYI TAHMİN OYUNU
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
    /*
    Bu bölümde tahmin edilecek olan başlangıç değerleri bilgisayar ve kullanıcı
    tarafından oluşturulur. Sayının rakamlarının tekrar etmesi durumunda sayının
    tekrar girilmesi sağlanır.
    */
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
    /*
    Bu bölümde kullanıcı ve yazılım, iki taraftan biri doğru tahmin edene kadar.
    tahminlerde bulunur. Sayının rakamlarının tekrar etmesi durumunda sayının
    tekrar girilmesi sağlanır.
    */
    cout << "\n\n ------------------- GUESSING & INFORMATION --------------------- ";
    while ( 1 ){

        cout << "\n\n User is guessing computer's number..\n";
        do{
           cout << " User's valid number : ";
           cin >> user1;
        } while ( !is_valid ( user1) );

        cout << " User's information : ";
        move_to_array( software1, user1 , s1, u1 );
        diff_digit( s1, u1, comp1 );
        same_digit( s1, u1, comp1 );
        print ( comp1 );

        if ( software1 == user1 ){
           cout << "\n\n ------ THE NUMBER IS => " << user1 << " ------> " << " USER WIN THE GAME!"<< endl;
           break;
        }

        cout << "\n\n Computer is guessing user's number..\n";
        do{
            software2 = rand_number();
            cout << " Computer's valid number : " << software2 << endl;
        } while (!is_valid ( software2 ));

        cout << " Computers information :";
        move_to_array( software2, user2 , s2, u2 );
        diff_digit( u2, s2, comp2 );
        same_digit( s2, u2, comp2 );
        print ( comp2 );

        if ( software2 == user2 ){
           cout << "\n\n ------ THE NUMBER IS => " << software2 << " ------> " << " COMPUTER WIN THE GAME!"<< endl;
           break;
        }
    }
    return 0;
}

/*
1000 ile 9999 arasında rasgele sayı üreten fonksiyon
*/
int rand_number(void){
   return rand() % 9000 + 1000;
}

/*
Üretilen sayının basamaklarının birbirinden farklı olup olmadığını test eden fonksiyon
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

/*
Dört basamaklı sayıların rakamlarını 4 boyutlu bir diziye atayan fonksiyon
*/
void move_to_array( int num1, int num2, int n1[], int n2[] ){
    for (int i = 3; i >= 0;  i--) {
        int x = pow( 10, i );
        n1[ i ] = num1 / x;
        n2[ i ] = num2 / x;
        num1 = num1 % x;
        num2 = num2 % x;
    }
}
/*
Basamaklardan oluşturulan dizilerin karşılaştırılıp aynı değer ve aynı
basamak değeri varsa 1 yok ise 0 değerini atayan fonksiyon
*/
void same_digit( int num1[], int num2[], int comp[] ){
     for (int i = 3; i >= 0;  i--) {
             if ( num1[ i ] == num2[ i ] )
                comp[ i ] = 1;
     }
}
/*
İki sayı içinde oluşturulan dizilerin karşılaştırılıp değeri doğru olan ancak
yanlış basamakta bulunanların değerine -1 atayan fonksiyon
*/
void diff_digit( int num2[], int num1[], int diff[] ){
     for (int i = 3; i >= 0;  i--){
         for (int j = 3; j >= 0; j--) {
             if ( num1[ i ] == num2[ j ] )
                diff[ i ] = -1;
         }
     }
}
/*
Parametre olarak aldığı diziyi yazdıran fonksiyon
*/
void print( int arr[] ){
    for (int i = 3;  i >= 0;  i--)
        cout << arr[ i ];
}
