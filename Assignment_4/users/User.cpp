#include "User.h"

#include <numeric>


User::User(std::string name, std::string phoneNumber, std::string email, size_t id) :
    name(std::move(name)), phoneNumber(std::move(phoneNumber)), email(std::move(email)),
    ratings(1, 5.0), signedIn(true), orderHistory(), id(id)
{ }

User::User(std::string name, std::string phoneNumber,
           std::string email, std::vector<double> ratings, size_t id) :
    name(std::move(name)), phoneNumber(std::move(phoneNumber)), email(std::move(email)),
    ratings(std::move(ratings)), signedIn(true), id(id)
{ }


void User::addOrder(const Order &order) {
    orderHistory.push_back(&order);
}


size_t User::getId() const {
    return id;
}


const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}


const std::string &User::getPhoneNumber() const {
    return phoneNumber;
}

void User::setPhoneNumber(const std::string &phoneNumber) {
    User::phoneNumber = phoneNumber;
}


const std::string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    User::email = email;
}


double User::getRating() const {
    auto sum = std::accumulate(ratings.begin(), ratings.end(), 0.0);
    return (sum / ratings.size());
}

void User::updateRating(double addedRating) {
    ratings.emplace_back(addedRating);
}


bool User::isSignedIn() const {
    return signedIn;
}

void User::setSignedIn(bool signedIn) {
    User::signedIn = signedIn;
}

bool User::operator==(const User &rhs) const {
    return phoneNumber == rhs.phoneNumber &&
           email == rhs.email;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}
