﻿#pragma once 
#include "ctdl.h"
#include "hotro.h"
#include "doc_ghi_file.h"
//=============================================Khoi tao===============================
void Init_MT(LIST_MT& l)
{
	l.pHead = l.pTail = NULL;
}
void Init_TREE(TREE& t)
{
	t = NULL;
}
void Init_DS(LIST_DS& l)
{
	l.sl = 0;
}
void Init_DMS(LIST_DMS& l)
{
	l.pHead = l.pTail = NULL;
}

// ======================================Doc gia========================================================

int NHAP_THONGTIN_DG(docgia& x);// nhập thành công rt 1 <> esc rt -2
void Add_DG_VAO_CAY(TREE& t, docgia x); // thêm độc giả vào cây
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo);// Xuất thông tin của 1 độc giả
void XUAT_DS_DG(TREE t, int& i);//duyet theo LNR in ra ma the tang dan
void XOA_DG(TREE& t, int x);// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
TREE TIM_KIEM_DG_MA(TREE& t, int ma_doc_gia);// tìm kiếm độc giả trong danh sách với mã độc giả
void TIM_KIEM_DG_TEN(TREE t, string ch1, int& tungdo);// tìm kiếm tên độc giả
int HIEU_CHINH_DG(TREE& t);// hiệu chỉnh thông tin độc giả thành công rt 1 <> ESC rt -2


//========================================== Đau Sach ==================================================

int NHAP_DS(LIST_DS& l, dausach& data);// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
void XUAT_THONGTIN_DS(dausach& a, int tungdo);// in ra 1 đầu sách
void XUAT_DS_DAUSACH(LIST_DS& l);// in danh sach theo the loai
void ADDTail_DS(LIST_DS& l, dausach data);// Thêm đầu sách vào danh sách đầu sách để quản lí
int TIM_KIEM_DS_THEO_TEN(LIST_DS l, string temp);// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1;
int TIM_KIEM_DS_THEO_MA(LIST_DS l, string ma);// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int HIEU_CHINH_DS(LIST_DS& l);// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2


//=========================================Danh muc sach===============================================
NODE_DMS* TAO_NODE_SACH(danhmucsach& x);// tạo 1 node mới 
int THEM_SACH(LIST_DS& l);// Thêm sách nếu thêm thành công rt 1 <> -1 ; ESC rt -2;
void AddTail_DMS(LIST_DMS& l, NODE_DMS* p);// thêm sách vào danh sách sách để quản lí
void XUAT_THONG_TIN_SACH(string ten_sach, danhmucsach a, int tungdo);// xuất 1 cuốn sách
NODE_DMS* TIM_KIEM_SACH(LIST_DS l, string ma_sach);// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL

//==========================================Muon tra===================================================

NODE_MT* TAO_NODE_MT(muontra x);// tạo 1 node mượn trả 
void NHAP_THONGTIN_MT(muontra& x);// lập phiếu mượn sách
void XUAT_THONG_TIN_MT(muontra a, string ten_sach, int tungdo);// in thong tin của 1 phiếu mượn trả
void AddTail_MT(LIST_MT& l, NODE_MT* p);// thêm phiếu vào danh sách để quản lí
int XUAT_SACH_MUON(TREE t, LIST_DS l);// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
void MUON_SACH(TREE& t, LIST_DS& l);// mượn thành công tr 1 <> -1 ; esc rt -2
void TRA_SACH(TREE& t, LIST_DS& l);// trả sách thành công tr 1 <> -1 ; ESC rt -2

// =========================================== Qua Han ================================
void DS_QUAHAN(TREE t);// in ra danh sách các độc giả quá hạn
bool Dem_SN_QUAHAN(TREE p);
// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l);

// ========================================== Độc Giả==========================================

// nhập thành công rt 1 <> esc rt -2
int NHAP_THONGTIN_DG(docgia& x)
{
	xoa_hien_thi_Box_NhapDG();
	Box_NhapDG();
	int k = 0; // check ESC nhap
	x.trangthaithe = 1; // trạng thái lúc thêm độc giả auto =1. có thể mượn sách
	gotoXY(boxx + 18, boxy + 10);
	cout << "HOAT DONG";
	gotoXY(boxx + 10, boxy + 2);
	cout << x.mathe;
	x.ho = "";
	gotoXY(boxx + 11, boxy + 4);
	k = nhap_ki_tu(x.ho, 0);
	if (k == -1) // ESC
		return -2;
	x.ten = "";
	gotoXY(boxx + 12, boxy + 6);
	k = nhap_ki_tu(x.ten, 0);
	if (k == -1) // ESC
		return -2;
	x.phai = "";
	gotoXY(boxx + 13, boxy + 8);
	k = nhap_ki_tu(x.phai, 2);
	if (k == -1) // ESC
		return -2;
	return 1;
}

// them 1 node vao cay theo ma doc gia 
void Add_DG_VAO_CAY(TREE& t, docgia x)
{
	if (t)
	{
		if (x.mathe < t->data.mathe)
			Add_DG_VAO_CAY(t->pLeft, x);
		else if (x.mathe > t->data.mathe)
			Add_DG_VAO_CAY(t->pRight, x);
	}
	else
	{
		NODE_DG* p = new NODE_DG;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
		Init_MT(t->data.mt); // khoi tao danh sach muon tra
	}
}

