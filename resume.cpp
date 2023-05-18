#include <iostream>
#include <string>
#include <vector>

struct WorkExperience {
    std::string jobTitle;
    std::string company;
    std::string duration;
};

struct Education {
    std::string degree;
    std::string university;
    int year;
};

struct Resume {
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<WorkExperience> workExperience;
    std::vector<Education> education;
};

void createResume(Resume& resume) {
    std::cout << "Resume Builder" << std::endl;

    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, resume.name);

    std::cout << "Enter your email: ";
    std::cin >> resume.email;

    std::cout << "Enter your phone number: ";
    std::cin >> resume.phoneNumber;

    std::cout << std::endl;
    std::cout << "Enter work experience (press q to stop):" << std::endl;

    std::string jobTitle, company, duration;
    while (true) {
        std::cout << "Job Title: ";
        std::getline(std::cin >> std::ws, jobTitle);
        if (jobTitle == "q")
            break;

        std::cout << "Company: ";
        std::getline(std::cin >> std::ws, company);

        std::cout << "Duration: ";
        std::getline(std::cin >> std::ws, duration);

        WorkExperience workExp{jobTitle, company, duration};
        resume.workExperience.push_back(workExp);

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Enter education details (press q to stop):" << std::endl;

    std::string degree, university;
    int year;
    while (true) {
        std::cout << "Degree: ";
        std::getline(std::cin >> std::ws, degree);
        if (degree == "q")
            break;

        std::cout << "University: ";
        std::getline(std::cin >> std::ws, university);

        std::cout << "Year: ";
        std::cin >> year;

        Education edu{degree, university, year};
        resume.education.push_back(edu);

        std::cout << std::endl;
    }
}

void displayResume(const Resume& resume) {
    std::cout << "Resume:" << std::endl;
    std::cout << "Name: " << resume.name << std::endl;
    std::cout << "Email: " << resume.email << std::endl;
    std::cout << "Phone Number: " << resume.phoneNumber << std::endl;

    std::cout << std::endl;
    std::cout << "Work Experience:" << std::endl;
    for (const auto& workExp : resume.workExperience) {
        std::cout << "Job Title: " << workExp.jobTitle << std::endl;
        std::cout << "Company: " << workExp.company << std::endl;
        std::cout << "Duration: " << workExp.duration << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Education:" << std::endl;
    for (const auto& edu : resume.education) {
        std::cout << "Degree: " << edu.degree << std::endl;
        std::cout << "University: " << edu.university << std::endl;
        std::cout << "Year: " << edu.year << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    Resume resume;

    createResume(resume);

    std::cout << std::endl;
    std::cout << "Resume created successfully!" << std::endl;
    std::cout << std::endl;

    displayResume(resume);

    return 0;
}
