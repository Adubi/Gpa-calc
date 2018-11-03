#include <iostream>
using namespace std;
class Course{
	string CourseCode, Grade;
	int Score, Unit;
	public : void SetValues(string cCode, int scr, int uni)
	{
		CourseCode = cCode;
		Score = scr;
		Unit = uni;
	}
	public : void CalculateGrade(){
		if(Score < 40){
			Grade = "F";
		}
		else if (Score < 50){
			Grade = "D";
		}
		else if (Score < 60){
			Grade = "C";
		}
		else if (Score < 70){
			Grade = "B";
		}
		else {
			Grade = "A";
		}
	}
	
	public : void OutPutValues()
	{
		cout << CourseCode << "\t" << Unit << "\t" << Score << "\t" << Grade << "\n";
	}
	
	public : float  GradeUnit(){
		float gradePoint;
		if(Grade ==  "A")
		{
			gradePoint = 5.0;
		}
		else if(Grade ==  "B")
		{
			gradePoint = 4.0;
		}
		else if(Grade ==  "C")
		{
			gradePoint = 3.0;
		}	
		else if(Grade ==  "D")
		{
			gradePoint = 2.0;
		}	
		else
		{
			gradePoint = 0.0;
		}
		
		return gradePoint * Unit;
	}
};

float CalculateGP(Course courses[], int n){
	
	float gradePoint = 0.0;
	
	for (int i = 0; i < n; i++)
	{
		gradePoint += courses[i].GradeUnit();
	}
	
	return gradePoint * unit /n;
}

int main()
{
	int n;
	cout << "Enter Number of Courses: ";
	cin >> n;
	
	Course courses[n];
	
	for (int i = 0; i < n; i ++){
		Course c;
		string code;
		int score, unit;
		cout << "Enter Course Code: ";
		cin >> code;
		cout << "Enter Course Unit: ";
		cin >> unit;
		cout << "Enter Student's Score: ";
		cin >> score;
		
		c.SetValues(code, score, unit);
		c.CalculateGrade();
		
		courses[i] = c;
	}
	
	for (int i = 0; i < n; i++)
	{
		courses[i].OutPutValues();
	}
	
	cout << "\nStudent's GP is: " << CalculateGP(courses, n);
	return 0;
}
