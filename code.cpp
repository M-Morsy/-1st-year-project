#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int diff_days(int day_min, int month_min, int year_min, int day_max, int month_max, int year_max)
{
    int year_min_op = year_min;
    int sum = 0;
    for (year_min_op; year_min_op < year_max; year_min_op++)
    {
   	 if (year_min_op % 400 == 0 || (year_min_op % 4 == 0 && year_min_op % 100 != 0)) sum = sum + 366;
   	 else sum = sum + 365;
    }
    if (year_max % 400 == 0 || (year_max % 4 == 0 && year_max % 100 != 0))
    {
   	 if (month_max == 1) sum = sum + 0; if (month_max == 2) sum = sum + 31; if (month_max == 3) sum = sum + 60; if (month_max == 4) sum = sum + 91;
   	 if (month_max == 5) sum = sum + 121; if (month_max == 6) sum = sum + 152; if (month_max == 7) sum = sum + 182; if (month_max == 8) sum = sum + 213;
   	 if (month_max == 9) sum = sum + 244; if (month_max == 10) sum = sum + 274; if (month_max == 11) sum = sum + 305; if (month_max == 12) sum = sum + 335;
    }
    else
    {
   	 if (month_max == 1) sum = sum + 0; if (month_max == 2) sum = sum + 31; if (month_max == 3) sum = sum + 59; if (month_max == 4) sum = sum + 90;
   	 if (month_max == 5) sum = sum + 120; if (month_max == 6) sum = sum + 151; if (month_max == 7) sum = sum + 181; if (month_max == 8) sum = sum + 212;
   	 if (month_max == 9) sum = sum + 243; if (month_max == 10) sum = sum + 273; if (month_max == 11) sum = sum + 304; if (month_max == 12) sum = sum + 334;
    }
    if (year_min % 400 == 0 || (year_min % 4 == 0 && year_min % 100 != 0))
    {
   	 if (month_min == 1) sum = sum - 0; if (month_min == 2) sum = sum - 31; if (month_min == 3) sum = sum - 60; if (month_min == 4) sum = sum - 91;
   	 if (month_min == 5) sum = sum - 121; if (month_min == 6) sum = sum - 152; if (month_min == 7) sum = sum - 182; if (month_min == 8) sum = sum - 213;
   	 if (month_min == 9) sum = sum - 244; if (month_min == 10) sum = sum - 274; if (month_min == 11) sum = sum - 305; if (month_min == 12) sum = sum - 335;
    }
    else
    {
   	 if (month_min == 1) sum = sum - 0; if (month_min == 2) sum = sum - 31; if (month_min == 3) sum = sum - 59; if (month_min == 4) sum = sum - 90;
   	 if (month_min == 5) sum = sum - 120; if (month_min == 6) sum = sum - 151; if (month_min == 7) sum = sum - 181; if (month_min == 8) sum = sum - 212;
   	 if (month_min == 9) sum = sum - 243; if (month_min == 10) sum = sum - 273; if (month_min == 11) sum = sum - 304; if (month_min == 12) sum = sum - 334;
    }
    sum = sum + day_max - day_min + 1;
    return sum;
}

double convert(string s)
{
    double  f;
    f = atof(s.c_str());
    return f;
    // usage is like : x = convert (y) >> x is float & y is string .
}

void test(string s)
{
    cout << s << endl;
}
void test(int s)
{
    cout << s << endl;
}
string cutter(string s, char c1, char c2, int d)
{
    string NEW; int x1, x2, steps;
    //cout << "test for c1 == c2" << endl;
    x1 = s.find(c1);
    //cout << x1 << endl;
    NEW = s.substr(x1 + 1);
    //cout << NEW << endl;
    x2 = NEW.find(c2);
    //cout << x2 << endl;
    if (d == 1)
    {
   	 NEW = s[x1] + NEW.substr(0, x2) + NEW[x2];
    }
    else if (d == 0)
    {
   	 NEW = NEW.substr(0, x2);
    }

    return NEW;
    // usage is like : x = cutter ( y , ' ' , ' ' ) >> x NEW string & y old string .
    // 1 means keep char 1 & 2

}

int assigner(string s, string ar[] /*returned*/, char c1, char c2, char c)
{
    s = cutter(s, c1, c2, 0);
    string s_backup = s;
    int x = s.length();
    int y = s_backup.length();
    int co = 0;
    for (int i = 0; i < y; i++)
    {
   	 if (s_backup[i] == c)
   	 {
   		 ar[co] = s.substr(0, i - (y - x));
   		 s = s_backup.substr(i + 1);
   		 co++;
   		 x = s.length();
   	 }
    }
    ar[co] = s;
    co++; // co now represents no of elements in array >> no = index of last element + 1
   	   // c1 >> start from here , one step after     // c2 >> stop here , one step before     // c >> at at that jump to next array element
    return co;
}

