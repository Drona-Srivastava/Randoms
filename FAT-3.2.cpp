#include <iostream>
#include <map>
#include <string>

template <typename T>
class TA {
public:
    TA(const std::string& name, const std::string& id, const std::string& course, const std::string& role)
        : name(name), id(id), course(course), role(role) {}

    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Course: " << course << "\n";
        std::cout << "Role: " << role << "\n";
        std::cout << "Department: Not specified\n";
    }

private:
    std::string name;
    std::string id;
    std::string course;
    std::string role;
};

template <>
class TA<astrobiology> {
public:
    TA(const std::string& name, const std::string& id, const std::string& course, const std::string& role, const std::string& department)
        : name(name), id(id), course(course), role(role), department(department) {}

    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Course: " << course << "\n";
        std::cout << "Role: " << role << "\n";
        std::cout << "Department: " << department << "\n";
    }

private:
    std::string name;
    std::string id;
    std::string course;
    std::string role;
    std::string department;
};

int main() {
    std::map<std::string, TA<void*> > tas;

    std::string id, name, course, role, department;

    while (true) {
        std::cout << "Enter 'add' to add a TA, 'list' to list all TAs, or 'quit' to quit: ";
        std::string command;
        std::cin >> command;

        if (command == "add") {
            std::cout << "Enter the TA's name, ID, course, role, and department (astrobiology only): ";
            std::cin >> name >> id >> course >> role >> department;

            if (department == "astrobiology") {
                tas[id] = TA<astrobiology>(name, id, course, role, department);
            } else {
                tas[id] = TA<void*>(name, id, course, role);
            }
        } else if (command == "list") {
            std::cout << "TA list:\n";
            for (const auto& ta : tas) {
                ta.second.display();
                std::cout << "\n";
            }
        } else if (command == "quit") {
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    return 0;
}