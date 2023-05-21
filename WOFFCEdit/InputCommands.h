#pragma once


enum ToolState
{
	Pressed,
	Released,
	Held

};

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool rotRight;
	bool rotLeft;
	bool rotUP;
	bool rotDown;
	bool moveUp;
	bool moveDown;

	bool mouseButtonUp;

	float mouse_X;
	float mouse_Y;

	float mouse_X_prev;
	float mouse_Y_prev;

	bool mouse_LB_Down;
	bool mouse_RB_Down;

	bool FocusCam;

	bool RButton;

	bool TButton;

	bool BButton;

	bool NButton;

	bool CopyDown;
	bool PasteDown;
	bool canScroll;

	

	int testingScroll;

	bool ifOK;

	bool isDragging;
	

	bool dragObj;
	bool dragObjEnd;

	bool TerrainEnd;

	int DirTerrain;

	bool terrain;



	ToolState MouseLeftButtonState;
};




