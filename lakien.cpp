#include<bits/stdc++.h>

using namespace std;

class KhachHang {
private:
    string ten;
    string diaChi;
    string soDienThoai;
    string email;
    string soCCCD;

public:
    void hienThi(int soThuTu) const {
        cout <<soThuTu <<". Ten:" <<ten <<", Dia chi:" <<diaChi <<", SDT: " <<soDienThoai <<", Email:" <<email <<", CCCD: " << soCCCD <<endl;
    }
    // hàm gọi Getter và Setter
    void setTen(const string& _ten) { 
		ten = _ten; }
    string getTen() const { 
		return ten; }
    void setDiaChi(const string& _diaChi) { 
		diaChi = _diaChi; }
    string getDiaChi() const { 
		return diaChi; }
    void setSoDienThoai(const string& _soDienThoai) { 
		soDienThoai = _soDienThoai; }
    string getSoDienThoai() const { 
		return soDienThoai; }
    void setEmail(const string& _email) { 
		email = _email; }
    string getEmail() const { 
		return email; }
    void setSoCCCD(const string& _soCCCD) { 
		soCCCD = _soCCCD; }
    string getSoCCCD() const { 
		return soCCCD; }
};

class DichVuUuDai {
private:
    string tenKhachHang;
    string thongTinLienHe;
    int diemTichLuy;
    string mucDoThanThiet;

public:
    void hienThi() const {
        cout <<"Ten khach hang: " <<tenKhachHang <<", Thong tin lien he: " <<thongTinLienHe <<", Diem tich luy: " <<diemTichLuy << ", Muc do than thiet: " <<mucDoThanThiet << endl;
    }

    // hàm gọi Getter và Setter
    void setTenKhachHang(const string& _tenKhachHang) { 
		tenKhachHang = _tenKhachHang; }
    string getTenKhachHang() const { 
		return tenKhachHang; }
    void setThongTinLienHe(const string& _thongTinLienHe) { 
		thongTinLienHe = _thongTinLienHe; }
    string getThongTinLienHe() const { 
		return thongTinLienHe; }
    void setDiemTichLuy(int _diemTichLuy) { 
		diemTichLuy = _diemTichLuy; }
    int getDiemTichLuy() const { 
		return diemTichLuy; }
    void setMucDoThanThiet(const string& _mucDoThanThiet) { 
		mucDoThanThiet = _mucDoThanThiet; }
    string getMucDoThanThiet() const { 
		return mucDoThanThiet; }
};

// hàm lưu danh sách khách hàng vào tệp khachhang.txt
void luuDanhSachKhachHang(const vector<KhachHang>& danhSach) {
    ofstream file("khachhang.txt");
    if (!file) {
        cerr << "Khong the mo tep de luu du lieu." << endl;
        return;
    }
    for (const auto& kh : danhSach) {
        file <<kh.getTen() << "," <<kh.getDiaChi() << "," <<kh.getSoDienThoai() << "," <<kh.getEmail() << "," <<kh.getSoCCCD() <<endl;
    }
    file.close(); 
}

// hàm tải danh sách khách hàng từ tệp khachhang.txt
void taiDanhSachKhachHang(vector<KhachHang>& danhSach) {
    ifstream file("khachhang.txt");
    if (!file) {
        cerr << "Khong the mo tep de tai du lieu." << endl;
        return;
    }
    KhachHang kh;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, temp, ',');
        kh.setTen(temp);
        getline(ss, temp, ',');
        kh.setDiaChi(temp);
        getline(ss, temp, ',');
        kh.setSoDienThoai(temp);
        getline(ss, temp, ',');
        kh.setEmail(temp);
        getline(ss, temp);
        kh.setSoCCCD(temp);

        danhSach.push_back(kh);
    }
    file.close(); 
}

// hàm thêm khách hàng vào dang sách
void themKhachHang(vector<KhachHang>& danhSach) {
    KhachHang kh;
    string temp;
    cout << "Nhap ten: ";
    getline(cin, temp);
    kh.setTen(temp);
    cout << "Nhap dia chi: ";
    getline(cin, temp);
    kh.setDiaChi(temp);
    cout << "Nhap so dien thoai: ";
    getline(cin, temp);
    kh.setSoDienThoai(temp);
    cout << "Nhap email: ";
    getline(cin, temp);
    kh.setEmail(temp);
    cout << "Nhap so CCCD: ";
    getline(cin, temp);
    kh.setSoCCCD(temp);
    danhSach.push_back(kh);
    luuDanhSachKhachHang(danhSach);
}

// hàm hiển thị danh sách khách hàng 
void hienThiDanhSachKhachHang(const vector<KhachHang>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach khach hang trong." << endl;
        return;
    }
    for (size_t i = 0; i < danhSach.size(); i++) {
        danhSach[i].hienThi(i + 1);
    }
}

