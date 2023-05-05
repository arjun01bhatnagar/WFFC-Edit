#pragma once
#include "pch.h"
#include "InputCommands.h"
#include <SimpleMath.h>

using namespace DirectX;
using namespace SimpleMath;

class ArcBall
{
public:
	float ArcBallSpeed;
	float RotateRate;

	DirectX::SimpleMath::Vector3 ArcBallPosition;
	DirectX::SimpleMath::Vector3 ArcBallCamOrientation;
	DirectX::SimpleMath::Vector3 ArcBallLookAt;
	DirectX::SimpleMath::Vector3 ArcBallLookDirection;
	DirectX::SimpleMath::Vector3 ArcBallRight;
	DirectX::SimpleMath::Matrix  ArcBallView;


	InputCommands* ArcBallInputCommands;

	DirectX::SimpleMath::Vector3 GetOrientation()
	{
		return ArcBallCamOrientation;
	};

	DirectX::SimpleMath::Matrix GetViewMatrix()
	{
		return ArcBallView;
	};

	ArcBall();
	~ArcBall();

	void Update(InputCommands* m_Inputcommands);
	void Inititalize(float width, float height);

	void SetPosition(Vector3 pos)
	{
		ArcBallPosition = pos;
	}

	void SetTarget(Vector3 TargetPos)
	{
		ArcBallLookAt = TargetPos;
	}

private:
	float arcBallWidth;
	float arcBallHeight;
};