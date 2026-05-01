#include <iostream>
#include <cmath>
#include "cDaGiac.h"

using namespace std;

const double PI = 3.14159265358979323846;

//LOP DIEM
cDiem::cDiem(double x, double y) : dX(x), dY(y) {}
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
    return sqrt(pow((dX - p.dX), 2) + pow((dY - p.dY), 2));
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

//LOP DA GIAC

cDaGiac::cDaGiac() : iSoDinh(0) {}

cDaGiac::cDaGiac(int n, vector<cDiem> dsDinh)
{
    iSoDinh = n;
    DanhSachDinh = dsDinh;
}

cDaGiac::~cDaGiac()
{
    //vector tự động thu hồi bộ nhớ nên không cần delete thủ công
    DanhSachDinh.clear();
}

void cDaGiac::Nhap()
{
    do {
        cout << "Nhập số lượng đỉnh của đa giác (n >= 3): ";
        cin >> iSoDinh;
        if (iSoDinh < 3) {
            cout << "Đa giác phải có ít nhất 3 đỉnh. Vui lòng nhập lại!\n";
        }
    } while (iSoDinh < 3);

    DanhSachDinh.resize(iSoDinh);
    for (int i = 0; i < iSoDinh; i++)
    {
        cout << "- Nhập tọa độ đỉnh " << i + 1 << ":\n";
        DanhSachDinh[i].Nhap();
    }
}

void cDaGiac::Xuat()
{
    cout << "Đa giác có " << iSoDinh << " đỉnh: ";
    for (int i = 0; i < iSoDinh; i++)
    {
        DanhSachDinh[i].Xuat();
        if (i < iSoDinh - 1) cout << " -> ";
    }
    cout << endl;
}

double cDaGiac::TinhChuVi()
{
    if (iSoDinh < 3) return 0;
    double ChuVi = 0;
    for (int i = 0; i < iSoDinh; i++)
    {
        //Tính khoảng cách từ đỉnh i tới đỉnh i+1 (sử dụng modulo để đỉnh cuối nối với đỉnh đầu)
        int j = (i + 1) % iSoDinh;
        ChuVi += DanhSachDinh[i].TinhKhoangCach(DanhSachDinh[j]);
    }
    return ChuVi;
}

double cDaGiac::TinhDienTich()
{
    if (iSoDinh < 3) return 0;
    double DienTich = 0;
    // Sử dụng công thức Shoelace (Công thức tọa độ) để tính diện tích đa giác
    for (int i = 0; i < iSoDinh; i++)
    {
        int j = (i + 1) % iSoDinh;
        DienTich += (DanhSachDinh[i].GetX() * DanhSachDinh[j].GetY());
        DienTich -= (DanhSachDinh[j].GetX() * DanhSachDinh[i].GetY());
    }
    return abs(DienTich) / 2.0;
}

void cDaGiac::TinhTien(double dx, double dy)
{
    for (int i = 0; i < iSoDinh; i++) {
        DanhSachDinh[i].TinhTien(dx, dy);
    }
}

void cDaGiac::Quay(double goc)
{
    for (int i = 0; i < iSoDinh; i++) {
        DanhSachDinh[i].Quay(goc);
    }
}

void cDaGiac::PhongTo(double k)
{
    if (k > 0) {
        for (int i = 0; i < iSoDinh; i++) {
            DanhSachDinh[i].ThuPhong(k);
        }
    }
}

void cDaGiac::ThuNho(double k)
{
    if (k > 0) {
        for (int i = 0; i < iSoDinh; i++) {
            DanhSachDinh[i].ThuPhong(1.0 / k);
        }
    }
}