// hàm tìm kiếm khách hàng theo tên
void timKiemKhachHang(const vector<KhachHang>& danhSach, const string& ten) {
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].getTen() == ten) {
            danhSach[i].hienThi(i + 1);
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten:" << ten << endl;
}

// hàm sửa thông tin khách hàng theo tên
void suaKhachHang(vector<KhachHang>& danhSach, const string& ten) {
    for (auto& kh : danhSach) {
        if (kh.getTen() == ten) {
            string temp;
            
            cout << "Nhap thong tin moi cho khach hang " << ten << ":" << endl;
            cout << "Ten: ";
            getline(cin, temp);
            kh.setTen(temp);
            cout << "Dia chi: ";
            getline(cin, temp);
            kh.setDiaChi(temp);
            cout << "So dien thoai: ";
            getline(cin, temp);
            kh.setSoDienThoai(temp);
            cout << "Email:";
            getline(cin, temp);
            kh.setEmail(temp);
            cout << "So CCCD:";
            getline(cin, temp);
            kh.setSoCCCD(temp);
            
            luuDanhSachKhachHang(danhSach);
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten:" << ten << endl;
}

// hàm xóa khách hàng theo tên
void xoaKhachHang(vector<KhachHang>& danhSach, const string& ten) {
    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getTen() == ten) {
            danhSach.erase(danhSach.begin() + i);
            luuDanhSachKhachHang(danhSach);
            cout << "Da xoa khach hang: " << ten << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten: " << ten << endl;
}

// hàm  lưu danh sách dịch vụ vào tệp dichvu.txt 
void luuDanhSachDichVu(const vector<DichVuUuDai>& danhSach) {
    ofstream file("dichvu.txt");
    if (!file) {
        cerr << "Khong the mo tep de luu du lieu." << endl;
        return;
    }
    for (const auto& dv : danhSach) {
        file <<dv.getTenKhachHang() << "," <<dv.getThongTinLienHe() << ","<<dv.getDiemTichLuy() << "," <<dv.getMucDoThanThiet() <<endl;
    }
    file.close(); // Đảm bảo tệp được đóng
}

// hàm tải danh sách dịch vụ từ tệp dichvu.txt
void taiDanhSachDichVu(vector<DichVuUuDai>& danhSach) {
    ifstream file("dichvu.txt");
    if (!file) {
        cerr << "Khong the mo tep de tai du lieu." << endl;
        return;
    }
    DichVuUuDai dv;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, temp, ',');
        dv.setTenKhachHang(temp);
        getline(ss, temp, ',');
        dv.setThongTinLienHe(temp);
        int diem;
        ss >> diem;
        dv.setDiemTichLuy(diem);
        getline(ss, temp);
        dv.setMucDoThanThiet(temp);
        
		danhSach.push_back(dv);
    }
    file.close(); 
}

// hàm thêm dịch vụ vào danh sách 
void themDichVu(vector<DichVuUuDai>& danhSach) {
    DichVuUuDai dv;
    string temp;

    cout << "Nhap ten khach hang: ";
    getline(cin, temp);
    dv.setTenKhachHang(temp);
    cout << "Nhap thong tin lien he: ";
    getline(cin, temp);
    dv.setThongTinLienHe(temp);
    int diem;
    cout << "Nhap diem tich luy:";
    cin >> diem;
    dv.setDiemTichLuy(diem); cin.ignore(); 
    cout << "Nhap muc do than thiet: ";
    getline(cin, temp);
    dv.setMucDoThanThiet(temp);

    danhSach.push_back(dv);
    luuDanhSachDichVu(danhSach);
}

// hàm hiển thị danh sách dịch vụ
void hienThiDanhSachDichVu(const vector<DichVuUuDai>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach dich vu trong." << endl;
        return;
    }
    for (const auto& dv : danhSach) {
        dv.hienThi();
    }
}

// hàm tìm kiếm dịch vụ theo tên khách hàng  
void timKiemDichVu(const vector<DichVuUuDai>& danhSach, const string& tenKhachHang) {
    for (const auto& dv : danhSach) {
        if (dv.getTenKhachHang() ==tenKhachHang) {
            dv.hienThi();
            return;
        }
    }
    cout << "Khong tim thay dich vu voi ten khach hang: " << tenKhachHang << endl;
}

// hàm sửa dịch vụ theo tên khách hàng 
void suaDichVu(vector<DichVuUuDai>& danhSach, const string& tenKhachHang) {
    for (auto& dv : danhSach) {
        if (dv.getTenKhachHang() == tenKhachHang) {
            string temp;
            cout << "Nhap thong tin moi cho dich vu cua khach hang " << tenKhachHang << ":" << endl;

            cout << "Ten khach hang: ";
            getline(cin, temp);
            dv.setTenKhachHang(temp);
            cout << "Thong tin lien he: ";
            getline(cin, temp);
            dv.setThongTinLienHe(temp);
            int diem;
            cout << "Diem tich luy: ";
            cin >> diem;
			dv.setDiemTichLuy(diem);cin.ignore(); 
            cout << "Muc do than thiet: ";
            getline(cin, temp);
            dv.setMucDoThanThiet(temp);
            
            luuDanhSachDichVu(danhSach);
            return;
        }
    }
    cout << "Khong tim thay dich vu voi ten khach hang: " << tenKhachHang << endl;
}

