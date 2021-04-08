#ifndef ASSIGNMENT_2_DIRECTOR_H
#define ASSIGNMENT_2_DIRECTOR_H

#include "UniversityUser.h"
#include "../rooms/DirectorCabinet.h"


class DirectorCabinet;


class Director : public UniversityUser {

    friend class DirectorCabinetSetter;

    /**
     * Director can often leave the university for business-trips
     * The system may need to know whether a director is at the university
     */
    bool presentAtUniversity;

    DirectorCabinet* cabinet;

public:
    /* Constructors */

    Director(std::string name,
             std::string surname,
             std::string tgAlias);

    /* Constructor */
    Director(std::string name,
             std::string surname,
             std::string tgAlias,
             DirectorCabinet& cabinet);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;

    void removeCabinet();


    /* Setters */

    void setPresentAtUniversity(bool presentAtUniversity);

    void setCabinet(DirectorCabinet& cabinet);


    /* Getters */

    [[nodiscard]] bool isPresentAtUniversity() const;

    /**
     * (Nullable)!
     *
     * @return - pointer to a director's cabinet;
     *         - 'nullptr' if it is no director's cabinet
     *                  associated to this director yet
     */
    [[nodiscard]] const DirectorCabinet *getCabinet() const;
};


#endif //ASSIGNMENT_2_DIRECTOR_H