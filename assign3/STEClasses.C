#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
    printST(out, indent,'\0', ';', true);
}

void EventEntry::print(ostream& out, int indent) const
{
    out << "Event " << name();
    out << "(";
    printST(out, indent,'\0', '\0', false);
    out << ")";
}

void ClassEntry::print(ostream& out, int indent) const
{
    out <<  "Class " << name();
}

void VariableEntry::print(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
}

void FunctionEntry::print(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
    out << "(";
    printST(out, indent,'\0', '\0', false);
    out << ")";
}
