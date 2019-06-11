#include <iostream>

#include "Variable.h"
#include "Negation.h"
#include "Conjunction.h"
#include "Disjunction.h"
#include "Implication.h"
#include "BiImplication.h"
#include "ExclusiveOr.h"

int main()
{
	BooleanExpression* p = new Variable('p');
	BooleanExpression* q = new Variable('q');

	BooleanExpression* tauthology    = new Variable('T');
	BooleanExpression* contradiction = new Variable('F');

	BooleanExpression* negation_of_tauthology    = new Negation(tauthology);
	BooleanExpression* negation_of_contradiction = new Negation(contradiction);

	BooleanExpression* negation_of_p = new Negation(p);
	BooleanExpression* neg_neg_of_p  = new Negation(negation_of_p);

	BooleanExpression* conjunction_p_p = new Conjunction(p, p);
	BooleanExpression* conjunction_p_q = new Conjunction(p, q);
	BooleanExpression* conjunction_T_F = new Conjunction(tauthology, contradiction);
	BooleanExpression* conjunction_T_T = new Conjunction(tauthology, tauthology);
	BooleanExpression* conjunction_F_F = new Conjunction(contradiction, contradiction);

	BooleanExpression* disjunction_p_p = new Disjunction(p, p);
	BooleanExpression* disjunction_T_F = new Disjunction(tauthology, contradiction);
	BooleanExpression* disjunction_T_T = new Disjunction(tauthology, tauthology);
	BooleanExpression* disjunction_F_F = new Disjunction(contradiction, contradiction);

	BooleanExpression* implication_p_p = new Implication(p, p);
	BooleanExpression* implication_T_F = new Implication(tauthology, contradiction);
	BooleanExpression* implication_F_T = new Implication(contradiction, tauthology);
	BooleanExpression* implication_T_T = new Implication(tauthology, tauthology);
	BooleanExpression* implication_F_F = new Implication(contradiction, contradiction);

	BooleanExpression* bi_implication_p_p = new BiImplication(p, p);
	BooleanExpression* bi_implication_T_F = new BiImplication(tauthology, contradiction);
	BooleanExpression* bi_implication_F_T = new BiImplication(contradiction, tauthology);
	BooleanExpression* bi_implication_T_T = new BiImplication(tauthology, tauthology);
	BooleanExpression* bi_implication_F_F = new BiImplication(contradiction, contradiction);

	BooleanExpression* xor_p_p = new ExclusiveOr(p, p);
	BooleanExpression* xor_T_F = new ExclusiveOr(tauthology, contradiction);
	BooleanExpression* xor_F_T = new ExclusiveOr(contradiction, tauthology);
	BooleanExpression* xor_T_T = new ExclusiveOr(tauthology, tauthology);
	BooleanExpression* xor_F_F = new ExclusiveOr(contradiction, contradiction);

	BooleanExpression* a = new Variable('a');
	BooleanExpression* b = new Variable('b');
	BooleanExpression* c = new Variable('c');
	BooleanExpression* d = new Variable('d');
	BooleanExpression* e = new Variable('e');
	
	
	BooleanExpression* a_and_b = new Conjunction(a, b);
	BooleanExpression* c_or_d = new Disjunction(c, d);
	BooleanExpression* T_implies_e = new Implication(tauthology, e);
	BooleanExpression* e_implies_T = new Implication(e, tauthology);
	BooleanExpression* tauth_implication = new Implication(contradiction, new ExclusiveOr(T_implies_e, e_implies_T));
	

	/* Basic tauthology and contradiction properties checking. */

	tauthology->print_all();
	contradiction->print_all();
	negation_of_tauthology->print_all();
	negation_of_contradiction->print_all();

	/* Checking the properties of a regular variable. */

	p->print_all();

	/* Checking the negation of a regular variable. */

	negation_of_p->print_all();

	/* Double negation on a single variable. */

	neg_neg_of_p->print_all();

	/* Simple conjunction tests. */

	conjunction_p_p->print_all();
	conjunction_T_T->print_all();
	conjunction_T_F->print_all();
	conjunction_F_F->print_all();

	/* Simple disjunction tests. */

	disjunction_p_p->print_all();
	disjunction_T_T->print_all();
	disjunction_T_F->print_all();
	disjunction_F_F->print_all();

	/* Simple implication tests. */

	implication_p_p->print_all();
	implication_T_T->print_all();
	implication_F_T->print_all();
	implication_T_F->print_all();
	implication_F_F->print_all();

	/* Simple bi-implication tests. */

	bi_implication_p_p->print_all();
	bi_implication_T_T->print_all();
	bi_implication_F_T->print_all();
	bi_implication_T_F->print_all();
	bi_implication_F_F->print_all();

	/* Simple exclusive or tests. */

	xor_p_p->print_all();
	xor_T_T->print_all();
	xor_F_T->print_all();
	xor_T_F->print_all();
	xor_F_F->print_all();

	/* Tauthology long logical proposition. */

	tauth_implication->print_all();
	std::cout << "Number of args for "; tauth_implication->print(); 
	std::cout << ": " << tauth_implication->get_number_of_vars() << std::endl;

	return 0;
}