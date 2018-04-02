#include "testpolymonial.h"

testPolymonial::testPolymonial()
{

}
testPolymonial::testCompute()
{
    std::vector<double> coeffs(5,13);
    std::vector<double> z(5,2);
    Polymonial poly(coeffs);
    QCOMPARE(poly.compute(z),130);
}

QTEST_MAIN(testPolymonial)
