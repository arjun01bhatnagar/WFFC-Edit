#include "CopyPaste.h"
#include "ToolMain.h"


CopyPaste::CopyPaste(ToolMain* toolMain)
{
	m_ToolMain = toolMain;
}

void CopyPaste::CopySelectedObjects(std::vector<unsigned int> selectedObjectIDs)
{
	SceneObject gameObjectFromSelection;
	std::vector<SceneObject> selectedObjects;
	SceneObject newCopiedObject;

	for (size_t i = 0; i < selectedObjectIDs.size(); i++)
	{
		newCopiedObject = m_ToolMain->m_sceneGraph[m_ToolMain->IndexID(selectedObjectIDs[i])];

		selectedObjects.push_back(newCopiedObject);
	}

	if (selectedObjects.size() != 0)
	{
		m_CopiedObjects.clear();
		m_CopiedObjects = selectedObjects;
	}
}

void CopyPaste::PasteCopiedObjects()
{
	for (size_t i = 0; i < m_CopiedObjects.size(); i++)
	{
		m_CopiedObjects[i].posX += 2;
		m_CopiedObjects[i].posY += 2;
	}

	m_ToolMain->onActionPaste(m_CopiedObjects);
}