int index_finder(string ar[], string x, int counter)
{
    int n = -1;
    for (int i = 0; i < counter; i++)
    {
   	 //cout << s[i] << endl; //remove
   	 //cout << x << endl;
   	 if (ar[i] == x)// there is a problem here
   	 {

   		 n = i;


   	 }
    }
    return n;
    // if o = -1>> no such thing in array
    // if o = number >> that number is the wanted one
}


void display_array_endl(string ar[], int counter)
{
    for (int i = 0; i < counter; i++)
    {
   	 cout << ar[i] << endl;
    }

}

void display_array_endl(string ar[][2], int counter) //check
{
    for (int i = 0; i < counter; i++)
    {
   	 cout << ar[i][0] << " || " << ar[i][1] << endl;
    }

}

void max_dates(int no_dates, int date[][3], int &max_D, int &max_M, int &max_Y) //check
{
    int i = 1;
    max_Y = date[0][2];
    max_M = date[0][1];
    max_D = date[0][0];
    for (i = 1; i < no_dates; i++)
    {
   	 if (date[i][2] > max_Y)
   	 {
   		 max_Y = date[i][2];
   		 max_M = date[i][1];
   		 max_D = date[i][0];
   	 }
   	 else if (date[i][2] == max_Y)
   	 {
   		 if (date[i][1] > max_M)
   		 {
   			 max_Y = date[i][2];  max_M = date[i][1];  max_D = date[i][0];

   		 }
   		 if (date[i][1] == max_M)
   		 {
   			 if (date[i][0] > max_D)
   			 {
   				 max_Y = date[i][2];    max_M = date[i][1];    max_D = date[i][0];
   			 }
   		 }
   	 }

    }
}

void min_dates(int no_dates, int date[][3], int &min_D, int &min_M, int &min_Y) //check
{
    int i = 1;
    min_Y = date[0][2];
    min_M = date[0][1];
    min_D = date[0][0];

    for (i = 1; i < no_dates; i++)
    {
   	 if (date[i][2] < min_Y)
   	 {
   		 min_Y = date[i][2];
   		 min_M = date[i][1];
   		 min_D = date[i][0];
   	 }
   	 else if (date[i][2] == min_Y)

   	 {
   		 if (date[i][1] < min_M)
   		 {

   			 min_Y = date[i][2];
   			 min_M = date[i][1];
   			 min_D = date[i][0];

   		 }
   		 if (date[i][1] == min_M)
   		 {
   			 if (date[i][0] < min_D)
   			 {
   				 min_Y = date[i][2];
   				 min_M = date[i][1];
   				 min_D = date[i][0];

   			 }
   		 }

   	 }

    }


}

int index_finder_2d(string array[][2], string s, int counter, string decide) //check
{
    int index;
    for (int i = 0; i < counter; i++)
    {
   	 if ((array[i][1] == s && decide == "second") || (array[i][0] == s && decide == "first"))
   	 {
   		 index = i;
   	 }
    }
    return index;
}


void sort_dates_function(string array_str[][2], int size_array) //check
{
    /// first step is to get the dates into array dates and its back up.
    string back_up[100];
    string  dates[100];
    int date[100][3];
    for (int i = 0; i < size_array; i++)
    {
   	 back_up[i] = array_str[i][1];
   	 dates[i] = back_up[i];
    }
    /// end step 1
    ///step 2 is to put dates into another array 2d that is int to use th function of min dates

    for (int i = 0; i < size_array; i++)
    {
   	 dates[i] = " " + dates[i] + " ";
   	 date[i][0] = convert(cutter(dates[i], ' ', '/', 0));
   	 date[i][1] = convert(cutter(dates[i], '/', '/', 0));
   	 date[i][2] = convert(cutter(dates[i], '/', ' ', 0));
   	 dates[i] = dates[i].substr(1);
   	 int length = dates[i].length();
   	 dates[i] = dates[i].substr(0, length - 1);
    }
    /// end step 2

    ///step three is to get the string array sorted
    int min_index;
    string vessel;
    int d_int, m_int, y_int;
    string d, m, y, wanted_date;
    for (int i = 0; i < size_array; i++)
    {
   	 min_dates(size_array, date, d_int, m_int, y_int);
   	 d = to_string(d_int); m = to_string(m_int); y = to_string(y_int);
   	 wanted_date = d + "/" + m + "/" + y;
   	 min_index = index_finder_2d(array_str, wanted_date, size_array, "second");
   	 vessel = array_str[i][1];
   	 array_str[i][1] = array_str[min_index][1];
   	 array_str[min_index][1] = vessel;
   	 dates[min_index][2] = 5000;
    }

}


