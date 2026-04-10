#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

class NgayThangNam
{
    private:
        int iNgay;
        int iThang;
        int iNam;

    public:
        void Nhap();
        void Xuat();

        NgayThangNam NgayThangNamTiepTheo();
};

#endif
