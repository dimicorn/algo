#include <bits/stdc++.h>

using namespace std;

int main() {
    int k1, m, k2, p2, n2, min_apart;

    cin >> k1 >> m >> k2 >> p2 >> n2;

    /*этаж на котором находилась квартира выше,
    чем количество этажей в подъездах, то
    такой квартиры не существует*/
    if (n2 > m) {
        cout << "-1 -1\n";
    /*отдельно рассмотрим первый этаж, первого подъезда*/
    } else if (p2 == 1 && n2 == 1) {
        /*если номер первой квартиры меньше номера второй квартиры,
        то она находится на первом этаже в первом подъезде*/
        if (k1 <= k2) {
            cout << "1 1\n";
        } else {
            /*иначе, мин. количество квартир на одном этаже =
            = номер второй квартиры*/
            min_apart = k2;
            /*если номер первой квартиры меньше, чем мин. количество
            квартир в первом подъезде, то она находится в первом подъезде,
            но этаж не определен*/
            if (k1 - 1 < min_apart * m) {
                cout << "1 0\n";
            } else {
                /*иначе, если в каждом подъезде по одному этажу,
                то квартира находится на первом этаже, но подъезд
                не определен*/
                if (m == 1) {
                    cout << "0 1\n";
                /*если в подъезде больше, чем один этаж, то
                ни подъезд, ни этаж не определен*/
                } else {
                    cout << "0 0\n";
                }
            }
        }
    } else {
        /*количество заполненных этажей по всем подъездам*/
        int floors2 = (p2 - 1) * m + (n2 - 1);
        /*наибольшее количество квартир на одном этаже*/
        int max_apart = (k2 - 1) / floors2;
        if (max_apart == 0) {
            cout << "-1 -1\n";
        } else {
            /*наименьшее количество квартир на одном этаже*/
            min_apart = ceil(k2 / (floors2 + 1.0));
            if (min_apart > max_apart) {
                cout << "-1 -1\n";
            } else {
                /*мин. количество заполненных этажей по всем подъездам*/
                int min_floors1 = (k1 - 1) / min_apart;
                /*количество заполненных подъездов*/
                int min_p1 = min_floors1 / m;
                /*количество этажей в незаполненном подъезде*/
                int min_n1 = min_floors1 % m;

                /*аналогичные вычисления, используя макс. количество заполненных этажей*/
                int max_floors1 = (k1 - 1) / max_apart;
                int max_p1 = max_floors1 / m;
                int max_n1 = max_floors1 % m;

                int p1, n1;
                /*если вычисления для количества заполненных подъездов совпали,
                иначе подъезд не определен*/
                if (min_p1 == max_p1) {
                    p1 = min_p1 + 1;
                } else {
                    p1 = 0;
                }

                /*если вычисления для количества заполненных этажей совпали,
                иначе этаж не определен*/
                if (min_n1 == max_n1 || m == 1) {
                    n1 = min_n1 + 1;
                } else {
                    n1 = 0;
                }

                cout << p1 << ' ' << n1 << '\n';
            }
        }
    }


    return 0;
}