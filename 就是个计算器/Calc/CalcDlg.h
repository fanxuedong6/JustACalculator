
// CalcDlg.h : ͷ�ļ�
//

#pragma once


// CCalcDlg �Ի���
class CCalcDlg : public CDialogEx
{
// ����
public:
	CCalcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Result;
	double a[20];
	char b[10];
	int s;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton22();
	afx_msg void ClearZero(CString str);
	afx_msg void OnBnClickedButton27();
	afx_msg void GetResult();
	afx_msg void GetStr(CString str);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
};
