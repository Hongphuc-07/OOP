#include <iostream>
#include <iomanip>
#include "cDaGiac.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    cDaGiac dg;

    cout << "NHẬP THÔNG TIN ĐA GIÁC: \n";
    dg.Nhap();

    cout << "\nTHÔNG TIN ĐA GIÁC SAU KHI NHẬP: \n";
    cout << "Tọa độ các đỉnh: ";
    dg.Xuat();
    cout << "Chu vi của đa giác: " << dg.TinhChuVi() << endl;
    cout << "Diện tích của đa giác: " << dg.TinhDienTich() << endl;

    cout << "\nBIẾN ĐỔI ĐA GIÁC: \n";

    // 1. Tịnh tiến
    cout << "[1] Tịnh tiến: \n";
    double dx, dy;
    cout << "Nhập độ dời dx và dy: \n";
    cout << "dx = ";
    cin >> dx;
    cout << "dy = ";
    cin >> dy;
    cout << "\nSau khi tịnh tiến (dx=" << dx << ", dy=" << dy << "): ";
    dg.TinhTien(dx, dy);
    dg.Xuat();

    // 2. Quay
    cout << "\n[2] Quay: \n";
    double goc;
    cout << "Nhập góc quay (độ): ";
    cin >> goc;
    cout << "\nSau khi quay " << goc << " độ quanh gốc tọa độ O: ";
    dg.Quay(goc);
    dg.Xuat();

    // 3. Phóng to
    cout << "\n[3] Phóng to: \n";
    double k_phong;
    cout << "Nhập hệ số phóng to: ";
    cin >> k_phong;
    cout << "\nSau khi phóng to lên " << k_phong << " lần: ";
    dg.PhongTo(k_phong);
    dg.Xuat();

    // 4. Thu nhỏ
    cout << "\n[4] Thu nhỏ: \n";
    double k_thu;
    cout << "Nhập hệ số thu nhỏ: ";
    cin >> k_thu;
    cout << "\nSau khi thu nhỏ đi " << k_thu << " lần: ";
    dg.ThuNho(k_thu);
    dg.Xuat();

    cout << "\nKết thúc chương trình.\n";
    return 0;
}
