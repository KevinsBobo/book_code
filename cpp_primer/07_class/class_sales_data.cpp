#include <iostream>
#include <string>

using namespace std;

class Sales_data{
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;

public:
#if 0
	Sales_data() = default;
	Sales_data(const string &book): bookNo(book){ }
	Sales_data(const string &book, const unsigned num,
			const double sellp, const double selep);
	Sales_data(istream &is){ is >> this->bookNo; }
#endif

	Sales_data(const string &book, unsigned num, double sellp, double salep)
		: bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep){
			if(sellingprice)
				discount = saleprice / sellingprice;
			cout << "This funtion accept bookNo, num, sellp salep 4 infomation" << endl; 
		}

	Sales_data() : Sales_data("", 0, 0, 0){
		cout << "This function not accept any infomation" << endl;
	}

	Sales_data(const string &book) : Sales_data(book, 0, 0, 0){
		cout << "This function accept bookNo infomation" << endl;
	}

	Sales_data(istream &is) : Sales_data(){
		is >> this->bookNo >> this->units_sold >> this->sellingprice >> this->saleprice;
		if(sellingprice)
			discount = saleprice / sellingprice;
		cout << "This function accept user input to be infomation" << endl;
	}

	string isbn() const { return bookNo; }
	Sales_data& combine( const Sales_data &rhs){
		units_sold += rhs.units_sold;
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) 
			/ (rhs.units_sold + units_sold);
		if(sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}

	double avg_price() const;
};

#if 0
Sales_data::Sales_data(const string &book, const unsigned num,
		const double sellp, const double salep){
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;
	if(sellingprice != 0)
		discount = saleprice / sellingprice;
}
#endif

inline double Sales_data::avg_price() const{
	if(units_sold)
		return saleprice;
	else
		return 0;
}

int main(){
	Sales_data first("123", 85, 128, 109);
	cout << first.isbn() << endl;
	Sales_data second;
	cout << second.isbn() <<endl; 
	Sales_data third("456");
	cout << third.isbn() << endl;
	Sales_data last(cin);
	cout << last.isbn() << endl;
	return 0;
}
