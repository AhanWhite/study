#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

void add_same();
void add_all();

int main()
{
    add_all();
    return 0;
}


void add_same()
{
    Sales_data data_all, data;
    if (std::cin >> data.bookNo >> data.units_sold >> data.revenue) {
        data_all = data;
        while (std::cin >> data.bookNo >> data.units_sold >> data.revenue){
            if (data.bookNo == data_all.bookNo) {
                data_all.units_sold += data.units_sold;
                data_all.revenue += data.revenue;
            } else {
                std::cout << "两个不一样" << std::endl;
                return;
            }

        }
    }
    std::cout << "BookNo: " << data_all.bookNo
              << "\nUnits Sold: " << data_all.units_sold
              << "\nRevenue: " << data_all.revenue
              << std::endl;
}

void add_all()
{
    Sales_data data_all, data;
    if (std::cin >> data.bookNo >> data.units_sold >> data.revenue) {
        data_all = data;
        while (std::cin >> data.bookNo >> data.units_sold >> data.revenue){
            if (data.bookNo == data_all.bookNo) {
                data_all.units_sold += data.units_sold;
                data_all.revenue += data.revenue;
            } else {
                std::cout << "BookNo: " << data_all.bookNo
                          << "\tUnits Sold: " << data_all.units_sold
                          << "\tRevenue: " << data_all.revenue
                          << "\tAvg: " << data_all.revenue / data_all.units_sold
                          << std::endl;
                data_all.bookNo = data.bookNo;
                data_all.units_sold = data.units_sold;
                data_all.revenue = data.revenue;
            }

        }
    }
    std::cout << "BookNo: " << data_all.bookNo
              << "\tUnits Sold: " << data_all.units_sold
              << "\tRevenue: " << data_all.revenue
              << "\tAvg: " << data_all.revenue / data_all.units_sold
              << std::endl;
}
