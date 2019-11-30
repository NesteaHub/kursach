
// MFCApplication1Dlg.cpp: д ©« аҐ «Ё§ жЁЁ
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

struct stud {
	stud *pred;
	stud *next;
	CString f;
	CString n;
	CString o;
	CString fakul;
	CString grou;
	CString no;
	CTime dr;
	CTime dp;
	CString predmets[9][10];
	CString ocenki[9][10];
	int i_ses;
	int n_pred;
};

stud *student = new stud;
bool b = FALSE;
int n_stud = 0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, fam(_T(""))
	, name(_T(""))
	, otch(_T(""))
	, fak(_T(""))
	, group(_T(""))
	, num(_T(""))
	, pred(_T(""))
	, del(_T(""))
	, vse(_T(""))
	, redach(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, CB1);
	DDX_Control(pDX, IDC_COMBO2, CB2);
	DDX_Control(pDX, IDC_COMBO3, CB3);
	DDX_Text(pDX, IDC_EDIT1, fam);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, otch);
	DDX_Text(pDX, IDC_EDIT4, fak);
	DDX_Text(pDX, IDC_EDIT5, group);
	DDX_Text(pDX, IDC_EDIT6, num);
	DDX_Text(pDX, IDC_EDIT7, pred);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dateR);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, dateP);
	DDX_Control(pDX, IDC_BUTTON6, but1);
	DDX_Control(pDX, IDC_BUTTON2, but2);
	DDX_Control(pDX, IDC_BUTTON1, but3);
	DDX_Text(pDX, IDC_EDIT12, del);
	DDX_Control(pDX, IDC_LIST1, vsel);
	DDX_Control(pDX, IDC_LIST2, tril);
	DDX_Control(pDX, IDC_LIST3, horl);
	DDX_Control(pDX, IDC_LIST4, otll);
	DDX_Text(pDX, IDC_EDIT13, redach);
	DDX_Control(pDX, IDC_BUTTON5, but5);
	DDX_Control(pDX, IDC_BUTTON3, but6);
	DDX_Control(pDX, IDC_BUTTON9, but9);
	DDX_Control(pDX, IDC_BUTTON11, but11);
	DDX_Control(pDX, IDC_BUTTON12, but12);
	DDX_Control(pDX, IDC_BUTTON13, but13);
	DDX_Control(pDX, IDC_BUTTON14, but14);
	DDX_Control(pDX, IDC_BUTTON15, but15);
	DDX_Control(pDX, IDC_BUTTON16, but16);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	/////////////////////////////////////////////////////////////////////////////////////////

	CB1.AddString(L"1"); CB1.AddString(L"2"); CB1.AddString(L"3"); CB1.AddString(L"4"); CB1.AddString(L"5");
	CB1.AddString(L"6"); CB1.AddString(L"7"); CB1.AddString(L"8"); CB1.AddString(L"9");
	CB2.AddString(L"1"); CB2.AddString(L"2"); CB2.AddString(L"3"); CB2.AddString(L"4"); CB2.AddString(L"5"); 
	CB2.AddString(L"6"); CB2.AddString(L"7"); CB2.AddString(L"8"); CB2.AddString(L"9"); CB2.AddString(L"10");
	CB3.AddString(L"неуд"); CB3.AddString(L"удв"); CB3.AddString(L"хор"); CB3.AddString(L"отл"); 
	CB3.AddString(L"зач"); CB3.AddString(L"незач");
	but1.EnableWindow(false);
	but2.EnableWindow(false);
	but15.EnableWindow(false);
	but16.EnableWindow(false);
	UpdateData(false);
	student->pred = NULL;
	student->next = NULL;
	/////////////////////////////////////////////////////////////////////////////////////////

	return TRUE;  
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


char *tochar(CString str) {
	int k = str.GetLength();
	char *chr = new char[k - 1];
	for (int i = 0; i < k; i++) {
		chr[i] = str[i];
		chr[i + 1] = '\0';
	}

	return chr;
}

