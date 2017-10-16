#include <string>
#include <iostream>
#include <vector>

//by Łuszczki Marcin 2017 | C++/11	polimorphism	iterator
/* 
task found in some list of interview questions:

"Na rozgrzewke daje cos takiego:
Zaprojektowac hierarchie klas Zwierzatko, Kotek, Piesek. Kazda ma miec metode daj_glos().

Tu pytam jak defniujemy interfejs w C++ (klasa czysto abstrakcyjna itp, co daje virtual, czy potrzebny destuktor).

Zdefiniowac vector wskaznikow na zwierzatka, wrzucic tam pare kotkow i pieskow. 
Dalej przechodzimy po wektorze wykonujac polimorficzny call i zwierzatka daja glos (wypas :P). 
Najlepszy foreach z boost::bind, potem jakis ptr_fun, potem iteratory (czy beda const? :P) a potem zwykly for (ostatecznie)."
*/

using namespace std;

class Animal
{
public:
        Animal();
        virtual ~Animal();
        virtual void sound() {
                cout << "Animal sound" << endl;
        }
};

Animal::Animal()
{
        cout << "Animal made" << endl;
}

Animal::~Animal()
{
        cout << "Animal passed away" << endl;
}

class Dog : public Animal
{
public:
        Dog();
        ~Dog();
        virtual void sound() {
                cout << "Dog sound" << endl;
        }
};

Dog::Dog()
{
        cout << "Dog made" << endl;
}

Dog::~Dog()
{
        cout << "Dog passed away" << endl;
}

class Fish : public Animal
{
public:
        Fish();
        ~Fish();
        virtual void sound() {
                cout << "Fish sound" << endl;
        }
};

Fish::Fish()
{
        cout << "Fish made" << endl;
}

Fish::~Fish()
{
        cout << "Fish passed away" << endl;
}



int main()
{
        std::cout <<"1st way - initializer lists" << endl;
        std::vector<Animal*> vec1 = {new Dog, new Fish, new Dog};
        
        std::cout << endl << "2 nd way - pushing elements to vector" << endl;
        std::vector<Animal*> vec2;
        vec2.push_back(new Fish);
        vec2.push_back(new Dog);
        vec2.push_back(new Fish);
        
        std::cout << endl << "1st way of iteration" << endl;
        for(unsigned int i = 0; i < vec1.size(); ++i) {
          vec1.at(i)->sound();
        }
        
        std::cout << endl << "2nd way of iteration " << endl;
        for(std::vector<Animal*>::const_iterator it = vec2.begin(); it != vec2.end(); ++it) {
          (*it)->sound();
        }
        
        std::cout << endl << "Deletion of dynamically  allocated elements in vec1 with 1st method" << endl;
        for(std::vector<Animal*>::const_iterator it = vec1.begin(); it != vec1.end(); ++it) {
          delete *it;
        }
        
        std::cout << endl << "Deletion of dynamically allocated elements in vec2 with 2nd method (range based for loop)" << endl;
        for(auto i : vec2) {
          delete i;
        }
        
        std::vector<Animal*> vec3 = {new Fish, new Fish, new Dog};
        std::cout << endl << "Simple for way" << endl;
        for(unsigned i = 0; i < vec2.size(); ++i) { delete vec2.at(i);}
        
		system("pause");
        return 0;
}