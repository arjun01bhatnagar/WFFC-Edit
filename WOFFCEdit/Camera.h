#pragma once
#include "pch.h"
#include "InputCommands.h"
#include "StepTimer.h"
#include <SimpleMath.h>

class Camera
{
public: 

	//functionality
	float								m_movespeed;
	float                               m_camRotRate;

	//camera
	//Variables for the components of the camera

	DirectX::SimpleMath::Vector3		m_camPosition;
	DirectX::SimpleMath::Vector3		m_camOrientation;
	DirectX::SimpleMath::Vector3		m_camLookAt;
	DirectX::SimpleMath::Vector3		m_camLookDirection;
	DirectX::SimpleMath::Vector3		m_camRight;
	DirectX::SimpleMath::Matrix         m_view;
	
	

	InputCommands* m_InputCommands;

	DirectX::SimpleMath::Vector3 GetOrientation() //Getting the correct orientation of the camera
	{
		return m_camOrientation;
	};

	DirectX::SimpleMath::Matrix GetViewMatrix() //Getting the view matrix
	{
		return m_view;
	};

	Camera();
	~Camera();

	


	void FocusCam(DirectX::XMFLOAT3 position, DirectX::XMFLOAT3 scale);  //Definition of function to focus the camera on a selected object


	void Lerp(DX::StepTimer const& t); //Function for lerping the camera to the object

	
	void Update(InputCommands* m_InputCommands, DX::StepTimer const& t);
	void Initialize(float width, float height);


	//Vectors for gathering data about the position of 
	//the camera and position of object to calculate distance between the two

	DirectX::SimpleMath::Vector3 M_from;
	DirectX::SimpleMath::Vector3 M_Towards;
	
	float CamSpeed = 1.5;

private:

	//Window
	//Variables required for the focus
	//and lerping functions

	float m_width;
	float m_height;
	float LerpRemaining;
	float lerp;
	
};