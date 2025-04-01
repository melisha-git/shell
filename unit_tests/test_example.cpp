#include <boost/test/unit_test.hpp>
#include "../Parser.hpp"

BOOST_AUTO_TEST_SUITE(CalculatorSuite)

BOOST_AUTO_TEST_CASE(AddTest) {
    Calculator calc;
    BOOST_CHECK_EQUAL(calc.add(2, 3), 5);
    BOOST_CHECK_EQUAL(calc.add(-1, 1), 0);
}

// Тест 2: Проверка деления
BOOST_AUTO_TEST_CASE(DivideTest) {
    Calculator calc;
    BOOST_CHECK_CLOSE(calc.divide(10, 2), 5.0, 0.0001);
    BOOST_CHECK_THROW(calc.divide(1, 0), std::logic_error);
}

// Закрываем набор
BOOST_AUTO_TEST_SUITE_END()