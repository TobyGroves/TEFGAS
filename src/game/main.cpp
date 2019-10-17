#include <Engine/Engine.h>

#include <iostream>
#include <string>

class Test : public TEFGAS::Component
{
public:
	void Awake(std::string color)
	{
		std::cout << "I just woke up and feel " << color << std::endl;
	}

	void Start()
	{
		std::cout << "ohhh yes we started" << std::endl;
	}

	void Update()
	{
		std::cout << "oop its an update" << std::endl;

		getCore()->stop();
	}
};

int main()
{
	std::shared_ptr<TEFGAS::Core> c = TEFGAS::Core::initialize();
	std::shared_ptr<TEFGAS::Entity> e = c->addEntity();
	std::shared_ptr<Test> t = e->addComponent<Test>("Puce");

	c->start();
	 
	return 0;
}