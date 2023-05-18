#include "stdafx.h"
#include"ObjectManip.h"

// SelectDialogue dialog

IMPLEMENT_DYNAMIC(ObjectManip, CDialogEx)

//Message map.  Just like MFCMAIN.cpp.  This is where we catch button presses etc and point them to a handy dandy method.
BEGIN_MESSAGE_MAP(ObjectManip, CDialogEx)
	//ON_COMMAND(IDOK, &ObjectManip::End)					//ok button
	ON_BN_CLICKED(IDOK, &ObjectManip::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST1, &ObjectManip::Select)	//listbox
	ON_BN_CLICKED(IDR_EXIT1, &ObjectManip::OnEnd)
	//ON_BN_CLICKED(IDOK,&ObjectManip::OnEnd)

	//ON_EN_CHANGE(IDC_EDIT4, &ObjectManip::OnEnChangeEdit4)
END_MESSAGE_MAP()


ObjectManip::ObjectManip(CWnd* pParent, std::vector<SceneObject>* SceneGraph)		//constructor used in modal
	: CDialogEx(IDD_DIALOG2, pParent)
{
	m_sceneGraph = SceneGraph;

}

ObjectManip::ObjectManip(CWnd* pParent)			//constructor used in modeless
	: CDialogEx(IDD_DIALOG2, pParent)

{

	 PosX=0;
	 PosY=0;
	 PosZ=0;

	 RotX=0;
	 RotY=0;
	 RotZ=0;

	 ScaleX=0;
	 ScaleY=0;
	 ScaleZ=0;
	 
	 current = 0;
	 isSelected = false;
}

ObjectManip::~ObjectManip()
{
}

///pass through pointers to the data in the tool we want to manipulate
void ObjectManip::SetObjectData(std::vector<SceneObject>* SceneGraph, int* selection, InputCommands* input)
{
	m_sceneGraph = SceneGraph;
	m_currentSelection = selection;
	m_Inputcommands = input;
	
	current = *selection;
	//roll through all the objects in the scene graph and put an entry for each in the listbox
	int numSceneObjects = m_sceneGraph->size();
	if (current > -1)
	{
		PosX = SceneGraph->at(*selection).posX;
		PosY = SceneGraph->at(*selection).posY;
		PosZ = SceneGraph->at(*selection).posZ;

		RotX = SceneGraph->at(*selection).rotX;
		RotY = SceneGraph->at(*selection).rotY;
		RotZ = SceneGraph->at(*selection).rotZ;

		ScaleX = SceneGraph->at(*selection).scaX;
		ScaleY = SceneGraph->at(*selection).scaY;
		ScaleZ = SceneGraph->at(*selection).scaZ;

	}
}


void ObjectManip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_POSX, PosX);
	DDX_Text(pDX, IDC_POSY, PosY);
	DDX_Text(pDX, IDC_POSZ, PosZ);
	
	DDX_Text(pDX, IDC_ROTX, RotX);
	DDX_Text(pDX, IDC_ROTY, RotY);
	DDX_Text(pDX, IDC_ROTZ, RotZ);

	DDX_Text(pDX, IDC_SCALEX, ScaleX);
	DDX_Text(pDX, IDC_SCALEY, ScaleY);
	DDX_Text(pDX, IDC_SCALEZ, ScaleZ);


	DDV_MinMaxFloat(pDX, ScaleX, 0.1, 10);
	DDV_MinMaxFloat(pDX, ScaleY, 0.1, 10);
	DDV_MinMaxFloat(pDX, ScaleZ, 0.1, 10);


	//DDX_Control(pDX, IDC_LIST1, m_listBox);
}

void ObjectManip::End()
{
	DestroyWindow();	//destory the window properly.  INcluding the links and pointers created.  THis is so the dialogue can start again. 
}

void ObjectManip::Select()
{
	//int index = m_listBox.GetCurSel();
	CString currentSelectionValue;

	//m_listBox.GetText(index, currentSelectionValue);

	//*m_currentSelection = index;//_ttoi(currentSelectionValue);

}

BOOL ObjectManip::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void ObjectManip::PostNcDestroy()
{

	DestroyWindow();
}



void ObjectManip::OnEnd()
{
	DestroyWindow();
}



// SelectDialogue message handlers callback   - We only need this if the dailogue is being setup-with createDialogue().  We are doing
//it manually so its better to use the messagemap
/*INT_PTR CALLBACK SelectProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		//	EndDialog(hwndDlg, wParam);
			DestroyWindow(hwndDlg);
			return TRUE;


		case IDCANCEL:
			EndDialog(hwndDlg, wParam);
			return TRUE;
			break;
		}
	}

	return INT_PTR();
}*/


void ObjectManip::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

	UpdateData(true);

	UpdateData(false);

	DestroyWindow();

	if (!m_Inputcommands->ifOK)
	{

		m_sceneGraph->at(current).posX = PosX;
		m_sceneGraph->at(current).posY = PosY;
		m_sceneGraph->at(current).posZ = PosZ;

		m_sceneGraph->at(current).rotX = RotX;
		m_sceneGraph->at(current).rotY = RotY;
		m_sceneGraph->at(current).rotZ = RotZ;

		m_sceneGraph->at(current).scaX = ScaleX;
		m_sceneGraph->at(current).scaY = ScaleY;
		m_sceneGraph->at(current).scaZ = ScaleZ;


		m_Inputcommands->ifOK = true;
	}


}


