#include <iostream>
#include <iomanip>
#include <ctime>
#include "cNhanVienSX.h"

using namespace std;

//LỚP CNGAY

cNgay::cNgay(int ng, int th, int nm) : iNgay(ng), iThang(th), iNam(nm) {}

void cNgay::Nhap()
{
    cout << "Nhap ngay: "; cin >> iNgay;
    cout << "Nhap thang: "; cin >> iThang;
    cout << "Nhap nam: "; cin >> iNam;
}

void cNgay::Xuat()
{
    //Căn lề in ra dạng DD/MM/YYYY
    cout << setfill('0') << setw(2) << iNgay << "/"
         << setw(2) << iThang << "/" << iNam << setfill(' ');
}

int cNgay::TinhTuoi(int namHienTai)
{
    return namHienTai - iNam;
}

//LỚP CNHANVIENSX

cNhanVienSX::cNhanVienSX() : sMaNV(""), sHoTen(""), iSoSanPham(0), dDonGia(0.0) {}

cNhanVienSX::~cNhanVienSX() {}

//Getters
string cNhanVienSX::GetMaNV() { return sMaNV; }
string cNhanVienSX::GetHoTen() { return sHoTen; }
int cNhanVienSX::GetSoSanPham() { return iSoSanPham; }
double cNhanVienSX::GetDonGia() { return dDonGia; }

int cNhanVienSX::GetTuoi()
{
    //Tự động lấy thời gian hiện tại của máy tính để tính tuổi
    time_t t = time(0);
    tm* now = localtime(&t);
    int namHienTai = now->tm_year + 1900;

    return ngSinh.TinhTuoi(namHienTai);
}

//Setter
void cNhanVienSX::SetMaNV(string ma) { sMaNV = ma; }
void cNhanVienSX::SetHoTen(string ten) { sHoTen = ten; }
void cNhanVienSX::SetSoSanPham(int soSP) { iSoSanPham = soSP; }
void cNhanVienSX::SetDonGia(double gia) { dDonGia = gia; }

//Nghiệp vụ
void cNhanVienSX::Nhap()
{
    cout << "Nhap Ma NV: ";
    getline(cin, sMaNV);
    cout << "Nhap Ho ten: ";
    getline(cin, sHoTen);

    cout << "Nhap Ngay sinh:\n";
    ngSinh.Nhap();

    cout << "Nhap So san pham: ";
    cin >> iSoSanPham;
    cout << "Nhap Don gia: ";
    cin >> dDonGia;

    //Xóa bộ nhớ đệm sau khi nhập số để không bị trôi lệnh nhập chuỗi ở NV tiếp theo
    cin.ignore();
}

void cNhanVienSX::Xuat()
{
    cout << left << setw(10) << sMaNV
         << "| " << setw(20) << sHoTen
         << "| ";
    ngSinh.Xuat();
    cout << " | SP: " << setw(5) << iSoSanPham
         << "| Gia: " << setw(10) << fixed << setprecision(0) << dDonGia
         << "| Luong: " << TinhLuong() << endl;
}

double cNhanVienSX::TinhLuong()
{
    return iSoSanPham * dDonGia;
}
