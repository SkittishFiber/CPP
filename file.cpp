#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");

    double x1, y1, x2, y2;
    double a, b, c;

    ifstream fin("INPUT.txt");
    fin >> x1;
    fin >> y1;
    fin >> x2;
    fin >> y2;
    fin.close();
    cout << "Начало: " << x1 << " " << y1 << endl;
    cout << "Конец: " << x2 << " " << y2 << endl;
        const float e = 10e-8;
        c = abs((y2 * x1 - x2 * y1) / sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        a = sqrt(pow(x1, 2) + pow(y1, 2));
        b = sqrt(pow(x2, 2) + pow(y2, 2));
        int val = 0;
        if (x1!= x2 or y1 != y2){
            if ((2 * x1 * x1 - 2 * x1 * x2 + 2 * y1 * y1 - 2 * y1 * y2 < 0) or (2 * x2 * x2 - 2 * x1 * x2 + 2 * y2 * y2 - 2 * y1 * y2 < 0))
                val = (int)(max(a, b) + e) - (int)(min(a, b) - e);
            else {
                val = (int)(a + e) - (int)(c - e);
                val = val + (int)(b + e) - (int)(c - e);
                if ((abs(round(c) - c) < e) and (abs(c) > e)) {
                    val--;
                }
            }
        }
        else {
            val = 0;
        }
        cout << "Общих точек: " << val;


    ofstream fout("OUTPUT.txt");
    fout << val;
    fout.close();
    return 0;
}
