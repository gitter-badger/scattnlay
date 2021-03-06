#ifndef SRC_SHELL_GENERATOR_H_
#define SRC_SHELL_GENERATOR_H_
//**********************************************************************************//
//    Copyright (C) 2009-2016  Ovidio Pena <ovidio@bytesfall.com>                   //
//    Copyright (C) 2013-2016  Konstantin Ladutenko <kostyfisik@gmail.com>          //
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
//   @brief  Generates points for integration on sphere surface
#include <complex>
#include <string>
#include <utility>
#include <vector>
namespace shell_generator {
  class ShellGenerator {  // will throw for any error
   public:
    /* ShellGenerator& ReadFromFile(std::string filename); */
    /* ShellGenerator& ResizeToComplex(double from_wl, double to_wl, int samples); */
    /* ShellGenerator& ToIndex(); */
    double dist(std::vector<double> a, std::vector<double> b);
    double norm(std::vector<double> a);
    std::vector< std::vector<double> > GetVertices(){return vertices_;};
    std::vector< std::vector<double> > GetVerticesT();
    std::vector< std::vector<long int> > GetEdges(){return edges_;};
    std::vector< std::vector<long int> > GetFaces(){return faces_;};
    void EvalEdgeLength();
    void GenerateEdges();
    void GenerateFaces();
    void Init();
    std::vector<double> Integrate();
    std::vector<double> IntegrateByComp();
    double IntegrateGauss(double charge, double dist);
    double IntegrateGaussSimple(double charge, double dist);
    void PrintVerts();
    void Refine();
    void Rescale(double scale);
    void RotateX(double angle);
    void RotateY(double angle);
    void RotateZ(double angle);
    void SetField(std::vector<std::vector< std::complex<double> > > &E,
                  std::vector<std::vector< std::complex<double> > > &H) {E_ = E; H_=H;};
    void SetInitialVertices();
  private:
    std::vector<std::vector< std::complex<double> > > E_, H_;
    double edge_length_ = 0.0;
    double face_area_ = 0.0;
    double per_vertice_area_ = 0.0;
    std::vector< std::vector<double> > vertices_;
    std::vector< std::vector<long int> > edges_;
    std::vector< std::vector<long int> > faces_;
    // std::vector< std::pair< double, std::complex<double> > > data_complex_;
    // std::vector< std::pair< double, std::complex<double> > > data_complex_index_;
    // void PermittivityToIndex();
  };  // end of class ShellGenerator
}  // end of namespase read_spectra
#endif  // SRC_SHELL_GENERATOR_H_
