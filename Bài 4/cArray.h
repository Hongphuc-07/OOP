#ifndef CARRAY_H
#define CARRAY_H

#include <vector>

class cArray
{
    private:
        std::vector<int> a;

        // Hàm hỗ trợ nội bộ để kiểm tra số nguyên tố
        bool LaSoNguyenTo(int val);

    public:
        cArray();
        ~cArray();


        void Nhap(int n);
        void Xuat();

        int DemGiaTri(int x); // Đếm số lần xuất hiện của x
        bool KiemTraTangDan(); // Kiểm tra tính tăng dần

        int TimSoLeNhoNhat(bool &timThay);
        int TimSoNguyenToLonNhat(bool &timThay);

        void SapXepTangDan(); // Sử dụng Interchange Sort
        void SapXepGiamDan();
};

#endif
