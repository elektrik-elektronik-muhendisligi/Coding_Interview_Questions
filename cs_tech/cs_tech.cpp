// CS-TECH APPLICANT ASSESMENT TEST 1
// SAYI TAHMİN OYUNU
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int rand_number( void );
int rand_digit( void );
bool is_valid( int );
bool is_valid_arr( int [] );
void move_to_array( int, int[] );
void digit_control( int [], int [], int [] );
void change_digit( int [], int [], int [] );
bool equal ( int [], int [] );
void print( int[] );

int main(){

    srand(time ( 0 ));
    int user1, software1, user2, software2;
    int u1[ 4 ] = { 0 }, s1[ 4 ] = { 0 }, u2[ 4 ] = { 0 }, s2[ 4 ] = { 0 };
    int comp1[ 4 ] = { 0 }, comp2[ 4 ] = { 0 };


    /*
    Bu bölümde tahmin edilecek olan başlangıç değerleri bilgisayar ve kullanıcı
    tarafından oluşturulur. Sayının rakamlarının tekrar etmesi durumunda sayının
    tekrar girilmesi sağlanır.
    */
    cout << " --------------------- GENERATING INITIAL VALUES ------------------- \n";
    cout << "\n Computer is generating a number for user..\n";
    do{
        software1 = rand_number();
    } while (!is_valid ( software1 ));
    cout << " Computers number : " << software1 << endl;

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
    cout << "\n\n ------------------- GUESSING & INFORMATION ------------------------";
    while ( 1 ){

        cout << "\n\n User is guessing computer's number..\n";
        do{
            cout << " User's valid number : ";
            cin >> user1;
        }while ( !is_valid ( user1) );

        cout << " User's information : ";
        move_to_array( software1, s1 );
        move_to_array( user1, u1 );
        digit_control( s1, u1, comp1 );
        print ( comp1 );

        if ( software1 == user1 ){
            cout << "\n\n ------ THE NUMBER IS => " << user1 << " ------> " << " USER WIN THE GAME!"<< endl;
            break;
        }

        cout << "\n\n Computer is guessing user's number..";
        do{
            change_digit( s2, u2, comp2);
        }while ( !is_valid_arr( s2 ) );
        cout << "\n Computer's valid number : " ;
        print ( s2 );

        cout << "\n Computer's information : ";
        move_to_array( user2, u2 );
        digit_control( u2, s2, comp2 );
        print ( comp2 );
        cout << endl;

        if ( equal ( s2, u2 ) ){
            cout << "\n\n ------ THE NUMBER IS => ";
            print( s2 );
            cout << " ------> " << " COMPUTER WIN THE GAME!"<< endl;
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
1 ile 10 arasında rasgele basamak üretem fonksiyon
*/
int rand_digit(void){
    return rand() % 10;
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
Üretilen sayının basamaklarının birbirinden farklı olup olmadığını dizi yaklaşımı
ile test eden fonksiyon. Bu fonksiyon bilgisayar tahminini optimize etmek amacıyla
kullanılacak
*/
bool is_valid_arr(int number[]){
    for (int i = 0; i < 10; i++){
        int count = 0;
        for (int j = 0; j < 4; j++){
            if ( number[ j ] == i )
               count += 1;
            if ( count > 1 )
               return 0;
        }
    }
    return 1;
}

/*
Dört basamaklı sayıların rakamlarını 4 boyutlu bir diziye atayan fonksiyon
*/
void move_to_array( int num, int n[] ){
    for (int i = 3; i >= 0;  i--) {
        int x = pow( 10, i );
        n[ i ] = num / x;
        num = num % x;
    }
}

/*
İki sayı için oluşturulan dizilerin karşılaştırılıp değeri doğru olan ancak yanlış
basamakta bulunanların değerine -1 ve doğru basamakta bulunanlara 1 değeri atayan
fonksiyon
*/
void digit_control( int num2[], int num1[], int diff[] ){
    for (int i = 3; i >= 0;  i--){
        diff[ i ] = 0;
        for (int j = 3; j >= 0; j--) {
            if ( num1[ i ] == num2[ j ] )
               diff[ i ] = -1;
            if ( num1[ i ] == num2[ i ] )
               diff[ i ] = 1;
        }
    }
}

/*
Basamaklardan oluşturulan dizileri, karşılaştırma dizilerindeki (-1 0 1 değerlere
sahip diziler ) değerlerle karşılaştırıp 1 olmayan elemanların tekrar üretilmesini
sağlayan fonksiyon. Aynı zamanda karşılaştırma değeri 0 olan belirli bir basamak
için önceki tahminlerin kullanılmaması için 10 boyutlu bir dizi kullanılmıştır.
*/
void change_digit( int s2[], int u2[], int comp[]){
    int temp[ 10 ] = { 0 };
    for ( int i = 3; i >= 0;  i-- ){
        if ( comp[ i ] == 0 ){
           if ( temp[ i ] == 0 ){
              s2[ i ] = rand_digit();
              temp[ i ] += 1;
           }
        }
        for ( int j = 3; j >= 0;  j-- ){
           if ( s2[ i ] == u2[ j ] ){
              s2[ j ] = u2[ j ];
              s2[ i ] = u2[ i ];
           }
        }
    }
}

/*
Bu fonksiyon iki dizinin tüm elemanları eşlenik ise 1 değil ise 0 değerini döndürür.
*/
bool equal ( int s2[], int u2[] ){
    for (int i = 3; i >= 0;  i--){
        if ( s2[ i ] != u2[ i ] )
           return 0;
    }
    return 1;
}

/*
Parametre olarak aldığı diziyi yazdıran fonksiyon
*/
void print( int arr[] ){
    for (int i = 3;  i >= 0;  i--)
        cout << arr[ i ];
}
