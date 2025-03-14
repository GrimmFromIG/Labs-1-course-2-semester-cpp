#include "Metods.h"

int main() {
    Rectangle Q1; 
    Rectangle Q2(0, 0, 6, 4);  
    Rectangle Q3(Q2);  

    std::cout << "Початкові прямокутники:\n";
    Q1.display();
    Q2.display();
    Q3.display();
    
    Q1.setCoordinates(1, 1, 5, 3);
    std::cout << "\nQ1 після зміни координат (по координатам двух вершин):\n";
    Q1.display();
    
    std::array<double, 4> vertices = {2, 2, 8, 6};
    Q2.setCoordinates(vertices);
    std::cout << "\nQ2 після зміни координат (через массив):\n";
    Q2.display();
    
    Q2 = Q2 / 2;
    std::cout << "\nQ2 після зменшення у 2 рази:\n";
    Q2.display();
    
    Q1 = Q3 - Q2;
    std::cout << "\nРезультат віднімання Q3 - Q2 -> Q1:\n";
    Q1.display();

    return 0;
}
