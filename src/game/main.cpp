#include <Engine/Engine.h>

#include <iostream>
#include <string>

class TestScreen : public TEFGAS::Component
{
public:
	void onInit(std::string color)
	{
		std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		std::cout << "onTick" << std::endl;

		getCore()->stop();
	}
};

int main()
{
	std::shared_ptr<TEFGAS::Core> c = TEFGAS::Core::initialize();
	std::shared_ptr<TEFGAS::Entity> e = c->addEntity();
	std::shared_ptr<TestScreen> t = e->addComponent<TestScreen>("Green");

	c->start();

	return 0;
}