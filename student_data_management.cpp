# include <iostream>
# include <fstream>
# include <vector>
# include <limits>
using namespace std ;

class student{
    public:
       int roll_number , age ;
       string name , gender , address , phone_number ;
       string course ;
       char choice ;

        student(){} 

        student(int x , string n , int a , string gen , string addr ,
                string phn_num , string cour){
            roll_number = x ;
            name = n ;
            age = a ; 
            gender = gen ;
            address = addr ;
            phone_number = phn_num ;
            course = cour ;
        }

        vector<student> arr ;

        void add_Student(){
                cout << "Enter Student Roll number: " ; cin >> roll_number ;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Student Name: " ; getline(cin , name) ; 
                cout << "Enter Age of Student: " ; cin >> age ;
                cout << "Enter Gender: " ; cin >> gender ;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Address: " ; getline(cin , address) ;
                cout << "Enter Phone Number: " ; cin >> phone_number ;
                cout << "Enter course name: " ; cin >> course ;

                student temp(roll_number , name , age , gender , address , phone_number , course) ;

            arr.push_back(temp) ;
        }

        int get_roll_number(){
            return roll_number;
        }

        string get_name(){
            return name;
        }

        int get_age(){
            return age;
        }

        string get_gender(){
            return gender;
        }

        string get_address(){
            return address;
        }

        string get_phone_number(){
            return phone_number;
        }

        string get_course(){
            return course;
        }
};

class academic_record{
    int total_marks , semester , roll_num ;
    float percentage ;
    string grade ;
    vector <string> subjects ;
    vector <int> marks ;
    
    public: 
        
        void add_std_record(){
            subjects.clear() ;
            marks.clear() ;
            int n ;
            cout << "Enter Roll Number: " ;
            cin >> roll_num ;
            cout << "Enter Semester: " ;
            cin >> semester ;
            cout << "Enter Number of Subjects: " ;
            cin >> n ;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for(int i = 0 ; i < n ; i++){
                string subject ;
                int mark ;

                cout << "Enter Subject Name: ";
                getline(cin , subject) ;
                cout << "Enter Marks: ";
                cin >> mark ;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                subjects.push_back(subject) ;
                marks.push_back(mark) ;
            }

            calculate_result() ;
        }

        void calculate_result(){
            total_marks = 0 ;

            for(int mark : marks){
                total_marks += mark ;
            }

            percentage = (float)total_marks / marks.size() ;

            if(percentage >= 95){
                grade = "A+" ;
            }else if(percentage >= 85 && percentage < 95){
                grade = "A" ;
            }else if(percentage >= 80 && percentage < 85){
                grade = "B+" ;
            }else if(percentage >= 70 && percentage < 80){
                grade = "B" ;
            }else{
                grade = "C" ;
            }
        }

        void display_record(){
            cout << "\n========== Displaying Academic Record ==========\n" ;

            cout << "Roll Number: " << roll_num << endl ;
            cout << "Semester: " << semester << endl ;

            cout << "\n------ Subject\t\tMarks ------\n" ;
            cout << "---------------------------------\n" ;
            for(int i = 0 ; i < subjects.size() ; i++){
                cout << "\t" << subjects[i] << "\t\t"
                    << marks[i] << endl ;
            }

            cout << "\n Total Marks: " << total_marks << endl ;
            cout << "Percentage: " << percentage << endl ;
            cout << "Grade: " << grade << endl ;

            cout << "=========================================\n" ;
        }

        int get_semester(){
            return semester;
        }

        int get_total_marks(){
            return total_marks;
        }

        float get_percentage(){
            return percentage;
        }

        string get_grade(){
            return grade;
        }

        vector<string> get_subjects(){
            return subjects;
        }

        vector<int> get_marks(){
            return marks;
        }
};  

class student_record{
    student personal; 
    academic_record academic ;

    public: 
        void add_record(){
            cout << "\n=========================================\n" ;
            cout << "         ENTER STUDENT DETAILS     \n" ;
            cout << "=========================================\n" ;

            personal.add_Student() ;

            cout << "\n=========================================\n" ;
            cout << "         ENTER ACADEMIC DETAILS   \n" ;
            cout << "=========================================\n" ;

            academic.add_std_record() ;

            save_record() ;
        }

