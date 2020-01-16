#include <Engine/Engine.h>

class CameraController : public TEFGAS::Component
{
public:
	void Update();

	float yaw, pitch;
};