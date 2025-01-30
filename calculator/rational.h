#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <numeric>
class Rational {
public:
    Rational() : numerator_(0), denominator_(1) {}
    Rational(int numerator) : numerator_(numerator), denominator_(1) {}
    Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        Reduction();
    }
    Rational(const Rational& other) : numerator_(other.numerator_), denominator_(other.denominator_) {}

    Rational Inv() const {
        return Rational(denominator_, numerator_);
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    Rational& operator+=(const Rational& other) {
        numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        numerator_ = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        numerator_ *= other.denominator_;
        denominator_ *= other.numerator_;
        Reduction();
        return *this;
    }

    Rational& operator=(const Rational& other) {
        if (this != &other) {
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;
        }
        return *this;
    }

    Rational operator+() const {
        return Rational(*this);
    }

    Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }
    // Напишите здесь перегрузки операций.

    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend auto operator<=>(const Rational& x, const Rational& y);
    friend bool operator==(const Rational& x, const Rational& y);


private:
    int numerator_ = 0;
    int denominator_ = 1;

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }
};
inline Rational operator+(Rational lhs, const Rational& rhs) {
    return lhs += rhs;
}

inline Rational operator-(Rational lhs, const Rational& rhs) {
    return lhs -= rhs;
}

inline Rational operator*(Rational lhs, const Rational& rhs) {
    return lhs *= rhs;
}

inline Rational operator/(Rational lhs, const Rational& rhs) {
    return lhs /= rhs;
}
inline std::istream& operator>>(std::istream& is, Rational& r) {
    int n, d;
    char div;

    if (!(is >> n)) {
        return is;
    }

    if (!(is >> std::ws >> div)) {
        r = Rational(n, 1);
        is.clear();
        return is;
    }

    if (div != '/') {
        r = Rational(n, 1);
        is.unget();
        return is;
    }

    if (!(is >> d) || (d == 0)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    r = Rational(n, d);

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& r) {
    using namespace std::literals;
    if (r.denominator_ == 1) {
        os << r.numerator_;
    } else {
        os << r.numerator_ << " / "s << r.denominator_;
    }
    return os;
}
inline auto operator<=>(const Rational& x, const Rational& y){
    int a = x.GetNumerator() * y.GetDenominator();
    int b = y.GetNumerator() * x.GetDenominator();
    return a <=> b;
}
inline bool operator==(const Rational& x, const Rational& y){
    int a = x.GetNumerator() * y.GetDenominator();
    int b = y.GetNumerator() * x.GetDenominator();
    return a == b;
}