        void save_record(){
            ofstream fout ;
            fout.open("student_record.txt" , ios::app) ;

            if(!fout){
                cout << "Error Not Opening File\n" ;
                return ;
            }

            fout << "=========================================\n";
            fout << "ROLL NUMBER: " << personal.get_roll_number() << "\n";
            fout << "NAME: " << personal.get_name() << "\n";
            fout << "AGE: " << personal.get_age() << "\n";
            fout << "GENDER: " << personal.get_gender() << "\n";
            fout << "ADDRESS: " << personal.get_address() << "\n";
            fout << "PHONE: " << personal.get_phone_number() << "\n";
            fout << "COURSE: " << personal.get_course() << "\n";

            fout << "\nACADEMIC RECORD\n";
            fout << "SEMESTER: " << academic.get_semester() << "\n";
            fout << "TOTAL MARKS: " << academic.get_total_marks() << "\n";
            fout << "PERCENTAGE: " << academic.get_percentage() << "\n";
            fout << "GRADE: " << academic.get_grade() << "\n";

            fout << "SUBJECTS AND MARKS:\n";

            for (int i = 0; i < academic.get_subjects().size(); i++){
                fout << academic.get_subjects()[i]
                    << " : "
                    << academic.get_marks()[i]
                    << "\n";
            }

            fout << "=========================================\n" ;

            fout.close();

            cout << "\n----- Student Record Saved Successfully -----\n";
        }

    
        void display_record(){
            ifstream fin;
            fin.open("student_record.txt");

            if(!fin){
                cout << "\n=========================================\n";
                cout << "       No Student Records Found\n";
                cout << "=========================================\n";
                return;
            }

            string line;
            bool found = false;

            cout << "\n=========================================\n";
            cout << "         ALL STUDENT RECORDS\n";
            cout << "=========================================\n";

            while(getline(fin, line)){

                if(line == "========================================="){
                    if(found){
                        cout << "=========================================\n";
                    }
                    continue;
                }

                if(line.find("ROLL NUMBER: ") == 0){

                    found = true;

                    cout << "\n";
                    cout << line << endl;

                    while(getline(fin, line)){

                        if(line == "========================================="){
                            break;
                        }

                        cout << line << endl;
                    }

                    cout << "=========================================\n";
                }
            }

            fin.close();

            if(!found){
                cout << "\nNo student records available.\n";
            }
        }

        void search_record(){
            int search_roll ;
            bool found = false ;

            cout << "\nEnter Roll Number to search: " ;
            cin >> search_roll ;

            ifstream fin ;
            fin.open("student_record.txt") ;

            string line ;
            if(!fin){
                cout << "====== Error in Opening File ======\n" ;
            }

            while(getline(fin , line)){
                if(line == "ROLL NUMBER: " + to_string(search_roll)){
                    found = true ;

                    cout << "-------- Student Found --------\n" ;

                    cout << line << endl ;

                    while(getline(fin, line)){

                        if(line == "=========================================")
                            break;

                        cout << line << endl;
                    }

                    cout << "=========================================\n" ;
                    break ;
                }
            }
            fin.close() ;

            if(!found){
                cout << "\n=========================================\n" ;
                cout << "------ Student Not Found ------\n" ;
                cout << "=========================================\n" ;
            }
        }
};

int main(){
    student_record record ;
    int choice ;

    do{
        cout << "\n========== Student Management System ==========\n" ;
        cout << "1. Add Student\n" ;
        cout << "2. Display Student\n" ;
        cout << "3. Search Student\n" ; 
        cout << "4. Exit\n" ;
        cout << "\nEnter Your Choice: " ; cin >> choice ;

        switch (choice){
            case 1:
               record.add_record() ;
            break;

            case 2:
               record.display_record() ;
            break ;

            case 3: 
               record.search_record() ;
            break ;

            case 4:
                cout << "\n------ Exiting The Programm ------\n" ;
            break ;

           default:
           cout << "Invalid Choice \n" ;
        }
    }while(choice != 4) ;
}