#pragma once
#include "afxdialogex.h"
#include "resource.h"
#include "afxwin.h"
#include "SceneObject.h"
#include "InputCommands.h"
#include <vector>

class ObjectManip : public CDialogEx
{
	DECLARE_DYNAMIC(ObjectManip)

public:
	ObjectManip(CWnd* pParent, std::vector<SceneObject>* SceneGraph);

	ObjectManip(CWnd* pParent = NULL);
	virtual ~ObjectManip();
	void SetObjectData(std::vector<SceneObject>* SceneGraph, int* Selection, InputCommands* input);	//passing in pointers to the data the class will operate on.

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void End();		//kill the dialogue
	afx_msg void Select();	//Item has been selected
	

	std::vector<SceneObject>* m_sceneGraph;
	int* m_currentSelection;
	InputCommands* m_Inputcommands;

	

	DECLARE_MESSAGE_MAP()
public:
	// Control variable for more efficient access of the listbox
	CListBox m_listBox;
	virtual BOOL OnInitDialog() override;
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnd();
	afx_msg void OnLbnSelchangeList1();


	//Variables to get the value from control boxes
	float PosX;
	float PosY;
	float PosZ;
	
	float RotX;
	float RotY;
	float RotZ;

	float ScaleX;
	float ScaleY;
	float ScaleZ;

	int current = 0;
	bool isSelected;


	
};


INT_PTR CALLBACK SelectProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam);