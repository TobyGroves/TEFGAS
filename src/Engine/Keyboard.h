#include <memory>
#include <vector>

namespace TEFGAS
{
	class Keyboard {
	public:
		bool getKey(int KeyCode);
		bool getKeyDown(int Keycode);
		bool getKeyUp(int KeyCode);

	private:
		std::vector<int> KeyCodes;


	};

}