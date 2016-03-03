#include "student.h"

Student::Student() {
    ///vacio
}

Student::Student(const Student& s) {
    code = s.code;
    name = s.name;
    career = s.career;
    birthDate = s.birthDate;
    startDate = s.startDate;
    score = s.score;
}

std::string Student::getCode() {

}

bool Student::operator==(const Student& s) {
    return code == s.code;
}

bool Student::operator!=(const Student& s) {
    return code != s.code;
}

bool Student::operator>(const Student& s) {
    return code > s.code;
}

bool Student::operator<=(const Student& s) {
    return code <= s.code;
}

bool Student::operator>=(const Student&) {
    return code >= s.code;
}

bool Student::operator<(const Student&) {

}

std::ostream& operator << (std::ostream& os,  Student& s){
    os << s.code << std::endl
        << s.name << std:: endl
        << s.career << std::endl
        << s.brithdate << std::endl
        << s.startDate << std::endl
        << s.score;
}
