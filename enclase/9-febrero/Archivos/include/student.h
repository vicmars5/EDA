#ifndef STUDENT_H
#define STUDENT_H


struct Student
{
    public:
        Student();
        Student(const Student&);

        std::string getCode();

        ///comparable
        bool operator == (const Student&);
        bool operator != (const Student&);
        bool operator > (const Student&);
        bool operator <= (const Student&);
        bool operator >= (const Student&);
        bool operator < (const Student&);

        friend std::ostream& operator << (std::ostream&,  Student&);
        friend std::istream& operator >> (std::istream&, Student&);
    private:
        string code;
        Name name;
        Date birthDate;
        string carrera;

};

#endif // STUDENT_H
