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


    int i = 0;
    const SymTab *st = symTab();
    if(st!=NULL)
    {

        SymTab::const_iterator it = st->begin();
        for (i=0; (it != st->end()); i++, ++it)
        {
            SymTabEntry *ste = (SymTabEntry *)(*it);
            if(ste->kind() == SymTabEntry::Kind::VARIABLE_KIND)
            {
                VariableEntry *ve = (VariableEntry *)ste;
                if(ve->varKind() != VariableEntry::VarKind::PARAM_VAR)
                {
                    break;
                }
            }
        }
    }
    if(i!=0)
    {
        printST(out, indent,'\0', '\0', false, 0, i);
    }
    out << ")";

    if((st != NULL && i < st->size()) || body())
    {
        out << " {";
	if(st != NULL && i < st->size())
	        printST(out, indent,'\0', ';',true, i, st->size());
	if(body())
		body()->printWithoutBraces(out, indent);
        out << "}";
    }

}






