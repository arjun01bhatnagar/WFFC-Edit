#pragma once
#include "pch.h"
#include "InputCommands.h"
#include <SimpleMath.h>


class ArcBall
{
public:
	ArcBall();
	~ArcBall();

	void SetWindow(int width, int height, float fov);
	void UpdateAC(float deltaTime);
	DirectX::XMFLOAT4X4 GetViewMatrix();

private:
	DirectX::XMFLOAT3 m_lastMousePos;
	DirectX::XMFLOAT4X4 m_viewMatrix;
	DirectX::XMFLOAT4X4 m_ProjMatrix();
	bool m_isDragging;


	InputCommands* m_InputCommands;
};