CTime ToCTime(char* str)
{
	int i = 0;
	int year, month, day;
	sscanf_s(str, "%d.%d.%d", &year, &month, &day);
	return CTime(year, month, day);
}

void swop(stud* a, stud* b){
	CString buf; CTime buf1;
	CString buf2[9][10];
	buf = a->f;
	a->f = b->f;
	b->f = buf;
	buf = a->n;
	a->n = b->n;
	b->n = buf;
	buf = a->o;
	a->o = b->o;
	b->o = buf;
	buf = a->fakul;
	a->fakul = b->fakul;
	b->fakul = buf;
	buf = a->grou;
	a->grou = b->grou;
	b->grou = buf;
	buf = a->no;
	a->no = b->no;
	b->no = buf;
	buf1 = a->dr;
	a->dr = b->dr;
	b->dr = buf1;
	buf1 = a->dp;
	a->dp = b->dp;
	b->dp = buf1;
	for (int i = 0; i<9; i++) {
		for (int j = 0; j < 10; j++) {
			buf2[i][j] = a->predmets[i][j];
			a->predmets[i][j] = b->predmets[i][j];
			b->predmets[i][j] = buf2[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			buf2[i][j] = a->ocenki[i][j];
			a->ocenki[i][j] = b->ocenki[i][j];
			b->ocenki[i][j] = buf2[i][j];
		}
	}
}

void sortir() {
	while (student->pred != NULL)
		student = student->pred;
	stud *tmp = new stud;
	while (student->next->next != NULL) {
		tmp = student->next;
		while (tmp->next != NULL) {
			if (student->f > tmp->f)
				swop(student, tmp);
			tmp = tmp->next;
		}
		student = student->next;
	}
	tmp = student->next;
	if (student->f > tmp->f)
		swop(student, tmp);
}

void otchislen() {
	if ((student->next != NULL) && (student->pred == NULL))
	{
		stud* tmp = new stud;
		tmp = student;
		student = student->next;
		student->pred = NULL;
		delete tmp;
		n_stud--;
	}
	else if ((student->next == NULL) && (student->pred != NULL))
	{
		stud* tmp = new stud;
		tmp = student;
		student = student->pred;
		student->next = NULL;
		delete tmp;
		n_stud--;
	}
	else if ((student->next != NULL) && (student->pred != NULL))
	{
		stud* tmp = new stud;
		tmp = student;
		student->pred->next = student->next;
		student->next->pred = student->pred;
		student = student->next;
		delete tmp;
		n_stud--;
	}
	else if ((student->next == NULL) && (student->pred == NULL))
	{
		delete student;
		stud *student = new stud;
		b = FALSE;
		student->pred = NULL;
		student->next = NULL;
		n_stud = 0;
	}
}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	CTime t = CTime::GetCurrentTime();
	CTime time, time2;
	dateR.GetTime(time);
	dateP.GetTime(time2);
	int now = t.GetTime();
	 if ((time.GetYear() <= time2.GetYear() - 16) && (time2 <= now)) {
		if (b == TRUE)
		{
			student->next = new stud;
			student->next->pred = student;
			student->next->next = NULL;
			student = student->next;
		}
		else
			b = TRUE;
		student->f = fam;
		student->n = name;
		student->o = otch;
		student->fakul = fak;
		student->grou = group;
		student->no = num;

		dateR.GetTime(student->dr);
		dateP.GetTime(student->dp);
		n_stud++;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				student->predmets[i][j] = "-";
				student->ocenki[i][j] = "-";
			}
		}
		but1.EnableWindow(true);
		but3.EnableWindow(false);
		UpdateData(true);
		UpdateData(false);
	}
	else MessageBox(L"wrong date");
	 if (student != NULL) {
		 if (student->pred != NULL) {
			 CString no = student->no;
			 BOOL b1 = FALSE;
			 while (student->pred != NULL) {
				 student = student->pred;
			 }
			 while (student->next != NULL) {
				 if (student->no == no) {
					 b1 = TRUE;
					 MessageBox(L"takoi nomer uje est'");
					 but1.EnableWindow(false);
					 but3.EnableWindow(true);
					 break;
				 }
				 student = student->next;
			 }
			 while (student->next != NULL) {
				 student = student->next;
			 }
			 if (b1) {
				 otchislen();
			 }
		 }
	 }
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	UpdateData(true);
	student->i_ses = CB1.GetCurSel();
	student->n_pred = CB2.GetCurSel();

	but1.EnableWindow(false);
	but2.EnableWindow(true);
	but3.EnableWindow(false);
	UpdateData(false);
}