// Xuất thông tin của 1 độc giả
void Xuat_Thong_Tin_Doc_Gia(docgia a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(14);
	gotoXY(50, 0);
	cout << "MA DOC GIA";
	gotoXY(65, 0);
	cout << "HO";
	gotoXY(90, 0);
	cout << "TEN";
	gotoXY(120, 0);
	cout << "PHAI";
	gotoXY(135, 0);
	cout << "TRANG THAI THE";
	TextColor(15);
	gotoXY(50, tungdo);
	cout << a.mathe;
	gotoXY(65, tungdo);
	cout << a.ho;
	gotoXY(90, tungdo);
	cout << a.ten;
	gotoXY(120, tungdo);
	cout << a.phai;
	gotoXY(137, tungdo);
	if (a.trangthaithe == 1)
		cout << "HOAT DONG";
	else
		cout << "KHOA";
	TextColor(7);
	gotoXY(x, y);
}

//duyet theo LNR in ra ma the tang dan
void XUAT_DS_DG(TREE t, int& i)
{
	int n = SoluongDG(t);
	int t_sotrang = (n - 1) / 40 + 1;
	docgia* arr = new docgia[n];
	int index = 0;
	CHUYEN_CAY_SANG_MANG(t, arr, index);
	int tungdo = 1;
	for (int i = 0; i < t_sotrang; i++)
	{
		for (int j = i * 40; j < (40 * i) + 40 && j < n && tungdo < 40; j++)
			Xuat_Thong_Tin_Doc_Gia(arr[j], tungdo++);

		gotoXY(105, 42); cout << i + 1 << "/" << t_sotrang;
		ButtonNext();
		ButtonPrev();
		chay_chu(85, 46, "PRESS ANY KEY TO CONTINUE");
		char c = _getch();
		if (c == -32)
			c = _getch();
		if (c == 77)
		{
			XOA_HIEN_THI();
			ClearLine(90, 44);
			tungdo = 1;
			if (i == t_sotrang - 1)
				i = -1;
		}
		else if (c == 75)
		{
			XOA_HIEN_THI();
			ClearLine(90, 44);
			tungdo = 1;
			if (i == 0)
				i = t_sotrang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
		else
		{
			ClearLine(85, 44);
			ClearLine(100, 42);
			delete[] arr;
			return;
		}
	}
	delete[] arr;
}
// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void XOA_DG(TREE& t, int x)
{
	if (t != NULL)
	{
		// duyệt cây để tìm phần tử cần xóa
		if (t->data.mathe < x)
		{
			XOA_DG(t->pRight, x);
		}
		else if (t->data.mathe > x)
		{
			XOA_DG(t->pLeft, x);
		}
		// đã tìm được mã độc giả
		else
		{
			int temp = DEM_SACH_DG_MUON(t);
			if (temp > 0)
			{
				BaoLoi("DOC GIA DANG CON SACH MUON.KHONG THE XOA");
				return;
			}
			NODE_DG* p = t;
			// xóa node có 1 con hoặc không có con nào
			if (t->pLeft == NULL) // cây con phải
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL) // cây con trái
			{
				t = t->pLeft;
			}
			// xóa node có 2 con.Trái nhất của cây con phải
			else
			{
				// trái nhất của cây con phải
				TIM_KIEM_PT_THEMANG(p, t->pRight);
			}
			delete p;
			BaoLoi("XOA THANH CONG");
		}
	}
}

// tìm kiếm độc giả trong danh sách với mã độc giả
TREE TIM_KIEM_DG_MA(TREE& t, int ma_doc_gia)
{
	if (t)
	{
		if (t->data.mathe == ma_doc_gia)
			return t;
		else if (t->data.mathe < ma_doc_gia)
			return TIM_KIEM_DG_MA(t->pRight, ma_doc_gia);
		else
			return TIM_KIEM_DG_MA(t->pLeft, ma_doc_gia);
	}
	else
		return NULL;
}

// tìm kiếm tên độc giả
void TIM_KIEM_DG_TEN(TREE t, string ch1, int& tungdo)
{
	if (t != NULL)
	{
		int pos = t->data.ten.find(ch1);
		// ch1 là chuỗi con của tên độc giả
		if (pos != string::npos)
		{
			if (tungdo == 1)
				XOA_HIEN_THI();
			Xuat_Thong_Tin_Doc_Gia(t->data, tungdo);
			ToMau(90 + pos, tungdo, ch1, 14);
			tungdo++;
		}
		TIM_KIEM_DG_TEN(t->pLeft, ch1, tungdo);
		TIM_KIEM_DG_TEN(t->pRight, ch1, tungdo);
	}
	return;
}

