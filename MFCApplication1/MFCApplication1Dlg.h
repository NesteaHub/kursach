
// MFCApplication1Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox CB1;
	CComboBox CB2;
	CComboBox CB3;
	afx_msg void OnBnClickedButton1();
	CString fam;
	CString name;
	CString otch;
	CString fak;
	CString group;
	CString num;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString pred;
	CDateTimeCtrl dateR;
	CDateTimeCtrl dateP;
	afx_msg void OnBnClickedButton6();
	CButton but1;
	CButton but2;
	CButton but3;
	afx_msg void OnBnClickedButton5();
	CString del;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton11();
	CString vse;
	CListBox vsel;
	CListBox tril;
	CListBox horl;
	CListBox otll;
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton14();
	CString redach;
//	CButton but4;
	CButton but5;
	CButton but6;
//	CButton but7;
//	CButton but8;
	CButton but9;
//	CButton but10;
	CButton but11;
	CButton but12;
	CButton but13;
	CButton but14;
	CButton but15;
	afx_msg void OnBnClickedButton15();
	CButton but16;
	afx_msg void OnBnClickedButton16();
};
