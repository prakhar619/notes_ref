#include <vector>
#include <utility>
using namespace std;
class Object
{
	//shape
	vector<pair<double,double>> vertex;
	
	//centre
	pair<double,double> center;

	//com (Center of Mass)
	pair<double, double> com;

	//mass
	double mass;

	//time
	double time;

	//color
	vector<vector<double>> color;

};