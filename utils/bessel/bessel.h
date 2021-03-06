//**********************************************************************************//
//    Copyright (C) 2009-2015  Ovidio Pena <ovidio@bytesfall.com>                   //
//    Copyright (C) 2013-2015  Konstantin Ladutenko <kostyfisik@gmail.com>          //
//                                                                                  //
//    This file is part of scattnlay                                                //
//                                                                                  //
//    This program is free software: you can redistribute it and/or modify          //
//    it under the terms of the GNU General Public License as published by          //
//    the Free Software Foundation, either version 3 of the License, or             //
//    (at your option) any later version.                                           //
//                                                                                  //
//    This program is distributed in the hope that it will be useful,               //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of                //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 //
//    GNU General Public License for more details.                                  //
//                                                                                  //
//    The only additional remark is that we expect that all publications            //
//    describing work using this software, or all commercial products               //
//    using it, cite the following reference:                                       //
//    [1] O. Pena and U. Pal, "Scattering of electromagnetic radiation by           //
//        a multilayered sphere," Computer Physics Communications,                  //
//        vol. 180, Nov. 2009, pp. 2348-2354.                                       //
//                                                                                  //
//    You should have received a copy of the GNU General Public License             //
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.         //
//**********************************************************************************//
#include <complex>
#include <vector>
namespace nmie {
  namespace bessel {
    void calcZeta(int n,  std::complex<double>z,
		  std::vector< std::complex<double> >& Zeta,
		  std::vector< std::complex<double> >& dZeta);
    void calcPsi(int n,  std::complex<double>z,
		  std::vector< std::complex<double> >& Psi,
		  std::vector< std::complex<double> >& dPsi);
    void csphjy (int n, std::complex<double>z, int& nm,
		 std::vector< std::complex<double> >& csj,
		 std::vector< std::complex<double> >& cdj,
		 std::vector< std::complex<double> >& csy,
		 std::vector< std::complex<double> >& cdy );
    double envj (int n, double x );
    int msta2 ( double x, int n, int mp );
    int  msta1 ( double x, int mp );
  }  // end of namespace bessel
}  // end of namespace nmie
