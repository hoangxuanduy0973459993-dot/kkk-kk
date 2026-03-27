#include <iostream>
#include <vector>
using namespace std;

// ================== TAI KHOAN ==================
class TaiKhoan {
protected:
    string soTK;
    double soDu;
public:
    TaiKhoan(string stk, double sd) {
        soTK = stk;
        soDu = sd;
    }

    virtual void hienThi() {
        cout << "So TK: " << soTK << " | So du: " << soDu << endl;
    }

    virtual void napTien(double tien) {
        soDu += tien;
    }

    virtual void rutTien(double tien) {
        if (soDu >= tien) soDu -= tien;
        else cout << "Khong du tien!\n";
    }

    virtual double tinhLai() { return 0; }

    string getSoTK() { return soTK; }
    double getSoDu() { return soDu; }
};

// ===== TIET KIEM =====
class TietKiem : public TaiKhoan {
public:
    TietKiem(string stk, double sd) : TaiKhoan(stk, sd) {}
    double tinhLai() override { return soDu * 0.05; }
};

// ===== THANH TOAN =====
class ThanhToan : public TaiKhoan {
public:
    ThanhToan(string stk, double sd) : TaiKhoan(stk, sd) {}
    double tinhLai() override { return soDu * 0.01; }
};

// ================== KHACH HANG ==================
class KhachHang {
private:
    string ten, cccd;
    vector<TaiKhoan*> dsTK;
public:
    KhachHang(string t, string c) {
        ten = t; cccd = c;
    }

    void themTaiKhoan(TaiKhoan* tk) {
        dsTK.push_back(tk);
    }

    vector<TaiKhoan*>& getDSTK() { return dsTK; }
    string getTen() { return ten; }
};

// ================== GIAO DICH ==================
class GiaoDich {
private:
    string loai;
    double soTien;
public:
    GiaoDich(string l, double s) {
        loai = l; soTien = s;
    }

    void hienThi() {
        cout << loai << " | So tien: " << soTien << endl;
    }
};

// ================== NGAN HANG ==================
class NganHang {
private:
    vector<KhachHang> dsKH;

public:
    void themKhachHang() {
        string ten, cccd;
        cout << "Nhap ten: "; cin.ignore(); getline(cin, ten);
        cout << "Nhap CCCD: "; getline(cin, cccd);

        dsKH.push_back(KhachHang(ten, cccd));
    }

    KhachHang* chonKhachHang() {
        for (int i = 0; i < dsKH.size(); i++) {
            cout << i << ". " << dsKH[i].getTen() << endl;
        }
        int chon;
        cout << "Chon KH: "; cin >> chon;
        if (chon >= 0 && chon < dsKH.size())
            return &dsKH[chon];
        return NULL;
    }

    void themTaiKhoan() {
        KhachHang* kh = chonKhachHang();
        if (!kh) return;

        string stk;
        double sd;
        int loai;

        cout << "Nhap so TK: "; cin >> stk;
        cout << "Nhap so du: "; cin >> sd;
        cout << "1. Tiet kiem | 2. Thanh toan: ";
        cin >> loai;

        if (loai == 1)
            kh->themTaiKhoan(new TietKiem(stk, sd));
        else
            kh->themTaiKhoan(new ThanhToan(stk, sd));
    }

    TaiKhoan* timTK(string stk) {
        for (auto &kh : dsKH)
            for (auto tk : kh.getDSTK())
                if (tk->getSoTK() == stk)
