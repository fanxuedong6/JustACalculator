
// CalcDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// 对话框数据
	enum { IDD = IDD_ABOUTBOX };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
// 实现
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


// CCalcDlg 对话框



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


// CCalcDlg 消息处理程序

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CCalcDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
void CCalcDlg::ClearZero(CString str)//**********有小数点后，清零函数*******
{
	int i=0,f=str.GetLength(),t;
	for(;i<f;i++)
		if(str.GetAt(i)=='.')  //判断是否有小数点
		{   t=i; //将i赋给t,作为标识‘.’的位置
			while((str.GetAt(--f)=='0' || str.GetAt(f)=='.')&&(f>=t))//当遇到零或者点并且f>=t
			{   
			str.Delete(f);//清除‘0’和‘.’
			}
			Result=str;//把清除零的数赋给编辑框m_Edit3
		}
}
void CCalcDlg::GetResult()//自己定义添加这个函数，代码如下
{
	int i=0,x=0,y=1,t=0,z=1;
//这个循环的目的是把所有除法运算都改为乘法计算
	for(i=0;i<=s;i++)                               
	{	
		if(b[i]=='/')                               //当循环遇到除号时
		{
			a[i+1]=1/a[i+1];                        //把a[i+1]的值改为1/a[i+1]
			b[i]='*';		                        //把b[i]的值改为乘号   	
		}                                           
	}
//这个循环可以对所有乘法进行计算
	for(i=0;i<=s;i++)                               
	{
		if(b[i]=='*')                               //当循环遇到乘号时
		{    
//如果i-t==2(再上次循环中,t被赋值成了i,这次2个值只相差2,说明表达式的情况是连续乘法
			if(i-t==2)                              
			{		
				a[t-z]=a[t-z]*a[i+1];              
 //进行乘法运算，把结果保存在前面的数组元素中                  
				z=z+2;                              
//这里引进变量z，可以解决很多数连续相乘的问题，比如2*2*2*2*2*2 
			}
			else
			a[i-1]=a[i-1]*a[i+1];                  
//碰到乘号后把乘号前后2个数字相乘，结果保存在前面的数组元素
			a[i+1]=1000000.0;                       //对乘号后面的数字初始化为0.0
			b[i]=' ';                               //对乘号初始化为空格
//2数相乘后把乘号及其后面的数字初始化了，如果是2*3*4的情况，将会无法计算*4，所以要用开始的条件语句来解决
			t=i;                                    //把i的值赋给t
		}
	}
//这个循环的目的是对数组a和b进行整理，因为已经进行了乘法和除法运算，进行运算的时候，把一些数字和运算符初始化了这个函数的作用可以使中间一些初始化了的数字和符号被后面的数字和符号代替，让数组可以重新排列
	for(i=0;i<=s;i++)                               
	{
		if(a[i]!=1000000.0)                         //如果a[i]的值不为0.0
		{
		    a[x]=a[i];                              //把a[i]的值赋给a[x]
			x+=2;                                   //x自加2
		}
		if(b[i]!=' ')                               //如果b[i]的值不为空格
		{
			b[y]=b[i];                              //把b[i]的值赋给b[y]
			y=y+2;                                  //y自加2
		}
	}
//这个循环是进行最后的加减法运算
	for(i=0,x=2;i<=y-2;i++)                             
//这里i的上限小于等于y-2，可以保证不进行多余的运算                          
	{
		if(b[i]=='+')                               //如果b[i]等于加号		
			{
				a[0]=a[0]+a[x];  
				x+=2;
		    }
//把加号后的数字和a[0]相加，结果保存在a[0]中
		else if(b[i]=='-')                          //如果b[i]等于减号
			{
				a[0]=a[0]-a[x];
		        x+=2;
		     }
//把减号后的数字和a[0]相减，结果保存在a[0]中
	}	
}
void CCalcDlg::GetStr(CString str)//这个自己根据类向导自己定义的函数，添加
{
	int i=0,z=0;
	double rate=10.0,itemp=0.0;
	for(i=0;i<20;i++)
    a[i]=1000000.0;  //对数组a[20]初始化
	for(i=0;i<10;i++)
    b[i]=' ';     //对数组b[10]初始化
	i=0;           //把0赋给i
	for(;i<str.GetLength();i++)                   
	{
		if(isdigit(str.GetAt(i)))                   //如果字符串str.GetAt(i)的内容是整数
		{                                          
			if(rate==10.0)                       	//整数部分
				itemp=itemp*rate+(str.GetAt(i)-'0');//获得整数
			else                                //小数部分
			{	
				itemp=itemp+rate*(str.GetAt(i)-'0');//获得小数
				rate=rate/10;                    //每次让rate小10倍
			}
		}
		else if(str.GetAt(i)=='.')                  //如果str.GetAt(i)是小数点
			rate=0.1;                           //让rate=0.1，开始计算小数部分
		else if(str.GetAt(i)=='+')                  //如果str.GetAt(i)是加号
        {   
			a[z]=itemp;itemp=0;                    
 //把itemp的值放入双精度数组a中，并把itemp的值改为0
			z++;                                   //让z自加一次
			b[z]='+';                               //把加号放入字符数组b中  
			z++;                                   //让z自加一次
			rate=10.0;                             
 //把10赋给rate，确保读取下个数字时，先计算整数部分
		}
		else if(str.GetAt(i)=='-')                  //如果str.GetAt(i)是减号 
        {   
			    a[z]=itemp;itemp=0;                
 //把itemp的值放入双精度数组a中，并把itemp的值改为0
		    	z++;                              //让z自加一次
		    	b[z]='-';                          //把减号放入字符数组b中
			    z++;                            //让z自加一次
		        rate=10.0;           				
//把10赋给rate，确保读取下个数字时，先计算整数部分
		}
		else if(str.GetAt(i)=='*')                  //如果str.GetAt(i)是乘号
        {
			a[z]=itemp;itemp=0;                    
 //把itemp的值放入双精度数组a中，并把itemp的值改为0
			z++;                                    //让z自加一次
			b[z]='*';                               //把减号放入字符数组b中
			z++;                                    //让z自加一次
		    rate=10.0;                             
 //把10赋给rate，确保读取下个数字时，先计算整数部分
		}
		else if(str.GetAt(i)=='/')                  //如果str.GetAt(i)是除号 
        {
			a[z]=itemp;itemp=0;                   
  //把itemp的值放入双精度数组a中，并把itemp的值改为0
			z++;                                    //让z自加一次
			b[z]='/';                               //把除号放入字符数组b中
			z++;                                    //让z自加一次
			rate=10.0;                           
   //把10赋给rate，确保读取下个数字时，先计算整数部分
		}
	}
	a[z]=itemp;                                   
  //把最后一个整数itemp的值放入双精度数组a中
   s=z;                                          
 //把z的值赋给变量s，用来控制计算结果的循环中的条件
}

