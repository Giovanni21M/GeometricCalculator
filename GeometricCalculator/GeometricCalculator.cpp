/*
Name: Giovanni Martinez
Program: Geomtric Calculator
Description: A Program that simulates a geometric calculator.
*/

/*********************** Header ***************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>		// seed unique srand()
#include <cwchar>		// Console FONT_INFOEX
#include <Windows.h>	// Modified console window

using namespace std;
const double PI = 3.1415927;

/*********** Initiate Global Variables ********************/
char studentGender;
double shapeArea, shapePerimeter, sineForumla,
shapeRadius, shapeSideX, shapeSideY,
shapeSideZ, shapeVolume, shapeHeight,
shapeSlant;
int studentUses, studentAge, studentId, shapeChoice;
string studentName, shapeDescription;
string title = "GEOMETRIC CALCULATOR";

/**************** Function Declaration *******************/
void ShapeHeader(string, string);
void OutputScreenDesign();
void HeaderDesign(string);
void StudentInfo(string&, int&, char&, int&);
void CircleOperations();
void SquareOperations();
void RectangleOperations();
void TriangleOperations();
void RightCircularConeOperations();
void SphereOperations();
void CubeOperations();
void CylinderOperations();
void FinalReport(string, int, char, int);
void ShapeDataOutput(string, string, string, string, double, double, double);
double ShapeDataInput(string);
int StudentChoice(string, string, string, string);

/******************** Main Function **********************/
int main() {
	srand(time(0));						// Change seed
	cout << fixed << setprecision(2);	// Set floating point to 2 decimal points

	/***************** Function Call ********************/
	OutputScreenDesign();
	HeaderDesign(title);
	StudentInfo(studentName, studentAge, studentGender, studentUses);
	FinalReport(studentName, studentAge, studentGender, studentUses);

	/******************** System Exit ********************/
	cout << "\t\t";
	system("Pause");
	return 0;
}

/**************** ShapeHeader Function *******************/
void ShapeHeader(string shapeName, string shapeDescription) {
	cout << endl << endl << "\t\t";
	cout << setfill('_') << left << setw(55) << shapeName << endl;
	cout << "\t\tDescription: " << shapeDescription << endl << endl;
	cout << endl;
}

/************* OutputScreenDesign Function ***************/
void OutputScreenDesign() {
	system("color 1F");					// Background and Text Color

	HWND hwnd = GetConsoleWindow();		// Create a Window object
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);	// Maximize the window in the screen whole


	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = 0;				// Width of each font character
	cfi.dwFontSize.Y = 16;				// Height of each font character
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

/*************** HeaderDesign Function ********************/
void HeaderDesign(string title) {
	cout << "\n" << setw(85) << title << endl;
	cout << right << setfill('*');
	cout << "\n" << setw(168) << "*" << endl;

	cout << fixed << setprecision(2);	// Sets the decimal precision to format floating point value
}

/*************** StudentChoice Function ********************/
int StudentChoice(string shape1, string shape2,
	string shape3, string shape4) {

	int choice;

	cout << "\t\tChoose a shape to calculate its measurements:"		// Menu design
		"\n\t\t- Type \"1\" for the " << shape1 << " shape"
		"\n\t\t- Type \"2\" for the " << shape2 << " shape"
		"\n\t\t- Type \"3\" for the " << shape3 << " shape"
		"\n\t\t- Type \"4\" for the " << shape4 << " shape"
		<< endl << "\t\t";

	cin >> choice;

	return choice;
}

/***************** StudentInfo Function **************************/
void StudentInfo(string& name, int& age, char& gender, int& uses) {
	cout << "\t\tName: ";
	getline(cin, name);														// use getline() in place of cin for string type input

	cout << "\t\tGender (F/M): ";
	cin >> gender;


	if (tolower(gender) == 'm' || tolower(gender) == 'f') {
		cout << "\t\tAge: ";
		cin >> age;

		if (age >= 18 && age <= 80) {											// Check if 18 <= age <= 80
			cout << "\t\tHow many uses are required: ";
			cin >> uses;
			cout << endl;

			cout << "\t\tName: " << name << endl;
			cout << "\t\tAge: " << age << endl;
			cout << "\t\tSex: " << gender << endl;
			cout << endl;

			shapeChoice = StudentChoice("Right Circular Cone", "Sphere",		// studentChoice function assigned to variable
				"Cube", "Cylinder");

			switch (shapeChoice) {												// switch-case shape chosen
			case 1:
				RightCircularConeOperations();
				break;
			case 2:
				SphereOperations();
				break;
			case 3:
				CubeOperations();
				break;
			case 4:
				CylinderOperations();
				break;
			default:															// No option selected - terminate app
				cout << "\t\tInvalid option" << endl;
			}

		}
		else if (age >= 12 && age <= 17) {										// Check if 12 <= age <= 17
			cout << "\t\tHow many uses are required: ";
			cin >> uses;
			cout << endl;

			cout << "\t\tName: " << name << endl;
			cout << "\t\tAge: " << age << endl;
			cout << "\t\tSex: " << gender << endl;
			cout << endl;

			shapeChoice = StudentChoice("Circle", "Square",						// shapeChoice function assigned to variable
				"Rectangle", "Triangle");

			switch (shapeChoice) {												// swtich-case for shape chosen
			case 1:
				CircleOperations();
				break;
			case 2:
				SquareOperations();
				break;
			case 3:
				RectangleOperations();
				break;
			case 4:
				TriangleOperations();
				break;
			default:															// No option selected - terminate app
				cout << "\t\tInvalid option" << endl;
			}
		}
		else {
			cout << endl;
			cout << "\t\tOut of range.";
			cout << endl;

			FinalReport(studentName, studentAge, studentGender, studentUses);	// FinalReport function call

			cout << "\t\t";
			system("Pause");
			exit(0);															// Termiate program
		}
	}
	else {
		cout << endl;
		cout << "\t\tOut of range.";
		cout << endl;

		FinalReport(studentName, studentAge, studentGender, studentUses);	// FinalReport function call

		cout << "\t\t";
		system("Pause");
		exit(0);															// Termiate program
	}
}

