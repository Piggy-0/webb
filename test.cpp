#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define ESC 27 
using namespace std;

struct Mon_CNTT {  
    char id[10];
    char name[50];	
    int so_tin_chi;
    int rate_qua_trinh;
    int rate_thi;
};

void menu();
void nhapDanhSachMon(vector<Mon_CNTT>& array,int n);
struct Mon_CNTT nhapMon();
int ds_Mon_Hoc_Theo_Tc(vector<Mon_CNTT> array,int sotinchi);
void in_Mang(vector<Mon_CNTT> array);
void in_Mon(struct Mon_CNTT mon);
void ghi_File(vector<Mon_CNTT>& array);
void doc_File(vector<Mon_CNTT>& array);

int main()
{
	vector<Mon_CNTT> array;
	int chon;
	do {
		menu();
		cout << "chon: ";
		cin >> chon;
		if(chon == ESC) break;
		switch (chon)
		{
			case 1: {
				int n;
				cout << "Nhap so luong mon: ";
				cin >> n;
				nhapDanhSachMon(array, n);
				break;
			}
			case 2: {
				in_Mang(array);
				break;
			}
			case 3: {
				ghi_File(array);
				break;
			}
			case 4: {
				doc_File(array);
				break;
			}
			case 5: {
				int sotinchi;
				cout << "Nhap so tin chi: ";
				cin >> sotinchi;
				
				ds_Mon_Hoc_Theo_Tc(array,sotinchi);
				in_Mang(array);
				break;
			}
			case 0: {
				return 0;
			}
			default: {
				cout << "!!!!<<< NHAP SAI >>>!!!!";
				break;
			}
		}
		cout << ">>>ENTER DE THOAT!!!<<<";
		system("pause");
		system("cls");
	} while (chon != ESC);
	return 0;
}

void menu()
{
	cout << "=======MENU=======" << endl;
	cout << "(1) Nhap danh sach mon hoc" << endl;
	cout << "(2) Hien thi tat ca cac mon hoc" << endl;
	cout << "(3) Luu danh sach mon hoc" << endl;
	cout << "(4) Doc danh sach hoc sinh" << endl;
	cout << "(5) Liet ke cac mon hoc theo tin chi" << endl;
	cout << "(0) ESC" << endl;
}

void nhapDanhSachMon(vector<Mon_CNTT>& array,int n)
{
	cout << "Nhap danh sach mon" << endl;
	for (int i=0;i<n;i++)
	{
		cout << "Nhap mon thu " << i << endl;
		array.push_back(nhapMon());
	}
}

struct Mon_CNTT nhapMon()
{
	Mon_CNTT mon;
	cout << "ID: ";
	cin >> mon.id;
	cout << "Name: ";
	cin >> mon.name;
	fflush(stdin);
	cout << "So tin chi: ";
	cin >> mon.so_tin_chi;
	do
	{
		cout << "Ti le qua trinh(0->100): ";
		cin >> mon.rate_qua_trinh;
		if(mon.rate_qua_trinh >= 0 and mon.rate_qua_trinh <= 100)
		{
			mon.rate_thi = 100 - mon.rate_qua_trinh;
			break;
		}
		cout << "Nhap sai!!!";
	}
	while(true);
	return mon;
}
int ds_Mon_Hoc_Theo_Tc(vector<Mon_CNTT> array,int sotinchi){
	vector<Mon_CNTT> array_1;
	for(int i=0;i<array.size();i++){
		if(array[i].so_tin_chi == sotinchi){
			array_1.push_back(array[i]);
		}
	}
}



void in_Mang(vector<Mon_CNTT> array)
{
	cout << "ID | Name | So tin chi | Ti le diem qua trinh | Ti le diem thi" << endl;
	for(int i = 0;i<array.size();i++)
	{
		in_Mon(array[i]);
	}
}

void in_Mon(struct Mon_CNTT mon)
{
	cout << mon.id << " " << mon.name << " " << mon.so_tin_chi << " " << mon.rate_qua_trinh << " " << mon.rate_thi <<  endl;
}


void ghi_File(vector<Mon_CNTT>& array){
	ofstream output("DATA.INP");
	output << array.size() << endl;
	for (int i = 0; i < array.size(); i++)
	{
		output << array[i].id << "\t" << array[i].name << "\t" << array[i].so_tin_chi << "\t" << array[i].rate_qua_trinh << "\t" << array[i].rate_thi << "\t" << endl;
	}
	output.close();
}
void doc_File(vector<Mon_CNTT>& array){	
	ifstream input("DATA.INP");
	int sl;
	input >> sl;
	for (int i = 0; i < sl; i++)
	{
		input >> array[i].id;
		input >> array[i].name;
		input >> array[i].so_tin_chi;
		input >> array[i].rate_qua_trinh;
		input >> array[i].rate_thi;
	}
	input.close();
}

