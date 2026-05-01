#include "cArray.h"
#include <iostream>
#include <algorithm>

using namespace std;

cArray::cArray() {}
cArray::~cArray() {}

// Phương thức để người dùng tự nhập dữ liệu cho mảng
void cArray::Nhap(int n) {
    a.clear();
    int temp;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> temp;
        a.push_back(temp);
    }
}

void cArray::Xuat() {
    for (int x : a) cout << x << " ";
    cout << endl;
}

bool cArray::LaSoNguyenTo(int val) {
    if (val < 2) return false;
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) return false;
    }
    return true;
}

int cArray::DemGiaTri(int x) {
    int count = 0;
    for (int val : a) if (val == x) count++;
    return count;
}

bool cArray::KiemTraTangDan() {
    if (a.size() < 2) return true;
    for (int i = 0; i < (int)a.size() - 1; i++) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int cArray::TimSoLeNhoNhat(bool &timThay) {
    int minLe;
    timThay = false;
    for (int val : a) {
        if (val % 2 != 0) {
            if (!timThay || val < minLe) {
                minLe = val;
                timThay = true;
            }
        }
    }
    return timThay ? minLe : -1;
}

int cArray::TimSoNguyenToLonNhat(bool &timThay) {
    int maxSNT;
    timThay = false;
    for (int val : a) {
        if (LaSoNguyenTo(val)) {
            if (!timThay || val > maxSNT) {
                maxSNT = val;
                timThay = true;
            }
        }
    }
    return timThay ? maxSNT : -1;
}

void cArray::SapXepTangDan() {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[i] > a[j]) swap(a[i], a[j]); // Interchange Sort
        }
    }
}

void cArray::SapXepGiamDan() {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[i] < a[j]) swap(a[i], a[j]);
        }
    }
}
