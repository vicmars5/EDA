#include "name.h"

Name::Name()
{
    //ctor
}

Name::~Name()
{
    //dtor
}
#include "name.h"
Name::Name()
{
    last= "";
    first= "";
}

Name::Name(std::string& l, std::string& f)
{
    last = l;
    first = f;
}

Name::Name(const Name&)
{

}

std::string Name::getLAst()
{

}

std::string Name::getFirst()
{

}

void Name::setFirst(const std::string&)
{

}

void Name::setLast(const std::string&)
{
    first = f;
}

bool Name::operator==(const Name&)
{
    return last + first == n.last + n.first;
}

bool Name::operator!=(const Name&)
{
    return !(*this == n);
}

bool Name::operator>(const Name&)
{
    return last+ first > n.last + n.first;
}

bool Name::operator<=(const Name&)
{
    return last + first <= n.last +n.first;
}

bool Name::operator>=(const Name&)
{
    return last + first >= n.last +n.first;

}

std::ostream& operator << (std::ostream& os,  Name& n){
    os << n.last << ", " << n.first;

    return os;
}
