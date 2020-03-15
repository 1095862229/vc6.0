#include <iostream>

#include <string>

using namespace std;

class BirthDate {

public:

    BirthDate(int,int,int);

    void display();

    void setbirthday(int,int,int);

private:

    int year;

    int month;

    int day;

};

class Teacher

{

public:

    Teacher(int,string,char);

    void display();

private:

    int num;

    string name;

    char sex;

};



class Professor:public Teacher

{

public:

    Professor(int,string,char,BirthDate);

    void display();

    void setbirthday(int,int,int);

private:

    BirthDate birthday;

};



主函数已给定如下，提交时不需要包含，会自动添加到程序尾部

/* C++代码 */

int main()

{

    int num;

    string name;

    char sex;

    int year,month,day;

    cin>>num>>name>>sex;

    cin>>year>>month>>day;

    Professor prof(num,name,sex,BirthDate(year,month,day));

    cin>>year>>month>>day;

    prof.setbirthday(year,month,day);

    prof.display();

    return 0;

}