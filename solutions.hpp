#ifndef SOLUTIONS_HPP
#define SOLUTIONS_HPP

#include "reclists.hpp"

// Already provided in your starter, but keep it here if you use it in grading.
int numNodesAtTheTopLevel(list p);

// Helpers you may call from other solutions
list append(list p, list q);            // join two (possibly nested) lists
bool member(list a, list q);            // true if atom a appears anywhere in q

// Required functions
bool is_lat(list p);                    // list of atoms (top-level)
list last(list p);                      // last element of a non-empty list
list list_pair(list p, list q);         // zip to pairs ((p1 q1) (p2 q2) ...)
list firsts(list p);                    // take car of each sublist
list flat(list p);                      // flatten nested lists to a single level
bool two_the_same(list p, list q);      // share at least one atom anywhere
bool equal(list p, list q);             // deep structural equality
list total_reverse(list p);             // reverse at all levels
list shape(list p);                     // parentheses-only shape
list intersection(list p, list q);      // set intersection (atoms, distinct)
list list_union(list p, list q);        // set union (atoms, distinct)

// Deep substitute: replace every occurrence of atom `old_a` with atom `new_a`
list substitute(list old_a, list new_a, list p);

// Remove all occurrences of atom `a` from a (flat) list of atoms
list remove_all(list p, list a);

// Subset using structural element membership (atoms or sublists)
bool subset(list p, list q);

// Extra credit
list permute(list p);

// Internal helpers (ok to expose in header or move to an anonymous namespace)
bool member_deep(list x, list q);       // membership by structural equality
list pairs_cons(list a, list b);        // ((a b))
list insert_at_all_positions(list x, list one_perm); // helper for permute
list map_insert_all(list x, list perms);             // helper for permute

#endif
