#include "MFCMain.h"
#include "resource.h"


BEGIN_MESSAGE_MAP(MFCMain, CWinApp)
	ON_COMMAND(ID_FILE_QUIT,	&MFCMain::MenuFileQuit)
	ON_COMMAND(ID_FILE_SAVETERRAIN, &MFCMain::MenuFileSaveTerrain)
	ON_COMMAND(ID_EDIT_SELECT, &MFCMain::MenuEditSelect)
	ON_COMMAND(ID_BUTTON40001, &MFCMain::ToolBarButton1)
	ON_COMMAND(ID_BUTTON40002, &MFCMain::ToolBarButton2)
	ON_COMMAND(ID_BUTTON40003, &MFCMain::ToolBarButton3)
	ON_COMMAND(ID_BUTTON40006, &MFCMain::ToolBarButton4)
	ON_COMMAND(ID_BUTTON40007, &MFCMain::ToolBarButton5)
	
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TOOL, &CMyFrame::OnUpdatePage)
END_MESSAGE_MAP()

BOOL MFCMain::InitInstance()
{
	//instanciate the mfc frame
	m_frame = new CMyFrame();
	m_pMainWnd = m_frame;

	RECT hDesktopsize;
	
	const HWND desktop = GetDesktopWindow(); //handle for the desktop window
	
	GetWindowRect(desktop, &hDesktopsize); // Size of the screen to the desktop
	


	m_frame->Create(	NULL,
					_T("World Of Flim-Flam Craft Editor"),
					WS_OVERLAPPEDWINDOW,
					CRect(0, 0, hDesktopsize.right, hDesktopsize.bottom),
					NULL,
					NULL,
					0,
					NULL
				);

	//show and set the window to run and update. 
	m_frame->ShowWindow(SW_SHOW);
	m_frame->UpdateWindow();


	//get the rect from the MFC window so we can get its dimensions
	m_toolHandle = m_frame->m_DirXView.GetSafeHwnd();				//handle of directX child window
	m_frame->m_DirXView.GetClientRect(&WindowRECT);
	m_width		= WindowRECT.Width();
	m_height	= WindowRECT.Height();

	m_ToolSystem.onActionInitialise(m_toolHandle, m_width, m_height);
	

	return TRUE;
}

int MFCMain::Run()
{
	MSG msg;
	BOOL bGotMsg;

	PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	while (WM_QUIT != msg.message)
	{
		if (true)
		{
			bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);
		}
		else
		{
			bGotMsg = (GetMessage(&msg, NULL, 0U, 0U) != 0);
		}

		if (bGotMsg)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			m_ToolSystem.UpdateInput(&msg);
		}
		else
		{	
			int ID = m_ToolSystem.getCurrentSelectionID();
			std::wstring statusString = L"Selected Object: " + std::to_wstring(ID);
			m_ToolSystem.Tick(&msg);

			//send current object ID to status bar in The main frame
			m_frame->m_wndStatusBar.SetPaneText(1, statusString.c_str(), 1);	
		}
	}

	return (int)msg.wParam;
}

void MFCMain::MenuFileQuit()
{
	//will post message to the message thread that will exit the application normally
	PostQuitMessage(0);
}

void MFCMain::MenuFileSaveTerrain()
{
	m_ToolSystem.onActionSaveTerrain();
}

void MFCMain::MenuEditSelect()
{
	//SelectDialogue m_ToolSelectDialogue(NULL, &m_ToolSystem.m_sceneGraph);		//create our dialoguebox //modal constructor
	//m_ToolSelectDialogue.DoModal();	// start it up modal

	//modeless dialogue must be declared in the class.   If we do local it will go out of scope instantly and destroy itself
	m_ToolSelectDialogue.Create(IDD_DIALOG1);	//Start up modeless
	m_ToolSelectDialogue.ShowWindow(SW_SHOW);	//show modeless
	m_ToolSelectDialogue.SetObjectData(&m_ToolSystem.m_sceneGraph, &m_ToolSystem.m_selectedObject);
}

void MFCMain::ToolBarButton1()
{
	m_ToolSystem.onActionSave();
}

void MFCMain::ToolBarButton2() //Function to call the wirefram toggle function
{
	m_ToolSystem.onActionWireframe();
}

void MFCMain::ToolBarButton3() //Function to turn the arcball camera on and off
{
	if (m_ToolSystem.m_selectedObject > -1)
	{
		if (!ArcBallOnOff)
		{

			ArcBallOnOff = true;
			m_ToolSystem.onFocusArcBall();
			m_ToolSystem.SetCameraTypeTool(2);
		}

		else
		{
			ArcBallOnOff = false;
			m_ToolSystem.SetCameraTypeTool(1);
		}
	}
	else
	{
		MessageBox(m_toolHandle, L"Make sure to select an object before opening the inspector.", L"Error", MB_OK);
	}
}

void MFCMain::ToolBarButton4() //Function to create the object manipulation inspector
{
	
	if (m_ToolSystem.m_selectedObject > -1)
	{
		m_ObjectManip.SetObjectData(&m_ToolSystem.m_sceneGraph, &m_ToolSystem.m_selectedObject, &m_ToolSystem.m_toolInputCommands);
		m_ObjectManip.Create(IDD_DIALOG2);
		m_ObjectManip.ShowWindow(SW_SHOW);
	}
	else
	{
		MessageBox(m_toolHandle, L"Make sure to select an object before opening the inspector.", L"Error", MB_OK);
	}
	
}

void MFCMain::ToolBarButton5() //Function enable and disable terrain editing
{

	m_ToolSystem.onActionTerrain();

}



MFCMain::MFCMain()
{
}


MFCMain::~MFCMain()
{
}
