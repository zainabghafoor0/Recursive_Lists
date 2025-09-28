#include <iostream>
#include <string>
#include <limits> 
#include "reclists.hpp"
#include "solutions.hpp"

static void line() { std::cout << "----------------------------------------\n"; }
static void print_bool(bool b){ std::cout << (b ? "true" : "false") << "\n"; }

int main() {
    std::cout << "Recursive Lists – Manual Tester\n";
    std::cout << "Atoms: 1–8 letters. Lists like: (a (b) (c d))\n";
    line();

    while (true) {
        std::cout <<
          "Choose:\n"
          " 1) is_lat (list)\n"
          " 2) member (atom, list)\n"
          " 3) last (list)\n"
          " 4) list_pair (list, list)\n"
          " 5) firsts (list)\n"
          " 6) flat (list)\n"
          " 7) two_the_same (list, list)\n"
          " 8) equal (list, list)\n"
          " 9) total_reverse (list)\n"
          "10) shape (list)\n"
          "11) intersection (list, list)\n"
          "12) union (list, list)\n"
          "13) substitute (old_atom, new_atom, list)\n"
          "14) remove_all (list_of_atoms, atom)\n"
          "15) subset (list, list)\n"
          "16) permute (list_of_atoms)\n"
          " 0) quit\n> ";

        int op; if (!(std::cin >> op)) return 0;
        if (op == 0) return 0;

        // eat trailing newline so read_list() sees the next token cleanly
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (op == 1) { // is_lat
            std::cout << "Enter list:\n";
            list p = read_list();
            print_bool(is_lat(p));
        } else if (op == 2) { // member
            std::cout << "Enter atom (e.g., a):\n";
            list a = read_list(); // must be an atom
            std::cout << "Enter list:\n";
            list q = read_list();
            print_bool(member(a, q));
        } else if (op == 3) { // last
            std::cout << "Enter non-empty list:\n";
            list p = read_list();
            write_list(last(p)); std::cout << "\n";
        } else if (op == 4) { // list_pair
            std::cout << "Enter list p (atoms):\n";
            list p = read_list();
            std::cout << "Enter list q (atoms, same length):\n";
            list q = read_list();
            write_list(list_pair(p, q)); std::cout << "\n";
        } else if (op == 5) { // firsts
            std::cout << "Enter list of lists of atoms:\n";
            list p = read_list();
            write_list(firsts(p)); std::cout << "\n";
        } else if (op == 6) { // flat
            std::cout << "Enter list:\n";
            list p = read_list();
            write_list(flat(p)); std::cout << "\n";
        } else if (op == 7) { // two_the_same
            std::cout << "Enter list p:\n";
            list p = read_list();
            std::cout << "Enter list q:\n";
            list q = read_list();
            print_bool(two_the_same(p, q));
        } else if (op == 8) { // equal
            std::cout << "Enter list p:\n";
            list p = read_list();
            std::cout << "Enter list q:\n";
            list q = read_list();
            print_bool(equal(p, q));
        } else if (op == 9) { // total_reverse
            std::cout << "Enter list:\n";
            list p = read_list();
            write_list(total_reverse(p)); std::cout << "\n";
        } else if (op == 10) { // shape
            std::cout << "Enter list:\n";
            list p = read_list();
            write_list(shape(p)); std::cout << "\n";
        } else if (op == 11) { // intersection
            std::cout << "Enter set p (distinct atoms):\n";
            list p = read_list();
            std::cout << "Enter set q (distinct atoms):\n";
            list q = read_list();
            write_list(intersection(p, q)); std::cout << "\n";
        } else if (op == 12) { // union
            std::cout << "Enter set p (distinct atoms):\n";
            list p = read_list();
            std::cout << "Enter set q (distinct atoms):\n";
            list q = read_list();
            write_list(list_union(p, q)); std::cout << "\n";
        } else if (op == 13) { // substitute
            std::cout << "Enter old atom:\n";
            list old_a = read_list();
            std::cout << "Enter new atom:\n";
            list new_a = read_list();
            std::cout << "Enter list:\n";
            list p = read_list();
            write_list(substitute(old_a, new_a, p)); std::cout << "\n";
        } else if (op == 14) { // remove_all
            std::cout << "Enter list of atoms:\n";
            list p = read_list();
            std::cout << "Enter atom to remove:\n";
            list a = read_list();
            write_list(remove_all(p, a)); std::cout << "\n";
        } else if (op == 15) { // subset
            std::cout << "Enter list p:\n";
            list p = read_list();
            std::cout << "Enter list q:\n";
            list q = read_list();
            print_bool(subset(p, q));
        } else if (op == 16) { // permute
            std::cout << "Enter list of atoms (e.g., (a b c)):\n";
            list p = read_list();
            write_list(permute(p)); std::cout << "\n";
        } else {
            std::cout << "Unknown option.\n";
        }
        line();
    }
}
