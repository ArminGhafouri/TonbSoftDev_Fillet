#include<iostream>
#include<TonbSoftDev_GeomTools_Fillet.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<TopTools_IndexedMapOfShape.hxx>
#include<Bnd_Box.hxx>


using namespace std;

int main()
{
	try
	{


		{

			gp_Pnt corner1(0.0, 0.0, 0.0);
			gp_Pnt corner2(5.0, 5.0, 5.0);
			BRepPrimAPI_MakeBox make(corner1, corner2);
			TopoDS_Shape shape0 = make.Shape();


			TonbSoftDev_GeomTools_Fillet fil(shape0, 0.8 , {1 , 6 , 8} );

			
			fil.PlotFillet("Fillet Edge");
			

		}

	}// <-- this bracket for try



	catch (const Standard_Failure& ex)
	{

		std::cout << ex.GetMessageString() << std::endl;

	}



	return 0;

}
