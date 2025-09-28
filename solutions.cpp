#include "reclists.hpp"
#include "solutions.hpp"

// ===== Provided example in your starter =====
int numNodesAtTheTopLevel(list p) {
    if (is_null(p)) return 0;
    if (is_atom(p)) return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}

// ===== Helpers you may use anywhere =====

list append(list p, list q) {
    if (is_null(p)) return q;
    return cons(car(p), append(cdr(p), q));
}

bool member(list a, list q) {
    // a must be an atom; returns true if a appears ANYWHERE in q (deep)
    if (is_null(q)) return false;
    list h = car(q);
    if (is_atom(h)) {
        if (eq(a, h)) return true;
        return member(a, cdr(q));
    } else {
        return member(a, h) || member(a, cdr(q));
    }
}

// Structural (deep) membership: does x appear as an element of q (by equal)?
bool member_deep(list x, list q) {
    if (is_null(q)) return false;
    if (equal(x, car(q))) return true;
    return member_deep(x, cdr(q));
}

// Small helper to build ((a b))
list pairs_cons(list a, list b) {
    return cons(cons(a, cons(b, null())), null());
}

// ===== Required functions =====

bool is_lat(list p) {
    // true iff p is (possibly empty) list whose TOP-LEVEL elements are all atoms
    if (is_null(p)) return true;
    return is_atom(car(p)) && is_lat(cdr(p));
}

list last(list p) {
    // p is non-empty list (not an atom)
    if (is_null(cdr(p))) return car(p);
    return last(cdr(p));
}

list list_pair(list p, list q) {
    // p and q are lists of atoms with the same length
    if (is_null(p)) return null();
    // build ( (car(p) car(q)) :: rest )
    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
}

list firsts(list p) {
    // p is a list whose elements are lists of atoms
    if (is_null(p)) return null();
    return cons(car(car(p)), firsts(cdr(p)));
}

list flat(list p) {
    // flatten nested lists into a single top-level list of atoms
    if (is_null(p)) return null();
    list h = car(p);
    if (is_atom(h))
        return cons(h, flat(cdr(p)));
    return append(flat(h), flat(cdr(p)));
}

bool two_the_same(list p, list q) {
    // true iff p and q share at least one atom anywhere (deep)
    if (is_null(p)) return false;
    list h = car(p);
    if (is_atom(h)) {
        if (member(h, q)) return true;
        return two_the_same(cdr(p), q);
    }
    return two_the_same(h, q) || two_the_same(cdr(p), q);
}

bool equal(list p, list q) {
    if (is_null(p) && is_null(q)) return true;
    if (is_null(p) || is_null(q)) return false;

    bool pa = is_atom(p), qa = is_atom(q);
    if (pa && qa) return eq(p, q);
    if (pa != qa) return false;

    // both are (lists)
    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}

list total_reverse(list p) {
    if (is_null(p) || is_atom(p)) return p;
    // reverse at all levels: reverse tail, then cons reversed head
    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

list shape(list p) {
    // parentheses-only shape: replace every atom with ()
    if (is_null(p)) return null();
    if (is_atom(p)) return null();            // atom -> ()
    return cons(shape(car(p)), shape(cdr(p))); // list -> (shape(head) . shape(tail))
}

list intersection(list p, list q) {
    // p and q are sets (lists) of distinct atoms (top-level)
    if (is_null(p)) return null();
    if (member(car(p), q))
        return cons(car(p), intersection(cdr(p), q));
    return intersection(cdr(p), q);
}

list list_union(list p, list q) {
    // union of two distinct-atom sets (no repetition in result)
    if (is_null(q)) return p;
    if (member(car(q), p))
        return list_union(p, cdr(q));
    return list_union(cons(car(q), p), cdr(q));
}

list substitute(list old_a, list new_a, list p) {
    // deep replace: every atom equal to old_a becomes new_a
    if (is_null(p)) return null();
    if (is_atom(p)) {
        return eq(p, old_a) ? new_a : p;
    }
    return cons(substitute(old_a, new_a, car(p)),
                substitute(old_a, new_a, cdr(p)));
}

list remove_all(list p, list a) {
    // remove all occurrences of atom a from a FLAT list of atoms
    if (is_null(p)) return null();
    if (eq(car(p), a))
        return remove_all(cdr(p), a);
    return cons(car(p), remove_all(cdr(p), a));
}

bool subset(list p, list q) {
    // true iff every element of p (atom or sublist) is present in q by structural equality
    if (is_null(p)) return true;
    return member_deep(car(p), q) && subset(cdr(p), q);
}

// ===== Extra credit: permutations of a flat list of atoms =====

list insert_at_all_positions(list x, list one_perm) {
    // Insert atom x into every position of one_perm, returning a list of lists
    // Base: insert into empty list -> ((x))
    if (is_null(one_perm))
        return pairs_cons(x, null()); // ((x))

    // For one_perm = (h ...t)
    // First position: (x h ...t)
    list first_pos = cons(x, one_perm);

    // For later positions: prepend h to each insertion of x into t
    list rest_insertions = insert_at_all_positions(x, cdr(one_perm));
    // Map: cons(h, each_list) over rest_insertions
    // Do this recursively:
    // rest_insertions is a list of lists: ((...t1) (...t2) ...)
    // We need ((h ...t1) (h ...t2) ...)
    // Define a small mapper inline:

    // mapper
    if (is_null(rest_insertions))
        return cons(first_pos, null());

    // take head of rest_insertions, push h in front, and recurse
    list mapped_head = cons(car(one_perm), car(rest_insertions));
    list mapped_tail_container = null();
    // We can’t build with variables/loops; do it by recursion:
    // Build a helper to push h in front of each list in rest_insertions
    // (to keep it loop-free, we inline a mini recursive builder)

    // push_h: returns a list where each element = cons(h, element_of(L))
    // Implemented here anonymously via recursion:
    // push_h(rest_insertions)
    //   = null                if rest_insertions == ()
    //   = cons( cons(h, car(rest_insertions)),
    //           push_h( cdr(rest_insertions) ) )

    // Define push_h:
    struct Local {
        static list push_h(list h, list L) {
            if (is_null(L)) return null();
            return cons(cons(h, car(L)), push_h(h, cdr(L)));
        }
    };

    list pushed_tail = Local::push_h(car(one_perm), rest_insertions);
    // prepend first_pos to pushed_tail
    return cons(first_pos, pushed_tail);
}

list map_insert_all(list x, list perms) {
    // perms is a list of permutations (each a list)
    // Return concatenation over insert_at_all_positions(x, each_perm)
    if (is_null(perms)) return null();
    return append(
        insert_at_all_positions(x, car(perms)),
        map_insert_all(x, cdr(perms))
    );
}

list permute(list p) {
    // permutations of a flat list of atoms
    if (is_null(p)) {
        // one permutation: the empty list
        return cons(null(), null()); // (())
    }
    list x = car(p);
    list perms_tail = permute(cdr(p));
    return map_insert_all(x, perms_tail);
}
