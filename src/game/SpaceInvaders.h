#include <Engine/Engine.h>

class SpaceInvaders : public TEFGAS::Component
{
public:
	void Awake();
	void Update();

	void SpawnRound(int round);


	std::list <std::shared_ptr<TEFGAS::Entity>> invaders;
};