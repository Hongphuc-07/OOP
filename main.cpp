#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main()
{
    NgayThangNam a;

    a.Nhap();

    cout << "Ngay thang nam tiep theo: ";
    NgayThangNam tt = a.NgayThangNamTiepTheo(); //Tìm ngày tháng năm tiếp theo
    tt.Xuat();

    return 0;
}