int kolvo = 0;
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	if (kolvo <= student->n_pred) {
		CString tmp;
		UpdateData(true);

		int o = CB3.GetCurSel() + 1;
		if (o == 1) tmp = "neud";
		if (o == 2) tmp = "udv";
		if (o == 3) tmp = "hor";
		if (o == 4) tmp = "otl";
		if (o == 5) tmp = "zach";
		if (o == 6) tmp = "nezach";

		student->predmets[student->i_ses][kolvo] = pred;
		student->ocenki[student->i_ses][kolvo] = tmp;
		kolvo++;
		pred = "";
		if (kolvo > student->n_pred) {
			MessageBox(L"nugnoe kol-vo predmetov vvedeno");
			but1.EnableWindow(true);
			but2.EnableWindow(false);
			but3.EnableWindow(true);
			kolvo = 0;
		}
	}
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	fam = "";
	name = "";
	otch = "";
	fak = "";
	group = "";
	num = "";
	pred = "";
	del = "";
	redach = "";
	tril.ResetContent();
	horl.ResetContent();
	otll.ResetContent();
	vsel.ResetContent();
	but3.EnableWindow(true);
	but1.EnableWindow(false);
	but2.EnableWindow(false);
	UpdateData(false);
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	UpdateData(true);
	while (student->pred != NULL) {
		student = student->pred;
	}
	for (int i = 0; i <= n_stud; i++) {			
		if (student->no == del) {
			otchislen();
			MessageBox(L"gotovo");
			break;
		}
		else if (student->next != NULL)
		{
			student = student->next;
		}
		if ((student->next == NULL) && (student->no != del))
		{
			MessageBox(L"net takogo");
		}
	} 
	del = "";
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	sortir();
	tril.ResetContent();
	horl.ResetContent();
	otll.ResetContent();
	bool o2 = false;
	bool o3 = false;
	bool o4 = false;
	bool o5 = false;
	CString j1, dr1, dp1;
	while (student->pred != NULL) {
		student = student->pred;
	}
	while (student != NULL) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if ((student->ocenki[j][k] == "nezach") || (student->ocenki[j][k] == "neud"))
					o2 = true;
				if (student->ocenki[j][k] == "udv")
					o3 = true;
				if (student->ocenki[j][k] == "hor")
					o4 = true;
				if (student->ocenki[j][k] == "otl")
					o5 = true;
			}
		}
		if (o2 == true) {
			o2 = false; o3 = false; o4 = false; o5 = false;
		}
		else if ((o2 == false) && (o3 == true)) {
			dr1 = student->dr.Format("%d.%m.%Y");
			dp1 = student->dp.Format("%d.%m.%Y");

			tril.AddString((LPCTSTR)student->f);
			tril.AddString((LPCTSTR)student->n);
			tril.AddString((LPCTSTR)student->o);
			tril.AddString((LPCTSTR)student->fakul);
			tril.AddString((LPCTSTR)student->grou);
			tril.AddString((LPCTSTR)student->no);
			tril.AddString((LPCTSTR)dr1);
			tril.AddString((LPCTSTR)dp1);
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 10; k++) {
					if (student->predmets[j][k] != "-")
					{
						tril.AddString(L"№sessii: ");
						j1.Format(_T("%i"), j + 1);
						tril.AddString((LPCTSTR)j1);
						tril.AddString(L"-----");
						tril.AddString((LPCTSTR)student->predmets[j][k]);
					}
					if (student->ocenki[j][k] != "-")
					{
						tril.AddString((LPCTSTR)student->ocenki[j][k]);
						tril.AddString(L"-----");
					}
				}
			}
			tril.AddString(L"**********");
			o3 = false; o4 = false; o5 = false;
		}
		else if ((o4 == true) && (o2 == false) && (o3 == false)) {
			dr1 = student->dr.Format("%d.%m.%Y");
			dp1 = student->dp.Format("%d.%m.%Y");

			horl.AddString((LPCTSTR)student->f);
			horl.AddString((LPCTSTR)student->n);
			horl.AddString((LPCTSTR)student->o);
			horl.AddString((LPCTSTR)student->fakul);
			horl.AddString((LPCTSTR)student->grou);
			horl.AddString((LPCTSTR)student->no);
			horl.AddString((LPCTSTR)dr1);
			horl.AddString((LPCTSTR)dp1);
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 10; k++) {
					if (student->predmets[j][k] != "-")
					{
						horl.AddString(L"№sessii: ");
						j1.Format(_T("%i"), j + 1);
						horl.AddString((LPCTSTR)j1);
						horl.AddString(L"-----");
						horl.AddString((LPCTSTR)student->predmets[j][k]);
					}
					if (student->ocenki[j][k] != "-")
					{
						horl.AddString((LPCTSTR)student->ocenki[j][k]);
						horl.AddString(L"-----");
					}
				}
			}
			horl.AddString(L"**********");
			o4 = false; o5 = false;
		}
		else if ((o5 == true) && (o4 == false) && (o2 == false) && (o3 == false)) {
			dr1 = student->dr.Format("%d.%m.%Y");
			dp1 = student->dp.Format("%d.%m.%Y");

			otll.AddString((LPCTSTR)student->f);
			otll.AddString((LPCTSTR)student->n);
			otll.AddString((LPCTSTR)student->o);
			otll.AddString((LPCTSTR)student->fakul);
			otll.AddString((LPCTSTR)student->grou);
			otll.AddString((LPCTSTR)student->no);
			otll.AddString((LPCTSTR)dr1);
			otll.AddString((LPCTSTR)dp1);
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 10; k++) {
					if (student->predmets[j][k] != "-")
					{
						otll.AddString(L"№sessii: ");
						j1.Format(_T("%i"), j + 1);
						otll.AddString((LPCTSTR)j1);
						otll.AddString(L"-----");
						otll.AddString((LPCTSTR)student->predmets[j][k]);
					}
					if (student->ocenki[j][k] != "-")
					{
						otll.AddString((LPCTSTR)student->ocenki[j][k]);
						otll.AddString(L"-----");
					}
				}
			}
			otll.AddString(L"**********");
			o5 = false;
		}	
		if (student->next != NULL)
			student = student->next;
		else break;
	}
	CString *buf = new CString[255];
	fstream trif("3.txt", ios_base::trunc);
	fstream horf("4.txt", ios_base::trunc);
	fstream otlf("5.txt", ios_base::trunc);
	for (int i = 0; i < tril.GetCount(); i++) {
		tril.GetText(i, buf[i]);
		trif << tochar(buf[i]) << endl;
	}
	for (int i = 0; i < horl.GetCount(); i++) {
		horl.GetText(i, buf[i]);
		horf << tochar(buf[i]) << endl;
	}
	for (int i = 0; i < otll.GetCount(); i++) {
		otll.GetText(i, buf[i]);
		otlf << tochar(buf[i]) << endl;
	}
}


