#include "classes.h"

using namespace std;

static vector<string> story;

void base::output(helper help) {

    // вывод дерева
    cout << "Object tree" << endl;
    cout << help.family[0]->get_name() << endl; // вывод корневого
    help.family[0]->out_tree("    ");

    string t;
//	if(help.error != "success"){ cout << "The head object " << help.error << " is not found"; return;}
    string path_one, path_two;
    while(1){
        cin >> path_one;
        if(path_one == "end_of_connections") break;
        cin >> path_two;
        if(!get_by_path(path_one, help)){ cout << "Object " << path_one << " not found" << endl; getline(cin, t);}
        if(!get_by_path(path_two, help)){ cout << "Handler object " << path_two << " not found" << endl;}
        if(!get_by_path(path_one, help) || !get_by_path(path_one, help)) continue;
        else get_by_path(path_one, help)->setConnection(SIGNAL_D(base, p_signal), get_by_path(path_two, help), HENDLER_D(base, p_hendler));

    }
    string command;
    cin >> command;
    if (command == "END") return;
    while (command != "END") {

        string path;
        cin >> path;
        string t;
        if(!get_by_path(path, help)){ story.push_back("Object " + path + " not found"); getline(cin, t); cin >> command;  continue; }
        if(command == "SET_CONNECT"){
            string pair_path; cin >> pair_path;
            if(!get_by_path(pair_path, help)){ story.push_back("Handler object " + pair_path + " not found"); getline(cin, t); cin >> command; continue; }
            get_by_path(path, help)->setConnection(SIGNAL_D(base, p_signal), get_by_path(pair_path, help), HENDLER_D(base, p_hendler));
        }

        else if(command == "DELETE_CONNECT"){

            string pair_path; cin >> pair_path;
            if(!get_by_path(pair_path, help)){ story.push_back("Handler object " + pair_path + " not found"); getline(cin, t); cin >> command; continue; }
            get_by_path(path, help)->deleteConnection(SIGNAL_D(base, p_signal), get_by_path(pair_path, help), HENDLER_D(base, p_hendler));

        }

        else if(command == "EMIT"){

            string sms; getline(cin, sms);
            get_by_path(path, help)->emitSignal(SIGNAL_D(base, p_signal), sms);

        }

        else if (command == "SET_CONDITION"){

            int ready; cin >> ready;
            this->get_by_path(path, help)->set_readiness(ready, help);

        }

        cin >> command;
    }
    for(int i = 0; i < story.size(); ++i){

        cout << story[i];
        if(story[i] != story[story.size() - 1]) cout << endl;

    }
}


void base::out_tree(string spaces){

    for(int i = 0; i < this->children.size(); ++i){

        cout << spaces << this->children[i]->get_name();
        cout << endl;
        this->children[i]->out_tree(spaces + "    ");

    }

} // функция вывода дерева

void base::out_readiness(string spaces){

    for(int i = 0; i < this->children.size(); ++i){

        cout << spaces << this->children[i]->get_name();
        if(this->children[i]->readiness) cout << " is ready";
        else cout << " is not ready";

        //проверка, чтобы не выводить последний перевод строки
        bool is_last_child = false;

        if(this->children[i]->children.empty() && i == this->children.size() - 1) {
            base *checker = this->children[i];
            while (checker->get_head()) {

                if (checker->get_head()->children.back() == checker) {
                    is_last_child = true;
                } else is_last_child = false;

                checker = checker->get_head();
            }
        }

        if(!is_last_child) cout << endl;
        this->children[i]->out_readiness(spaces + "    ");

    }
}


void base::change_name(string name) {

    this->name = name;

}

string base::get_name() {

    return name;

}

void base::change_head(base* p) {

    for(int i = 0; i < this->get_head()->children.size(); ++i){

        if(this->get_head()->children[i] == this){

            this->get_head()->children.erase(this->get_head()->children.begin() + i, this->get_head()->children.begin() + i + 1);

        }

    }

    this->head = p;
    p->children.push_back(this);

}

base* base::get_head() {

    return this->head;

}


base* base::search_by_name(string name, helper help, base* parent){

    for	(int i = 0; i < help.family.size(); ++i){

        if(help.family[i]->name == name && help.family[i]->get_head() == parent) return help.family[i];

    }
    return nullptr;
}

