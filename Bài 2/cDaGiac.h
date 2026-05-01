#ifndef CDAGIAC_H
#define CDAGIAC_H

#include <vector>

class cDiem
{
    private:
        double dX;
        double dY;

    public:
        // Constructors & Destructor
        cDiem(double x = 0, double y = 0);
        ~cDiem();

        void Nhap();
        void Xuat();

        double TinhKhoangCach(cDiem p);
        double GetX();
        double GetY();

        void TinhTien(double dx, double dy);
        void Quay(double goc);
        void ThuPhong(double k);
};

class cDaGiac
{
    private:
        int iSoDinh;
        std::vector<cDiem> DanhSachDinh;

    public:
        // Constructors & Destructor
        cDaGiac();
        cDaGiac(int n, std::vector<cDiem> dsDinh);
        ~cDaGiac();

        void Nhap();
        void Xuat();

        double TinhChuVi();
        double TinhDienTich();

        // Các phương thức biến đổi hình học
        void TinhTien(double dx, double dy);
        void Quay(double goc);
        void PhongTo(double k);
        void ThuNho(double k);
};

#endif // CDAGIAC_H
