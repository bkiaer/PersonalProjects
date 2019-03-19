/*program to create an organization of Gunpla Collection*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

struct gundam{

string model;
string grade; 
float price;

};

void writeOutput(ofstream&, gundam);
float calculateTotal(vector<gundam>);

int main(){

	char cont = 'y';
	int pg = 0, mg = 0, rg = 0, hg = 0, o = 0;
	ofstream outputfile;
	outputfile.open("gundamCatalog.txt", fstream::app); //app is append text file
	string grade;
	string model;
	float cost;
	//gundam temp;
	vector<gundam> models;



	while(cont == 'y'){
		cout << "What category of Gunpla Model?" << endl << endl; 
		cout << "	Perfect Grade (PG) " << endl;
		cout << "	Master Grade (MG) " << endl;
		cout << "	Real Grade (RG) " << endl;
		cout << "	High Grade (HG) " << endl;
		cout << "	Other Grade (O)" << endl << endl;
		cout << "Grade: "; 
		cin >> grade;
		if(grade == "PG")
			pg++;
		else if(grade == "MG")
			mg++;
		else if(grade == "RG")
			rg++;
		else if(grade == "HG")
			hg++;
		else if(grade == "O")
			o++;
		cout << "What is the " << grade << " model name? " << endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, model);
		cout << "How much did the " << grade << " " << model << " cost? " << endl;
		cin >> cost; 
		gundam temp = {model, grade, cost};
		writeOutput(outputfile, temp);
		models.push_back(temp);
		cout << "Do you want to continue? (y/n): ";
		cin >> cont; 

	}
	cout << fixed << setprecision(2);
	cout << "Total Cost: $ " <<  calculateTotal(models) << endl << endl;
	cout << "PG: " << pg << endl;
	cout << "MG: " << mg << endl;
	cout << "RG: " << rg << endl;
	cout << "HG: " << hg << endl;
	cout << "O: " << o << endl;
	cout << "Total Gunpla: " << pg + mg + rg + hg + o << endl;

	outputfile.close();
	return 0;
}


void writeOutput(ofstream& outputfile, gundam models){

outputfile << "Grade: "; 
outputfile << models.grade;
outputfile << " 	Model: ";
outputfile << models.model; 
outputfile << " 	Price: $";
outputfile << models.price; 
outputfile << "\n";

}

float calculateTotal(vector<gundam> models){
	float sum = 0; 
	for(int i = 0; i < models.size(); i++){
		sum  = sum + models[i].price; 
	}

return sum;

}