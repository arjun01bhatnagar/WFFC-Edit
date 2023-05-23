#pragma once
#include "pch.h"
#include "InputCommands.h"
#include "StepTimer.h"
#include <SimpleMath.h>

using namespace DirectX;
using namespace SimpleMath;

class ArcBall
{
public:
	
	float RotateRate;
	float radiusArcBall;
	
	DirectX::SimpleMath::Vector3 ArcBallCamOrientation;
	DirectX::SimpleMath::Vector3 ArcBallLookAt;
	DirectX::SimpleMath::Vector3 ArcBallLookDirection;
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

	void Update(InputCommands* m_Inputcommands, DX::StepTimer const& t);
	
	void Inititalize(float width, float height);
	DirectX::SimpleMath::Vector3 ArcBallFrom;
	DirectX::SimpleMath::Vector3 ArcBallTowards;

	void SetPosition(Vector3 pos);

	void SetTarget(Vector3 TargetPos)
	{
		ArcBallLookAt = TargetPos;
	}
	

private:
	float arcBallWidth;
	float arcBallHeight;
	
};