int Study_Days(string ID, string code, string student_array[], string course_array[], int no_courses) //check
{
    int study_days;
    ///step 1 : using student ID >> get all courses of that student into array_StdCrcs

    string array_StdCrcs[10]; int counter = 0;
    string array_dates_str[10]; int c = 0; int date[10][3];
    int index_student = index_finder(student_array, ID, 300);
    index_student = index_student + 2;
    counter = assigner(student_array[index_student], array_StdCrcs, '(', ')', ' '); //array >> courses
   																				 ///end step 1

   																				 /// step 2 is to get the dates of each course of the studnt given in an course_date_array
    string course_date_array[10][2];
    int index_course = 0;
    for (int i = 0; i < counter; i++)
    {
   	 index_course = index_finder(course_array, array_StdCrcs[i], 400);
   	 course_date_array[i][0] = course_array[index_course];
   	 course_date_array[i][1] = course_array[index_course + 2]; // course_array[index_course + 2] is the date
    }
    ///end step 2

    /// step 3 is to sort the array of dates .
    //we do that using a function
    string dates_only[10];
    sort_dates_function(course_date_array, counter);
    /// end step 3

    /// step 4 get the study days
    /*int index_code = index_finder(course_array, code, no_courses);*/  // I don't remember why i did that
    int index_code = index_finder_2d(course_date_array, code, counter, "first");
    if (index_code == 0) { study_days = 7; }
    else
    {
   	 /// get the dates of the wanted code and the previous one
   	 string B_L_date = " " + course_date_array[index_code - 1][1] + " ";
   	 string L_date = " " + course_date_array[index_code][1] + " ";
   	 int L_D = convert(cutter(L_date, ' ', '/', 0)); int  L_M = convert(cutter(L_date, '/', '/', 0)); int L_Y = convert(cutter(L_date, '/', ' ', 0));
   	 int B_L_D = convert(cutter(B_L_date, ' ', '/', 0)); int B_L_M = convert(cutter(B_L_date, '/', '/', 0)); int B_L_Y = convert(cutter(B_L_date, '/', ' ', 0));
   	 /// get the diff in days "function" & subscribe 2 or 1 >> test it // don't forget that
   	 study_days = diff_days(B_L_D, B_L_M, B_L_Y, L_D, L_M, L_Y) + 2; //check
    }
    return study_days;
}





