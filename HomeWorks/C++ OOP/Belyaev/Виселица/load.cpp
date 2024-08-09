#include "load.h"

Load::Load() : size{ 0 }, path{ nullptr }
{

}

Load::Load(const char* path) : size{ strlen(path) }, path{ path }
{
	
}