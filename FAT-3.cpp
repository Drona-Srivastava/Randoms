#include <iostream>
#include <string>
#include <vector>

// Forward declaration of the TA class
template <typename Department>
class TA;

// Department-specific template specialization
struct Astrobiology {
    static std::string departmentName() { return "Astrobiology"; }
};

struct QuantumMechanics {
    static std::string departmentName() { return "Quantum Mechanics"; }
};

// TA class template
template <typename Department>
class TA {
private:
    std::string name;
    int id;
    std::string courseAssignment;
    std::string role;

public:
    TA(const std::string& name, int id, const std::string& courseAssignment, const std::string& role)
        : name(name), id(id), courseAssignment(courseAssignment), role(role) {}

    // Print TA details
    void printDetails() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Department: " << Department::departmentName() << std::endl;
        std::cout << "Course Assignment: " << courseAssignment << std::endl;
        std::cout << "Role: " << role << std::endl;
    }
};

// Function to print all TAs
template <typename Department>
void printAllTAs(const std::vector<TA<Department>>& tas) {
    std::cout << "All Teaching Assistants in the " << Department::departmentName() << " department:\n";
    for (const auto& ta : tas) {
        ta.printDetails();
        std::cout << std::endl;
    }
}

int main() {
    // Vector to store TAs
    std::vector<TA<Astrobiology>> astrobiologyTAs;
    std::vector<TA<QuantumMechanics>> quantumMechanicsTAs;

    // Menu loop
    while (true) {
        std::cout << "1. Add TA\n";
        std::cout << "2. View Astrobiology TAs\n";
        std::cout << "3. View Quantum Mechanics TAs\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, courseAssignment, role;
                int id;
                int departmentChoice;

                std::cout << "Enter TA name: ";
                std::cin >> name;
                std::cout << "Enter TA ID: ";
                std::cin >> id;
                std::cout << "Enter TA course assignment: ";
                std::cin >> courseAssignment;
                std::cout << "Enter TA role: ";
                std::cin >> role;
                std::cout << "Select Department (1 for Astrobiology, 2 for Quantum Mechanics): ";
                std::cin >> departmentChoice;

                if (departmentChoice == 1)
                    astrobiologyTAs.emplace_back(name, id, courseAssignment, role);
                else if (departmentChoice == 2)
                    quantumMechanicsTAs.emplace_back(name, id, courseAssignment, role);
                else
                    std::cout << "Invalid department choice.\n";
                break;
            }
            case 2:
                printAllTAs(astrobiologyTAs);
                break;
            case 3:
                printAllTAs(quantumMechanicsTAs);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
