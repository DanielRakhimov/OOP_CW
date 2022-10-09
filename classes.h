#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class base;
class helper;
class cl2;
class cl3;
class cl4;
class cl5;
class cl6;
struct connect;

struct connect{

    base* p_cl_base;
    void (base::* p_hendler)(base* p_ob, string&);
    void (base::* p_signal)(string&);

};


class base
{

public:

    int class_number = 1;
    vector <base*> children = {}; // массив подчиненных объектов
    vector <connect> connections; // массив установленных связей
    string get_name(); // функция получения имени
    void change_head(base* point); // функция изменения головного объекта
    void change_name(string name); // функция изменения имени
    base* search_by_name(string name, helper help, base* parent); // поиск по имени
    void set_readiness(int readiness, helper help); // установка готовности

    void setConnection(void (base::* p_signal)(string&), base*p_ob_hendler, void(base::* p_hendler)(base*, string&));
    void deleteConnection(void (base::* p_signal)(string&), base*p_ob_hendler, void(base::* p_hendler)(base*, string&));
    void emitSignal(void(base::* p_signal)(string&), string& command);
    void p_signal(string& text);
    void p_hendler(base* p_ob, string& text);


    base(base* pointer, string name = "Object") {

        this->head = pointer;
        this->name = name;

    }

    base() = default;

protected:
    int readiness = 1; // готовность
    string name; // наименование объекта
    base* head; // указатель на головной объект
    void output(helper help); // функция вывода
    void out_tree(string spaces); // функция вывода дерева
    void out_readiness(string spaces); // функция вывода готовности
    base* get_head(); // функция получения головного объекта
    base* get_by_path(string path, helper help); // поиск по координате
    string get_path_by_pointer(); // поиск координаты текущего


    ~base() = default;

};


class helper: public base{
public:
    base* root = nullptr;
    base* current;
    string error = "success";
    vector <base*> family; // массив всех объектов

};

class application: public base{
protected:
    helper help;
public:

    application() = default;
    application(base* point) {

        head = point;

    }
    ~application() = default;
    void build_tree();
    void exec();

};

class cl2: public base{
public:
    cl2(base* pointer, string name): base(pointer, name){}

};

class cl3: public cl2{
public:
    cl3(base* pointer, string name): cl2(pointer, name){}

};

class cl4: public cl3{
public:
    cl4(base* pointer, string name): cl3(pointer, name){}

};

class cl5: public cl4{
public:
    cl5(base* pointer, string name): cl4(pointer, name){}

};

class cl6: public cl5{
public:
    cl6(base* pointer, string name): cl5(pointer, name){}
};
#define SIGNAL_D(S, signal_f) ((void(S::*) (string&))(&S::signal_f)) //для получения указателя на метод сигнала
#define HENDLER_D(H, hendler_f) ((void(H::*) (base*, string&))(&H::hendler_f)) //для получения указателя на метод обработчика

#endif
