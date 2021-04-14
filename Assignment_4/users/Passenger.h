#ifndef ASSIGNMENT_4_PASSENGER_H
#define ASSIGNMENT_4_PASSENGER_H

#include "User.h"
#include "../order/Order.h"
#include "../order/PotentialOrder.h"

#include "../location/Location.h"
#include "../payment/Payment.h"

#include <vector>
#include <string>



class Passenger : public User {

    static inline size_t counter = 0;


    std::vector<Location> pinnedLocations;

    Payment paymentMethod;

public:
    /**
     * For a new passenger
     */
    Passenger(std::string name,
              std::string phoneNumber,
              std::string email);

    /**
     * For an already existed passenger
     */
    Passenger(std::string name,
              std::string phoneNumber,
              std::string email,
              std::vector<double> ratings,
              std::vector<Location> pinnedLocations,
              Payment paymentMethod,
              size_t id);


    void addLocation(const Location &location);

    /**
     * Return a collection of potential order info (price, expected time) for all car types
     *  (Economy, Comfort, ...)
     */
    [[nodiscard]] std::vector<PotentialOrder> getPotentialRideInfo(Location from, Location to) const;

    /**
     * If user agreed with conditions of the ride which he can figure out in the method
     *  'getPotentialRideInfo(Location, Location)', then he can order this ride by this method
     */
    void makeOrder(const PotentialOrder &potentialOrder, Payment payment) const;

    /**
     * Same as 'makeOrder(const PotentialOrder&, Payment)' but with default
     *  payment method
     */
    void makeOrder(const PotentialOrder &potentialOrder);

    void askForBill(const Order &order) const;


    std::string toString() const override;


    [[nodiscard]] const std::vector<const Order *> &getOrderHistory() const;

    [[nodiscard]] const std::vector<Location> &getPinnedLocations() const;

    void setPaymentMethod(Payment payment);

    [[nodiscard]] Payment getPaymentMethod() const;
};


#endif //ASSIGNMENT_4_PASSENGER_H
