#include "Metods.h"

int main() {
    Rectangle Q1;  // Конструктор за замовчуванням
    Rectangle Q2(0, 0, 6, 4);  // З параметром
    Rectangle Q3(Q2);  // Конструктор копіювання

    std::cout << "Початкові прямокутники:\n";
    Q1.display();
    Q2.display();
    Q3.display();
    
    Q2 = Q2 / 2;
    std::cout << "\nQ2 після зменшення у 2 рази:\n";
    Q2.display();
    
    Q1 = Q3 - Q2;
    std::cout << "\nРезультат віднімання Q3 - Q2 -> Q1:\n";
    Q1.display();

    return 0;
}
