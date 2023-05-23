#pragma once

//Enum for defining states
enum ToolState
{
	Down,
	Up,
	Dragged

};

struct InputCommands
{
	//Controls for camera movement

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

	
	//Controls for camera rotation

	float mouse_X;
	float mouse_Y;

	float mouse_X_prev;
	float mouse_Y_prev;

	bool isDragging;

	//Mouse button bools

	bool mouse_LB_Down;
	bool mouse_RB_Down;


	//Misc Bools for input from keyboard and focusing
	bool FocusCam;

	bool RButton;

	bool FButton;

	bool ShiftButton;

	bool NButton;


	//Bools for copy and paste
	bool CopyDown;
	bool PasteDown;
	

	bool ifOK;



	//Bools for terrain editing
	bool TerrainEnd;

	int DirTerrain;

	bool terrain;



	ToolState MouseLeftButtonState;
};




