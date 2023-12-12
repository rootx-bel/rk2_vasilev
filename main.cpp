#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MusicalInstrument{
    private:
        char name[100];
        char material[100];
    public:
        MusicalInstrument(char name_n[], char material_n[])
        {
            strcpy(name, name_n);
            strcpy(material, material_n);
        }
        virtual ~MusicalInstrument() {};
        virtual void display() const{
            cout << name << endl;
            cout << material << endl;
        }
        void setFirst(char name_n[]){
		    strcpy(name, name_n);
        };
        void setSecond(char material_n[]){
            strcpy(material, material_n);
        };
};

class StringInstrument : public MusicalInstrument{
    private:
        int countstrun;
    public:
        void display() const override{
            MusicalInstrument::display();
            cout << countstrun << endl;
        }
        StringInstrument(char name_n[], char material_n[], int countstrun_n) : MusicalInstrument(name_n, material_n)
        {
            countstrun = countstrun_n;
        }
        ~StringInstrument() {};
};

class BrassInstrument : public MusicalInstrument{
    private:
        char typelatun[100];
    public:
        void display() const override{
            MusicalInstrument::display();
            cout << typelatun << endl;
        }
        BrassInstrument(char name_n[], char material_n[], char countstrun_n[]) : MusicalInstrument(name_n, material_n)
        {
            strcpy(typelatun, countstrun_n);
        }
        ~BrassInstrument() {};
};

void modif(MusicalInstrument* ptr){
	ptr->setFirst("rewrite");
	ptr->setSecond("rewrite");
}

int main(){
    vector<MusicalInstrument*> vec;
    vec.resize(4);
    vec[0] = new StringInstrument("test1","test1",3);
	vec[1] = new StringInstrument("test2","test2",4);
	vec[2] = new BrassInstrument("test3","test3","20/80");
    vec[3] = new BrassInstrument("test4","test4","60/40");
    for(const auto i: vec){
		i->display();
	}
    for(const auto i: vec){
		modif(i);
		i->display();
	}
    return 0;
}