// hiệu chỉnh thông tin độc giả thành công rt 1 <>  ESC rt -2
int HIEU_CHINH_DG(TREE& p)
{
	docgia x;
	int k = 0;
	Box_NhapDG();
	gotoXY(boxx + 10, boxy + 2);
	cout << p->data.mathe;

	x.ho = p->data.ho;
	gotoXY(boxx + 11, boxy + 4);
	cout << x.ho;
	k = nhap_ki_tu(x.ho, 0);
	if (k == -1) // ESC
		return -2;

	x.ten = p->data.ten;
	gotoXY(boxx + 12, boxy + 6);
	cout << x.ten;
	k = nhap_ki_tu(x.ten, 0);
	if (k == -1) // ESC
		return -2;

	x.phai = p->data.phai;
	gotoXY(boxx + 13, boxy + 8);
	cout << x.phai;
	k = nhap_ki_tu(x.phai, 2);
	if (k == -1) // ESC
		return -2;

	x.trangthaithe = p->data.trangthaithe;
	gotoXY(boxx + 18, boxy + 10);
	cout << x.trangthaithe;
	k = nhap_so_nguyen1(x.trangthaithe);
	if (k == -1) // ESC
		return -2;
	p->data.ho = x.ho;
	p->data.ten = x.ten;
	p->data.phai = x.phai;
	p->data.trangthaithe = x.trangthaithe;
	return 1;
}


// =========================================Dau sach==============================================

// thêm đầu sách nếu thêm thành công rt 1 <> ESC rt -2
int NHAP_DS(LIST_DS& l, dausach& data)
{
	xoa_hien_thi_Box_NhapDS();
	Box_NhapDS();
	int k = 0;
	while (1)
	{
		gotoXY(boxx + 8, boxy + 2);
		k = nhap_ki_tu(data.ISBN, 3);
		if (k == -1) // ESC
			return -2;
		if (TIM_KIEM_DS_THEO_MA(l, data.ISBN) != -1)
		{
			BaoLoi("MA ISBN DA TON TAI");
			gotoXY(boxx + 8, boxy + 2);
			cout << "                  ";
			data.ISBN = "";
			continue;
		}
		gotoXY(boxx + 12, boxy + 4);
		k = nhap_ki_tu(data.tensach, 1);
		if (k == -1) // ESC
			return -2;
		data.sotrang = 0;
		gotoXY(boxx + 12, boxy + 6);
		k = nhap_so_nguyen(data.sotrang);
		if (k == -1) // ESC
			return -2;
		gotoXY(boxx + 11, boxy + 8);
		k = nhap_ki_tu(data.tacgia, 0);
		if (k == -1) // ESC
			return -2;
		data.namxuatban = 0;
		gotoXY(boxx + 10, boxy + 10);
		k = nhap_so_nguyen(data.namxuatban);
		if (k == -1) // ESC
			return -2;
		gotoXY(boxx + 12, boxy + 12);
		k = nhap_ki_tu(data.theloai, 0);
		if (k == -1) // ESC
			return -2;
		data.soluongmuon = 0;
		return 1;
	}
}

// in ra 1 đầu sách
void XUAT_THONGTIN_DS( dausach& a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(14);
	gotoXY(40, 0);
	cout << "ISBN";
	gotoXY(55, 0);
	cout << "TEN SACH";
	gotoXY(95, 0);
	cout << "SO TRANG";
	gotoXY(105, 0);
	cout << "TAC GIA";
	gotoXY(145, 0);
	cout << "NAM XB";
	gotoXY(155, 0);
	cout << "THE LOAI";
	TextColor(15);
	gotoXY(40, tungdo);
	cout << a.ISBN;
	gotoXY(55, tungdo);
	cout << a.tensach;
	gotoXY(95, tungdo);
	cout << a.sotrang;
	gotoXY(105, tungdo);
	cout << a.tacgia;
	gotoXY(145, tungdo);
	cout << a.namxuatban;
	gotoXY(155, tungdo);
	cout << a.theloai;
	gotoXY(x, y);
	TextColor(7);
}

// Thêm đầu sách vào danh sách đầu sách để quản lí
void ADDTail_DS(LIST_DS& l, dausach data)
{	  // nếu còn thêm được
	if (l.sl < MAX)
	{
		l.ds_dausach[l.sl] = new dausach;
		*l.ds_dausach[l.sl] = data;
		Init_DMS(l.ds_dausach[l.sl]->dms);
		l.sl++;
	}
}


