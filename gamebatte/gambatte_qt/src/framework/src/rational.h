/***************************************************************************
 *   Copyright (C) 2008 by Sindre Aamås                                    *
 *   aamas@stud.ntnu.no                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

struct Rational
{
  long num;
  long denom;

  Rational(const long num = 1, const long denom = 1) : num(num), denom(denom) {}
  float toFloat() const
  {
    return static_cast<float>(num) / denom;
  }
  double toDouble() const
  {
    return static_cast<double>(num) / denom;
  }

  const Rational reciprocal() const
  {
    return Rational(denom, num);
  }

  // assumes positive num and denom
  long ceiled() const
  {
    return (num - 1) / denom + 1;
  }
  long floored() const
  {
    return num / denom;
  }
  long rounded() const
  {
    return (num + (denom >> 1)) / denom;
  }
};

inline bool operator==(const Rational &lhs, const Rational &rhs)
{
  return lhs.num == rhs.num && lhs.denom == rhs.denom;
}

inline bool operator!=(const Rational &lhs, const Rational &rhs)
{
  return lhs.num != rhs.num || lhs.denom != rhs.denom;
}

#endif