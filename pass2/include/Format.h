#ifndef FORMAT_H
#define FORMAT_H
#include <string>

using namespace std;

class Format
{
    public:
        static const int FORMAT_3 = 3;
        static const int FORMAT_2 = 2;
        static const int FORMAT_4 = 4;
        void setNflag(bool);
        void setIflag(bool);
        void setXflag(bool);
        void setPflag(bool);
        void setBflag(bool);
        void setRegister1(int);
        void setRegister2(int);
        void setDispalcement(string);
        void setOperationCode(string);
        void setFormateType(int);
        string getObjectCode();


    private:
        ///set ur getters
        ///set booleans for all flags + format + strings
        ///set variables

};

#endif // FORMAT_H
