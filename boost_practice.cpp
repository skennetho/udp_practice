#include<iostream>
#include<fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
 
using namespace std;
 
class tst{
public:
    friend class boost::serialization::access;
 
    tst(string sName, int sage, float spi)
        :Name(sName), age(sage), pi(spi)
    {}
 
    tst(){
    }
 
    string Name;
    int age;
    float pi;
 
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & Name;
        ar & age;
        ar & pi;
    }
 
 
};
 
 
int main(){
 
    tst T("Tab", 31, 3.1415);
    tst* pT = new tst("Bat", 13, 2.5);
 
    ofstream output("output.txt", ios::binary);
 
    boost::archive::text_oarchive oa(output);
    oa << T;
    output.close();
 
    ifstream input("output.txt", ios::binary);
    boost::archive::text_iarchive ia(input);
 
    tst TT;
    ia >> TT;
 
    cout << TT.Name << endl;
    cout << TT.age << endl;
    cout << TT.pi << endl;
 
    ofstream pout("pout.txt", ios::binary);
    boost::archive::text_oarchive poa(pout);
    poa << pT;
    pout.close();
 
    ifstream pin("pout.txt", ios::binary);
    boost::archive::text_iarchive pia(pin);
 
    tst* pTT;
    pia >> pTT;
 
    cout << pTT->Name << endl;
    cout << pTT->age << endl;
    cout << pTT->pi << endl;
 
    return 0;
}