void CMFCApplication1Dlg::OnBnClickedButton11()
{
	vsel.ResetContent();
	CString j1, dr1, dp1;
	
	UpdateData(true); 
		while (student->pred != NULL) {
			student = student->pred;
		}

		while (student != NULL) {
			dr1 = student->dr.Format("%d.%m.%Y");
			dp1 = student->dp.Format("%d.%m.%Y");

			vsel.AddString((LPCTSTR)student->f);
			vsel.AddString((LPCTSTR)student->n);
			vsel.AddString((LPCTSTR)student->o);
			vsel.AddString((LPCTSTR)student->fakul);
			vsel.AddString((LPCTSTR)student->grou);
			vsel.AddString((LPCTSTR)student->no);
			vsel.AddString((LPCTSTR)dr1);
			vsel.AddString((LPCTSTR)dp1);
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 10; k++) {
					if ((student->predmets[j][k] != "-")&&(student->predmets[j][k] != " "))
					{
						vsel.AddString(L"№sessii: ");
						j1.Format(_T("%i"), j + 1);
						vsel.AddString((LPCTSTR)j1);
						vsel.AddString(L"-----");
						vsel.AddString((LPCTSTR)student->predmets[j][k]);
					}
					if ((student->ocenki[j][k] != "-")&&(student->ocenki[j][k] != " "))
					{
						vsel.AddString((LPCTSTR)student->ocenki[j][k]);
						vsel.AddString(L"-----");
					}
				}
			}
			vsel.AddString(L"**********");
			if (student->next != NULL)
				student = student->next;
			else
				break;
		}
	//}

	UpdateData(false);
}



