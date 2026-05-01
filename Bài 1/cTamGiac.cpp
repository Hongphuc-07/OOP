#include <iostream>
#include <cmath>
#include "cTamGiac.h"

using namespace std;

const double PI = 3.14159265358979323846;
const double EPSILON = 1e-6; // Dung de so sanh so thuc


cDiem::cDiem(double x, double y)
{
    dX = x;
    dY = y;
}

cDiem::~cDiem() {}

void cDiem::Nhap()
{
    cout << "x = "; cin >> dX;
    cout << "y = "; cin >> dY;
}

void cDiem::Xuat()
{
    cout << "(" << dX << ", " << dY << ")";
}

double cDiem::TinhKhoangCach(cDiem p)
{
    return sqrt(pow((dX - p.dX), 2) + pow((dY - p.dY), 2)); //khoang cach cua 2 diem toa do = sqrt((xA - xB)^2 + (yA - yB)^2)
}

double cDiem::GetX() { return dX; }
double cDiem::GetY() { return dY; }

void cDiem::TinhTien(double dx, double dy)
{
    dX += dx;
    dY += dy;
}

void cDiem::Quay(double goc)
{
    //Chuyen doi tu do sang radian
    double rad = goc * PI / 180.0;
    double xMoi = dX * cos(rad) - dY * sin(rad);
    double yMoi = dX * sin(rad) + dY * cos(rad);
    dX = xMoi;
    dY = yMoi;
}

void cDiem::ThuPhong(double k)
{
    dX *= k;
    dY *= k;
}

//LOP CTAMGIAC

cTamGiac::cTamGiac() {}

cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c)
{
    A = a; B = b; C = c;
}

cTamGiac::~cTamGiac()
{
    //Khong co con tro nen Destructor khong can xu ly gi them
}

bool cTamGiac::KiemTraHopLe()
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void cTamGiac::Nhap()
{
    do {
        cout << "- Nhap toa do dinh A:\n"; A.Nhap();
        cout << "- Nhap toa do dinh B:\n"; B.Nhap();
        cout << "- Nhap toa do dinh C:\n"; C.Nhap();

        if (!KiemTraHopLe()) {
            cout << "=> 3 diem khong tao thanh tam giac. Vui long nhap lai!\n";
        }
    } while (!KiemTraHopLe());
}

void cTamGiac::Xuat()
{
    cout << "A"; A.Xuat();
    cout << ", B"; B.Xuat();
    cout << ", C"; C.Xuat();
    cout << endl;
}

void cTamGiac::KiemTraLoai()
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);

    bool vuong = (abs(a*a + b*b - c*c) < EPSILON) ||
                 (abs(a*a + c*c - b*b) < EPSILON) ||
                 (abs(b*b + c*c - a*a) < EPSILON);
    bool can = (abs(a - b) < EPSILON) ||
               (abs(a - c) < EPSILON) ||
               (abs(b - c) < EPSILON);
    bool deu = (abs(a - b) < EPSILON) && (abs(a - c) < EPSILON);

    cout << "=> Loai tam giac: ";
    if (deu) cout << "Tam giac deu";
    else if (vuong && can) cout << "Tam giac vuong can";
    else if (vuong) cout << "Tam giac vuong";
    else if (can) cout << "Tam giac can";
    else cout << "Tam giac thuong";
    cout << endl;
}

double cTamGiac::TinhChuVi()
{
    return A.TinhKhoangCach(B) + B.TinhKhoangCach(C) + C.TinhKhoangCach(A);
}

double cTamGiac::TinhDienTich()
{
    // Su dung cong thuc Heron
    double p = TinhChuVi() / 2;
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::TinhTien(double dx, double dy)
{
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void cTamGiac::Quay(double goc)
{
    A.Quay(goc);
    B.Quay(goc);
    C.Quay(goc);
}

void cTamGiac::PhongTo(double k)
{
    if (k > 0) {
        A.ThuPhong(k);
        B.ThuPhong(k);
        C.ThuPhong(k);
    }
}

void cTamGiac::ThuNho(double k)
{
    if (k > 0) {
        A.ThuPhong(1.0 / k); //Thu nho la nhan cho 1/k
        B.ThuPhong(1.0 / k);
        C.ThuPhong(1.0 / k);
    }
}