/**************** CircleOperations Function **********************/
void CircleOperations() {
	studentUses = 0;

	shapeDescription = "The circle is a shape where all points"
		"\n\t\talong the shape are equal distance from a specific point.";

	ShapeHeader("Circle", shapeDescription);								// ShapeHeader Function Call

	shapeRadius = ShapeDataInput("Radius");									// ShapeDataInput Function Call

	shapePerimeter = 2 * PI * shapeRadius;									// Circle Perimeter Formula
	shapeArea = PI * pow(shapeRadius, 2);									// Circle Area Formula

	cout << endl;
	ShapeDataOutput("Circle", "Perimeter", "Area", "", shapePerimeter,		// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/************* SquareOperations Function *******************/
void SquareOperations() {
	shapeDescription = "A square is a four-sided regular polygon"
		"\n\t\twhere all sides are equal.";

	ShapeHeader("Square", shapeDescription);						// ShapeHeader Function Call

	shapeSideX = ShapeDataInput("Side Length");						// ShapeDataInput Function Call

	shapePerimeter = 4 * shapeSideX;								// Square Perimeter Formula
	shapeArea = pow(shapeSideX, 2);									// Square Area Formula

	cout << endl;
	cout << "\t\tThe perimeter and area of a square with a"
		"\n\t\tlength of " << shapeSideX << " is:" << endl;

	cout << "\t\tSquare Perimeter: " << shapePerimeter << endl;		// Output Square Perimeter
	cout << "\t\tSquare Area: " << shapeArea << endl;				// Output Square Area
	cout << endl;

	studentUses++;
}

/************ RectangleOperations Function *****************/
void RectangleOperations() {
	shapeDescription = "A rectangle is a four-sided polygon,"
		"\n\t\tquadrilateral with right angle corners.";

	ShapeHeader("Rectangle", shapeDescription);								// ShapeHeader Function Call

	shapeSideX = ShapeDataInput("Side A Length");							// ShapeDataInput Function Call
	shapeSideY = ShapeDataInput("Side B Length");							// ShapeDataInput Function Call

	shapePerimeter = (2 * shapeSideX) + (2 * shapeSideY);					// Rectangle Perimeter Formula
	shapeArea = shapeSideX * shapeSideY;									// Rectangle Area Formula

	cout << endl;
	ShapeDataOutput("Rectangle", "Perimeter", "Area", "", shapePerimeter,	// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/********** TriangleOperations Function ********************/
void TriangleOperations() {
	shapeDescription = "A triangle is a three-sided polygon.";

	ShapeHeader("Triangle", shapeDescription);								// ShapeHeader Function Call

	shapeSideX = ShapeDataInput("Side Length A");							// ShapeDataInput Function Call
	shapeSideY = ShapeDataInput("Side Length B");							// ShapeDataInput Function Call
	shapeSideZ = ShapeDataInput("Side Length C");							// ShapeDataInput Function Call

	shapePerimeter = shapeSideX + shapeSideY + shapeSideZ;					// Triangle Perimeter Formula
	sineForumla = shapePerimeter / 2;										// Sine Formula
	shapeArea = sqrt(sineForumla * (sineForumla - shapeSideX) *				// Triangle Area - Heron's Formula
		(sineForumla - shapeSideY) * (sineForumla - shapeSideZ));

	cout << endl;
	ShapeDataOutput("Triangle", "Perimeter", "Area", "", shapePerimeter,	// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/******** RightCirclularConeOperations Function **********/
void RightCircularConeOperations() {
	shapeDescription = "The right circular cone is a three-dimensional"
		"\n\t\tobject created by rotating a right triangle about the vertical";

	ShapeHeader("Right Circular Cone", shapeDescription);						// ShapeHeader Function Call

	shapeRadius = ShapeDataInput("Radius");										// ShapeDataInput Function Call
	shapeHeight = ShapeDataInput("Height");										// ShapeDataInput Function Call

	shapeSlant = sqrt(pow(shapeRadius, 2) + pow(shapeHeight, 2));				// Right Circular Cone Slant Formula
	shapeArea = (PI * pow(shapeRadius, 2)) + (PI * shapeRadius * shapeSlant);	// Right Circular Cone Area Formula
	shapeVolume = (PI * pow(shapeRadius, 2) * shapeHeight) / 3;					// Right Circular Cone Volume Formula

	cout << endl;
	ShapeDataOutput("Right Circular Cone", "Volume", "Slant", "Area",			// ShapeDataOutput Function Call 
		shapeVolume, shapeSlant, shapeArea);
	cout << endl;

	studentUses++;
}

/**************** SphereOperations Function ****************/
void SphereOperations() {
	shapeDescription = "The sphere is a 3 dimensional object,"
		"\n\t\twhose surface is continuous and all points of the surface"
		"\n\t\tare an equal distance from a fixed point, the center.";

	ShapeHeader("Sphere", shapeDescription);								// ShapeHeader Function Call

	shapeRadius = ShapeDataInput("Radius");									// ShapeDataInput Function Call

	shapeArea = (4 * PI * pow(shapeRadius, 2));								// Sphere Surface Area Formula
	shapeVolume = (4 * PI * pow(shapeRadius, 3)) / 3;						// Sphere Volume Formula

	cout << endl;
	ShapeDataOutput("Sphere", "Volume", "Surface Area", "", shapeVolume,	// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/**************** CubeOperations Function ******************/
void CubeOperations() {
	shapeDescription = "A cube is a three dimensional"
		"\n\t\tobject bounded by 6 equal square sides.";

	ShapeHeader("Cube", shapeDescription);								// ShapeHeader Function Call

	shapeSideX = ShapeDataInput("Side Length");							// ShapeDataInput Function Call

	shapeArea = (6 * pow(shapeSideX, 2));								// Cube Surface Area Formula
	shapeVolume = pow(shapeSideX, 3);									// Cube Volume Formula

	cout << endl;
	ShapeDataOutput("Cube", "Volume", "Surface Area", "", shapeVolume,	// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/*************** CylinderOperations Function ***************/
void CylinderOperations() {
	shapeDescription = "The cylinder, also know as the right"
		"\n\t\tcircular cylinder, is formed by rotating a line, of length"
		"\n\t\th, around a fixed axis parallel to that line. A cylinder"
		"\n\t\thas two ends that are equally sized circles parallel to one"
		"\n\t\tanother and the circular side is at a right angle to these"
		"\n\t\tcircular ends.";

	ShapeHeader("Cylinder", shapeDescription);							// ShapeHeader Function Call


	shapeRadius = ShapeDataInput("Radius");								// ShapeDataInput Function Call
	shapeHeight = ShapeDataInput("Height");								// ShapeDataInput Function Call

	shapeArea = 2 * PI * (shapeRadius * (shapeRadius + shapeHeight));	// Cylinder Surface Area Formula
	shapeVolume = PI * pow(shapeRadius, 2) * shapeHeight;				// Cylinder Volume Formula

	cout << endl;
	ShapeDataOutput("Cylinder", "Volume", "Area", "", shapeVolume,		// ShapeDataOutput Function Call
		shapeArea, NULL);
	cout << endl;

	studentUses++;
}

/************ FinalReport Function **************************/
void FinalReport(string name, int age, char gender, int uses) {
	studentId = (rand() % 9000) + 1000;

	cout << "\t\t";
	system("Pause");
	system("cls");

	title = "Final Report";
	cout << right << setfill(' ');
	cout << "\n" << setw(85) << title << endl;
	cout << right << setfill('_');
	cout << "\n" << setw(168) << "_" << endl;

	cout << left << setw(16) << setfill(' ') << ' ';
	cout << setw(15) << left << "Student ID" <<
		setw(20) << left << "Name" <<
		setw(10) << left << "Age" <<
		setw(8) << right << "Gender" <<
		setw(17) << right << "No.Uses" << endl;

	cout << left << setw(16) << setfill(' ') << ' ';
	cout << setw(15) << left << studentId <<
		setw(20) << left << name <<
		setw(14) << left << age <<
		setw(1) << right << gender <<
		setw(17) << right << uses << endl;
}


/***************** ShapeDataInput Function *******************/
double ShapeDataInput(string data) {
	double shapeData;
	cout << "\t\t" << data << ": ";
	cin >> shapeData;					// Get input from user

	return shapeData;					// return user input
}

/***************** ShapeDataOutput Function *******************/
void ShapeDataOutput(string shapeTitle, string measurementX,
	string measurementY, string measurementZ, double valueX,
	double valueY, double valueZ) {

	cout << "\n\t\tThe results for " << shapeTitle << " is: " << endl;

	if (valueX != NULL) {													// Check for non NULL value
		cout << "\t\t" << measurementX << ": " << valueX << endl;

		if (valueY != NULL) {												// Check for non NULL value
			cout << "\t\t" << measurementY << ": " << valueY << endl;

			if (valueZ != NULL) {											// Check for non Null value
				cout << "\t\t" << measurementZ << ": " << valueZ << endl;
			}
		}
	}
}