#ifndef CTAMGIAC_H
#define CTAMGIAC_H

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

        // Cac phuong thuc bien doi cho diem
        void TinhTien(double dx, double dy);
        void Quay(double goc); // Goc tinh bang do
        void ThuPhong(double k);
};

class cTamGiac
{
    private:
        cDiem A, B, C;

    public:
        // Constructors & Destructor
        cTamGiac();
        cTamGiac(cDiem a, cDiem b, cDiem c);
        ~cTamGiac();

        void Nhap();
        void Xuat();

        bool KiemTraHopLe();
        void KiemTraLoai();

        double TinhChuVi();
        double TinhDienTich();

        // Cac phuong thuc bien doi cho tam giac
        void TinhTien(double dx, double dy);
        void Quay(double goc);
        void PhongTo(double k);
        void ThuNho(double k);
};

#endif // CTAMGIAC_H
