#include "File.h"

void File::WriteFile()
{
	std::ofstream out;
	out.open(_path, std::ios::app);
	if (out.is_open())
	{

		cout << "Writing success!";
	}
	out.close();
}
