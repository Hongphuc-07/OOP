#include <iostream>
#include "NgayThangNam.h"
using namespace std;

//Hàm tìm số ngày lớn nhất của tháng đã nhập
int LaySoNgayTrongThang(int thang, int nam) {
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    } else if (thang == 2) {

        bool laNamNhuan = ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0));
        return laNamNhuan ? 29 : 28;
    }
    return 31;
}

void NgayThangNam::Nhap() {
    do {
        cout << "Nhap Nam: ";
        cin >> iNam;
    } while (iNam <= 0);

    do {
        cout << "Nhap Thang: ";
        cin >> iThang;
    } while (iThang < 1 || iThang > 12);

    int maxNgay = LaySoNgayTrongThang(iThang, iNam);
    do {
        cout << "Nhap Ngay: ";
        cin >> iNgay;
    } while (iNgay < 1 || iNgay > maxNgay);
}

void NgayThangNam::Xuat() {
    cout << "Ngay " << iNgay << ", Thang "<< iThang << ", Nam " << iNam;
}

NgayThangNam NgayThangNam::NgayThangNamTiepTheo() {
    NgayThangNam kq;
    kq.iNgay = iNgay + 1;
    kq.iThang = iThang;
    kq.iNam = iNam;

    int maxNgay = LaySoNgayTrongThang(iThang, iNam);

    if (kq.iNgay > maxNgay) { //vì ngày tiếp theo lớn hơn ngày lớn nhất của tháng đó nên qua tháng sau
        kq.iNgay = 1;
        kq.iThang++;

        if (kq.iThang > 12) { //vì tháng tiếp theo lớn hơn tháng lớn nhất trong năm nên qua năm sau
            kq.iThang = 1;
            kq.iNam++;
        }
    }

    return kq;
}
