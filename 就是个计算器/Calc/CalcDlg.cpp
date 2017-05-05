
// CalcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"
#include "cmath"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int JH=1;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcDlg �Ի���



CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalcDlg::IDD, pParent)
	, Result(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Result);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCalcDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalcDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalcDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalcDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalcDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalcDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON37, &CCalcDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalcDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalcDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalcDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalcDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalcDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON27, &CCalcDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalcDlg::OnBnClickedButton17)
	ON_EN_CHANGE(IDC_EDIT1, &CCalcDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCalcDlg ��Ϣ�������

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CCalcDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
void CCalcDlg::ClearZero(CString str)//**********��С��������㺯��*******
{
	int i=0,f=str.GetLength(),t;
	for(;i<f;i++)
		if(str.GetAt(i)=='.')  //�ж��Ƿ���С����
		{   t=i; //��i����t,��Ϊ��ʶ��.����λ��
			while((str.GetAt(--f)=='0' || str.GetAt(f)=='.')&&(f>=t))//����������ߵ㲢��f>=t
			{   
			str.Delete(f);//�����0���͡�.��
			}
			Result=str;//���������������༭��m_Edit3
		}
}
void CCalcDlg::GetResult()//�Լ�������������������������
{
	int i=0,x=0,y=1,t=0,z=1;
//���ѭ����Ŀ���ǰ����г������㶼��Ϊ�˷�����
	for(i=0;i<=s;i++)                               
	{	
		if(b[i]=='/')                               //��ѭ����������ʱ
		{
			a[i+1]=1/a[i+1];                        //��a[i+1]��ֵ��Ϊ1/a[i+1]
			b[i]='*';		                        //��b[i]��ֵ��Ϊ�˺�   	
		}                                           
	}
//���ѭ�����Զ����г˷����м���
	for(i=0;i<=s;i++)                               
	{
		if(b[i]=='*')                               //��ѭ�������˺�ʱ
		{    
//���i-t==2(���ϴ�ѭ����,t����ֵ����i,���2��ֵֻ���2,˵�����ʽ������������˷�
			if(i-t==2)                              
			{		
				a[t-z]=a[t-z]*a[i+1];              
 //���г˷����㣬�ѽ��������ǰ�������Ԫ����                  
				z=z+2;                              
//������������z�����Խ���ܶ���������˵����⣬����2*2*2*2*2*2 
			}
			else
			a[i-1]=a[i-1]*a[i+1];                  
//�����˺ź�ѳ˺�ǰ��2��������ˣ����������ǰ�������Ԫ��
			a[i+1]=1000000.0;                       //�Գ˺ź�������ֳ�ʼ��Ϊ0.0
			b[i]=' ';                               //�Գ˺ų�ʼ��Ϊ�ո�
//2����˺�ѳ˺ż����������ֳ�ʼ���ˣ������2*3*4������������޷�����*4������Ҫ�ÿ�ʼ��������������
			t=i;                                    //��i��ֵ����t
		}
	}
//���ѭ����Ŀ���Ƕ�����a��b����������Ϊ�Ѿ������˳˷��ͳ������㣬���������ʱ�򣬰�һЩ���ֺ��������ʼ����������������ÿ���ʹ�м�һЩ��ʼ���˵����ֺͷ��ű���������ֺͷ��Ŵ��棬�����������������
	for(i=0;i<=s;i++)                               
	{
		if(a[i]!=1000000.0)                         //���a[i]��ֵ��Ϊ0.0
		{
		    a[x]=a[i];                              //��a[i]��ֵ����a[x]
			x+=2;                                   //x�Լ�2
		}
		if(b[i]!=' ')                               //���b[i]��ֵ��Ϊ�ո�
		{
			b[y]=b[i];                              //��b[i]��ֵ����b[y]
			y=y+2;                                  //y�Լ�2
		}
	}
//���ѭ���ǽ������ļӼ�������
	for(i=0,x=2;i<=y-2;i++)                             
//����i������С�ڵ���y-2�����Ա�֤�����ж��������                          
	{
		if(b[i]=='+')                               //���b[i]���ڼӺ�		
			{
				a[0]=a[0]+a[x];  
				x+=2;
		    }
//�ѼӺź�����ֺ�a[0]��ӣ����������a[0]��
		else if(b[i]=='-')                          //���b[i]���ڼ���
			{
				a[0]=a[0]-a[x];
		        x+=2;
		     }
//�Ѽ��ź�����ֺ�a[0]��������������a[0]��
	}	
}
void CCalcDlg::GetStr(CString str)//����Լ����������Լ�����ĺ��������
{
	int i=0,z=0;
	double rate=10.0,itemp=0.0;
	for(i=0;i<20;i++)
    a[i]=1000000.0;  //������a[20]��ʼ��
	for(i=0;i<10;i++)
    b[i]=' ';     //������b[10]��ʼ��
	i=0;           //��0����i
	for(;i<str.GetLength();i++)                   
	{
		if(isdigit(str.GetAt(i)))                   //����ַ���str.GetAt(i)������������
		{                                          
			if(rate==10.0)                       	//��������
				itemp=itemp*rate+(str.GetAt(i)-'0');//�������
			else                                //С������
			{	
				itemp=itemp+rate*(str.GetAt(i)-'0');//���С��
				rate=rate/10;                    //ÿ����rateС10��
			}
		}
		else if(str.GetAt(i)=='.')                  //���str.GetAt(i)��С����
			rate=0.1;                           //��rate=0.1����ʼ����С������
		else if(str.GetAt(i)=='+')                  //���str.GetAt(i)�ǼӺ�
        {   
			a[z]=itemp;itemp=0;                    
 //��itemp��ֵ����˫��������a�У�����itemp��ֵ��Ϊ0
			z++;                                   //��z�Լ�һ��
			b[z]='+';                               //�ѼӺŷ����ַ�����b��  
			z++;                                   //��z�Լ�һ��
			rate=10.0;                             
 //��10����rate��ȷ����ȡ�¸�����ʱ���ȼ�����������
		}
		else if(str.GetAt(i)=='-')                  //���str.GetAt(i)�Ǽ��� 
        {   
			    a[z]=itemp;itemp=0;                
 //��itemp��ֵ����˫��������a�У�����itemp��ֵ��Ϊ0
		    	z++;                              //��z�Լ�һ��
		    	b[z]='-';                          //�Ѽ��ŷ����ַ�����b��
			    z++;                            //��z�Լ�һ��
		        rate=10.0;           				
//��10����rate��ȷ����ȡ�¸�����ʱ���ȼ�����������
		}
		else if(str.GetAt(i)=='*')                  //���str.GetAt(i)�ǳ˺�
        {
			a[z]=itemp;itemp=0;                    
 //��itemp��ֵ����˫��������a�У�����itemp��ֵ��Ϊ0
			z++;                                    //��z�Լ�һ��
			b[z]='*';                               //�Ѽ��ŷ����ַ�����b��
			z++;                                    //��z�Լ�һ��
		    rate=10.0;                             
 //��10����rate��ȷ����ȡ�¸�����ʱ���ȼ�����������
		}
		else if(str.GetAt(i)=='/')                  //���str.GetAt(i)�ǳ��� 
        {
			a[z]=itemp;itemp=0;                   
  //��itemp��ֵ����˫��������a�У�����itemp��ֵ��Ϊ0
			z++;                                    //��z�Լ�һ��
			b[z]='/';                               //�ѳ��ŷ����ַ�����b��
			z++;                                    //��z�Լ�һ��
			rate=10.0;                           
   //��10����rate��ȷ����ȡ�¸�����ʱ���ȼ�����������
		}
	}
	a[z]=itemp;                                   
  //�����һ������itemp��ֵ����˫��������a��
   s=z;                                          
 //��z��ֵ��������s���������Ƽ�������ѭ���е�����
}

void CCalcDlg::OnBnClickedButton18()
{
	//����1
	CString str=L"1";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton21()
{
	//����0
	UpdateData(TRUE);          //�ѱ༭����ʾ���ַ���������Ӧ�ı���m_strResult
	Result+="0";     //�ڰ������ּ�������£�����m_strResult���"0"         
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButton19()
{
	CString str=L"2";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton20()
{
	CString str=L"3";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton15()
{
	CString str=L"4";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton37()
{
	CString str=L"5";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton17()
{
	CString str=L"6";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton12()
{
	CString str=L"7";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton13()
{
	CString str=L"8";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton14()
{
	CString str=L"9";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}

void CCalcDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);  //�ѱ༭����ʾ���ַ���������Ӧ�ı���m_strResult       
	if(Result!="0"&&Result.GetLength()>1)   //�жϱ༭���Ƿ�ֻʣ�¡�0�������Ƿ����ַ��ڱ༭����
		Result=Result.Left(Result.GetLength()-1);  //��m_strResult��ߵ����������Ѿ���һ�����¸���m_strResult
	else
	{
	//	Restarted=true;  //��bool����Restarted��ֵ��Ϊtrue
		Result="0";   //����m_strResult��ֵΪ���µİ���"0"
	}
	UpdateData(FALSE);//���ַ�������m_strResult�����༭��   
}


void CCalcDlg::OnBnClickedButton11()
{
	//����C
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"");
}


void CCalcDlg::OnBnClickedButton23()
{
	//����+
	CString str=L"+";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}


void CCalcDlg::OnBnClickedButton24()
{
    CString str=L"-";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}


void CCalcDlg::OnBnClickedButton25()
{
	CString str=L"*";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}


void CCalcDlg::OnBnClickedButton26()
{
	CString str=L"/";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}


void CCalcDlg::OnBnClickedButton22()
{
	CString str=L".";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
	p->LineScroll(p->GetLineCount());
}

void CCalcDlg::OnBnClickedButton27()
{
	// �Ⱥ�
	UpdateData(TRUE);
	//L1=true;
	int p=0,i=0,g[10]={0},k=0;

	GetStr(Result);	    //���ú���GetStr(m_strResult)�������ǰ�m_strResultת�������ֺͼӼ��˳���������
    GetResult();               //���ú���GetResult()�������Ǽ�������ʽ��ֵ
	Result.Format(_T("%1f"),a[0]);
	ClearZero(Result);
		//�ر�ע�⣬����ģ�����һ���飬����һ����������ִ���塣
		{
			CString str1=L"=";
			CString str=str1+Result;
			CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
			int Len=p->SendMessage(WM_GETTEXTLENGTH);
			p->SetSel(Len,Len);
			//p->ReplaceSel(L"\n");
			p->ReplaceSel(str);
		}
}


void CCalcDlg::OnBnClickedButton1()
{
	// ��ʽ����
	//WinExec("1.exe",1);
}

void CCalcDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
