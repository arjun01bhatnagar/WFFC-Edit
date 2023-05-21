#pragma once
#include "pch.h"
#include "InputCommands.h"
#include "StepTimer.h"
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


	void FocusCam(DirectX::XMFLOAT3 position, DirectX::XMFLOAT3 scale);  // , InputCommands* m_InputCommands);

	//XMFLOAT3 Lerp(DirectX:: XMFLOAT3 start, DirectX:: XMFLOAT3 end, float t);
	/*{
		float x = start.x + (end.x - start.x) * t;
		float y = start.y + (end.y - start.y) * t;
		float z = start.z + (end.z - start.z) * t;

		return XMFLOAT3(x, y, z);
	}*/
	void Lerp(DX::StepTimer const& t);

	//void Focus(const Vector3 objectPosition, float objectRadius, const XMFLOAT3 cameraDirection, XMFLOAT3 cameraPosition, float lerpSpeed);
	void Update(InputCommands* m_InputCommands, DX::StepTimer const& t);
	void Initialize(float width, float height);
	DirectX::SimpleMath::Vector3 M_from;
	DirectX::SimpleMath::Vector3 M_Towards;
	bool FocusCamera;
	float CamSpeed = 1.5;

private:
	float m_width;
	float m_height;
	float LerpRemaining;
	float lerp;
	//

	//std::vector<DisplayObject>			m_displayList;
};