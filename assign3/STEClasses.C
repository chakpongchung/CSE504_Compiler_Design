#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
    printST(out, indent,'\0', ';', true);
}

void EventEntry::print(ostream& out, int indent) const
{
	// Add your code
}

void ClassEntry::print(ostream& out, int indent) const
{
	out<<"Class "<<name();
}
