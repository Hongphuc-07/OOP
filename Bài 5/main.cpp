#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main()
{
    cDaThuc P, Q;

    cout << "NHAP DA THUC P(x): \n";
    P.Nhap();

    cout << "\nNHAP DA THUC Q(x):\n";
    Q.Nhap();

    cout << "\nTHONG TIN DA THUC: \n";
    cout << "P(x) = "; P.Xuat();
    cout << "Q(x) = "; Q.Xuat();

    cout << "\nKIEM THU TINH GIA TRI: \n";
    double x;
    cout << "Nhap gia tri x can tinh: ";
    cin >> x;
    cout << "=> P(" << x << ") = " << P.TinhGiaTri(x) << endl;
    cout << "=> Q(" << x << ") = " << Q.TinhGiaTri(x) << endl;

    cout << "\nKIEM THU PHEP TOAN: \n";

    cDaThuc Tong = P.Cong(Q);
    cout << "P(x) + Q(x) = ";
    Tong.Xuat();

    cDaThuc Hieu = P.Tru(Q);
    cout << "P(x) - Q(x) = ";
    Hieu.Xuat();

    cout << "\nKet thuc chuong trinh.\n";
    return 0;
}
