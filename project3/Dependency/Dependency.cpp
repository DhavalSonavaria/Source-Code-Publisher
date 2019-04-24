#include "Dependency.h"
Dependency::Dependency(dep  dependencies_)
{
	for (auto i : dependencies_) 
	{
		
			std::string link = "<a href =" + i + ".html>" + "</a>";
			depen.push_back(link);
	}
}
	

 Dependency::dep  & Dependency::Dependencies() 
{
	return depen;
}


Dependency::~Dependency()
{
}
#ifdef TEST_DEP



void main()
{
	std::vector<std::string> depen = { "#include \"../abs/vdv/sdf.h\"","#include \"dhaval/dhaval/OOD/OOD.cpp\"" };
	Dependency d(depen);
	getchar();
}
#endif // TEST_DEP