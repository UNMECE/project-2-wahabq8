#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string first_name;
    string last_name;
    double gpa;
    int grad_year;
    string grad_semester;
    int enroll_year;
    string enroll_semester;
    string undergrad_or_grad;

public:

    Student() : first_name("N/A"), last_name("N/A"), gpa(0), grad_year(00), grad_semester("N/A"),
                enroll_year(0), enroll_semester("N/A"), undergrad_or_grad("N/A") {}

    
    virtual ~Student() {}

   
    void setName(const string& first, const string& last) {
        first_name = first;
        last_name = last;
    }
    
    string getName() const {
        return first_name + "  " + last_name;
    }

    void setGPA(double new_gpa) {
        gpa = new_gpa;
    }

    double getGPA() const {
        return gpa;
    }

    void setGradYear(int year) {
        grad_year = year;
    }

    int getGradYear() const {
        return grad_year;
    }

    void setGradSemester(const string& semester) {
        grad_semester = semester;
    }

    string getGradSemester() const {
        return grad_semester;
    }

    void setEnrollYear(int year) {
        enroll_year = year;
    }

    int getEnrollYear() const {
        return enroll_year;
    }

    void setEnrollSemester(const string& semester) {
        enroll_semester = semester;
    }

    string getEnrollSemester() const {
        return enroll_semester;
    }

    void setUndergradOrGrad(const string& status) {
        undergrad_or_grad = status;
    }

    string getUndergradOrGrad() const {
        return undergrad_or_grad;
    }

    
   
    virtual void writeToFile(ofstream &outfile) const {
        outfile << "Name: " << getName() << ", " << "Gpa: "<< gpa << ", " << "Graduation year: " << grad_year << ", " << "Graduation semester: " << grad_semester << ", "
                << "Enrollment year: " << enroll_year << ", " << "Enrollment semester: "<< enroll_semester << ", " << "Grad/undergrad: " << undergrad_or_grad << endl;
    }
};

class Art_Student : public Student {
private:
    string art_emphasis;

public:

    Art_Student() : art_emphasis("Art History") {}

    void setArtEmphasis(const string& emphasis) {
        art_emphasis = emphasis;
    }

    string getArtEmphasis() const {
        return art_emphasis;
    }

    void writeToFile(ofstream &outfile) const override {
        Student::writeToFile(outfile);
        outfile << art_emphasis << endl;
    }
};

class Physics_Student : public Student {
private:
    string concentration;

public:
    Physics_Student() : concentration("Biophysics") {}

  
    void setConcentration(const string& new_concentration) {
        concentration = new_concentration;
    }

    string getConcentration() const {
        return concentration;
    }

 
  
    void writeToFile(ofstream &outfile) const override {
        Student::writeToFile(outfile); 
        outfile << concentration << endl;
    }
};

int main() {
  
    vector<Art_Student *> art_students;
    vector<Physics_Student *> physics_students;

    
    art_students.push_back(new Art_Student);
    art_students[0]->setName("abdel", "wahab");
    art_students[0]->setGPA(3.7);
    art_students[0]->setGradYear(2025);
    art_students[0]->setGradSemester("Fall");
    art_students[0]->setEnrollYear(2021);
    art_students[0]->setEnrollSemester("Fall");
    art_students[0]->setUndergradOrGrad("Undergrad");
    art_students[0]->setArtEmphasis("Art Studio");

 
    physics_students.push_back(new Physics_Student);
    
    physics_students[0]->setName("Muhammad", "Abdullah");
    physics_students[0]->setGPA(2.9);
    physics_students[0]->setEnrollYear(2019);
    physics_students[0]->setEnrollSemester("Fall");
    physics_students[0]->setUndergradOrGrad("Undergrad");
    physics_students[0]->setConcentration("Earth and Planetary Sciences");
    physics_students[0]->setGradYear(2027);
    physics_students[0]->setGradSemester("Spring");
    
    art_students.push_back(new Art_Student);
    art_students[1]->setName("John", "Doe");
    art_students[1]->setGPA(3.8);
    art_students[1]->setGradYear(2023);
    art_students[1]->setGradSemester("Spring");
    art_students[1]->setEnrollYear(2019);
    art_students[1]->setEnrollSemester("Fall");
    art_students[1]->setUndergradOrGrad("Undergrad");
    art_students[1]->setArtEmphasis("Art Studio");

    
    physics_students.push_back(new Physics_Student);
    physics_students[1]->setName("Alice", "Smith");
    physics_students[1]->setGPA(3.9);
    physics_students[1]->setGradYear(2024);
    physics_students[1]->setGradSemester("Fall");
    physics_students[1]->setEnrollYear(2020);
    physics_students[1]->setEnrollSemester("Spring");
    physics_students[1]->setUndergradOrGrad("Undergrad");
    physics_students[1]->setConcentration("Biophysics");
   


    ofstream outfile("student_info.dat");
    if (outfile.is_open()) {
    
        for (int i = 0; i < art_students.size(); i++) {
            art_students[i]->writeToFile(outfile);
        }
        
        
        for (int i = 0; i < physics_students.size(); i++) {
            physics_students[i]->writeToFile(outfile);
        }
        outfile.close();
    }

    
    for (int i = 0; i < art_students.size(); i++) {
        delete art_students[i];
    }

    for (int i = 0; i < physics_students.size(); i++) {
        delete physics_students[i];
    }

    return 0;
}
