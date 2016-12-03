#include <iostream>

using namespace std;

class Sales_data{
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;

public:
	Sales_data() = default;
	Sales_data(const string &book): bookNo(book){ }
	Sales_data(const string &book, const unsigned num,
			const double sellp, const double selep);
	Sales_data(istream &is){ is >> this->bookNo; }

	string isbn() const { return bookNo; }
	Sales_data& combine( const Sales_data &rhs){
		units_sold += rhs.units_sold;
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) 
			/ (rhs.units_sold + units_sold);
		if(sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}
};

Sales_data::Sales_data(const string &book, const unsigned num,
		const double sellp, const double salep){
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;
	if(sellingprice != 0)
		discount = saleprice / sellingprice;
}

