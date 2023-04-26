#include "Camera.h"
using namespace DirectX;
using namespace DirectX::SimpleMath;

Camera::Camera()
{

	//functional
	m_movespeed = 0.30;
	m_camRotRate = 3.0;

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

	m_camOrientation.x = 0.0f;
	m_camOrientation.y = 0.0f;
	m_camOrientation.z = 0.0f;

	
	
	

}

Camera::~Camera()
{

}

void Camera::Update(InputCommands* m_InputCommands)
{
	Vector3 planarMotionVector = m_camLookDirection;
	planarMotionVector.y = 0.0;



	if (m_InputCommands->rotRight)
	{
		m_camOrientation.y -= m_camRotRate;
	}
	if (m_InputCommands->rotLeft)
	{
		m_camOrientation.y += m_camRotRate;
	}


	/*if (m_InputCommands->mouse_RB_down)
	{
	}*/


	//}
	/*if (m_InputCommands->isDragging == true)
	{*/

	if (!m_InputCommands->mouse_RB_down)
	{

		m_InputCommands->isDragging = false;
	}
		if (m_InputCommands->mouse_RB_down && m_InputCommands->isDragging)
		{
			if (m_InputCommands->mouse_X < m_InputCommands->mouse_X_prev)
			{
				m_camOrientation.y += m_camRotRate;

			}

			else if (m_InputCommands->mouse_X > m_InputCommands->mouse_X_prev)
			{
				m_camOrientation.y -= m_camRotRate;
			}

			else if (m_InputCommands->mouse_Y < m_InputCommands->mouse_Y_prev)
			{
				m_camOrientation.x += m_camRotRate;
			}

			else if (m_InputCommands->mouse_Y > m_InputCommands->mouse_Y_prev)
			{
				m_camOrientation.x -= m_camRotRate;
			}
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

	m_view = Matrix::CreateLookAt(m_camPosition, m_camLookAt, Vector3::UnitY);
}


//void Camera::FocusCam(XMFLOAT3 position, XMFLOAT3 scale, InputCommands* m_InputCommands)
//{
//	m_camOrientation = Vector3(225, 180, 0);
//
//	m_camPosition = position - (XMFLOAT3(0, -5, 5) * scale);
//
//	Update(m_InputCommands);
//
//	
//}

