/*---------------------------------------------------------------------------------*/
/*  NOMAD - Nonlinear Optimization by Mesh Adaptive Direct Search -                */
/*                                                                                 */
/*  NOMAD - Version 4.0.0 has been created by                                      */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  The copyright of NOMAD - version 4.0.0 is owned by                             */
/*                 Sebastien Le Digabel        - Polytechnique Montreal            */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  NOMAD v4 has been funded by Rio Tinto, Hydro-Québec, NSERC (Natural Science    */
/*  and Engineering Research Council of Canada), INOVEE (Innovation en Energie     */
/*  Electrique and IVADO (The Institute for Data Valorization)                     */
/*                                                                                 */
/*  NOMAD v3 was created and developed by Charles Audet, Sebastien Le Digabel,     */
/*  Christophe Tribes and Viviane Rochon Montplaisir and was funded by AFOSR       */
/*  and Exxon Mobil.                                                               */
/*                                                                                 */
/*  NOMAD v1 and v2 were created and developed by Mark Abramson, Charles Audet,    */
/*  Gilles Couture, and John E. Dennis Jr., and were funded by AFOSR and           */
/*  Exxon Mobil.                                                                   */
/*                                                                                 */
/*  Contact information:                                                           */
/*    Polytechnique Montreal - GERAD                                               */
/*    C.P. 6079, Succ. Centre-ville, Montreal (Quebec) H3C 3A7 Canada              */
/*    e-mail: nomad@gerad.ca                                                       */
/*    phone : 1-514-340-6053 #6928                                                 */
/*    fax   : 1-514-340-5665                                                       */
/*                                                                                 */
/*  This program is free software: you can redistribute it and/or modify it        */
/*  under the terms of the GNU Lesser General Public License as published by       */
/*  the Free Software Foundation, either version 3 of the License, or (at your     */
/*  option) any later version.                                                     */
/*                                                                                 */
/*  This program is distributed in the hope that it will be useful, but WITHOUT    */
/*  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or          */
/*  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License    */
/*  for more details.                                                              */
/*                                                                                 */
/*  You should have received a copy of the GNU Lesser General Public License       */
/*  along with this program. If not, see <http://www.gnu.org/licenses/>.           */
/*                                                                                 */
/*  You can find information on the NOMAD software at www.gerad.ca/nomad           */
/*---------------------------------------------------------------------------------*/
/**
 \file   SgtelibModelFeasibilityType.hpp
 \brief  types for parameter SGTELIB_MODEL_FEASIBILITY
 \author Viviane Rochon Montplaisir
 \date   July 2019
 \see    SgtelibModel.hpp
 */
#ifndef __NOMAD400_SGTELIB_MODEL_FEASIBILITY_TYPE__
#define __NOMAD400_SGTELIB_MODEL_FEASIBILITY_TYPE__

#include <string>
#include <sstream>

#include "../nomad_nsbegin.hpp"

// Feasibility types for sgtelib model Search
enum class SgtelibModelFeasibilityType
{
    C         , /// one model for each constraint
    H         , /// one model for H
    B         , /// one binary model
    M         , /// one model of the max of (c_j)
    UNDEFINED   /// Undefined
};


// Convert a string (ex "C", "H", "B"...)
// to a SgtelibModelFeasibilityType.
SgtelibModelFeasibilityType stringToSgtelibModelFeasibilityType(const std::string &s);

std::string SgtelibModelFeasibilityTypeToString(const SgtelibModelFeasibilityType &smft);

inline std::ostream& operator<<(std::ostream& os, const SgtelibModelFeasibilityType &smft)
{
    switch (smft)
    {
        case SgtelibModelFeasibilityType::C:
            os << "C";
            break;
        case SgtelibModelFeasibilityType::H:
            os << "H";
            break;
        case SgtelibModelFeasibilityType::B:
            os << "B";
            break;
        case SgtelibModelFeasibilityType::M:
            os << "M";
            break;
        default:
            return os << "UNDEFINED";
            break;
    }

    return os;
}


#include "../nomad_nsend.hpp"

#endif // __NOMAD400_SGTELIB_MODEL_FEASIBILITY_TYPE__