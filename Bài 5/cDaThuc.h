#ifndef CDATHUC_H
#define CDATHUC_H

#include <vector>

class cDaThuc
{
    private:
        int iBac;
        std::vector<double> HeSo;

        //Hàm hỗ trợ nội bộ để xóa bỏ các hệ số 0 ở bậc cao nhất
        void ChuanHoa();

    public:
        //Khởi tạo đa thức bậc 0 hoặc bậc n
        cDaThuc();
        cDaThuc(int bac);
        ~cDaThuc();

        void Nhap();
        void Xuat();

        //Tính giá trị đa thức khi biết x
        double TinhGiaTri(double x);

        //Các phép toán
        cDaThuc Cong(cDaThuc dtKhac);
        cDaThuc Tru(cDaThuc dtKhac);
};

#endif // CDATHUC_H
