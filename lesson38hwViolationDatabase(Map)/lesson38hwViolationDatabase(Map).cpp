#include "ViolationDatabase.h"

int main()
{
    ViolationDatabase vd;
    vd.addViolation("AX1818XA", Violation("Speeding", Date(), Time_(), 1000));
    vd.addViolation("AX1818XA", Violation("Speeding", Date(), Time_(), 1500));
    vd.addViolation("AX1818XA", Violation("Speeding", Date(), Time_(), 2000));
    vd.addViolation("PK9120HO", Violation("Drunk", Date(), Time_(), 3000));
    vd.addViolation("AS1391SK", Violation("Road accident", Date(), Time_(), 10000));
    vd.show();
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << endl;
    vd.findCarViolations("AX1818XA");
    vd.findCarViolations("123");
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << vd.findTotalPaymentOfCar("AX1818XA") << endl;
    cout << vd.findTotalPaymentOfCar("123") << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << "==============================" << endl;
    cout << endl;
    
    float money = 4323;
    vd.payViolation("AX1818XA", money);
    vd.show();
    cout << money << endl;
}