void CCalcDlg::OnBnClickedButton18()
{
	//按键1
	CString str=L"1";
	CEdit *p=(CEdit*)GetDlgItem(IDC_EDIT1);
	int Len=p->SendMessage(WM_GETTEXTLENGTH);
	p->SetSel(Len,Len);
	p->ReplaceSel(str);
}


void CCalcDlg::OnBnClickedButton21()
{
	//按键0
	UpdateData(TRUE);          //把编辑框显示的字符串传给相应的变量m_strResult
	Result+="0";     //在按下数字键的情况下，则在m_strResult后加"0"         
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
	UpdateData(TRUE);  //把编辑框显示的字符串传给相应的变量m_strResult       
	if(Result!="0"&&Result.GetLength()>1)   //判断编辑框是否只剩下“0”或者是否有字符在编辑框上
		Result=Result.Left(Result.GetLength()-1);  //把m_strResult左边的数（长度已经减一）重新赋给m_strResult
	else
	{
	//	Restarted=true;  //把bool变量Restarted的值改为true
		Result="0";   //变量m_strResult的值为按下的按忸"0"
	}
	UpdateData(FALSE);//把字符串变量m_strResult传给编辑框   
}


void CCalcDlg::OnBnClickedButton11()
{
	//按键C
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"");
}


void CCalcDlg::OnBnClickedButton23()
{
	//按键+
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
	// 等号
	UpdateData(TRUE);
	//L1=true;
	int p=0,i=0,g[10]={0},k=0;

	GetStr(Result);	    //调用函数GetStr(m_strResult)，作用是把m_strResult转化成数字和加减乘除四则运算
    GetResult();               //调用函数GetResult()，作用是计算出表达式的值
	Result.Format(_T("%1f"),a[0]);
	ClearZero(Result);
		//特别注意，下面的｛｝是一个块，不是一个语句或函数的执行体。
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
	// 算式解析
	//WinExec("1.exe",1);
}

void CCalcDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
