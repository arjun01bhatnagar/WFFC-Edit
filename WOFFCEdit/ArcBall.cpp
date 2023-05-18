#include"ArcBall.h"
using namespace DirectX;
using namespace DirectX::SimpleMath;

ArcBall::ArcBall()
{
	ArcBallSpeed = 0.30;
	RotateRate = 10;

	ArcBallPosition.x = 0.0f;
	ArcBallPosition.y = 0.0f;
	ArcBallPosition.z = 0.0f;

	ArcBallCamOrientation.x = 0;
	ArcBallCamOrientation.y = 0;
	ArcBallCamOrientation.z = 0;

	ArcBallLookAt.x = 0.0f;
	ArcBallLookAt.y = 0.0f;
	ArcBallLookAt.z = 0.0f;

	ArcBallLookDirection.x = 0.0f;
	ArcBallLookDirection.y = 0.0f;
	ArcBallLookDirection.z = 0.0f;

	ArcBallRight.x = 0.0f;
	ArcBallRight.y = 0.0f;
	ArcBallRight.z = 0.0f;

	//ArcBall


}

ArcBall::~ArcBall()
{

}

void ArcBall::Inititalize(float width, float height)
{
	arcBallWidth = width;
	arcBallHeight = height;
}

void ArcBall::Update(InputCommands* m_InputCommands)
{
	Vector3 planarMotionVector = ArcBallLookDirection;
	planarMotionVector.y = 0.0;

	if (m_InputCommands->RButton && m_InputCommands->isDragging)
	{
		float x = m_InputCommands->mouse_X - m_InputCommands->mouse_X_prev;
		float y = m_InputCommands->mouse_Y - m_InputCommands->mouse_Y_prev;

		/*float dx = x * ((2 * 3.1415) / 898); 
		float dy = y * (3.1415) / 499;*/ 

		float dx = x * ((2 * 3.1415) / arcBallWidth); 
		float dy = y * (3.1415) / arcBallHeight;

		if (x > 0)
		{
			ArcBallCamOrientation.y += RotateRate * dx;
		}

		else if (x < 0)
		{
			ArcBallCamOrientation.y -= RotateRate * (-1) * dx;// *(-1);
		}

		if (y > 0)
		{
			ArcBallCamOrientation.x -= RotateRate * dy;
		}

		else if (y < 0)
		{
			ArcBallCamOrientation.x += RotateRate * (-1) * dy;// * (-1);
		}

		if (ArcBallCamOrientation.x >= 90.f)
		{
			ArcBallCamOrientation.x = 89.f;
		}

		else if (ArcBallCamOrientation.x <= -90.f)
		{
			ArcBallCamOrientation.x = -89.f;
		}
	}

	ArcBallLookDirection.x = ArcBallLookAt.x + radiusArcBall * cos(ArcBallCamOrientation.y * 3.1415 / 180) * cos(ArcBallCamOrientation.x * 3.415 / 180) ;
	ArcBallLookDirection.y = ArcBallLookAt.y + radiusArcBall * sin(ArcBallCamOrientation.x * 3.1415 / 180);
	ArcBallLookDirection.z = ArcBallLookAt.z + radiusArcBall * sin(ArcBallCamOrientation.y * 3.1415 / 180) * cos(ArcBallCamOrientation.x * 3.1415 / 180);


	ArcBallView = Matrix::CreateLookAt(ArcBallLookDirection, ArcBallLookAt, Vector3::UnitY);

}

void ArcBall::SetPosition(Vector3 pos)
{
	ArcBallLookAt = pos;
	radiusArcBall = 5;
}