// hàm xóa dịch vụ theo tên khách hàng
void xoaDichVu(vector<DichVuUuDai>& danhSach, const string& tenKhachHang) {
    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getTenKhachHang() == tenKhachHang) {
            danhSach.erase(danhSach.begin() + i);
            luuDanhSachDichVu(danhSach);
            cout << "Da xoa dich vu cua khach hang: " << tenKhachHang << endl;
            return;
        }
    }
    cout << "Khong tim thay dich vu voi ten khach hang: " << tenKhachHang << endl;
}

int main() {
    vector<KhachHang> danhSachKhachHang;
    vector<DichVuUuDai> danhSachDichVu;

// tải danh sách từ tệp khachhang.txt và tệp dichvu.txt
    taiDanhSachKhachHang(danhSachKhachHang);
    taiDanhSachDichVu(danhSachDichVu);

    int luaChonChinh, luaChonPhu;
    do {
        cout << "\n-----CHUONG TRINH QUAN LY-----\n";
        cout << "1.Quan ly thong tin khach hang\n";
        cout << "2.Quan ly thong tin dich vu uu dai\n";
        cout << "0.Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChonChinh;
        cin.ignore(); 
        switch (luaChonChinh) {
            case 1: 
                do {
                    cout <<"\n-----QUAN LY KHACH HANG-----\n";
                    cout <<"1.Them khach hang\n";
                    cout <<"2.Hien thi danh sach khach hang\n";
                    cout <<"3.Tim kiem khach hang\n";
                    cout <<"4.Sua thong tin khach hang\n";
                    cout <<"5.Xoa khach hang\n";
                    cout <<"0.Quay lai\n";
                    cout <<"Nhap lua chon cua ban: ";
                    cin >> luaChonPhu;
                    cin.ignore();
                    switch (luaChonPhu) {
                        case 1: themKhachHang(danhSachKhachHang); 
							break;
                        case 2: hienThiDanhSachKhachHang(danhSachKhachHang); 
							break;
                        case 3: {
                            string ten;
                            cout <<"Nhap ten khach hang can tim: ";
                            getline(cin, ten);
                            timKiemKhachHang(danhSachKhachHang, ten);
                            break;
                        }
                        case 4: {
                            string ten;
                            cout <<"Nhap ten khach hang can sua:";
                            getline(cin, ten);
                            suaKhachHang(danhSachKhachHang, ten);
                            break;
                        }
                        case 5: {
                            string ten;
                            cout <<"Nhap ten khach hang can xoa:";
                            getline(cin, ten);
                            xoaKhachHang(danhSachKhachHang, ten);
                            break;
                        }
                        case 0: 
							break;
                        default: cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
                    }
                } while (luaChonPhu != 0);
                break;

            case 2:
                do {
                    cout <<"\n---QUAN LY DICH VU UU DAI---\n";
                    cout <<"1.Them dich vu uu dai\n";
                    cout <<"2.Hien thi danh sach dich vu uu dai\n";
                    cout <<"3.Tim kiem dich vu uu dai\n";
                    cout <<"4.Sua dich vu uu dai\n";
                    cout <<"5.Xoa dich vu uu dai\n";
                    cout <<"0.Quay lai\n";
                    cout <<"Nhap lua chon cua ban: ";
                    cin >> luaChonPhu;
                    cin.ignore(); // Bỏ qua ký tự newline

                    switch (luaChonPhu) {
                        case 1: themDichVu(danhSachDichVu); break;
                        case 2: hienThiDanhSachDichVu(danhSachDichVu); break;
                        case 3: {
                            string tenKhachHang;
                            cout <<"Nhap ten khach hang can tim dich vu uu dai: ";
                            getline(cin, tenKhachHang);
                            timKiemDichVu(danhSachDichVu, tenKhachHang);
                            break;
                        }
                        case 4: {
                            string tenKhachHang;
                            cout <<"Nhap ten khach hang can sua dich vu uu dai: ";
                            getline(cin, tenKhachHang);
                            suaDichVu(danhSachDichVu, tenKhachHang);
                            break;
                        }
                        case 5: {
                            string tenKhachHang;
                            cout <<"Nhap ten khach hang can xoa dich vu uu dai: ";
                            getline(cin, tenKhachHang);
                            xoaDichVu(danhSachDichVu, tenKhachHang);
                            break;
                        }
                        case 0: break; // Quay lại
                        default: cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
                    }
                } while (luaChonPhu != 0);
                break;
            case 0:
                cout <<"Thoat chuong trinh." << endl;
                break;
            default:
                cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while (luaChonChinh != 0);
    return 0;
}
