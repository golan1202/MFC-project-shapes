// DlgDlg.cpp : implementation file

#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog

CDlgDlg::CDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDlg::IDD, pParent)
	, isThin(FALSE)
{
	futureFigKIND=RECTANGLE;
	figtemp=NULL;
	isPressed=false;
	set=0;
	curColor=RGB(255,0,0);


	//{{AFX_DATA_INIT(CDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Check(pDX, IDC_CHECK1, isThin);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnBnClickedRadio3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_CHECK1, &CDlgDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(UndoButton, &CDlgDlg::OnBnClickedUndobutton)
	ON_BN_CLICKED(RedoButton, &CDlgDlg::OnBnClickedRedoButton)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgDlg::OnBnClickedButton7)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers

BOOL CDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	{
   CButton* pBtn= (CButton*)GetDlgItem(UndoButton);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON7),IMAGE_ICON, 60,60, LR_DEFAULTCOLOR ); // Undo Icon
   pBtn->SetIcon( hIcn );
	}

	{
   CButton* pBtn= (CButton*)GetDlgItem(RedoButton);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4),IMAGE_ICON, 60,60, LR_DEFAULTCOLOR ); // Redo Icon
   pBtn->SetIcon( hIcn );
	}
	
	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON4);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON6),IMAGE_ICON, 55,55, LR_DEFAULTCOLOR ); // Delete Icon
   pBtn->SetIcon( hIcn );
	}
	
	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON6);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2),IMAGE_ICON, 50,50, LR_DEFAULTCOLOR ); // Color Icon
   pBtn->SetIcon( hIcn );
	}
	
	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON3);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1),IMAGE_ICON, 50,50, LR_DEFAULTCOLOR ); // Change Color Icon
   pBtn->SetIcon( hIcn );
	}
	
	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON1);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5),IMAGE_ICON, 55,55, LR_DEFAULTCOLOR );  // Save Icon
   pBtn->SetIcon( hIcn );
	}

	
	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON2);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3),IMAGE_ICON, 55,55, LR_DEFAULTCOLOR ); // Load Color Icon
   pBtn->SetIcon( hIcn );
	}

	{
   CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON7);
   pBtn->ModifyStyle( 0, BS_ICON );
   HICON hIcn= (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON8),IMAGE_ICON, 50,50, LR_DEFAULTCOLOR ); // New Icon
   pBtn->SetIcon( hIcn );
	}

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//!!2
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgDlg::OnPaint() 
{
    CRect rect;
    GetClientRect (&rect);

	CPaintDC dc (this);	

	{
	CFont font;
    font.CreatePointFont (200, _T ("Showcard Gothic"));
	CFont *oldFont= dc.SelectObject (&font);
    dc.SetBkMode (TRANSPARENT);

    CString string = "Almog  and  Golan";

    rect.OffsetRect (-250,350); // Change font location
    dc.SetTextColor (RGB (0, 0, 0));
    dc.DrawText (string, &rect, DT_SINGLELINE |
        DT_CENTER | DT_VCENTER);

    rect.OffsetRect (-4, -4);
    dc.SetTextColor (RGB (0, 128, 192));
    dc.DrawText (string, &rect, DT_SINGLELINE |
        DT_CENTER | DT_VCENTER);

	dc.SelectObject (oldFont);	
	}
	dc.SetBkMode (TRANSPARENT);
	

	for(int i=0;i<figs.GetSize();i++)
	{
		figs[i]->Draw(&dc);
	}
    //if creation
	if(isPressed)
	{
		dc.MoveTo(startP.x,startP.y);
		dc.LineTo(startP.x,endP.y);
		dc.LineTo(endP.x,endP.y);
		dc.LineTo(endP.x,startP.y);
		dc.LineTo(startP.x,startP.y);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// check that the drawing is on the right area
	CRect rect;
	CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	if(point.y > rect.top + 7 && point.y < rect.bottom -7 && point.x < rect.right -7&& point.x > rect.left +7)
	{
		inArea = true;
	}
	else
	{
		inArea = false;
		return;
	}

	bool insideObject = false;
    endP=startP=point;
	isPressed=true;
	int x = point.x;
	int y = point.y;
	for(int i=figs.GetSize()-1;i>=0;i--)
	{
		figtemp = figs[i];
		if(x <= max(figtemp->getX1(),figtemp->getX2()) && x >=min(figtemp->getX1(),figtemp->getX2())
			&& y <= max(figtemp->getY1(),figtemp->getY2()) && y >=min(figtemp->getY1(),figtemp->getY2()))
		{
			insideObject = true;
			isSelectingObject = true;
			break;
		}
	}
	if(insideObject == false)
	{
		figtemp = NULL;
		isSelectingObject = false;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(isPressed && !isSelectingObject && inArea)
	{
		endP=point;
		switch(futureFigKIND)
		{
		case RECTANGLE:
			figs.Add(new RectangleM(startP.x,startP.y,endP.x,endP.y));
			break;
		case ELLIPSE:
			figs.Add(new EllipseM(startP.x,startP.y,endP.x,endP.y));
			break;
		case CIRCLE:
			figs.Add(new CircleM(startP.x,startP.y,endP.x,endP.y));
			break;
		}
		
		actions.push_back(ADD);
		undo_redo_objects.clearRedo(); // when creating a new object there is no point for redo stack anymore
		figs[figs.GetSize()-1]->setColor(curColor);
		figs[figs.GetSize()-1]->setSet(set);
		CRect r;
		r.left=min(startP.x,endP.x);
		r.right=max(startP.x,endP.x)+10;
		r.top=min(startP.y,endP.y);
		r.bottom=max(startP.y,endP.y)+10;
		InvalidateRect(&r);
		Invalidate();
	}
	else
		Invalidate();
	isPressed=false;
	CDialog::OnLButtonUp(nFlags, point);
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    if(isPressed)
	{
		isSelectingObject = false;
		figtemp = NULL;
		//local drawing with CClientDC 
		//////CHANGES (disables flickering)
		
		CClientDC dc(this);
                     
		CPen myPen1(PS_SOLID, isThin?1:5, curColor);

		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN); 

		CRect rect;
		CWnd *pWnd = this->GetDlgItem(IDC_STATIC);
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		if(point.y > rect.top + 7 && point.y < rect.bottom -7 && point.x < rect.right -7&& point.x > rect.left +7)
		{
			inArea = true;
		}
		else
		{
			inArea = false;
			//return;
		}
		switch(futureFigKIND)
		{
		case RECTANGLE:
			dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
			endP=point;
			dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
			break;
		case ELLIPSE:
			dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
			endP=point;
			dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
			break;
		case CIRCLE:
			int midY = (startP.y+endP.y)/2;
			int midX = (startP.x+endP.x)/2;
			CPoint p1(midX,midY); // get the center as a point
			int distY = abs(startP.y - midY);
			int distX = abs(startP.x - midX);
			int minDist = min(distX,distY);
			dc.Ellipse(p1.x-minDist,p1.y-minDist,p1.x+minDist+1,p1.y+minDist+1);
			endP = point;
			midY = (startP.y+endP.y)/2;
			midX = (startP.x+endP.x)/2;
			p1.x = midX;
			p1.y = midY;
			distY = abs(startP.y - midY);
			distX = abs(startP.x - midX);
			minDist = min(distX,distY);
			dc.Ellipse(p1.x-minDist,p1.y-minDist,p1.x+minDist+1,p1.y+minDist+1);

			// invalidate the start point because it leaves a dot on the screen
			RECT r;
			r.left=startP.x-2;
			r.right=startP.x+2;
			r.top=startP.y+2;
			r.bottom=startP.y-2;
			InvalidateRect(&r);
			break;
		}
		dc.SelectObject( oldPen ); 
		dc.SetROP2(R2_COPYPEN);  
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CDlgDlg::OnBnClickedButton1()
{ 
	// Save File 
	TCHAR szFilters[] = _T("Project Files(*.fig)|*.fig|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("1.fig"),_T("*.fig"),OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
	CFile file(fileDlg.GetPathName(), CFile::modeCreate|CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	}
}

void CDlgDlg::OnBnClickedButton2()
{
	// Load File 
	TCHAR szFilters[] = _T("Project Files(*.fig)|*.fig|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("fig"),_T("*.fig"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
		CFile file(fileDlg.GetPathName(), CFile::modeRead);
		CArchive ar (&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		// setting the proper set number
		set = -1;
		for(int i=0;i<figs.GetSize();i++)
		{
			if(figs[i]->getSet() > set)
				set = figs[i] -> getSet();
		}
		set++;
		Invalidate();
	}
}
void CDlgDlg::OnBnClickedRadio1()
{
    futureFigKIND=RECTANGLE;
}

void CDlgDlg::OnBnClickedRadio2()
{
	futureFigKIND=ELLIPSE;
}

void CDlgDlg::OnBnClickedRadio3()
{
	futureFigKIND=CIRCLE;
}

void CDlgDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	

	CDialog::OnRButtonDown(nFlags, point);
}

void CDlgDlg::OnBnClickedCheck1()
{
	UpdateData(true);
}



void CDlgDlg::OnBnClickedUndobutton()
{
	// if last action was adding an object or on a series of undoing objects
	if(actions.size()==0)
		return;
	if(actions[actions.size()-1] == ADD || actions[actions.size()-1] == REDO_OBJECT)
	{
		if(figs.GetSize() > 0)
		{
			actions.pop_back();
			undo_redo_objects.pushRedo(figs[figs.GetSize()-1]);
			figs.RemoveAt(figs.GetSize()-1);
			actions.push_back(UNDO_OBJECT);
			Invalidate();
		}
	}
	else if(actions[actions.size()-1] == UNDO_OBJECT)
	{
		if(figs.GetSize() > 0)
		{
			// check if the figure is from the last set of objects defined, otherwise don't delete it
			if(figs[figs.GetSize()-1]->getSet() == set)
			{
				actions.pop_back();
				undo_redo_objects.pushRedo(figs[figs.GetSize()-1]);
				figs.RemoveAt(figs.GetSize()-1);
				actions.push_back(UNDO_OBJECT);
				Invalidate();
			}
		}
	}
	else if(actions[actions.size()-1] == REMOVE || actions[actions.size()-1] == REMOVE_REVIVAL || actions[actions.size()-1] == REVIVE_OBJECT )
	{
		if(undo_redo_objects.undoSize() > 0)
		{
			
			for(int i = actions.size()-1;i>=0;i--)
			{
				if(actions[i] == REMOVE || actions[i] == REMOVE_REVIVAL)
				{
					actions.erase(actions.end()-(actions.size()-i));
					break;
				}
			}
			
			figs.Add(undo_redo_objects.undoPop(false));
			actions.push_back(REVIVE_OBJECT);
			Invalidate();
		}
	}
}


void CDlgDlg::OnBnClickedRedoButton()
{
	bool revival = false;
	if(actions.size()==0)
		return;
	// if last action was removing an object or on a series of redoing objects
	if(actions[actions.size()-1]==UNDO_OBJECT || actions[actions.size()-1] == REDO_OBJECT)
	{
		if(undo_redo_objects.redoSize() > 0)
		{
			actions.pop_back();
			figs.Add(undo_redo_objects.redoPop());
			actions.push_back(REDO_OBJECT);
			Invalidate();
		}
	}

	else if(actions[actions.size()-1]==REVIVE_OBJECT || actions[actions.size()-1] == REMOVE_REVIVAL)
	{
		if(figs.GetSize()>0)
		{
			for(int i = actions.size()-1;i>=0;i--)
			{
				if(actions[i] == REVIVE_OBJECT)
				{
					revival = true;
					actions.erase(actions.end()-(actions.size()-i));
					actions.push_back(REMOVE_REVIVAL);
					break;
				}
			}

			if(revival)
			{
				undo_redo_objects.pushUndo(figs[figs.GetSize()-1]);
				figs.RemoveAt(figs.GetSize()-1);
				Invalidate();
			}
		}
	}
}

void CDlgDlg::OnBnClickedButton3()
{
	if(figtemp != NULL)
	{
		figtemp->setColor(curColor);
		Invalidate();
	}
}


void CDlgDlg::OnBnClickedButton4()
{
	if(figtemp !=NULL)
	{
		for(int i=0;i<figs.GetSize();i++)
		{
			if(figtemp==figs[i])
			{
				undo_redo_objects.clearRedo();
				 //if removing an object after we did a redo then the stacks are no longer relevant
				if(actions.size() !=0)
				{
					if(actions[actions.size()-1] == REDO_OBJECT)
					{	
						undo_redo_objects.clearUndo();
					}
					else if(actions[actions.size()-1] != REMOVE)
					{
						set++;
					}
				}
				undo_redo_objects.pushUndo(figtemp);
				figs.RemoveAt(i);
				figtemp = NULL;
				break;
			}
		}
		// clearing the add actions from the actions vector, they are no longer relevant
		actions.push_back(REMOVE);
		Invalidate();
	}
}

void CDlgDlg::OnBnClickedButton6()
{
	CColorDialog dlg; 
	if (dlg.DoModal() == IDOK) 
	{ 
		curColor = dlg.GetColor();
	}
}


void CDlgDlg::OnBnClickedButton7()
{
	figs.RemoveAll();
	undo_redo_objects.clearRedo();
	undo_redo_objects.clearUndo();
	Invalidate();
}
