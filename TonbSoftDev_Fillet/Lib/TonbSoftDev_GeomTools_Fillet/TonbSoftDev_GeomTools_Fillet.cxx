#include"TonbSoftDev_GeomTools_Fillet.hxx"
#include<Tools.hxx>

#include<BRepFilletAPI_MakeFillet.hxx>
#include<TopoDS.hxx>
#include<TopoDS_Face.hxx>
#include<TopExp_Explorer.hxx>
#include<TopExp.hxx>
#include<BRepBuilderAPI_MakeSolid.hxx>
#include<ShapeFix_Shape.hxx>
#include<BRepBuilderAPI_MakeWire.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<BRepBuilderAPI_MakeFace.hxx>




TonbSoftDev_GeomTools_Fillet::TonbSoftDev_GeomTools_Fillet(const TopoDS_Shape& shape, double radius, const std::vector<int>& in)
{
	{
		if (shape.IsNull())
		{
			throw std::exception("The Shape is null!");
			//throw;
		}
		else
		{
			theShape_ = shape;
		}
	}

	{
		if (radius < 0.0)
		{
			throw std::exception("Radis is not valid!");
			//throw;
		}
		else
		{
			theRadius_ = radius;
		}
	}

	{
		if (in.size() == 0.0)
		{
			throw std::exception("number of Edge null!");
			//throw;
		}
		else
		{
			theIndex_ = in;
		}
	}


}


void TonbSoftDev_GeomTools_Fillet::SetShape(const TopoDS_Shape shape)
{

	if (shape.IsNull())
	{
		throw std::exception("The Shape is null!");
		//throw;
	}
	else
	{
		theShape_ = shape;
	}

}


void TonbSoftDev_GeomTools_Fillet::SetRadius(const double rad)
{

	if (rad < 0.0)
	{
		throw std::exception("Radis is not valid!");
		
	}

	else
	{
		theRadius_ = rad;
	}

}


TopoDS_Shape TonbSoftDev_GeomTools_Fillet::GetShape()const
{

	if (theShape_.IsNull())
	{
		throw std::exception("The Shape is null!");
		//throw;
	}
	else
	{
		return theShape_;
	}

}

double TonbSoftDev_GeomTools_Fillet::GetRadius()const
{

	if (theRadius_ < 0.0)
	{
		throw std::exception("Radis is not valid!");
		/*throw;*/
	}
	else
	{
		return theRadius_;
	}

}


int TonbSoftDev_GeomTools_Fillet::NumberOfEdge(/*const TopoDS_Shape shape*/)
{

	int num = 0;
	for (TopExp_Explorer explorer(GetShape(), TopAbs_EDGE); explorer.More(); explorer.Next())
	{
		num++;
	}

	//another way ====>>>

	//int num = 0 ;
	//TopExp_Explorer explorer(shape, TopAbs_EDGE);
	//while (explorer.More())
	//{
	//	TopoDS_Edge edge = TopoDS::Edge(explorer.Current());
	//	// Do something with the edge
	//	num++;
	//	explorer.Next();
	//}



	//another way ====>>>
	
	/*int num = 0;
	TopExp_Explorer explorer(shape, TopAbs_EDGE);
	while (explorer.More())
	{
		num++;

		explorer.Next();
	}*/


	std::cout << "number of edge: " << num << std::endl;
	return num;
}



int TonbSoftDev_GeomTools_Fillet::NumberOfFace(const TopoDS_Shape shape)
{

	int num = 0;
	TopExp_Explorer explorer(shape, TopAbs_FACE);
	while (explorer.More())
	{
		num++;
		explorer.Next();
	}

	return num;


}




TopoDS_Shape TonbSoftDev_GeomTools_Fillet::ApplyFillet()
{


	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(GetShape(), TopAbs_EDGE, mymap);
	BRepFilletAPI_MakeFillet mkFillet(theShape_);

	for (int i = 0; i < theIndex_.size(); i++)
	{ 
		
			mkFillet.Add(theRadius_, TopoDS::Edge(mymap(theIndex_[i])));
			//mkFillet.Build();
	
	}

	TopoDS_Shape shape = mkFillet.Shape();
	return shape;
}






void TonbSoftDev_GeomTools_Fillet::PlotFillet(std::string filename)
{

	Tools::PlotShapeTwo(ApplyFillet(), filename  );

}






std::vector<TopoDS_Edge> TonbSoftDev_GeomTools_Fillet::FindEdgesFromNumber(std::vector<int> index)
{

	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(GetShape(), TopAbs_EDGE, mymap);
	std::vector<TopoDS_Edge> edgs;


	for (int i = 0; i < index.size(); i++)
	{
		TopoDS_Edge edge = TopoDS::Edge(mymap(index[i]));
		edgs.push_back(edge);
	}


	return edgs;
}


//TopoDS_Shape TonbSoftDev_GeomTools_Fillet::ApplyFilletTwo()
//{
//	/*****/
//	std::vector<TopoDS_Edge> AllEdgs = FindEdgesFromShape();
//	BRepFilletAPI_MakeFillet mkFillet(GetShape());
//	
//
//		//BRepFilletAPI_MakeFillet2d mkFillet();
//	for (int i = 0; i < theIndex_.size(); i++)
//	{
//		//mkFillet().ModifyFillet(AllEdgs[theIndex_[i]], theRadius_);
//	    mkFillet.Add(theRadius_, AllEdgs[theIndex_[i]]);
//	    //mkFillet.Build();
//	}
//
//	TopoDS_Shape shape = mkFillet.Shape();
//	return shape;
//
//}




//void TonbSoftDev_GeomTools_Fillet::PlotFilletTwo(std::string filename)
//{
//	Tools::PlotShapeTwo(ApplyFilletTwo(), filename );
//
//}





std::vector<TopoDS_Edge> TonbSoftDev_GeomTools_Fillet::FindEdgesFromShape()
{

	 TopExp_Explorer Ex;
	 std::vector<TopoDS_Edge> edgs;

		 for (Ex.Init(theShape_, TopAbs_EDGE); Ex.More(); Ex.Next())
		 {
			 const TopoDS_Edge& edge = TopoDS::Edge(Ex.Current());  
			 edgs.push_back(edge);

		 }

	return  edgs;
}