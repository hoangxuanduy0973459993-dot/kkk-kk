#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TaiKhoan {
private:
    string soTK;
    double soDu;

public:
    TaiKhoan(string stk, double sd) {
        soTK = stk;
        soDu = sd;
    }

    string getSoTK() {
        return soTK;
    }

    double getSoDu() {
        return soDu;
    }
};

class KhachHang {
private:
    string ten;
    vector<TaiKhoan*> dsTK;

public:
    KhachHang(string t) {
        ten = t;
    }

    void themTK(TaiKhoan* tk) {
        dsTK.push_back(tk);
    }

    vector<TaiKhoan*> getDSTK() {
        return dsTK;
    }
};

vector<KhachHang> dsKH;

TaiKhoan* timTK(string stk) {
    for (int i = 0; i < dsKH.size(); i++) {
        KhachHang &kh = dsKH[i];
        vector<TaiKhoan*> dstk = kh.getDSTK();

        for (int j = 0; j < dstk.size(); j++) {
            TaiKhoan* tk = dstk[j];
            if (tk->getSoTK() == stk) {
                return tk;
            }
        }
    }
    return NULL;
}

int main() {
    KhachHang kh1("Duy");
    KhachHang kh2("Hoang");

    TaiKhoan* tk1 = new TaiKhoan("123", 1000);
    TaiKhoan* tk2 = new TaiKhoan("456", 2000);

    kh1.themTK(tk1);
    kh2.themTK(tk2);

    dsKH.push_back(kh1);
    dsKH.push_back(kh2);

    string stk;
    cout << "Nhap so tai khoan: ";
    cin >> stk;

    TaiKhoan* kq = timTK(stk);

    if (kq != NULL) {
        cout << "Tim thay! So du: " << kq->getSoDu() << endl;
    } else {
        cout << "Khong tim thay!" << endl;
    }

    return 0;
}

