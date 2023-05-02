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

	float mouse_X;
	float mouse_Y;

	float mouse_X_prev;
	float mouse_Y_prev;

	bool mouse_LB_Down;
	bool mouse_RB_down;

	bool FocusCam;

	bool RButton;
<<<<<<< HEAD
	bool CopyDown;
	bool PasteDown;
	bool canScroll;


	int testingScroll;


=======
>>>>>>> parent of e2d0139 (Tried copy paste and arcball)
	bool isDragging;
};

	
