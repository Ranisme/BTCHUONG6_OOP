#include <bits/stdc++.h>

using namespace std;

class NhanVien {
protected:
    string MNV;
    string Hoten;
    int Tuoi;
    string SDT;
    string EM;
    double Luong;

public:
    NhanVien() {}

    void nhap() {
        cout << "Nhap ma nhan vien: ";
        cin >> MNV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, Hoten);
        cout << "Nhap tuoi: ";
        cin >> Tuoi;
        cout << "Nhap so dien thoai: ";
        cin >> SDT;
        cout << "Nhap email: ";
        cin >> EM;
        cout << "Nhap luong co ban: ";
        cin >> Luong;
    }
};


class LapTrinhVien : public NhanVien {
private:
    int OVT;
public:
    LapTrinhVien() : OVT(0) {}

    void nhap() {
        NhanVien::nhap();
        cout << "Nhap so gio overtime: ";
        cin >> OVT;
    }

    double tinhLuong() {
        return Luong + OVT * 200000;
    }

    friend ostream & operator << (ostream & os, LapTrinhVien & cur) {
        os << "Lap trinh vien: " << cur.Hoten << "\n";
        os << "Ma nhan vien: " << cur.MNV << "\n";
        os << "Tuoi: " << cur.Tuoi << "\n";
        os << "So dien thoai: " << cur.SDT << "\n";
        os << "Email: " << cur.EM << "\n";
        os << "So gio overtime: " << cur.OVT << "\n";
        os << "Luong: " << cur.Luong << "\n";
        return os;
    }
};

class KiemChungVien : public NhanVien {
private:
    int Loi;
public:
    KiemChungVien() : Loi(0) {}

    void nhap() {
        NhanVien::nhap();
        cout << "Nhap so loi phat hien duoc: ";
        cin >> Loi;
    }

    double tinhLuong() {
        return Luong + Loi * 50000;
    }

    friend ostream & operator << (ostream & os, KiemChungVien & cur) {
        os << "Kiem chung vien: " << cur.Hoten << "\n";
        os << "Ma nhan vien: " << cur.MNV << "\n";
        os << "Tuoi: " << cur.Tuoi << "\n";
        os << "So dien thoai: " << cur.SDT << "\n";
        os << "Email: " << cur.EM << "\n";
        os << "So loi phat hien duoc: " << cur.Loi << "\n";
        os << "Luong: " << cur.Luong << "\n";
        return os;
    }
};


int main() {
    vector <LapTrinhVien> a;
    vector <KiemChungVien> b;
    int nL, nK;
    double TB = 0;
    cout << "Nhap so lap trinh vien \n";
    cin >> nL;
    cout << "Nhap so kiem chung vien \n";
    cin >> nK;
    for (int i = 1; i <= nL; i++) {
        LapTrinhVien cur;
        cur.nhap();
        a.push_back(cur);
        TB += cur.tinhLuong();
    }
    for (int i = 1; i <= nK; i++) {
        KiemChungVien cur;
        cur.nhap();
        b.push_back(cur);
        TB += cur.tinhLuong();
    }
    cout << "Danh sach cac nhan vien :\n";
    for (auto cur : a)
        cout << cur;
    for (auto cur : b)
        cout << cur;

    TB /= (nL + nK);

    cout << "Nhung nhan vien co luong duoi trung binh :\n";

    for (auto cur : a)
        if (cur.tinhLuong() < TB)
            cout << cur;
    for (auto cur : b)
        if (cur.tinhLuong() < TB)
            cout << cur;
    return 0;
}
