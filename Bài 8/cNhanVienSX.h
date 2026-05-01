#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>

// Lớp phụ quản lý ngày tháng năm
class cNgay
{
    private:
        int iNgay;
        int iThang;
        int iNam;

    public:
        cNgay(int ng = 1, int th = 1, int nm = 2000);
        void Nhap();
        void Xuat();
        int TinhTuoi(int namHienTai);
};

// Lớp chính quản lý Nhân viên sản xuất
class cNhanVienSX
{
    private:
        std::string sMaNV;
        std::string sHoTen;
        cNgay ngSinh;
        int iSoSanPham;
        double dDonGia;

    public:
        // Constructor & Destructor
        cNhanVienSX();
        ~cNhanVienSX();

        // Getters
        std::string GetMaNV();
        std::string GetHoTen();
        int GetSoSanPham();
        double GetDonGia();
        int GetTuoi();

        // Setters
        void SetMaNV(std::string ma);
        void SetHoTen(std::string ten);
        void SetSoSanPham(int soSP);
        void SetDonGia(double gia);

        // Các phương thức nghiệp vụ
        void Nhap();
        void Xuat();
        double TinhLuong();
};

#endif // CNHANVIENSX_H
