#include <iostream>

#include "Variable.h"
#include "Negation.h"
#include "Conjunction.h"
#include "Disjunction.h"
#include "Implication.h"

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
	BooleanExpression* implication_p_q = new Implication(p, q);
	BooleanExpression* implication_T_F = new Implication(tauthology, contradiction);
	BooleanExpression* implication_F_T = new Implication(contradiction, tauthology);
	BooleanExpression* implication_T_T = new Implication(tauthology, tauthology);
	BooleanExpression* implication_F_F = new Implication(contradiction, contradiction);

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

	return 0;
}