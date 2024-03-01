
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

    if (kingX < 1 || kingX > 8 || kingY < 1 || kingY > 8 || 
        rookX < 1 || rookX > 8 || rookY < 1 || rookY > 8 || 
        bishopX < 1 || bishopX > 8 || bishopY < 1 || bishopY > 8) {
            cout << "Одна из позиций за пределами доски. \
            Пожалуйста, введите корректные координаты от 1 до 8." << endl;
            return 1;
    }

    // Проверка на угрозу от ладьи
    if (kingX == rookX || kingY == rookY) {
        // Проверка на наличие второй фигуры между ладьей и королем
        bool threat = false;
        for (int x = min(kingX, rookX) + 1; x < max(kingX, rookX); x++) {
            if (x == bishopX && kingY == bishopY) {
                threat = true;
                break;
            }
        }

        if (!threat) {
            cout << "Угроза королю от черной ладьи!" << endl;
        }
    }

    // Проверка на угрозу от слона
    if (kingX - bishopX == kingY - bishopY 
    	|| kingX - bishopX == bishopY - kingY) {
        // Проверка на наличие второй фигуры между слоном и королем
        bool threat = false;
        for (int x = min(kingX, bishopX) + 1, y = min(kingY, bishopY) + 1; 
            x < max(kingX, bishopX) && y < max(kingY, bishopY); x++, y++) {
            if (x == rookX && y == rookY) {
                threat = true;
                break;
            }
        }

        if (!threat) {
            cout << "Угроза королю от черного слона!" << endl;
        }
    }

    return 0;
}
