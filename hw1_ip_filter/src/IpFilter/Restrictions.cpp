#include "Restrictions.h"

namespace hw1 {

const Boundaries<IpV4> Restrictions<IpV4>::boundaries = {IpV4{0, 0, 0, 0}, IpV4{255, 255, 255, 255} };

}
