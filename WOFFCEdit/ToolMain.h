#pragma once

#include <afxext.h>
#include "pch.h"
#include "Game.h"
#include "sqlite3.h"
#include "SceneObject.h"
#include "InputCommands.h"
#include "CopyPaste.h"
#include <vector>


class ToolMain
{
public: //methods
	ToolMain();
	~ToolMain();

	//onAction - These are the interface to MFC
	int		getCurrentSelectionID();										//returns the selection number of currently selected object so that It can be displayed.
	void	onActionInitialise(HWND handle, int width, int height);			//Passes through handle and hieght and width and initialises DirectX renderer and SQL LITE
	//void	onActionFocusCamera();
	void	onActionLoad();													//load the current chunk
	afx_msg	void	onActionSave();											//save the current chunk
	afx_msg void	onActionSaveTerrain();									//save chunk geometry
	afx_msg void    onActionWireframe();
	afx_msg void    onFocusArcBall();
	afx_msg void    onActionTerrain();
	

	void	Tick(MSG *msg);
	void	UpdateInput(MSG *msg);


	//CopyPaste

	void Delete();
	SceneObject m_copy;
	void Copy();
	void Paste();
	

	//std::vector<std::vector<SceneObject>> m_scene_objects_memory;
	std::vector<SceneObject> m_scene_objects;
	//Game GameObject;
	
	//CopyPaste m_CopyPaste{ this };


	int CamTypetool;

	void SetCameraTypeTool(int cam)
	{
		CamTypetool = cam;
	}

	void UpdateDisplayList()
	{
		m_d3dRenderer.BuildDisplayList(&m_sceneGraph);
	};

	/*void StoreBackup();

	void Undo();
	void Redo();

	void Instantiate();
	void RemoveObject();
	void DuplicateObject();*/

public:	//variables
	std::vector<SceneObject>    m_sceneGraph;	//our scenegraph storing all the objects in the current chunk
	ChunkObject					m_chunk;		//our landscape chunk
	int m_selectedObject = -1;						//ID of current Selection
	

	std::vector <std::vector <SceneObject>> m_sceneObjectMem;

	std::vector<int>  PositionDiffX;
	std::vector<int>  PositionDiffY;

	

	InputCommands m_toolInputCommands;		//input commands that we want to use and possibly pass over to the renderer

	DirectX::XMFLOAT2 GetBrushData();
	/*void ToggleTerrainEdit()
	{
		m_d3dRenderer.m_TerrainEditModeActive = !m_d3dRenderer.m_TerrainEditModeActive;
	};*/

	void GetTerrainEditMode()
	{

	}

	


private:	//methods
	void	onContentAdded();


		
private:	//variables
	HWND	m_toolHandle;		//Handle to the  window
	Game	m_d3dRenderer;		//Instance of D3D rendering system for our tool
	
	CRect	WindowRECT;		//Window area rectangle. 
	char	m_keyArray[256];
	sqlite3 *m_databaseConnection;	//sqldatabase handle

	int m_width;		//dimensions passed to directX
	int m_height;
	int m_currentChunk;			//the current chunk of thedatabase that we are operating on.  Dictates loading and saving. 
	
	
};
