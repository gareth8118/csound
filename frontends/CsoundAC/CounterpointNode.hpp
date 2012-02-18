/*
 * C S O U N D
 *
 * L I C E N S E
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef COUNTERPOINTNODE_H
#define COUNTERPOINTNODE_H
#if defined(_MSC_VER) && !defined(__GNUC__)
#pragma warning (disable:4786)
#endif

#include "Platform.hpp"
#ifdef SWIG
%module CsoundAC
%{
#include "Node.hpp"
#include "Counterpoint.hpp"
#include <cmath>
%}
%include "std_vector.i"
%template(IntVector) std::vector<int>;
#else
#include "Node.hpp"
#include "Counterpoint.hpp"
#include <cmath>
using namespace boost::numeric;
#endif

namespace csound
{
  /**
   * Uses Bill Schottstaedt's species counterpoint generator code
   * to either (a) generate a counterpoint in species 1, 2, or 3
   * for a cantus firmus selected from notes generated by child nodes,
   * or (b) attempt to correct the voice leading for species 1, 2, or 3
   * counterpoint in notes generated by child nodes.
   */
  class SILENCE_PUBLIC CounterpointNode :
    public Node,
    public Counterpoint
  {
  public:
    enum
      {
        GenerateCounterpoint = 0,
        CorrectCounterpoint = 1
      };
    int generationMode;
    int musicMode;
    int species;
    size_t voices;
    double secondsPerPulse;
    std::vector<int> voiceBeginnings;
    CounterpointNode();
    virtual ~CounterpointNode();
    virtual void produceOrTransform(Score &score, size_t beginAt, size_t endAt, const ublas::matrix<double> &globalCoordinates);
  };
}
#endif
