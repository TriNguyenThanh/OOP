#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
using namespace std;

long long ans = 0, a = 0;
char operation = 43, user;
int main(){
    system("cls");
    cout << "Press ESC to exit!\nPress X to reset!\n\n\n";
    while(true){  
        user = getch();
        if (user == 27) break; //ASCii cua esc la 27
        if (user == 43 || user == 42 || user == 45 || user == 47 || user == 13){
            if (operation == 43){
                ans += a;
            }else if (operation == 45){
                ans -= a;
            }else if (operation == 42){
                ans *= a;
            }else if (operation == 47){
                ans /= a;
            }
            if (ans != 0) cout << '\n'<< setw(15) << right << ans << '\n';
            a = 0;
        }

        if (user == 8){ // ASCii cua backspace la 8
            a = (a - (a % 10)) / 10;
            user = 13;
            cout << user << a;
        }

        if (user == 120){ //ASCii cua X la 120
            system("cls");
            cout << "Press ESC to exit!\nPress X to reset!\n";
            ans = 0;
            a = 0;
        }

        if (48 <= user && user <= 57){ //ASCii cua 0 la 48 va cua 9 la 57
            a = a*10 + (user-48);
            user = 13;
            cout << user << setw(15) << right << a;
        }

        if (user == 43 || user == 42 || user == 45 || user == 47){               // ASCii cua dau + la 43, * la 42, - la 45, / la 47
            operation = user;
            if (a != 0){
                ans = a;
                a = 0;
                cout << '\n';
            }
            cout << char(user) << "\n";
        }
    }

    return 0;
}