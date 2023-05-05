#include"CopyPaste.h"
#include"ToolMain.h"


CopyPaste::CopyPaste(ToolMain* toolMain)
{
	m_ToolMain = toolMain;
}

void CopyPaste::CopySelected(std::vector <unsigned int> selectedObjectID)
{
	SceneObject gameObjectFromSelection;
	std::vector<SceneObject> selecteObjects;
	SceneObject newCopiedObject;

	for (int i = 0; i < selectedObjectID.size(); i++)
	{
		newCopiedObject = m_ToolMain->m_sceneGraph[m_ToolMain->IndexID(selectedObjectID.size())];


		selecteObjects.push_back(newCopiedObject);
	}

	if (selecteObjects.size() != 0)
	{
		m_CopiedObjects.clear();
		m_CopiedObjects = selecteObjects;
	}
}

void CopyPaste::PasteCopied()
{
	for (size_t i = 0; i < m_CopiedObjects.size(); i++)
	{
		m_CopiedObjects[i].posX += 2;
		m_CopiedObjects[i].posY += 2;
	}

	m_ToolMain->onActionPaste(m_CopiedObjects);
}