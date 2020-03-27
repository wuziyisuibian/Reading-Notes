#include "sales_data.h"

int main()
{
    SData data_1, data_2; 
   
    double price=0;
    
    cin >> data_1.bookNo >> data_1.units_sold >> price;
    data_1.revenue = data_1.units_sold * price;
   
    cin >> data_2.bookNo >> data_2.units_sold >> price;
    data_2.revenue = data_2.units_sold * price;

    if(data_1.bookNo == data_2.bookNo){
        unsigned totalCnt = data_1.units_sold + data_2.units_sold;
        double totalRevenue = data_1.revenue + data_2.revenue;

        cout << data_1.bookNo << " " << totalCnt
             << " " << totalRevenue << " ";

        if(totalCnt != 0)
            cout << totalRevenue/totalCnt << endl;
        else
            cout << "(no sales)" << endl;
        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }

    return 0;
}

