#include <iostream>
#include "cArray.h"

using namespace std;

int main() {
    cArray arr;
    int n, x;

    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    // Tiến hành nhập liệu thủ công cho từng phần tử
    arr.Nhap(n);

    cout << "\nMang ban vua nhap: ";
    arr.Xuat();

    // Kiểm tra tính tăng dần
    if (arr.KiemTraTangDan()) cout << "=> Mang dang sap xep TANG DAN.\n";
  00  else cout << "=> Mang KHONG tang dan.\n";

    // Kiểm tra đếm giá trị
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "=> So lan xuat hien cua " << x << " la: " << arr.DemGiaTri(x) << endl;

    // Tìm số lẻ nhỏ nhất và SNT lớn nhất
    bool coLe, coSNT;
    int leMin = arr.TimSoLeNhoNhat(coLe);
    int sntMax = arr.TimSoNguyenToLonNhat(coSNT);

    if (coLe) cout << "=> So le nho nhat: " << leMin << endl;
    else cout << "=> Khong co so le trong mang.\n";

    if (coSNT) cout << "=> So nguyen to lon nhat: " << sntMax << endl;
    else cout << "=> Khong co so nguyen to trong mang.\n";

    // Sắp xếp
    cout << "\nTien hanh Sap xep TANG DAN \n";
    arr.SapXepTangDan();
    arr.Xuat();

    cout << "\nTien hanh Sap xep GIAM DAN \n";
    arr.SapXepGiamDan();
    arr.Xuat();

    return 0;
}
