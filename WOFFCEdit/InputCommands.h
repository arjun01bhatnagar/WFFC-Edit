#pragma once

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

	int mouse_X;
	int mouse_Y;

	int mouse_X_prev;
	int mouse_Y_prev;

	bool mouse_LB_Down;
	bool mouse_RB_down;

	bool FocusCam;
};

	
