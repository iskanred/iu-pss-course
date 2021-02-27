#include "Lab.h"


/* Constants  */

const Lab Lab::DATA_SCIENCE = Lab(LabType::DATA_SCIENCE);

const Lab Lab::CYBER_SECURITY = Lab(LabType::CYBER_SECURITY);

const Lab Lab::NETWORKS = Lab(LabType::NETWORKS);

const Lab Lab::SOFTWARE_ENGINEERING = Lab(LabType::SOFTWARE_ENGINEERING);

const Lab Lab::OPERATING_SYSTEMS = Lab(LabType::OPERATING_SYSTEMS);

const Lab Lab::ROBOTICS = Lab(LabType::ROBOTICS);


/* Constructor */

Lab::Lab(Lab::LabType lab) : lab(lab)
{ }


/* Public member-functions */

std::string Lab::toString() const {
    switch (lab) {
        case LabType::DATA_SCIENCE :
            return "DATA_SCIENCE";

        case LabType::CYBER_SECURITY :
            return "CYBER_SECURITY";

        case LabType::NETWORKS :
            return "NETWORKS";

        case LabType::SOFTWARE_ENGINEERING :
            return "SOFTWARE_ENGINEERING";

        case LabType::OPERATING_SYSTEMS :
            return "OPERATING_SYSTEMS";

        case LabType::ROBOTICS :
            return "ROBOTICS";
    }
}
