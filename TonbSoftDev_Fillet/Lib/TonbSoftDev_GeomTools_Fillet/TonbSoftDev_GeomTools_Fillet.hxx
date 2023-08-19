#pragma once
#include<TopoDS_Shape.hxx>
#include<TopoDS_Edge.hxx>
#include<vector>
#include<TonbSoftDev_GeomBaseGlobal_FilletBuild.hxx>



class TonbSoftDev_GeomTools_Fillet
{
private:

	TopoDS_Shape  theShape_;
	double  theRadius_;
	std::vector<int> theIndex_;

public:

	TonbSoftDev_Fillet_EXPORT TonbSoftDev_GeomTools_Fillet(const TopoDS_Shape& shape, double radius, const std::vector<int>& in);

	TonbSoftDev_Fillet_EXPORT TopoDS_Shape ApplyFillet();
	TonbSoftDev_Fillet_EXPORT void PlotFillet(std::string filename);

   //TonbSoftDev_Fillet_EXPORT TopoDS_Shape ApplyFilletTwo();
   //TonbSoftDev_Fillet_EXPORT void PlotFilletTwo(std::string filename);

private:

	TonbSoftDev_Fillet_EXPORT void SetShape(TopoDS_Shape sh);
	TonbSoftDev_Fillet_EXPORT void SetRadius(double rad);
	TonbSoftDev_Fillet_EXPORT TopoDS_Shape GetShape()const;
	TonbSoftDev_Fillet_EXPORT double GetRadius()const;
	TonbSoftDev_Fillet_EXPORT std::vector<TopoDS_Edge> FindEdgesFromNumber(std::vector<int> index);
	TonbSoftDev_Fillet_EXPORT std::vector<TopoDS_Edge> FindEdgesFromShape();
	TonbSoftDev_Fillet_EXPORT int NumberOfEdge(/*const TopoDS_Shape shape*/);
	TonbSoftDev_Fillet_EXPORT int NumberOfFace(const TopoDS_Shape shape);

};