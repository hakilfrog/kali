
#include <iostream>

using namespace std;

int main() {
    int kingX, kingY, rookX, rookY, bishopX, bishopY;

    // Ввод позиций фигур
    cout << "Введите позицию белого короля (x y): ";
    cin >> kingX >> kingY;
    cout << "Введите позицию черной ладьи (x y): ";
    cin >> rookX >> rookY;
    cout << "Введите позицию черного слона (x y): ";
    cin >> bishopX >> bishopY;

    // Проверка на угрозу от ладьи
    if (kingX == rookX || kingY == rookY) {
        cout << "Угроза королю от черной ладьи!" << endl;
    }

    // Проверка на угрозу от слона
    if (kingX - bishopX == kingY - bishopY || kingX - bishopX == bishopY - kingY) {
        cout << "Угроза королю от черного слона!" << endl;
    }

    return 0;
}
