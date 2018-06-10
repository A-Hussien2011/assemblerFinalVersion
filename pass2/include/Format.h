#ifndef FORMAT_H
#define FORMAT_H
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class Format
{
    public:
        Format();
        virtual ~Format();
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
        void setFormatType(int);
        string getObjectCode();

    private:
        string bin_to_hex(string);
};

#endif // FORMAT_H