int main()
{
    //taking i/p
    string course_input, course_backup, course;
    string student_input, student_backup, student, vessel;
    //testing

    /*course_input = "CoursesExams=[HUM001,Technical Writing,28/4/2016,HallA;CSE121,Computer Programming,3/5/2016,HallA;PHM110,Math 3,5/5/2016,HallC;PHM103,Physics,5/5/2016,HallA;EPM120,Electric Circuits,6/5/2016,HallD;ECE132,Electronics,7/5/2016,HallB];CSE432,Computer Security,28/4/2016,HallA]";
    student_input = "Students=[12001,Ahmed Hassan,(CSE121,HUM001,PHM110);12002,Aly Hamed,(CSE121,PHM110,PHM103);12003,Ayman Ali,(PHM110,EPM120,ECE132);12006,Hazem Elshenawy,(PHM103,ECE132);12007,Ahmed Gaber,(CSE432)]";
    */
    /*
    course_input  = "CoursesExams=[CES231,Steel Structures Design(1),17/5/2014,HallA;MDP163,Machine Drawing and Solid Modeling,11/6/2014,HallA;MDP162,Mechanical Engineering Drawing,20/5/2014,HallB;CEI122,Fluid Mechanics,18/5/2014,HallC;ECE141,Electrical and Electronic Circuits,7/6/2014,HallC;EPM232,Electrical Machines(2),25/5/2014,HallB]";
    student_input = "Students=[1340,Islam Said,(EPM232,MDP163,CEI122,MDP162);1339,Ahmed Kamal,(CEI122,MDP163,MDP162);1382,Ali Moussa,(CES231,EPM232,MDP162);1373,Mohamed Said,(MDP163,MDP162,ECE141);1410,Ahmed Adballah,(CEI122,ECE141,CES231,EPM232);1307,Mohamed Kamal,(MDP163,CES231,ECE141);1434,Osama Bassem,(ECE141,CEI122,CES231);1183,Ahmed Said,(CEI122,MDP163,CES231);1411,Osama Said,(EPM232);1435,Wael Bassem,(MDP162,ECE141,CEI122,CES231);1174,Esraa AbdAlrahman,(ECE141);1263,Osama Zain,(CEI122,MDP163,CES231);1196,Bassant Tarek,(MDP163,CES231);1454,Ali Hassan,(MDP162,CES231,CEI122);1198,Bassant Moussa,(ECE141,MDP163,MDP162);1265,Ismail AbdAlrahman,(EPM232,MDP162,CES231);1171,Bassant Zain,(MDP163,EPM232,MDP162,CEI122);1204,Mohamed Kassem,(CEI122,CES231);1372,Ismail Kamal,(CEI122)]";
    */

    getline(cin, course_input);
    getline(cin, student_input);


    // cutting the string & making backup
    int  student_input_length = student_input.length();
    int  course_input_length = course_input.length();
    student = student_input.substr(10, student_input_length - 11);
    course = course_input.substr(14, course_input_length - 15);
    course_backup = course;
    student_backup = student;


    // data transportation into arrays
    int student_length = student.length();
    int course_length = course.length();
    int course_backup_length = course.length();
    int student_backup_length = student.length();

    string student_array[300];
    string course_array[400];
    int course_array_counter = 0;
    int student_array_counter = 0;

    //CODE  get rid of "," in students' course_code
    int x1 = 0; int x2 = 0; int i;
    for (int i = 0; i < student_length; i++)
    {
   	 if (student[i] == '(')
   	 {
   		 x1 = i;
   		 //cout << x1 << endl ;
   	 }
   	 if (student[i] == ')')
   	 {
   		 x2 = i;
   		 //cout << x2 << endl ;
   	 }
   	 for (int j = 0; j <= x2; j++)
   	 {
   		 if ((j > x1) && (j < x2) && (student[j] == ','))
   		 {
   			 //cout << student << endl ;
   			 student[j] = ' ';
   		 }
   	 }
    }

    //cout << student << endl ;    
    student_backup = student;
    /*cout << endl ;
    cout << endl ;*/


    //CODE to fill the array with data isa .
    //courses
    for (int i = 0; i < course_backup_length; i++)
    {
   	 if ((course_backup[i] == ';') || (course_backup[i] == ','))
   	 {
   		 course_array[course_array_counter] = course.substr(0, i - (course_backup_length - course_length));
   		 course = course_backup.substr(i + 1);
   		 course_array_counter++;
   		 course_length = course.length();
   	 }
    }
    //cout << course_array_counter << endl ;
    //cout << course_backup_length << endl ;
    course_array[course_array_counter] = course; // for the last course : not followed with a ; .
    course = course_backup; // to return course to its initial state >> the full important data .

   						 //students
    for (int i = 0; i < student_backup_length; i++)
    {
   	 if ((student_backup[i] == ';') || (student_backup[i] == ','))
   	 {

   		 student_array[student_array_counter] = student.substr(0, i - (student_backup_length - student_length));
   		 student = student_backup.substr(i + 1);
   		 student_array_counter++;

   		 student_length = student.length();

   	 }
    }
    student_array[student_array_counter] = student; // for the last student : not followed with a ; .
    student = student_backup; // to return student to its initial state >> the full important data .


   						   //code to get the no. of students & courses >> then cout the array
    int no_students = (student_array_counter + 1) / 3;
    int no_courses = (course_array_counter + 1) / 4;
    //  due to taking "," into considration not only ";" so we do (/4) & counter ddn't take the last element into cosidiration so we count it be adding (+1)


    //NOW WE GET TO THE OPERATION .
    string operation;

    while (1)
    {
   	 //getting operation name
   	 getline(cin, operation);
   	 //test(operation.substr(0, 29)); cout << "."; //remove

   	 if (operation == "Number_Students")
   	 {
   		 cout << no_students << endl;
   	 }


   	 if (operation == "Number_Courses")
   	 {
   		 cout << no_courses << endl;
   	 }


   	 if (operation == "Quit")
   	 {

   		 break;
   	 }


   	 if (operation == "Number_Halls")
   	 {
   		 string operation;
   		 string vessel;
   		 int no_halls = 0;
   		 string hall_array[100];
   		 string hall_array_backup[100];
   		 // filling array of halls
   		 int j = 3;
   		 for (int i = 0; i < course_array_counter; i++)
   		 {
   			 hall_array[i] = course_array[j];
   			 j = j + 4;

   		 }
   		 //to calculate no_halls with the repeated ones
   		 no_halls = (course_array_counter + 1) / 4;
   		 int no_halls_backup = no_halls;
   		 // loop to get back up array
   		 for (int i = 0; i < no_halls; i++)
   		 {
   			 hall_array_backup[i] = hall_array[i];
   			 //cout << hall_array_backup [i] << endl ;
   		 }
   		 // to make an array to replace its elements with repeated halls in hall_array
   		 string replace[100];
   		 for (int i = 0; i < no_halls_backup; i++)
   		 {
   			 replace[i] = "0";
   		 }
   		 // to remove the extra halls .
   		 int flag = 0;
   		 no_halls = 0;
   		 for (int i = 0; i < no_halls_backup; i++)
   		 {
   			 vessel = hall_array[i];
   			 flag = 0;
   			 for (int j = 0; j < no_halls_backup; j++)
   			 {
   				 if (vessel == hall_array[j])
   				 {
   					 flag++;

   					 if (flag > 1)
   					 {
   						 hall_array[j] = replace[i];
   					 }
   				 }
   			 }
   		 }
   		 // code to count halls after cleaning the array
   		 for (int i = 0; i < no_halls_backup; i++)
   		 {
   			 no_halls++;
   			 if (hall_array[i] == "0")
   			 {
   				 no_halls--;
   			 }
   		 }
   		 cout << no_halls << endl;
   	 }


   	 if (operation == "Student_ID_Min" || operation == "Student_ID_Max" || operation == "Students_Dropped_IDs")
   	 {
   		 // operation student ID max & mini
   		 //code to get no. of Ids
   		 int no_IDs = (student_array_counter + 1) / 3;
   		 //cout << no_IDs << endl ;
   		 //code to get ID array of int .
   		 int ID_array[100];
   		 int j = 0;
   		 for (int i = 0; i < no_IDs; i++)
   		 {
   			 ID_array[i] = atof(student_array[j].c_str());
   			 j = j + 3;

   			 /*cout << ID_array [i] << endl ;
   			 cout << ID_array [i] +1 << endl ;
   			 cout << endl ;*/
   		 }
   		 // now a loop to choose max id & mini
   		 int max_ID = ID_array[0];
   		 int min_ID = ID_array[0];
   		 for (int i = 0; i < no_IDs; i++)
   		 {
   			 if (ID_array[i] > max_ID) { max_ID = ID_array[i]; }
   			 if (ID_array[i] < min_ID) { min_ID = ID_array[i]; }
   		 }

   		 if (operation == "Student_ID_Max")
   			 cout << max_ID << endl;
   		 else if (operation == "Student_ID_Min")
   			 cout << min_ID << endl;

   		 else if (operation == "Students_Dropped_IDs")
   		 {
   			 // to know the total no. of Ids & the expected no. assuming that there is no dropped Ids .
   			 int no_IDs_expected = (max_ID + 1) - min_ID;

   			 //cout << no_IDs_expected << endl ;
   			 int IDs_expected_array[1000];
   			 IDs_expected_array[0] = min_ID;
   			 int balance = 0;
   			 //cout << IDs_expected_array [0] << endl  ;
   			 // to check whether there was any dropped Ids or not & printing none if there wasn't
   			 if ((no_IDs_expected - no_IDs) == 0) { cout << "none" << endl; }

   			 else
   			 {// making an array from mini to max with all the no.s covered
   				 for (int i = 1; i < no_IDs_expected; i++)
   				 {
   					 IDs_expected_array[i] = IDs_expected_array[i - 1] + 1;
   					 //cout << IDs_expected_array [i] << endl ;
   				 }
   				 // compaing bet. the 2 arrays >> i/p & written by me
   				 int flag = 0;

   				 for (int i = 0; i < no_IDs_expected; i++)
   				 {
   					 flag = 0;
   					 for (int j = 0; j < no_IDs; j++)
   					 {
   						 if (IDs_expected_array[i] == ID_array[j])
   						 {
   							 flag++;
   							 //cout << flag << endl ;
   						 }
   					 }
   					 if (flag == 0)
   					 {
   						 //cout << "test " << endl ;
   						 cout << IDs_expected_array[i] << endl;
   					 }
   				 }
   			 }
   		 }
   	 }


   	 if (operation == "Exams_End_Date" || operation == "Exams_Start_Date" || operation == "Exams_Period_InDays")
   	 {// code to get date array .
   		 string vessel;
   		 string  dates_array[100];
   		 int day_array[100], month_array[100], year_array[100];
   		 int no_dates = (course_array_counter + 1) / 4; //used as counter to all loops
   														//cout << no_dates << endl ;

   														// code to get string array of date
   		 int j = 2;
   		 for (int i = 0; i < no_dates; i++)
   		 {
   			 dates_array[i] = course_array[j];
   			 j = j + 4;
   			 //cout << dates_array [i] << endl ;
   		 }


   		 // code to get arrays of day month year .
   		 int first_slash, second_slash;

   		 int date_length;
   		 int flag = 0;
   		 for (int i = 0; i < no_dates; i++)
   		 {
   			 vessel = dates_array[i];
   			 date_length = vessel.length();
   			 //cout << vessel << endl << date_length << endl ;
   			 for (j = 0; j < date_length; j++)
   			 {
   				 if (vessel[j] == '/')
   				 {
   					 flag++;
   					 if (flag == 1)
   					 {
   						 first_slash = j;
   					 }
   					 if (flag == 2)
   					 {
   						 second_slash = j;
   					 }
   				 }

   			 }
   			 //cout << first_slash << endl << second_slash << endl   ;
   			 flag = 0;
   			 int month_cut_end = (date_length - (first_slash + 1) - (date_length - (second_slash)));
   			 day_array[i] = atof((dates_array[i].substr(0, first_slash)).c_str());
   			 month_array[i] = atof((dates_array[i].substr(first_slash + 1, month_cut_end)).c_str());
   			 year_array[i] = atof((dates_array[i].substr(second_slash + 1)).c_str());
   			 /*cout << day_array [i] << " " << month_array [i] << " "  << year_array [i] << endl  ;
   			 cout << day_array [i] +1 << " " << month_array [i]+1 << " "  << year_array [i]+1 << endl << endl ;*/
   		 }
   		 int max_D = day_array[0]; int max_M = month_array[0]; ; int max_Y = year_array[0]; int index_max_year[100];
   		 int min_D = day_array[0]; int min_M = month_array[0]; ; int min_Y = year_array[0]; int index_min_year[100];
   		 // code to get end date exam & start date exams
   		 for (int i = 1; i < no_dates; i++)
   		 {
   			 if (year_array[i] > max_Y)
   			 {
   				 max_Y = year_array[i];
   				 max_M = month_array[i];
   				 max_D = day_array[i];
   			 }
   			 else if (year_array[i] == max_Y)
   			 {
   				 if (month_array[i] > max_M)
   				 {
   					 max_Y = year_array[i];
   					 max_M = month_array[i];
   					 max_D = day_array[i];

   				 }


   				 if (month_array[i] == max_M)
   				 {

   					 if (day_array[i] > max_D)
   					 {
   						 max_Y = year_array[i];
   						 max_M = month_array[i];
   						 max_D = day_array[i];

   					 }
   				 }
   			 }
   			 /******************************************/
   			 if (year_array[i] < min_Y)
   			 {
   				 min_Y = year_array[i];
   				 min_M = month_array[i];
   				 min_D = day_array[i];
   			 }
   			 else if (year_array[i] == min_Y)

   			 {
   				 if (month_array[i] < min_M)
   				 {

   					 min_Y = year_array[i];
   					 min_M = month_array[i];
   					 min_D = day_array[i];

   				 }
   				 if (month_array[i] == min_M)
   				 {
   					 if (day_array[i] < min_D)
   					 {
   						 min_Y = year_array[i];
   						 min_M = month_array[i];
   						 min_D = day_array[i];

   					 }
   				 }

   			 }
   		 }

   		 if (operation == "Exams_End_Date")
   		 {
   			 cout << max_D << "/";
   			 cout << max_M << "/";
   			 cout << max_Y << endl;
   		 }
   		 if (operation == "Exams_Start_Date")
   		 {
   			 cout << min_D << "/";
   			 cout << min_M << "/";
   			 cout << min_Y << endl;
   		 }

   		 if (operation == "Exams_Period_InDays")
   		 {
   			 int diff_day;
   			 diff_day = diff_days(min_D, min_M, min_Y, max_D, max_M, max_Y);
   			 cout << diff_day << endl;
   		 }

   	 }



   	 if (operation.substr(0, 15) == "Student_Courses")
   	 {
   		 //display_array_endl(student_array, no_students * 3);
   		 string s;
   		 string output[10];
   		 int index = 0;
   		 // s here is the ID
   		 s = operation.substr(16);
   		 //cout << s << endl;
   		 index = index_finder(student_array, s, (no_students * 3));
   		 index = index + 2; // index is the index of s : ID , in assigner we need the index of courses
   							//cout << student_array[index] << endl;
   							//cout << index << endl;
   							//index = 2;
   		 int counter = assigner(student_array[index], output, '(', ')', ' ');
   		 //cout << counter << endl;

   		 display_array_endl(output, counter);

   	 }



   	 if (operation.substr(0, 15) == "Course_Students")
   	 {
   		 string code = operation.substr(16);
   		 //cout << code << endl;
   		 string array[10];
   		 int counter = 0;
   		 for (int i = 2; i < (no_students + 2) * 3; i = i + 3)
   		 {// no_students : i from 0 , no_students+2 : i from 2
   			 counter = assigner(student_array[i], array, '(', ')', ' ');
   			 for (int j = 0; j < counter; j++)
   			 {
   				 if (array[j] == code)
   				 {
   					 cout << student_array[i - 2] << endl;
   				 }
   			 }
   		 }
   	 }

   	 if (operation.substr(0, 20) == "List_Course_Students")
   	 {
   		 int length = operation.length();
   		 string reason = cutter(operation, ' ', ' ', 0);
   		 //cout << reason << endl;//
   		 string n_str = operation.substr(length - 1);
   		 int n = convert(n_str);
   		 //cout << n << endl;//
   		 int counter = 0;
   		 int no_stds = 0;
   		 string array[10];
   		 int none_decide = 0;
   		 for (int k = 0; k < (no_courses * 4); k = k + 4)
   		 {
   			 no_stds = 0;
   			 for (int i = 2; i < (no_students + 2) * 3; i = i + 3)
   			 {
   				 //cout << i << endl; //remove
   				 //cout << student_array[i] << endl; //remove
   				 counter = assigner(student_array[i], array, '(', ')', ' ');
   				 //cout << counter << endl;//remove
   				 //display_array_endl(array, counter);//remove
   				 for (int j = 0; j < counter; j++)
   				 {
   					 if (array[j] == course_array[k]) no_stds++;
   					 //cout << no_stds << endl ;
   				 }
   				 //cout << endl; //remove

   			 }
   			 //cout << "end" << endl; //remove
   			 if (reason == "More" && no_stds > n) { cout << course_array[k] << endl; none_decide++; }
   			 if (reason == "Less" && no_stds < n) { cout << course_array[k] << endl;  none_decide++; }
   			 if (reason == "Equal" && no_stds == n) { cout << course_array[k] << endl;  none_decide++; }

   		 }
   		 if (none_decide == 0) cout << "none";
   	 }

   	 if (operation.substr(0, 20) == "List_Student_Courses")
   	 {
   		 //cout << "1" << endl;
   		 int length = operation.length();
   		 string n_str = operation.substr(length - 1);
   		 int n = convert(n_str);
   		 //cout << n << endl;
   		 string reason = cutter(operation, ' ', ' ', 0);
   		 //cout << reason << endl;
   		 string array[10];
   		 int counter = 0;
   		 int none_decide = 0;
   		 for (int i = 2; i < (no_students * 3); i = i + 3)
   		 {
   			 counter = assigner(student_array[i], array, '(', ')', ' ');
   			 // here we just need the counter
   			 //cout << counter << endl;
   			 if (counter > n && reason == "More") { cout << student_array[i - 2] << endl;  none_decide++; }
   			 if (counter < n && reason == "Less") { cout << student_array[i - 2] << endl;  none_decide++; }
   			 if (counter == n && reason == "Equal") { cout << student_array[i - 2] << endl; none_decide++; }
   		 }
   		 if (none_decide == 0) cout << "none";
   	 }

   	 if (operation.substr(0, 19) == "List_Hall_Students ")// this operation is so like course_students but allitle advanced "one loop".
   	 {
   		 operation = operation + " "; // put a space to use cutter function
   		 string s1 = cutter(operation, ',', ' ', 0); // date
   													 //cout << s1 << endl; //remove
   		 int length = operation.length();
   		 //cout << length << endl; //remove
   		 operation = operation.substr(0, length - 1); // to remove the space again
   		 string s2 = cutter(operation, ' ', ',', 0); //hall
   													 //cout << s2 << endl; //remove
   		 string array[10];
   		 int counter = 0;
   		 string code;
   		 //cout << code << endl; //remove
   		 for (int i = 0; i < (no_courses * 4); i++)// here put * 4 because you started from 0 && moves one step per loop >> loop for every element
   		 {
   			 //cout << "course_array[i + 2] =" << course_array[i + 2] << endl; //remove
   			 //cout << "course_array[i + 3] =" << course_array[i + 3] << endl; //remove
   			 if (course_array[i + 2] == s1 && course_array[i + 3] == s2) // s1 is the date whick is 0 + 2 = 2 +1 >> 3 , element 3 in the courses array .
   			 {
   				 code = course_array[i];
   				 //cout << code << endl;//remove

   				 for (int j = 2; j < (no_students + 2) * 3; j = j + 3)
   				 {
   					 //cout << student_array[j] << endl; //remove
   					 counter = assigner(student_array[j], array, '(', ')', ' ');
   					 //cout << counter << endl; //remove
   					 for (int k = 0; k < counter; k++)
   					 {
   						 if (array[k] == code)
   						 {
   							 cout << student_array[j - 2] << endl;

   						 }
   					 }

   				 }

   			 }

   		 }
   	 }

   	 if (operation.substr(0, 27) == "List_Hall_Students_InAnyday")//like List_Hall_Students
   	 {
   		 operation = operation + " "; // put a space to use cutter function
   									  //cout << operation << endl ;
   		 string s = cutter(operation, ' ', ' ', 0); // hall name
   													//test(s) ;//remove
   		 int length = operation.length();
   		 operation = operation.substr(0, length - 1); // to remove the space again
   													  //cout << operation<< "." << endl; //remove
   		 string array[10];
   		 int counter = 0;
   		 string code;
   		 string array_checker[100];
   		 int c = 0; // the counter of aarray_checker
   					/* there was a flaw in the code >> the concept is to get hall name > course code > student ID : the same hall may have many courses & the same student may have many courses >> that finding method aint efficient*/
   					/*we need to get rid of repeated students & expand more possiblities for the searching process */
   		 for (int i = 0; i < (no_courses * 4); i = i + 4)// here put * 4 because of i+4 . (0123456 = i++)*4=(0 4 8 12....=i=i+4).
   		 {
   			 // first loop is to get course code using hall name >> every course has a hall >> that can be more than one course for the same hall .
   			 //test(course_array[i + 3]); test(course_array[i]); //remove >> hall name
   			 if (course_array[i + 3] == s) // s1 is the date whick is 0 + 2 = 2 +1 >> 3 , element 3 in the courses array .
   			 {

   				 code = course_array[i];
   				 //test(code); //remove
   				 for (int j = 2; j < (no_students * 3) + 2; j = j + 3)
   				 {
   					 //this loop is to get student ID from course code : first get all courses for that student : second test if he has the spesific course code we want.

   					 //student_array[j] here is courses & student_array[j - 2] is the ID
   					 counter = assigner(student_array[j], array, '(', ')', ' ');
   					 //display_array_endl(array, counter); //remove
   					 //test(counter); //remove
   					 for (int k = 0; k < counter; k++)
   					 {
   						 //here we check if the student has the course or not
   						 if (array[k] == code)
   						 {
   							 int n = index_finder(array_checker, student_array[j - 2], 100);

   							 if (n == -1)
   							 {
   								 cout << student_array[j - 2] << endl;
   								 array_checker[c] = student_array[j - 2];
   								 c++;
   							 }

   						 }
   					 }
   					 //cout << "end loop3" << endl; //remove
   				 }
   				 //cout << "end loop2" << endl; //remove
   			 }
   			 //cout << "end loop1" << endl; //remove
   		 }

   	 }
   	 if (operation.substr(0, 27) == "List_Day_Students_InAnyHall")// like List_Hall_Students
   	 {
   		 operation = operation + " "; // put a space to use cutter function
   		 string s = cutter(operation, ' ', ' ', 0); // date
   		 int length = operation.length();
   		 operation = operation.substr(0, length - 1); // to remove the space again

   		 string array[10];
   		 int counter = 0;
   		 string code;
   		 string array_checker[100];
   		 int c = 0; // the counter of aarray_checker
   		 for (int i = 0; i < (no_courses * 4); i = i + 4)// here put * 4 because you started from 0 && moves one step per loop >> loop for every element
   		 {
   			 if (course_array[i + 2] == s) // s is the date whick is 0 + 2 = 2 +1 >> 3 , element 3 in the courses array .
   			 {
   				 code = course_array[i];
   				 for (int j = 2; j < (no_students * 3) + 2; j = j + 3)
   				 {
   					 counter = assigner(student_array[j], array, '(', ')', ' ');
   					 for (int k = 0; k < counter; k++)
   					 {
   						 if (array[k] == code)
   						 {
   							 int n = index_finder(array_checker, student_array[j - 2], 100);

   							 if (n == -1)
   							 {
   								 cout << student_array[j - 2] << endl;
   								 array_checker[c] = student_array[j - 2];
   								 c++;
   							 }
   						 }
   					 }
   				 }
   			 }
   		 }

   	 }

   	 if (operation.substr(0, 11) == "List_Exams ") //keep the distance >> another operation later with the same initials
   	 {
   		 operation = operation + " ";
   		 string date = cutter(operation, ' ', ' ', 0);
   		 int length = date.length();
   		 operation = operation.substr(0, length - 1);

   		 for (int i = 0; i < (no_courses * 4); i = i + 4)
   		 {
   			 if (course_array[i + 2] == date)
   			 {
   				 cout << course_array[i] << endl;
   			 }
   		 }
   	 }


   	 if (operation.substr(0, 14) == "List_StudyDays" || operation.substr(0, 12) == "List_Minimum")
   	 {
   		 if (operation.substr(0, 15) == "List_StudyDays ")
   		 {
   			 operation = operation + " ";  string code = cutter(operation, ',', ' ', 0);
   			 int length = operation.length(); operation = operation.substr(0, length - 1); string ID = cutter(operation, ' ', ',', 0);
   			 int study_days = Study_Days(ID, code, student_array, course_array, no_courses);
   			 cout << study_days;
   		 }

   		 if (operation.substr(0, 30) == "List_StudyDays_ForEveryStudent")
   		 {
   			 operation = operation + " ";
   			 string code = cutter(operation, ' ', ' ', 0);
   			 int length = operation.length();  operation = operation.substr(0, length - 1);
   			 /// step1 fix operation course_students & use the code here to get all IDs of the given course >> put the output in an array & make it a function
   			 /// for each ID get the study days using thee function

   		 }
   		 if (operation.substr(0, 30) == "List_StudyDays_ForEveryCourse")
   		 {
   			 operation = operation + " ";
   			 string ID = cutter(operation, ' ', ' ', 0);
   			 int length = operation.length();  operation = operation.substr(0, length - 1);
   			 /// step 1 fix operation student_courses & use the code here to get all courses of the given ID >> put the putput in an array & make it a function
   			 /// step 2 for each code get the study days using function
   		 }

   		 if (operation.substr(0, 30) == "List_Minimum_Student_StudyDays")
   		 {
   			 operation = operation + " ";
   			 string ID = cutter(operation, ' ', ' ', 0);
   			 int length = operation.length();  operation = operation.substr(0, length - 1);
   		 }
   		 if (operation.substr(0, 29) == "List_Minimum_Course_StudyDays")
   		 {
   			 operation = operation + " ";
   			 string code = cutter(operation, ' ', ' ', 0);
   			 int length = operation.length();  operation = operation.substr(0, length - 1);

   		 }

   		 if (operation.substr(0, 22) == "List_Minimum_StudyDays")
   		 {
   			 /// step 1 for each student get all the courses
   			 /// follow on as List_Minimum_student_StudyDays & repeat it for all students
   		 }
   	 }

   	 if (operation.substr(0, 35) == "List_Exam_InSameDay_ForEveryStudent")
   	 {

   	 }

   	 /*
   	 if
   	 if
   	 if
   	 */



    }// for while .

    return 0;
}// for main .

 // index_finder >> المشكلة هنا ان الفنكشن ديه بتجيب سترينج موجود مرة واحدة بس فالاراى ، بمعنى انه لو فى اكتر من واحد هيرجع اخر قيمة >> عدل الكلام ده
// there is aproblem with : List_Course_Students More & equal & less ||   List_Hall_Students || studydays : timeout ??

 // preview all the checks >> all the new functions.
 // fix old functions