void CMFCApplication1Dlg::OnBnClickedButton13()
{
	UpdateData(true);
	CString dr1, dp1, tmp;
	fstream file("file.txt");
	while (student->pred != NULL) {
		student = student->pred;
	}
	while (student != NULL) {
		file << tochar(student->f) << endl;
		file << tochar(student->n) << endl;
		file << tochar(student->o) << endl;
		file << tochar(student->fakul) << endl;
		file << tochar(student->grou) << endl;
		file << tochar(student->no) << endl;
		dr1 = student->dr.Format("%d.%m.%Y");
		dp1 = student->dp.Format("%d.%m.%Y");
		file << tochar(dr1) << endl;
		file << tochar(dp1) << endl;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 10; k++) {
				if ((student->predmets[j][k] != "-")&&(student->ocenki[j][k] != "-"))
				{
					file << "№sessii: "<<endl;
					file << j+1 << endl;
					file << "-----" << endl;
					file << tochar(student->predmets[j][k]) << endl;
					file << tochar(student->ocenki[j][k]) << endl;
					file << "-----" << endl;
				}
			}
		}
		file << "**********" << endl;
		if (student->next!=NULL)
			student = student->next;
		else {
			MessageBox(L"gotovo");
			break;
		}
	}
}


void CMFCApplication1Dlg::OnBnClickedButton12()
{
	char* buf = new char[255];
	int p = 0;

	ifstream file;
	file.open("file.txt", std::ios_base::in);

	char *tmp1 = new char[2];
	char *tmp2 = new char[2];
	char *tmp3 = new char[4];

	while (!file.eof()) {
		if (b == TRUE)
		{
			student->next = new stud;
			student->next->pred = student;
			student->next->next = NULL;
			student = student->next;
		}
		else
			b = TRUE;
		file >> buf;
		student->f = buf;
		file >> buf;
		if (file.eof()) {
			if (strcmp(buf, "") == 0) {
				otchislen();
			}
			break;
		}
		student->n = buf;
		file >> buf;
		student->o = buf;
		file >> buf;
		student->fakul = buf;
		file >> buf;
		student->grou = buf;
		file >> buf;
		student->no = buf;
		file >> buf;
		tmp1[0] = buf[0];
		tmp1[1] = buf[1];
		tmp1[2] = '\0';
		tmp2[0] = buf[3];
		tmp2[1] = buf[4];
		tmp2[2] = '\0';
		for (int i = 0; i < 4; i++) {
			tmp3[i] = buf[i + 6];
			tmp3[i + 1] = '\0';
		}
		CTime dr2(atoi(tmp3), atoi(tmp2), atoi(tmp1), 1, 1, 1, 0);
		student->dr = dr2;
		file >> buf;
		tmp1[0] = buf[0];
		tmp1[1] = buf[1];
		tmp2[0] = buf[3];
		tmp2[1] = buf[4];
		for (int i = 0; i < 4; i++) {
			tmp3[i] = buf[i + 6];
		}
		CTime dp2(atoi(tmp3), atoi(tmp2), atoi(tmp1), 1, 1, 1, 0);
		student->dp = dp2;
		n_stud++;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				student->predmets[i][j] = "-";
				student->ocenki[i][j] = "-";
			}
		}
		p = 0;
		file >> buf;
		while (strcmp("**********", buf) != 0) {
			file >> buf;
			student->i_ses = atoi(buf)-1;
			file >> buf;
			file >> buf;
			student->predmets[student->i_ses][p] = buf;
			file >> buf;
			student->ocenki[student->i_ses][p] = buf;
			p++;
			file >> buf;
			file >> buf;
		}
		if (student != NULL) {
			if (student->pred != NULL) {
				CString no = student->no;
				BOOL b1 = FALSE;
				while (student->pred != NULL) {
					student = student->pred;
				}
				while (student->next != NULL) {
					if (student->no == no) {
						b1 = TRUE;
						break;
					}
					student = student->next;
				}
				while (student->next != NULL) {
					student = student->next;
				}
				if (b1) {
					otchislen();
				}
			}
		}
	}
	MessageBox(L"gotovo");

}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	while (student->pred != NULL) {
		student = student->pred;
	}
	UpdateData(true);
	while (strcmp(tochar(student->no), tochar(redach)) != 0)
		student = student->next;
	if (strcmp(tochar(student->no), tochar(redach)) == 0) { 
		MessageBox(L"vvedite dannye dlya redaktirovaniya");
		fam = student->f;
		name = student->n;
		otch = student->o;
		fak = student->fakul;
		group = student->grou;
		num = student->no;
		dateR.SetTime(&student->dr);
		dateP.SetTime(&student->dp);
		CB2.EnableWindow(false);
		but1.EnableWindow(false);
		but2.EnableWindow(false);
		but3.EnableWindow(false);
		but5.EnableWindow(false);
		but6.EnableWindow(false);
		but9.EnableWindow(false);
		but12.EnableWindow(false);
		but13.EnableWindow(false);
		but14.EnableWindow(false);
		but15.EnableWindow(true);
		but16.EnableWindow(true);
	}
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	UpdateData(true);
	but1.EnableWindow(true);
	but2.EnableWindow(true);
	but3.EnableWindow(true);
	but5.EnableWindow(true);
	but6.EnableWindow(true);
	but9.EnableWindow(true);
	but12.EnableWindow(true);
	but13.EnableWindow(true);
	but14.EnableWindow(true);
	student->f = fam;
	student->n = name;
	student->o = otch;
	student->fakul = fak;
	student->grou = group;

	dateR.GetTime(student->dr);
	dateP.GetTime(student->dp);
	student->i_ses = CB1.GetCurSel();
	CString tmp;
	int o = CB3.GetCurSel() + 1;
	if (o == 1) tmp = "neud";
	if (o == 2) tmp = "udv";
	if (o == 3) tmp = "hor";
	if (o == 4) tmp = "otl";
	if (o == 5) tmp = "zach";
	if (o == 6) tmp = "nezach";

	for (int j = 0; j < 10; j++) {
		if (student->predmets[student->i_ses][j] == pred) {
			student->ocenki[student->i_ses][j] = tmp;
			break;
		}
		else {
			student->predmets[student->i_ses][j] = pred;
			student->ocenki[student->i_ses][j] = tmp;
			break;
		}
	}
	but15.EnableWindow(false);
	but16.EnableWindow(false);
	OnBnClickedButton3();
}

void CMFCApplication1Dlg::OnBnClickedButton16()
{
	UpdateData(true);
	but1.EnableWindow(true);
	but2.EnableWindow(true);
	but3.EnableWindow(true);
	but5.EnableWindow(true);
	but6.EnableWindow(true);
	but9.EnableWindow(true);
	but12.EnableWindow(true);
	but13.EnableWindow(true);
	but14.EnableWindow(true);
	but15.EnableWindow(false);
	but16.EnableWindow(false);
	for (int j = 0; j < 10; j++) {
		if (student->predmets[student->i_ses][j] == pred) {
			student->predmets[student->i_ses][j] = "-";
			student->ocenki[student->i_ses][j] = "-";
			break;
		}
	}
	OnBnClickedButton3();
}