#include <iostream>
#include <cmath>
#include <algorithm> // Để dùng hàm max
#include "cDaThuc.h"

using namespace std;

// Khởi tạo đa thức mặc định (Bậc 0, P(x) = 0)
cDaThuc::cDaThuc()
{
    iBac = 0;
    HeSo.push_back(0.0);
}

// Khởi tạo đa thức có bậc n (các hệ số ban đầu bằng 0)
cDaThuc::cDaThuc(int bac)
{
    iBac = bac;
    HeSo.assign(bac + 1, 0.0);
}

cDaThuc::~cDaThuc()
{
    HeSo.clear();
}

void cDaThuc::ChuanHoa()
{
    // Rút gọn bậc đa thức nếu hệ số bậc cao nhất bằng 0 (ví dụ sau khi trừ)
    while (iBac > 0 && HeSo[iBac] == 0)
    {
        HeSo.pop_back();
        iBac--;
    }
}

void cDaThuc::Nhap()
{
    do {
        cout << "Nhap bac cua da thuc (n >= 0): ";
        cin >> iBac;
    } while (iBac < 0);

    HeSo.resize(iBac + 1);
    cout << "Nhap cac he so tuong ung (tu bac cao nhat xuong bac 0):\n";
    for (int i = iBac; i >= 0; i--)
    {
        cout << "He so cua x^" << i << " = ";
        cin >> HeSo[i];
    }
    ChuanHoa();
}

void cDaThuc::Xuat()
{
    if (iBac == 0 && HeSo[0] == 0) {
        cout << "0" << endl;
        return;
    }

    bool laPhanTuDauTien = true;
    for (int i = iBac; i >= 0; i--)
    {
        if (HeSo[i] == 0) continue; // Bỏ qua nếu hệ số bằng 0

        // Xử lý dấu cộng/trừ cho đẹp mắt
        if (HeSo[i] > 0 && !laPhanTuDauTien) {
            cout << " + ";
        } else if (HeSo[i] < 0) {
            if (laPhanTuDauTien) cout << "-";
            else cout << " - ";
        }

        double giaTriTuyetDoi = abs(HeSo[i]);

        // In hệ số (không in số 1 trừ khi là hằng số tự do)
        if (giaTriTuyetDoi != 1 || i == 0) {
            cout << giaTriTuyetDoi;
        }

        // In biến x và số mũ
        if (i > 0) {
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }

        laPhanTuDauTien = false;
    }
    cout << endl;
}

double cDaThuc::TinhGiaTri(double x)
{
    double ketQua = 0;
    // Sử dụng thuật toán Horner để tính toán nhanh và chính xác hơn thay vì dùng pow()
    // P(x) = a_n*x^n + a_{n-1}*x^{n-1} + ... + a_0
    for (int i = iBac; i >= 0; i--)
    {
        ketQua = ketQua * x + HeSo[i];
    }
    return ketQua;
}

cDaThuc cDaThuc::Cong(cDaThuc dtKhac)
{
    int bacLonNhat = max(this->iBac, dtKhac.iBac);
    cDaThuc ketQua(bacLonNhat);

    for (int i = 0; i <= bacLonNhat; i++)
    {
        double heSo1 = (i <= this->iBac) ? this->HeSo[i] : 0;
        double heSo2 = (i <= dtKhac.iBac) ? dtKhac.HeSo[i] : 0;

        ketQua.HeSo[i] = heSo1 + heSo2;
    }
    ketQua.ChuanHoa();
    return ketQua;
}

cDaThuc cDaThuc::Tru(cDaThuc dtKhac)
{
    int bacLonNhat = max(this->iBac, dtKhac.iBac);
    cDaThuc ketQua(bacLonNhat);

    for (int i = 0; i <= bacLonNhat; i++)
    {
        double heSo1 = (i <= this->iBac) ? this->HeSo[i] : 0;
        double heSo2 = (i <= dtKhac.iBac) ? dtKhac.HeSo[i] : 0;

        ketQua.HeSo[i] = heSo1 - heSo2;
    }
    ketQua.ChuanHoa();
    return ketQua;
}
