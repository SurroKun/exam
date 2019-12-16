#include "l1.h"
#include "ui_l1.h"
#include <QTreeWidgetItem>
#include <string.h>
#include <set>
using namespace std;
class Technology;

struct T;

bool operator<(const T& a, const T& b) { return false; }

L1::L1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::L1)
{
    ui->setupUi(this);
}

L1::~L1()
{
    delete ui;
}

class Company {
public:
    string name;
    set<T> List_Of_Technology, History_Of_Technology, Duty_Technology;
    string Strategy_Name;
    int time, money;

    Company() = default;

    Company(string name, set<T> List_Of_Technology, set<T> History_Of_Technology, set<T> Duty_Technology) :
        name(name),
        List_Of_Technology(List_Of_Technology),
        History_Of_Technology(History_Of_Technology),
        Duty_Technology(Duty_Technology) {
    }

    friend ostream& operator<<(ostream& s, Company& c);

};

class Technology {
public:
    string name;
    int time;
    int price;
    int priceForLicense;
    vector<Technology> otherTechnology;
    vector<Company> company;

    Technology() = default;

    Technology(string name, int time,
        int price, int priceForLicense, vector<Technology> otherTechnology) :
        name(name),
        time(time),
        price(price),
        priceForLicense(priceForLicense),
        otherTechnology(otherTechnology) {
    }

    void addCompany(Company company) { this->company.push_back(company); }


    friend ostream& operator<<(ostream& s, const Technology& t) {
        s << "Technology :";
        s << "Name = " << t.name << "\n";
        s << "Time =" << t.time << "\n";
        s << "Price = " << t.price << "\n";
        s << "Other Technology ( ";
        for (auto a : t.otherTechnology)s << a.name << " ";
        s << " )";
        s << "priceForLicense = " << t.priceForLicense << "\n";
        for (auto a : t.company)s << a << " ";
        s << ")";
        s << "\n________________________________________________________________________________\n";
        return s;
    }
};

struct T
{
    int start, finish;
    Technology technology;
};

void one_day(Company company,int day) {
    if (company.Strategy_Name == "S1") {
        for (auto a : company.List_Of_Technology) {
            for (auto b : company.History_Of_Technology)if (a.technology.name == b.technology.name)goto next_step1;
            a.start = day;
            a.finish = a.technology.time + day;
            for (auto b : a.technology.otherTechnology)company.History_Of_Technology.insert({ day,day,b });
            company.History_Of_Technology.insert(a);
        next_step1:;
        }
    }
    if (company.Strategy_Name == "S2") {
        for (auto a : company.List_Of_Technology) {
            for (auto b : company.History_Of_Technology)if (a.technology.name == b.technology.name)goto next_step2;
            a.start = day;
            for (auto b : a.technology.otherTechnology) {
                for (auto c : company.History_Of_Technology)if (c.technology.name == b.name)goto next_step3;
                company.History_Of_Technology.insert({ day,day += b.time,b });
            next_step3:;
            }
            a.finish= a.technology.time + day;
        next_step2:;
        }
    }
}
Technology t1("t1", 70, 12, 0, {});
Technology t2("t2", 87, 56, 50, {t1});
Technology t3("t3", 89, 32, 12, {t1,t2});

Company c1("c1",   { {0,0, t1 } }, { { 0,0, t1 } }, { {} });
Company c2("c2", { {0,0, t3 }  ,  {0,0, t2 } }, { { 0,0, t1 } }, { {} });
Company c3("c2", { {0,0, t3 } }, { { 0,0, t1 } }, { {} });

void L1::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString e,s="";

        e=item->text(column);
        if(e=="First Tech"){


            s += "Technology :";
            s += "Name = " ;
            s += t1.name.c_str() ;
            s += "\n";
            s += "Time =" +  e.number(t1.time) + "\n";
            s += "Price = " +  e.number(t1.price) + "\n";
            s += "Other Technology ( ";
            for (auto a : t1.otherTechnology){s += a.name.c_str() ;
            s+= " ";}
            s += " )";
            s += "priceForLicense = " +  e.number(t1.priceForLicense) + "\n";
            for (auto a : t1.company){s += a.name.c_str();s+= " ";}
            s += ")";
            s += "\n___________________________________________________________________________\n";
            ui->textBrowser->setText(s);

        }
        if(e=="Second Tech"){


            s += "Technology :";
            s += "Name = " ;
            s += t2.name.c_str() ;
            s += "\n";
            s += "Time =" +  e.number(t2.time) + "\n";
            s += "Price = " +  e.number(t2.price) + "\n";
            s += "Other Technology ( ";
            for (auto a : t2.otherTechnology){s += a.name.c_str() ;
            s+= " ";}
            s += " )";
            s += "priceForLicense = " +  e.number(t2.priceForLicense) + "\n";
            for (auto a : t2.company){s += a.name.c_str();
                    s+= " ";}
            s += ")";
            s += "\n___________________________________________________________________________\n";
            ui->textBrowser->setText(s);

        }
        if(e=="Third Tech"){


            s += "Technology :";
            s += "Name = " ;
            s += t3.name.c_str() ;
            s += "\n";
            s += "Time =" +  e.number(t3.time) + "\n";
            s += "Price = " +  e.number(t3.price) + "\n";
            s += "Other Technology ( ";
            for (auto a : t3.otherTechnology){s += a.name.c_str() ;
            s+= " ";}
            s += " )";
            s += "priceForLicense = " +  e.number(t3.priceForLicense) + "\n";
            for (auto a : t3.company){s += a.name.c_str();
                    s+= " ";}
            s += ")";
            s += "\n______________________________________________________\n";
            ui->textBrowser->setText(s);

        }

}

void L1::on_treeWidget_2_itemClicked(QTreeWidgetItem *item, int column)
{
    QString e,s="";

        e=item->text(column);
        if(e=="First"){
            s += "Company :\n";
            s += "Name = ";
            s+= c1.name.c_str();
            s+="\n";
            s += "ListOfTechnology =" ;
            for (auto a : c1.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
            s += "\n";
            s += "HistoryOfTechnology = ";
            for (auto a : c1.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n";
            s += "DutyTechnology = ";
            for (auto a : c1.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n___________________________________________________________________________\n";
            ui->textBrowser->setText(s);

        }
        else if(e=="Second"){
            s += "Company :\n";
            s += "Name = ";
            s+= c2.name.c_str();
            s+="\n";
            s += "ListOfTechnology =" ;
            for (auto a : c2.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
            s += "\n";
            s += "HistoryOfTechnology = ";
            for (auto a : c2.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n";
            s += "DutyTechnology = ";
            for (auto a : c2.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n___________________________________________________________________________\n";
            ui->textBrowser->setText(s);

        }
        else if(e=="Third"){
            s += "Company :\n";
            s += "Name = ";
            s+= c3.name.c_str();
            s+="\n";
            s += "ListOfTechnology =" ;
            for (auto a : c3.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
            s += "\n";
            s += "HistoryOfTechnology = ";
            for (auto a : c3.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n";
            s += "DutyTechnology = ";
            for (auto a : c3.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
            s += "\n___________________________________________________________________________\n";
            ui->textBrowser->setText(s);

        }
       else ui->textBrowser->setText(e);
}
