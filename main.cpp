#include <iostream>
#include <limits>
#include <vector>

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
void putOff(std::vector<int> arr, int n, int* sum){
    std::vector <int> a = arr;
    for (int i = 0; i < a.size(); i++){
        if (a.at(i) == n){
            *sum += 1;
        }
        a.erase(a.begin()+i);
        putOff(a,n+1, sum);
        a = arr;
    }
}
int balls(int c){
    std::vector <int> arr;
    for (int i = 0; i < c; i++){
        arr.push_back(i);
    }
    int sum = 0;
    putOff(arr, 0, &sum);
    return sum;
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
                std::cout << "Введите колиечство шариков в отрезке [1, 12]" << std::endl;
                if (safe_inp(&a, -1) and a <= 12 and a >= 1) {
                    std::cout << balls(a) << std::endl;
                } else{
                    std::cout << "Неверный ввод" << std::endl;
                }
                break;
            case 2:
                break;
            default:
                std::cout << "Неверный ввод" << std::endl;
        }
    }
}
