#include "Camera.h"
using namespace DirectX;
using namespace DirectX::SimpleMath;

Camera::Camera()
{

	//functional
	m_movespeed = 0.30;
	m_camRotRate = 10;

	//camera
	m_camPosition.x = 0.0f;
	m_camPosition.y = 3.7f;
	m_camPosition.z = -3.5f;

	m_camOrientation.x = 0;
	m_camOrientation.y = 0;
	m_camOrientation.z = 0;

	m_camLookAt.x = 0.0f;
	m_camLookAt.y = 0.0f;
	m_camLookAt.z = 0.0f;

	m_camLookDirection.x = 0.0f;
	m_camLookDirection.y = 0.0f;
	m_camLookDirection.z = 0.0f;

	m_camRight.x = 0.0f;
	m_camRight.y = 0.0f;
	m_camRight.z = 0.0f;

	/*m_camOrientation.x = 0.0f;
	m_camOrientation.y = 0.0f;
	m_camOrientation.z = 0.0f;*/

	
	
	

}

Camera::~Camera()
{

}


void Camera::Initialize(float width, float height)
{
	m_width = width;
	m_height = height;
	

}

void Camera::Update(InputCommands* m_InputCommands, DX::StepTimer const& t)
{
	Vector3 planarMotionVector = m_camLookDirection;
	planarMotionVector.y = 0.0;
	if (LerpRemaining > 0)
	{
		Lerp(t);
	}

	
	if (m_InputCommands->mouse_RB_Down && m_InputCommands->isDragging)
	{
		

			float x = m_InputCommands->mouse_X - m_InputCommands->mouse_X_prev;
			float y = m_InputCommands->mouse_Y - m_InputCommands->mouse_Y_prev;

			float dx = x * ((2 * 3.1415) / m_width);
			float dy = y * (3.1415) / m_height;
			

			if (x > 1)
			{
				m_camOrientation.y += m_camRotRate * dx;
			}
			else if (x < -1)
			{
				m_camOrientation.y -= m_camRotRate * dx * (-1);
			}

			if (y > 1)
			{
				m_camOrientation.x -= m_camRotRate * dy;
			}

			else if (y < -1)
			{

				m_camOrientation.x += m_camRotRate * dy * (-1);

			}

			if (m_camOrientation.x >= 90.f)
			{
				m_camOrientation.x = 89.f;
			}

			else if (m_camOrientation.x <= -90.f)
			{
				m_camOrientation.x = -89.f;
			}

		/*	if (m_camOrientation.y < -85.f)
			{
				m_camOrientation.y = -85.f;
			}

			if (m_camOrientation.y > 85.f)
			{w
				m_camOrientation.y = 85.f;
			}*/



		//}
	}
	

	m_camLookDirection.x = cos(m_camOrientation.y * 3.1415 / 180) * cos(m_camOrientation.x * 3.1415 / 180); //sin((m_camOrientation.y) * 3.1415 / 180);
	m_camLookDirection.y = sin(m_camOrientation.x * 3.1415 / 180);//cos((m_camOrientation.y) * 3.1415 / 180);
	m_camLookDirection.z = sin(m_camOrientation.y * 3.1415 / 180) * cos(m_camOrientation.x * 3.1415 / 180);

	m_camLookDirection.Normalize();

	//create right vector from look Direction
	m_camLookDirection.Cross(Vector3::UnitY, m_camRight);

	//process input and update stuff
	if (m_InputCommands->forward)
	{
		m_camPosition += m_camLookDirection * m_movespeed;
	}
	if (m_InputCommands->back)
	{
		m_camPosition -= m_camLookDirection * m_movespeed;
	}
	if (m_InputCommands->right)
	{
		m_camPosition += m_camRight * m_movespeed;
	}
	if (m_InputCommands->left)
	{
		m_camPosition -= m_camRight * m_movespeed;
	}

	//update lookat point
	m_camLookAt = m_camPosition + m_camLookDirection;
	//m_camPosition = m_camLookAt + m_camLookDirection;

	m_view = Matrix::CreateLookAt(m_camPosition, m_camLookAt, Vector3::UnitY);
}



void Camera::Lerp(DX::StepTimer const& t)
{
	
	LerpRemaining -= t.GetElapsedSeconds();
	float lerpFac = (lerp - LerpRemaining) / lerp;
	m_camPosition = Vector3::Lerp(M_from, M_Towards, lerpFac);

}

void Camera::FocusCam(XMFLOAT3 position,XMFLOAT3 scale)
{

	//float LerpFactor = 0.1f;

	LerpRemaining = 0.5;
	lerp = 0.5;
	m_camOrientation = Vector3(-30, 0, 0);
	//m_camPosition = position - (XMFLOAT3(2.5, -2, 0) * scale);
	M_Towards = position - (XMFLOAT3(2.5, -2, 0) * scale);
	M_from = m_camPosition;
	FocusCamera = true;
	


}



