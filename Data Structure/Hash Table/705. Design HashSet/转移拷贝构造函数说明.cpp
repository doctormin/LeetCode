#include <cstring>
using namespace std;

class MyString{
private:
    char * _data;
    size_t _len;
    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
public:
    //构造函数
    MyString(){
        _data = nullptr;
        _len = 0;
    }
    
    //构造函数
    MyString(const char * p){
        _len = strlen(p);
        _init_data(p);
    }

    //拷贝构造函数
    MyString(const MyString& str){
        _len = str._len;
        _init_data(str._data);
    }

    //=
    MyString& operator = (const MyString& str){
        if(this != &str){
            _len = str._len;
            _init_data(str._data);
        }
        return *this;
    }
    //转移拷贝构造函数
    MyString(MyString&& tmp){
        _len      = tmp._len;
        _data     = tmp._data;
        tmp._len  = 0;
        tmp._data = nullptr;
    }

    ~MyString(){
        delete [] _data;
    }
}