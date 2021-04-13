#ifndef ASSIGNMENT_4_USER_H
#define ASSIGNMENT_4_USER_H

#include <string>
#include <vector>


class Order;


/*
 * There is no way to create an instance of this class.
 * It is legal only to create an instance of the class that is derived
 *  from this one.
 */
class User {

protected:

    std::string name;

    std::string phoneNumber;

    std::string email;

    std::vector<double> ratings;

    bool signedIn;

    std::vector<const Order*> orderHistory;


    /**
     * For a new user
     */
    User(std::string name,
         std::string phoneNumber,
         std::string email);

    /**
     * For an already existed user
     */
    User(std::string name,
         std::string phoneNumber,
         std::string email,
         std::vector<double> ratings,
         std::vector<const Order*> orderHistory);


public:

    void addOrder(const Order &order);


    [[nodiscard]] virtual std::string toString() const = 0;


    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;


    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);


    [[nodiscard]] const std::string &getPhoneNumber() const;

    void setPhoneNumber(const std::string &phoneNumber);


    [[nodiscard]] const std::string &getEmail() const;

    void setEmail(const std::string &email);


    [[nodiscard]] double getRating() const;

    void updateRating(double addedRating);


    [[nodiscard]] bool isSignedIn() const;

    void setSignedIn(bool signedIn);


    User() = delete;
};


#endif //ASSIGNMENT_4_USER_H