// in danh sach theo the loai
void XUAT_DS_DAUSACH(LIST_DS& l)
{
	int tso_trang = (l.sl - 1) / 40 + 1;
	int so_trang = 1;
	TextColor(15);
	SX_THELOAI_DS(l);
	for (int i = 0; i < tso_trang; i++)
	{
		int tungdo = 1;
		XOA_HIEN_THI();
		for (int j = 40 * i; j < (40 * i) + 40 && j < l.sl; j++)
			XUAT_THONGTIN_DS(*l.ds_dausach[j], tungdo++);
		gotoXY(105, 42); cout << i + 1 << "/" << tso_trang;
		ButtonNext();
		ButtonPrev();
		chay_chu(85, 44, "PRESS ANY KEY TO CONTINUE");
		char c = _getch();
		if (c == -32)
			c = _getch();
		if (c == 77)
		{
			ClearLine(85, 44);
			if (i == tso_trang - 1)
				i = -1;
		}
		else if (c == 75)
		{
			ClearLine(85, 44);
			if (i == 0)
				i = tso_trang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
		else
		{
			ClearLine(85, 44);
			break;
		}
	}
	gotoXY(100, 42); cout << "                           ";
	TextColor(7);
}



// tim kiếm đầu sách theo tên đầu sách nếu có xuất ra đầu sách <> -1 , ESC rt -2
int TIM_KIEM_DS_THEO_TEN(LIST_DS l, string temp)
{
	int kt; // biến dùng để kiểm tra có tìm được đầu sách hay ko
	int j;
	int tungdo;
	int vitri_timthay;
	int sl_sach ; // số lượng sách còn ở thư viện
	int* arr = new int[l.sl]; // mảng chứa  các đầu sách tìm thấy. dùng đê xuất sách
	int* soluongsach = new int[l.sl]; // mảng soluongsach lưu số lượng các sách của đầu sách tìm thấy
	bool KT = false;
	while (KT == false)
	{
		XOA_HIEN_THI();
		tungdo = 1, j = 0, kt = 0, vitri_timthay = 0, sl_sach = 0;
		for (int i = 0; i < l.sl; i++)
		{
			// nếu tìm thấy temp là chuỗi con của tên đầu sách
			vitri_timthay = l.ds_dausach[i]->tensach.find(temp);
			if (vitri_timthay != string::npos)
			{
				XUAT_THONGTIN_DS(*l.ds_dausach[i], tungdo++);
				sl_sach = Dem_Sach_CON_MUON_DUOC(l, l.ds_dausach[i]->ISBN);
				gotoXY(180, 0); TextColor(14); cout << "SL CON";
				gotoXY(180, tungdo - 1); TextColor(15); cout << sl_sach;
				ToMau(vitri_timthay + 55, tungdo - 1, temp, 14);
				kt++;
				arr[j] = i; // lưu đầu sách được tìm thấy
				soluongsach[j] = tong_so_sach(*l.ds_dausach[i]);
				j++;
			}
		}
		if (kt != 0)
		{
			int k = 1;
			bool check = false;
			while (check == false)
			{
				gotoXY(37, k); cout << ">>";
				gotoXY(55, k);
				ToMau(55, k, l.ds_dausach[arr[k - 1]]->tensach, 14);
				control_cursor(false);
				char c = _getch();
				gotoXY(37, k); cout << "  ";
				ToMau(55, k, l.ds_dausach[arr[k - 1]]->tensach, 15);
				TRANGTHAI tt = key(c);
				switch (tt)
				{
				case UP:
				case LEFT:
				{
					if (k == 1)
						k = j;
					else
						k--;
					break;
				}
				case DOWN:
				case RIGHT:
				{
					if (k == j)
						k = 1;
					else
						k++;
					break;
				}
				case ESC:
				{
					delete[] arr;
					delete[] soluongsach;
					return -2;
				}
				case ENTER:
				{
					check = true;
					break;
				}
				}
			}
			XOA_HIEN_THI();
			if (soluongsach[k - 1] <= 0)
			{
				BaoLoi("KHONG CO SACH");
				continue;
			}
			int tso_trang = (soluongsach[k - 1] - 1) / 40 + 1;
			int so_trang = 1;
			int tungdo1 = 1;
			NODE_DMS* p = l.ds_dausach[arr[k - 1]]->dms.pHead;
			NODE_DMS* temp[10]; // mảng con trỏ chứa tối đa 10 trang
			for (int i = 0; i < tso_trang; i++)
			{
				temp[i] = p; // lưu vị trí con trỏ p trước khi duyệt để quay lại
				while (p != NULL)
				{
					XOA_HIEN_THI();
					for (int j1 = 0; j1 < 40 && p != NULL; j1++)
					{
						XUAT_THONG_TIN_SACH(l.ds_dausach[arr[k - 1]]->tensach, p->data, j1 + 1);
						p = p->pNext;
					}
					gotoXY(105, 42); cout << i + 1 << "/" << tso_trang;
					ButtonNext();
					ButtonPrev();
					char c = _getch();
					if (c == -32)
						c = _getch();
					if (c == 77)
					{
						if (i == tso_trang - 1)
						{
							i = -1;
							break;
						}
						gotoXY(95, 42); cout << "                  ";
						break;
					}
					else if (c == 75)
					{
						if (i == 0) {
							i = tso_trang - 2;
							break;
						}
						p = temp[i - 1];
						i -= 2;
						gotoXY(95, 42); cout << "                   ";
						break;
					}
					else {
						i = tso_trang - 1;
						gotoXY(95, 42); cout << "             ";
						break;
					}

				}
			}
		}
		else
		{
			delete[] soluongsach;
			delete[] arr;
			return -1;
		}
	}
}

// tìm kiếm đầu sách theo mã đầu sách nêu có trả về vị trí <> -1
int TIM_KIEM_DS_THEO_MA(LIST_DS l, string ma)
{
	for (int i = 0; i < l.sl; i++)
	{
		if (l.ds_dausach[i]->ISBN == ma)
			return i;
	}
	return -1;
}

// sửa đầu sách theo mã đầu sách. Nếu sửa thành công return 1 <> -1 ;ESC return -2
int HIEU_CHINH_DS(LIST_DS& l)
{
	int k = 0;
	string isbn;
	int i = 0;
	xoa_hien_thi_Box_NhapDS();
	do
	{
		XUAT_DS_DAUSACH(l);
		isbn = "";
		Box_NHAP("NHAP MA ISBN");
		k = nhap_ki_tu(isbn, 3);
		Xoa_hien_thi_Box_NHAP();
		if (k == -1) return -2;
		i = TIM_KIEM_DS_THEO_MA(l, isbn);
		if (i == -1) {
			BaoLoi("MA SACH KHONG DUNG");
			continue;
		}
		XOA_HIEN_THI();
		break;
	} while (1);
	Box_NhapDS();
	dausach data;
	gotoXY(boxx + 8, boxy + 2);
	cout << l.ds_dausach[i]->ISBN;

	data.tensach = l.ds_dausach[i]->tensach;
	gotoXY(boxx + 12, boxy + 4);
	cout << data.tensach;
	k = nhap_ki_tu(data.tensach, 1);
	if (k == -1) // ESC
		return -2;

	data.sotrang = l.ds_dausach[i]->sotrang;
	gotoXY(boxx + 12, boxy + 6);
	cout << data.sotrang;
	k = nhap_so_nguyen(data.sotrang);
	if (k == -1) // ESC
		return -2;

	data.tacgia = l.ds_dausach[i]->tacgia;
	gotoXY(boxx + 11, boxy + 8);
	cout << data.tacgia;
	k = nhap_ki_tu(data.tacgia, 0);
	if (k == -1) // ESC
		return -2;

	data.namxuatban = l.ds_dausach[i]->namxuatban;
	gotoXY(boxx + 10, boxy + 10);
	cout << data.namxuatban;
	k = nhap_so_nguyen(data.namxuatban);
	if (k == -1) // ESC
		return -2;

	data.theloai = l.ds_dausach[i]->theloai;
	gotoXY(boxx + 12, boxy + 12);
	cout << data.theloai;
	k = nhap_ki_tu(data.theloai, 0);
	if (k == -1) // ESC
		return -2;

	l.ds_dausach[i]->tensach = data.tensach;
	l.ds_dausach[i]->sotrang = data.sotrang;
	l.ds_dausach[i]->tacgia = data.tacgia;
	l.ds_dausach[i]->namxuatban = data.namxuatban;
	l.ds_dausach[i]->theloai = data.theloai;
	return 1;
}


// =========================================Danh muc sach=====================================
// tạo 1 node mới 
NODE_DMS* TAO_NODE_SACH(danhmucsach& x)
{
	node_danhmucsach* p = new node_danhmucsach;
	if (p == NULL)

		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
// Thêm sách nếu thêm thành công rt 1, ESC rt -1;
int THEM_SACH(LIST_DS& l)
{
	int k = 0;
	string isbn;
	int i = 0;
	int n = 0;
	xoa_hien_thi_Box_NhapSach();
	do
	{
		XUAT_DS_DAUSACH(l);
		isbn = "";
		Box_NHAP("NHAP MA ISBN");
		k = nhap_ki_tu(isbn, 3);
		Xoa_hien_thi_Box_NHAP();
		if (k == -1) // ESC
			return -1;
		i = TIM_KIEM_DS_THEO_MA(l, isbn);
		if (i == -1) {
			BaoLoi("MA ISBN KHONG DUNG");
			continue;
		}
		Box_NHAP("SL SACH CAN THEM");
		k = nhap_so_nguyen(n);
		Xoa_hien_thi_Box_NHAP();
		if (k == -1)
			return -1;
		break;
	} while (1);
	string vitri = "";
	danhmucsach x;
	// lược bỏ phần mã đầu sách
	int q = 0;
	if (l.ds_dausach[i]->dms.pHead != NULL)
	{
		vitri = l.ds_dausach[i]->dms.pTail->data.vitri; // lấy vị trí cuối cùng của sách đã tồn tại
		int pos = l.ds_dausach[i]->dms.pTail->data.masach.find("-"); // lấy vị trí của kí tự - trong chuỗi
		string str = l.ds_dausach[i]->dms.pTail->data.masach.substr(pos + 1); //  lấy chuỗi con của l.ds_dausach[i]->dms.pTail->data.masach bắt đầu sau kí tự -
		q = chuoi_sang_so(str);
	}
	XOA_HIEN_THI();
	Box_NhapSach();
	for (int j = 0; j < n; j++)
	{
		if (q == 0)
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(j + 1);
		else
			x.masach = l.ds_dausach[i]->ISBN + "-" + so_sang_chuoi(q + j + 1);

		gotoXY(boxx + 12, boxy + 2);
		cout << x.masach;
		gotoXY(boxx + 11, boxy + 4);
		cout << vitri;
		k = nhap_ki_tu(vitri, 1);
		if (k == -1) // ESC
			return -1;
		x.vitri = vitri;
		x.trangthai = 0; // mặc định sách có thể mượn được
		AddTail_DMS(l.ds_dausach[i]->dms, TAO_NODE_SACH(x));
	}
	return 1;
}

// thêm sách vào danh sách sách để quản lí
void AddTail_DMS(LIST_DMS& l, NODE_DMS* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// xuất 1 cuốn sách
void XUAT_THONG_TIN_SACH(string ten_sach, danhmucsach a, int tungdo)
{
	int x = whereX();
	int y = whereY();
	TextColor(14);
	gotoXY(40, 0);
	cout << "Ma Sach";
	gotoXY(60, 0);
	cout << "Ten Sach";
	gotoXY(95, 0);
	cout << "Trang Thai";
	gotoXY(110, 0);
	cout << "Vi Tri";
	TextColor(15);
	gotoXY(40, tungdo);
	cout << a.masach;
	gotoXY(60, tungdo);
	cout << ten_sach;
	gotoXY(95, tungdo);
	cout << a.trangthai;
	gotoXY(110, tungdo);
	cout << a.vitri;
	gotoXY(x, y);
	TextColor(7);
}


// tìm kiếm sách theo mã sách nếu có trả về  vị trí node trong ds <>  NULL
NODE_DMS* TIM_KIEM_SACH(LIST_DS l, string ma_sach)
{
	string isbn = tach_ma_sach(ma_sach);
	int i = TIM_KIEM_DS_THEO_MA(l, isbn);
	if(i!=-1)
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			if (p->data.masach == ma_sach)
				return p;
		}
	return NULL;
}


// =========================================== Muon Tra=====================================
// tạo 1 node mượn trả 
NODE_MT* TAO_NODE_MT(muontra x)
{
	NODE_MT* p = new NODE_MT;
	p->data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

// lập phiếu mượn sách
void NHAP_THONGTIN_MT(muontra& x)
{
	// phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
	thoi_gian_thuc(x.ngaymuon);
	x.ngaytra.ngay = 0;
	x.ngaytra.thang = 0;
	x.ngaytra.nam = 0;
	x.trangthai = 0; // trạng thái mặc định =0 độc giả đang mượn cuốn sách
}

// in thong tin của 1 phiếu mượn trả
void XUAT_THONG_TIN_MT(muontra a, string ten_sach, int tungdo)
{
	TextColor(15);
	int x = whereX();
	int y = whereY();
	gotoXY(45, 0);
	cout << "Ma Sach";
	gotoXY(60, 0);
	cout << "Ten Sach";
	gotoXY(100, 0);
	cout << "Ngay Muon";
	gotoXY(130, 0);
	cout << "Ngay Tra";
	gotoXY(160, 0);
	cout << "Trang Thai";
	gotoXY(45, tungdo);
	cout << a.masach;
	gotoXY(60, tungdo);
	cout << ten_sach;
	gotoXY(100, tungdo);
	cout << a.ngaymuon.ngay << "/" << a.ngaymuon.thang << "/" << a.ngaymuon.nam;
	gotoXY(130, tungdo);
	cout << a.ngaytra.ngay << "/" << a.ngaytra.thang << "/" << a.ngaytra.nam;
	gotoXY(160, tungdo);
	if (a.trangthai == 0)
		cout << "DANG MUON";
	else if (a.trangthai == 1)
		cout << "DA TRA";
	else
		cout << "LAM MAT";
	gotoXY(x, y);
	TextColor(7);
}

// thêm phiếu vào danh sách để quản lí
void AddTail_MT(LIST_MT& l, NODE_MT* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

// hàm có chức năng xuất các sách đang mượn của 1 độc giả nếu có sách mượn rt 1 <> 0
int XUAT_SACH_MUON(TREE t, LIST_DS l)
{
	int kt = 0; // kiểm tra nếu độc giả có sách đang mượn thì tăng. nếu không có sách đang mượn =0
	int tungdo = 0;
	for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
	{
		for (int i = 0; i < l.sl; i++)
		{
			for (NODE_DMS* k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
			{
				if (p->data.masach == k->data.masach)
				{
					if (p->data.trangthai == 0 || p->data.trangthai == 2)
					{
						kt++;
						XUAT_THONG_TIN_MT(p->data, l.ds_dausach[i]->tensach, ++tungdo);
					}
				}
			}
		}
	}
	if (kt == 0) // độc giả không mượn sách
		return 0;
	return 1;
}




void MUON_SACH(TREE& t, LIST_DS& l)
{
	int k1 = 0; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE p = NULL;// lưu  độc giả tìm được
	int ma_doc_gia;
	int dem; // dem sách độc giả đang mượn
	while (1)
	{
		dem = 0;
		ma_doc_gia = 0;
		XUAT_DS_DG(t, tungdo);
		gotoXY(99, 42); cout << "                    ";
		tungdo = 0;
		Box_NHAP("NHAP MA DG");
		k1 = nhap_so_nguyen(ma_doc_gia);
		Xoa_hien_thi_Box_NHAP();
		if (k1 == -1) return;
		p = TIM_KIEM_DG_MA(t, ma_doc_gia);
		if (p == NULL)
		{
			BaoLoi("MA DOC GIA KHONG DUNG");
			continue;
		}
		XOA_HIEN_THI();
		if (p->data.trangthaithe == 0) // thẻ bị khóa
		{
			BaoLoi("THE DOC GIA BI KHOA.TRA SACH DE TIEP TUC");
			continue;
		}
		if (Dem_SN_QUAHAN(p) == true) // độc giả mượn sách quá hạn
		{
			BaoLoi("DOC GIA MUON SACH QUA HAN. KHONG THE MUON");
			continue;
		}
		// kiểm tra số lượng sách độc giả đã mượn nếu > 3 không mượn được
		dem = DEM_SACH_DG_MUON(p);
		if (dem >= 3)
		{
			BaoLoi("! DOC GIA MUON QUA 3 CUON. !TRA SACH DE MUON THEM");
			continue;
		}
		NODE_DMS* k = NULL;
		string ma_sach;
		string ma_dau_sach;
		bool check = false; // kiem tra co tim thay ma sach hay ko
		int i = 0;
		gotoXY(99, 42); cout << "                         ";
		while (1)
		{
			if (dem >= 3) break;
			XUAT_SACH_MUON(p, l);
			ma_sach = "";
			Box_NHAP("NHAP MA SACH");
			k1 = nhap_ki_tu(ma_sach, 1);
			XOA_HIEN_THI();
			Xoa_hien_thi_Box_NHAP();
			if (k1 == -1) // ESC
				return;
			ma_dau_sach = tach_ma_sach(ma_sach);
			i = TIM_KIEM_DS_THEO_MA(l, ma_dau_sach);
			if (i == -1) // khoong tim thay
			{
				BaoLoi("MA SACH KHONG DUNG");
				continue;
			}
			else // tim thay lay vi tri cua i
			{
				if (KT_SACH_DG_MUON(p, ma_sach) == true) // ĐANG MƯỢN SÁCH THUỘC ĐS TƯƠNG TỰ
				{
					BaoLoi("DOC GIA DANG MUON SACH NAY");
					continue;
				}
				for (k = l.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.masach == ma_sach)
					{
						if (k->data.trangthai == 0)
						{
							dem++;
							check = true; // danh dau tim thay sach
							k->data.trangthai = 1; // cap nhat sach co nguoi muon
							break;
						}
						else if (k->data.trangthai == 1)
						{
							BaoLoi("SACH DA CO NGUOI MUON");
							break;
						}
						else if (k->data.trangthai == 2)
						{
							BaoLoi("SACH DA THANH LI");
							break;
						}
					}
				}
				if (check == true)
				{
					// thêm vào danh sách mượn trả
					muontra x;
					x.masach = ma_sach;
					l.ds_dausach[i]->soluongmuon++; // tăng số lượng mượn cuốn sách
					NHAP_THONGTIN_MT(x);
					AddTail_MT(p->data.mt, TAO_NODE_MT(x));
					BaoLoi("MUON THANH CONG");
					GhiFileDS(l);
					GHI_FILE_DS_DG(t);
				}

			}
		}
	}
}
void TRA_SACH(TREE& t, LIST_DS& l)
{
	TREE p = NULL;
	int tungdo;
	int ma;
	int k1;
	do
	{
		tungdo = 0;
		ma = 0;
		k1 = 0;
		XUAT_DS_DG(t, tungdo);
		Box_NHAP("NHAP MA DG");
		k1 = nhap_so_nguyen(ma);
		Xoa_hien_thi_Box_NHAP();
		if (k1 == -1) // ESC
			return;

		p = TIM_KIEM_DG_MA(t, ma);
		XOA_HIEN_THI();
		if (p == NULL)
		{
			BaoLoi("MA DOC GIA KHONG DUNG");
			continue;
		}
		else
		{
			do
			{
				int n = DEM_SACH_DG_MUON(p);
				muontra* arr = new muontra[n];
				int j = 0;
				bool check = false; // check xem doc gia co muon sach hay khong
				for (NODE_MT* q = p->data.mt.pHead; q != NULL; q = q->pNext)
				{
					if (q->data.trangthai == 0 || q->data.trangthai == 2)
					{
						check = true;
						NODE_DMS* dms = TIM_KIEM_SACH(l, q->data.masach);
						string temp = tach_ma_sach(dms->data.masach);
						int i = TIM_KIEM_DS_THEO_MA(l, temp);
						if (i != -1)
						{
							XUAT_THONG_TIN_MT(q->data, l.ds_dausach[i]->tensach, j + 1);
							arr[j++] = q->data;
						}
					}
				}
				if (check == true)
				{
					control_cursor(false);
					int k = 1;
					bool check = false;
					while (check == false)
					{
						ToMau(45, k, arr[k - 1].masach, 14);
						gotoXY(59, k);
						char c = _getch();
						ToMau(45, k, arr[k - 1].masach, 15);
						TRANGTHAI tt = key(c);
						switch (tt)
						{
						case UP:
						case LEFT:
						{
							if (k == 1)
								k = j;
							else
								k--;
							break;
						}
						case DOWN:
						case RIGHT:
						{
							if (k == j)
								k = 1;
							else
								k++;
							break;
						}
						case ESC:
						{
							delete[] arr;
							return;
						}
						case ENTER:
						{
							if (xac_nhan(80, 15, "XAC NHAN TRA SACH ", arr[k-1].masach) == true)
								check = true;
							else check = false;
							break;
						}
						}
					}
					int dem = 0; // bien kiem tra so sach doc gia da lam mat =0 mo the
					Date n1;
					thoi_gian_thuc(n1);
					NODE_DMS* dms1 = TIM_KIEM_SACH(l, arr[k - 1].masach);
					for (NODE_MT* MT = p->data.mt.pHead; MT != NULL; MT = MT->pNext)
					{
						if (MT->data.masach == dms1->data.masach)
						{
							dms1->data.trangthai = 0; // cap nhat sach co the muon
							MT->data.trangthai = 1; // cap nhat lai doc gia da tra sach
							MT->data.ngaytra = n1;
						}
						if (MT->data.trangthai == 2) dem++;
					}
					if (dem != 0) // còn sách làm mất -> khóa thẻ
						p->data.trangthaithe = 0;
					else
						p->data.trangthaithe = 1; // mở thẻ
					BaoLoi("TRA SACH THANH CONG");
					delete[] arr;
					XOA_HIEN_THI();
					GHI_FILE_DS_DG(t);
					GhiFileDS(l);
				}
				else
				{
					BaoLoi("DOC GIA KHONG MUON SACH");
					break;
				}

			} while (1);
		}
	} while (1);
}
// ========================================= Qua Han =============================
void CAY_SANG_MANG_QUAHAN(TREE t, quahan* arr,int& index)
{
	int temp = 0;
	if (t)
	{
		CAY_SANG_MANG_QUAHAN(t->pLeft, arr,index);
		for (NODE_MT* p = t->data.mt.pHead; p != NULL; p = p->pNext)
		{
			if (p->data.trangthai == 0 || p->data.trangthai == 2)
			{
				temp = tinh_so_ngay(p->data.ngaymuon);
				if (temp >= 7)
				{
					arr[index].ma_doc_gia = t->data.mathe;
					arr[index].ma_sach = p->data.masach;
					arr[index].so_ngay_quahan = temp;
					index++;
				}
			}
		}
		CAY_SANG_MANG_QUAHAN(t->pRight, arr,index);
	}
}
// in ra danh sách các độc giả quá hạn
void DS_QUAHAN(TREE t)
{
	int n1 = SoluongDG(t);
	quahan* arr = new quahan[n1];
	int n = 0;
	CAY_SANG_MANG_QUAHAN(t, arr,n);
	quahan temp;
	// sap xep giam dan ds qua han
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].so_ngay_quahan < arr[j].so_ngay_quahan)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	bool check = false;
	TREE p = NULL;
	NODE_MT* q = NULL;
	// xuat ds qua han theo thu tu giam dan
	for (int k = 0; k < n; k++)
	{
		p = TIM_KIEM_DG_MA(t, arr[k].ma_doc_gia);
		q = p->data.mt.pHead;
		while (q != NULL)
		{
			if (q->data.masach == arr[k].ma_sach) break;
			q = q->pNext;
		}
		check = true;
		TextColor(15);
		gotoXY(45, 0);
		cout << "MA THE";
		gotoXY(65, 0);
		cout << "HO";
		gotoXY(85, 0);
		cout << "TEN";
		gotoXY(100, 0);
		cout << "PHAI";
		gotoXY(120, 0);
		cout << "MA SACH";
		gotoXY(140, 0);
		cout << "NGAY MUON";
		gotoXY(165, 0);
		cout << "SO NGAY QH";
		gotoXY(45, k + 1);
		cout << arr[k].ma_doc_gia;
		gotoXY(65, k + 1);
		cout << p->data.ho;
		gotoXY(85, k + 1);
		cout << p->data.ten;
		gotoXY(100, k + 1);
		cout << p->data.phai;
		gotoXY(120, k + 1);
		cout << arr[k].ma_sach;
		gotoXY(140, k + 1);
		cout << q->data.ngaymuon.ngay << "/" << q->data.ngaymuon.thang << "/" << q->data.ngaymuon.nam;
		gotoXY(170, k + 1);
		cout << arr[k].so_ngay_quahan;
		TextColor(7);
	}
	if (check == false)
		BaoLoi("DANH SACH TRONG");
	else
		_getch();
	delete[] arr;
}

// =================== 10 sách có lượt mượn nhiều nhất ====================
void top10sach(LIST_DS l)
{
	// có thể dùng heapsort lấy ra top 10 nhưng không thay đổi vị trí
	// hoặc dùng mảng temp chứa mã sách và số lượng mượn 
	dausach* temp = NULL;
	// sắp xếp theo thứ tự giảm dần top 10 sách
	for (int i = 0; i < l.sl - 1; i++)
	{
		for (int j = i + 1; j < l.sl; j++)
		{
			if (l.ds_dausach[i]->soluongmuon < l.ds_dausach[j]->soluongmuon)
			{
				temp = l.ds_dausach[i];
				l.ds_dausach[i] = l.ds_dausach[j];
				l.ds_dausach[j] = temp;
			}

		}
	}
	for (int k = 0; k < l.sl && k < 10; k++)
	{
		XUAT_THONGTIN_DS(*l.ds_dausach[k], k + 1);
		gotoXY(175, 0); cout << "                  ";
		gotoXY(175, 0); TextColor(14); cout << "SO LAN MUON";
		gotoXY(180, k + 1); cout << "     ";
		gotoXY(180, k + 1); TextColor(15); cout << l.ds_dausach[k]->soluongmuon;
	}
}