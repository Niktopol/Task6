#include <iostream>
#include <limits>
#include <vector>
#include <valarray>
#include<iomanip>

bool safe_inp(double* arr[], int len, double err) {
    double n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(double* x, double err) {
    double n;
    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
        *x = n;
        return true;
    }
}
bool safe_inp(int* arr[], int len, int err) {
    int n;
    bool rs = true;
    for (int i = 0; i < len; i++) {
        if (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *arr[i] = err;
            rs = false;
        }
        else {
            *arr[i] = n;
        }
    }
    return rs;
}
bool safe_inp(int* x, int err = -1) {
    int n;
    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *x = err;
        return false;
    }
    else {
        *x = n;
        return true;
    }
}
int fact(int a) {
    int n = 1;
    for (int i = 1; i <= a; i++) {
        n *= i;
    }
    return n;
}
void putOff(std::vector<int> arr, int n, int* sum, int strtln) {
    std::vector <int> a = arr;
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) == n) {
            *sum += fact(strtln-(n+1));
        }
        else {
            a.erase(a.begin() + i);
            putOff(a, n + 1, sum, strtln);
        }
        a = arr;
    }
}
int balls(int c) {
    std::vector <int> arr;
    for (int i = 0; i < c; i++) {
        arr.push_back(i);
    }
    int sum = 0;
    putOff(arr, 0, &sum, c);
    return sum;
}
std::string year21(int bgn, int yr) {
    std::string clr[] = {"green", "red", "yellow", "white", "black"};
    std::string anml[] = { "rat", "cow", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "chicken", "dog", "pig" };
    int dlt = (yr-bgn)%60;
    if (dlt >= 0) {
        return (anml[dlt % 12] + " " + clr[int((dlt - dlt % 12) / 12)]);
    }
    else {
        return (anml[12 + (dlt % 12)] + " " + clr[4 + (int((dlt - dlt % 12) / 12))]);
    }
}
int len(int n) {
    int c = 0;
    while (n > 0){
        n /= 10;
        c++;
    }
    return c;
}
int rever(int n) {
    int rs = 0;
    for (int i = 1; i <= len(n); i++) {
        rs += int(n % int(pow(10,i))/ int(pow(10, i-1))) * pow(10, len(n)-i);
    }
    return rs;
}
bool polinum29(int num) {
    int bg = 0;
    int end = 0;
    if (len(num) % 2 == 0) {
        bg = int(num / pow(10, int(len(num) / 2)));
        end = num % int(pow(10, int(len(num) / 2)));
    }
    else {
        bg = int(num / pow(10, int(len(num) / 2) + 1));
        end = num % int(pow(10, int(len(num) / 2)));
    }
    return rever(bg) == end;
}
int fndminmx(std::vector<int> a, bool fl){
    int m = a[0];
    if (fl){
        for (int i = 0; i < a.size(); i++){
            m = (a[i] < m) ? a[i] : m;
        }
    }else{
        for (int i = 0; i < a.size(); i++){
            m = (a[i] > m) ? a[i] : m;
        }
    }
    return m;
}
void sort48(int n){
    std::vector<int> arr;
    std::vector<int> b;
    int a;
    std::cout << "Введите "<< n << " элементов" << std::endl;
    for (int i = 0; i < n; i++){
        safe_inp(&a, 0);
        arr.push_back(a);
    }
    b = arr;
    std::cout << fndminmx(b, true) << fndminmx(b, false);
    //struct
}
void printMx(std::vector<std::vector<int>> a, int ln){
    int ab = ln+2;
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size(); j++){
            std::cout <<  std::setw(ab) << a.at(i).at(j);
        }
        std::cout << std::endl;
    }
}
void rotmx(std::vector<std::vector<int>> a, int rot, int mxel){
    std::vector<std::vector<int>> b;
    int sz = a.size();
    b.resize(sz);
    for (int i = 0; i < sz; i++){
        b.at(i).resize(sz);
    }
    if (rot < 0){
        rot = 4 + rot;
    }
    for (int i = 0; i < rot; i ++){
        for (int j = 0; j < sz; j++){
            for (int g = 0; g < sz; g++){
                b[g][sz-1-j] = a[j][g];
            }
        }
        a = b;
    }
    printMx(a, mxel);
}
void rotate62(int m){
    std::vector <std::vector <int>> arr;
    arr.resize(m);
    int a;
    std::cout << "Введите "<< m*m << " элементов" << std::endl;
    int mxel;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            safe_inp(&a, 0);
            int ln = len(a);
            mxel = (mxel < ln) ? ln : mxel;
            arr.at(i).push_back(a);
        }
    }
    printMx(arr, mxel);
    std::cout << "Введите количество поворотов на 90 и их направление (-n = повернуть против часовой n раз, n = повернуть по часовой n раз)" << std::endl;
    if (safe_inp(&a, -1)){
        rotmx(arr, a%4, mxel);
    }
    else{
        std::cout << "Неверный ввод" << std::endl;
    }
}
std::string makestr(int a, int ln){
    std::string dct = "0123456789";
    std::string out = "";
    for (int i = 0; i < ln; i++){
        out += dct[a];
    }
    return out;
}
void rec79(int a, int b, int ln, int dir){
    if (b == 0){
        return;
    }
    int x = ln + (a*a-ln)/2;
    std::cout << std::setw(x) << makestr(b, ln) << std::endl;
    if (b == a){
        dir = -dir;
    }
    rec79(a,b+dir,ln-(a*dir), dir);
}
int main() {
    setlocale(0, "");
    int a = 0, b = 0;
    int* ab[] = { &a, &b };
    double c = 0, d = 0;
    double* cd[] = { &c, &d };
    while (true) {
        std::cout << "Введите номер задания" << std::endl;
        safe_inp(&a, -1);
        switch (a) {
            case 1:
                std::cout << "Введите колиечство шариков в отрезке [1, 11]" << std::endl;
                if (safe_inp(&a, -1) and a <= 11 and a >= 1) {
                    std::cout << balls(a) << std::endl;
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 2:
                std::cout << "Введите год начала цикла и искомый год" << std::endl;
                if (safe_inp(ab, 2, -1) and a >= 0 and b >= 0) {
                    std::cout << year21(a, b) << std::endl;
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 3:
                std::cout << "Введите число" << std::endl;
                if (safe_inp(&a, -1) and a >= 0) {
                    if (polinum29(a)) {
                        std::cout << "Да" << std::endl;
                    }
                    else {
                        std::cout << "Нет" << std::endl;
                    }
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 4:
                std::cout << "Введите длину массива в отрезке [1, 100]" << std::endl;
                if (safe_inp(&a, -1) and a > 0 and a <= 100) {
                    sort48(a);
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 5:
                std::cout << "Введите порядок матрицы" << std::endl;
                if (safe_inp(&a, -1) and a > 0) {
                    rotate62(a);
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 6:
                std::cout << "Введите чётное число из отрезка [2,8]" << std::endl;
                if (safe_inp(&a, -1) and a > 0 and a%2 == 0 and a < 10) {
                    rec79(a,1, a*a, 1);
                }
                else {
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            default:
                std::cout << "Неверный ввод" << std::endl;
        }
    }
}
