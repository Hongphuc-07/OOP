#include <iostream>
#include <vector>
#include "cNhanVienSX.h"

using namespace std;

int main()
{
    int n;
    cout << "NHAP DANH SACH NHAN VIEN \n";
    cout << "Nhap so luong nhan vien (n): ";
    cin >> n;
    cin.ignore(); // Xóa phím enter còn thừa trong bộ nhớ đệm

    vector<cNhanVienSX> ds(n);

    //Nhập danh sách
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << "\n";
        ds[i].Nhap();
    }

    //Xuất danh sách
    cout << "\nDANH SACH NHAN VIEN SAN XUAT \n";
    for (int i = 0; i < n; i++)
    {
        ds[i].Xuat();
    }

    if (n > 0)
    {
        //Tìm nhân viên có lương thấp nhất
        double minLuong = ds[0].TinhLuong();
        int idxMinLuong = 0;
        double tongLuong = 0; // Tích hợp tính tổng lương trong cùng 1 vòng lặp

        //Tìm nhân viên có tuổi cao nhất
        int maxTuoi = ds[0].GetTuoi();
        int idxMaxTuoi = 0;

        for (int i = 0; i < n; i++)
        {
            double luongHT = ds[i].TinhLuong();
            tongLuong += luongHT;

            if (luongHT < minLuong) {
                minLuong = luongHT;
                idxMinLuong = i;
            }

            if (ds[i].GetTuoi() > maxTuoi) {
                maxTuoi = ds[i].GetTuoi();
                idxMaxTuoi = i;
            }
        }

        cout << "\nTHONG KE\n";
        cout << "- Nhan vien co luong thap nhat la: " << ds[idxMinLuong].GetHoTen()
             << " (Ma: " << ds[idxMinLuong].GetMaNV() << " - Luong: " << minLuong << ")\n";

        cout << "- Tong luong cong ty phai tra: " << tongLuong << endl;

        cout << "- Nhan vien co tuoi cao nhat la: " << ds[idxMaxTuoi].GetHoTen()
             << " (" << maxTuoi << " tuoi)\n";

        //Sắp xếp danh sách tăng dần theo lương (Interchange Sort)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                    swap(ds[i], ds[j]);
                }
            }
        }

        cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG\n";
        for (int i = 0; i < n; i++)
        {
            ds[i].Xuat();
        }
    }

    cout << "\nKet thuc chuong trinh.\n";
    return 0;
}
