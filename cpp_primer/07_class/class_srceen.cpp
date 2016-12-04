#include <iostream>
#include <string>

using namespace std;

class Window_mgr{
public:
	void clear();
};

class Screen{
friend void Window_mgr::clear();

private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;

public:
	Screen() = default;
	Screen(unsigned ht, unsigned wd): height(ht), width(wd), contents(ht * wd, ' '){ }
	Screen(unsigned ht, unsigned wd, char c): height(ht), width(wd), contents(ht * wd, c){ }

	Screen& move(unsigned ht, unsigned wd){
		cursor = ht * width + wd;
		return *this;
	}
	Screen& set(char c){
		contents[ cursor ] = c;
		return *this;
	}
	Screen& display(ostream &os){
		os << contents;
		return *this;
	}
};

void Window_mgr::clear(){
	Screen myScreen(10, 20, 'X');
	cout << "Befor Clear, myScreen's contents is: " << endl;
	cout << myScreen.contents << endl;

	for(auto &c : myScreen.contents){
		c = '#';
	}

	cout << "After clear, myScreen's contents is: " << endl;
	cout << myScreen.contents << endl;
}

int main(){
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display( cout );
	cout << endl;

	Window_mgr w;
	w.clear();

	return 0;
}