base *base::get_by_path(string path, helper help) {

    if (path == "/") return help.root; // корневой
    if (path == ".") return help.current; // текущий

    if (path.substr(0, 2) == "//") {
        path.erase(path.begin(), path.begin() + 2); // убрать "//" в начале пути
        base* pointer = new base;
        // поиск от корневого
        for(int i = 0; i < help.family.size(); ++i) if(help.family[i]->get_name() == path) return help.family[i];
        return nullptr;
    }

    string splited_object = "";
    base *parent = new base;
    if (path[0] == '/') {
        parent = help.root;
        path.erase(path.begin(), path.begin() + 1);
    } else parent = help.current;
    base *pointer_object = new base;
    while (path.find('/') != -1) {
        splited_object = path.substr(0, path.find('/'));
        path.erase(path.begin(), path.begin() + path.find('/') + 1);

        pointer_object = pointer_object->search_by_name(splited_object, help, parent);
        if (!pointer_object) return nullptr; // мы не получили nullptr и родителем объекта, полученного из текущей части координаты является parent
        parent = pointer_object;
    }
    //проверяем последнюю часть координаты
    pointer_object = pointer_object->search_by_name(path, help, parent);
    if (!pointer_object) return nullptr;
    if (!(pointer_object->get_head() == parent)) return nullptr;
    return pointer_object;
}


void base::set_readiness(int readiness, helper help){ // указатель изменить

    base* checker = this->get_head();
    while(checker != nullptr){ // если какой-то из головных отключен, проигнорировать команду

        if(checker->readiness == 0) return;
        checker = checker->get_head();

    }

    this->readiness = readiness;
    if(readiness == 0)

        for(int i = 0; i < help.family.size(); ++i)

            if(help.family[i]->get_head() != nullptr) // избежать обращение к полям nullptr
                if(help.family[i]->get_head()->readiness == 0) help.family[i]->readiness = 0;
}

string base::get_path_by_pointer() {
    string path = "";
    base* checker = this;
    if(checker->get_head() == nullptr) return "/";
    while(checker->get_head()){

        path = "/" + checker->get_name() + path;
        checker = checker->get_head();
    }
    return path;
}

void base::setConnection(void (base::* p_signal)(string&), base*p_ob_hendler, void(base::* p_hendler)(base*, string&)) {
    for (int i = 0; i < connections.size(); i++)
    {
        if (connections[i].p_signal == p_signal && connections[i].p_cl_base == p_ob_hendler &&
            connections[i].p_hendler == p_hendler)
            return;
    }

    connect element;
    element.p_cl_base = p_ob_hendler;
    element.p_hendler = p_hendler;
    element.p_signal = p_signal;
    connections.push_back(element);

}

void base::deleteConnection(void (base::* p_signal)(string&), base*p_ob_hendler, void(base::* p_hendler)(base*, string&)) {
    for (int i = 0; i < connections.size(); i++)
    {
        if (connections[i].p_signal == p_signal && connections[i].p_cl_base == p_ob_hendler && connections[i].p_hendler == p_hendler)
        {
            connections.erase(connections.begin() + i);
            return;
        }
    }
}

void base::p_signal(string &text) {
    story.push_back("Signal from " + this->get_path_by_pointer());
}

void base::emitSignal(void(base::* p_signal)(string&), string& command) {
    if(!readiness) return;

    (this->*p_signal)(command);
    for (int i = 0; i < connections.size(); i++)
    {
        if (connections[i].p_signal == p_signal)
        {
            void (base:: * p_hendler)(base*, string&);
            p_hendler = connections[i].p_hendler;
            (connections[i].p_cl_base->*p_hendler)(this, command);
        }
    }
}

void base::p_hendler(base* p_ob, string& text) {
    story.push_back("Signal to " + this->get_path_by_pointer() + " Text: " + text + " (class: " + to_string(p_ob->class_number) + ")");
}

void application::build_tree() { // построение дерева

    // инициализация корневого
    string name_root; cin >> name_root;
    base* root_el = new base(head, name_root);
    help.family.push_back(root_el);
    help.root = root_el;
    help.current = root_el;

    //считывание нового в цикле
    while (true) {

        string name_parent, path_parent;
        cin >> path_parent;
        if (path_parent == "endtree") break;
        if (this->get_by_path(path_parent, help)) name_parent = this->get_by_path(path_parent, help)->get_name();
        else{
            help.error = path_parent;
            return;
        }
        string name_child;
        cin >> name_child;
        int class_number;
        cin >> class_number;

        base* pointer = new base;
        for(int i = 0; i < help.family.size(); ++i){ // поиск головного для текущего

            if(help.family[i]->get_name() == name_parent) pointer = help.family[i];

        }

        base* obj; // инициализация нового объекта

        switch (class_number){
            case 1:
                obj = new base(pointer, name_child);
                break;
            case 2:
                obj = new cl2(pointer, name_child);
                obj->class_number = 2;
                break;
            case 3:
                obj = new cl3(pointer, name_child);
                obj->class_number = 3;
                break;
            case 4:
                obj = new cl4(pointer, name_child);
                obj->class_number = 4;
                break;
            case 5:
                obj = new cl5(pointer, name_child);
                obj->class_number = 5;
                break;
            case 6:
                obj = new cl6(pointer, name_child);
                obj->class_number = 6;
                break;
        }

        pointer->children.push_back(obj); // добавление текущего объекта в массив подчиненных его головного
        help.family.push_back(obj);

    }

}

void application::exec(){

    output(help);

}


