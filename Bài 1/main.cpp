#include <iostream>
#include <iomanip>
#include "cTamGiac.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    cTamGiac tg;

    cout << "NHAP THONG TIN TAM GIAC: \n";
    tg.Nhap();

    cout << "\nTHONG TIN TAM GIAC SAU KHI NHAP:\n";
    cout << "Toa do 3 dinh: ";
    tg.Xuat();
    tg.KiemTraLoai();
    cout << "Chu vi: " << tg.TinhChuVi() << endl;
    cout << "Dien tich: " << tg.TinhDienTich() << endl;

    cout << "\nBIEN DOI TAM GIAC\n";

    // 1. Tinh tien
    cout << "[1] Tinh tien: \n";
    double delta_x, delta_y;
    cout << "Nhap doan bien thien delta_x va delta_y: \n";
    cout << "delta_x = ";
    cin >> delta_x;
    cout << "delta_y = ";
    cin >> delta_y;
    cout << "\nSau khi tinh tien (dx=" << delta_x << ", dy=" << delta_y << "): ";
    tg.TinhTien(delta_x, delta_y);
    tg.Xuat();

    // 2. Quay tam giac
    cout << "[2] Quay: \n";
    double goc;
    cout << "Nhap goc quay: ";
    cin >> goc;
    cout << "\nSau khi quay " << goc << " do quanh goc toa do O: ";
    tg.Quay(goc);
    tg.Xuat();

    // 3. Phong to
    cout << "[3] Phong to: \n";
    double k_phong;
    cout << "Nhap do phong: ";
    cin >> k_phong;
    cout << "\nSau khi phong to len " << k_phong << " lan: ";
    tg.PhongTo(k_phong);
    tg.Xuat();

    // 4. Thu nho
    cout << "[4] Thu nho: \n";
    double k_thu;
    cout << "Nhap do thu: ";
    cin >> k_thu;
    cout << "\nSau khi thu nho di " << k_thu << " lan: ";
    tg.ThuNho(k_thu);
    tg.Xuat();

    cout << "\nKet thuc chuong trinh.\n";
    return 0;
}
