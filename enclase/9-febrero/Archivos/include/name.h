#ifndef NAME_H
#define NAME_H


class Name
{
    public:
        Name();
        Name(std::string, std::string);
        Name(const Name&);

        std::string getLAst();
        std::string getFirst();

        void setFirst(const std::string&);
        void setLast(const std::string&);


        ///Comparable
        bool operator == (const Name&);
        bool operator != (const Name&);
        bool operator > (const Name&);
        bool operator <= (const Name&);
        bool operator >= (const Name&);
        bool operator < (const Name&);


        friend std::ostream& operator << (std::ostream&,  Name&);
        friend std::istream& operator >> (std::istream&, Name&);
    protected:
    private:
};

#endif // NAME_H
