#pragma once
#include"SceneObject.h"
#include <vector>

class CopyPaste
{
public:


	CopyPaste(class ToolMain* toolMain);
	void CopySelected(std::vector <unsigned int> selectedObjectID);
	void PasteCopied();




private:

	ToolMain* m_ToolMain;
	std::vector<SceneObject> m_CopiedObjects;
};