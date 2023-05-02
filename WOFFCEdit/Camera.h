#pragma once
#include "pch.h"
#include "InputCommands.h"
#include <SimpleMath.h>

//#define width;
//#define height;

class Camera
{
public: 
	//functionality
	float								m_movespeed;
	float                               m_camRotRate;

	//camera
	DirectX::SimpleMath::Vector3		m_camPosition;
	DirectX::SimpleMath::Vector3		m_camOrientation;
	DirectX::SimpleMath::Vector3		m_camLookAt;
	DirectX::SimpleMath::Vector3		m_camLookDirection;
	DirectX::SimpleMath::Vector3		m_camRight;
	DirectX::SimpleMath::Matrix         m_view;
	
	

	InputCommands* m_InputCommands;

	DirectX::SimpleMath::Vector3 GetOrientation()
	{
		return m_camOrientation;
	};

	DirectX::SimpleMath::Matrix GetViewMatrix()
	{
		return m_view;
	};

	Camera();
	~Camera();

	//void SetCameraScreenSize(int &w, int &h);


	void Update(InputCommands* m_InputCommands);

	//void FocusCam(DirectX::XMFLOAT3 position, DirectX::XMFLOAT3 scale, InputCommands* m_InputCommands);
};