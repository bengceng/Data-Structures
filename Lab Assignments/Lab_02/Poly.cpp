#include <stdio.h>
#include "Poly.h"
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include <cctype>
#include <stdio.h>
//Bengisu Þahin || 152120191064 || DS Lab HW2
using namespace std;

//-------------------------------------------------//
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5

PolyNode *CreatePoly(char *expr){
	
	int i = 0, j = 0, termNum = 0;
	char arr[100];
	while (*(expr + i) != '\0')
	{
		arr[i] = *(expr + i);
		i++;
	}
	arr[i] = '\0';
	string new_expr(arr);

	/*while (arr[i] != '\0')
	{
		new_expr[i] = arr[i];
		i++;
	}
	new_expr[i] = '\0';*/
	i = 0; int xNum = 0;
	new_expr.erase(std::remove_if(new_expr.begin(), new_expr.end(), ::isspace), new_expr.end());
	while (new_expr[j] != '\0')
	{
		if ((new_expr[j] == '+' || new_expr[j] == '-') && j != 0 && new_expr[j] != 'x') {
			termNum++;
		}
		
		if (new_expr[j] == 'x') // fibd 33 or -33
			xNum++;
		j++;

	}
	if (new_expr[0] == '-' || new_expr[0] == '+')
	{
		termNum++;
	}
	else {
		termNum++;
	}
	
	if (xNum == 0)
		termNum = 1;
	

	int *exp = new int[termNum + 1];
	double *coef = new double[termNum + 1];

	j = 0;
	int m = 0, k = 0, l = 0, n = 0, y = 0, len, term = 1, Xnum = 0;
	string temp, tempExp, tempCoef;
	len = new_expr.length();
	double c;
	for (i = 1; i <= termNum; i++) {
		if (new_expr[j] == '-' && j == 0) {
			temp += new_expr[0];
			j++;
		}
		while (new_expr[j] != '+' && new_expr[j] != '-'  && new_expr[j] != '\0')//term i ayýr
		{
			temp += new_expr[j];
			j++;
		}
		//temp[j] = '\0';
		int tmpL= temp.length();
		for (m = 0; m < tmpL; m++)
		{
			if (temp[m] == '^') {//üssü oku  //x sizlerin üssüne karar ver x^1 olanlara karar ver
				m++; Xnum++;
				while (temp[m] != '\0') {
					tempExp += temp[m];
					m++;
				}
				exp[n] = stoi(tempExp); n++;
			}
			if (temp[m] == 'x' && temp[m + 1] != '^') {
				exp[n] = 1; n++; Xnum++;
			}
			/*if (temp[m] != 'x') {
				while (temp[m] != '\0') {

				}
			}*/
			if (temp[m] == 'x') {
				if (m == 0)
				{
					tempCoef = "x";
				}
				for (; l < m; l++) {
					if (temp[m] == '-' &&temp[m + 1] == 'x') {
						coef[k] = -1; k++;
					}
					/*else if (m =0) {
						coef[k] = 1; k++;
					}*/
					else {
						//if(temp[l]=)   //stod sorunlu ve stod nereye kkonulacak
						tempCoef += temp[l];

					}

				}


				if (tempCoef == "-")
				{
					coef[k] = -1; k++;
				}
				else if (tempCoef == "+") {
					coef[k] = 1; k++;
				}
				else if (tempCoef == "x") {
					coef[k] = 1; k++;
				}
				else
				{
					coef[k] = stod(tempCoef);
					k++;
				}
				l = 0;
			}
		}
		y = 0;
		if (Xnum == 0) {
			while (temp[y] != '\0') {
				tempCoef += temp[y];
				y++;
			}
			exp[n] = 0; n++;
			c = stod(tempCoef);
			coef[k] = c;
			k++;
		}
		Xnum = 0;
		temp.clear();
		tempCoef.clear();
		tempExp.clear();
		temp += new_expr[j];
		j++;

	}
	class PolyLinkedList
	{
	private:
		PolyNode *head;
	public:
		PolyLinkedList() { head = NULL; }//Constructor

		void add(double coef_, int exp_)
		{
			PolyNode *node = new PolyNode();
			node->coef = coef_;
			node->exp = exp_;
			node->next = NULL;

			PolyNode *p = head;
			PolyNode *q = NULL;

			while (p != NULL && exp_ < p->exp)
			{
				q = p;
				p = p->next;
			}
			if (q == NULL) {
				node->exp = exp_;
				node->coef = coef_;
				head = node;
			}
			else {
				node->next = q->next;
				q->next = node;

			}



		}
		PolyNode *getHead() const {
			return head;
		}
	};
	PolyLinkedList Poly;
	for (i = 0; i < termNum; i++)
	{
		Poly.add(coef[i], exp[i]);
	}
	return Poly.getHead();
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {
	PolyNode *current=poly,*tmp;
	tmp = current;
	while (tmp != NULL && current!=NULL)
	{
		tmp = current;
		current = current->next;
		delete tmp;
		
	}
} // end-DeletePoly

//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode *AddNode(PolyNode *head, double coef, int exp) {
	double coef_ = coef;
	int exp_=exp;
	
	PolyNode *p = new PolyNode(), *newNode = new PolyNode(),*tmp, *q = new PolyNode(),*tmp2 = new PolyNode(),*tmp3 = new PolyNode(), *same = new PolyNode();
	p = head; newNode = NULL; tmp = p; same = NULL; tmp3 = same;
	q->coef = coef_;
	q->exp = exp_;

	class addNode {
	private:
		PolyNode *head;
	public:
		//addNode() { head = tail = NULL; }
		addNode(PolyNode *head_) {
			head = head_;
		}
		void add(double c, int e) {
			double Coef = c; int Exp = e;
			//Allocate new node
			PolyNode *node = new PolyNode();
			node->coef = Coef;
			node->exp = Exp;
			node->next = NULL;
			//For Traverse
			PolyNode *p = head;
			PolyNode *q = NULL;
			//  make a decision for  which place should node is suitable
			PolyNode *tmp = new PolyNode();
			while (p != NULL && Exp != p->exp) {
				q = p;
				p = p->next;
			}

			if (q == NULL && head == NULL) //poly is empty
			{
				node->next = head;
				head = node;
			}
			else if (p != NULL && p->exp != NULL) //not empty || trying to add terms || same exp
			{
				if (node->exp == p->exp) {
					p->coef = p->coef + node->coef;
				}

			}
			else //different exp || adding a new term
			{
				p = head; q = NULL;

				while ( p != NULL && node->exp < p->exp )
				{

					q = p;
					p = p->next;
				}
				if (q == NULL) {
					node->next = head;
					head = node;
				}
				else {
					node->next = q->next;
					q->next = node;
				}


					/*if (q == head && q->exp > node->exp) //head den sonraya ekle
					{
						node->next = q->next;
						q->next = node;

					}
					else if (q == head && q->exp < node->exp) // listenin baþýna eklenecek
					{
						node = head;
						node->next = q;
					}
					else
					{
						if (node->next != NULL) {
							node->next = q->next;
							q->next = node;
						}
					}*/

				
			}
		}
		PolyNode *getHead() const {
			return head;
		}
		void remove(PolyNode *h) {
			PolyNode *p = h;
			PolyNode *q = NULL;
			while (p != NULL && p->coef != 0)
			{
				q = p; 
				p = p->next;

			}
			if (p == NULL) return;
			if (q == NULL) {
				head = p->next;
			}
			else
			{
				q->next = p->next;
			}
			delete p;
		}
	};
	addNode newPoly(p);
	newPoly.add(coef_, exp_);
	newPoly.remove(p);
	return newPoly.getHead();



	/*if (p == NULL)
	{
		newNode=q;
		
		p = newNode;
		return newNode;
	}
	else
	{
		while (p->next!=NULL || p->exp == q->exp) {
			
			if (p->exp == q->exp) {
				p->coef = p->coef + q->coef;
				break;
			}
			if (p->next == NULL)
				break;
			else
				p = p->next;
		}
		if (p->next == NULL && p->exp != q->exp && p->coef != 0) {
			newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
			newNode->coef = q->coef;
			newNode->exp = q->exp;
			newNode->next = NULL;
			p->next = newNode;
		}
	}*/
	/*int flag = 0;
	
	while (tmp != NULL)
	{
			 if(tmp->coef != 0 )
		{
			tmp2 = (struct PolyNode*)malloc(sizeof(struct PolyNode));
			tmp2->coef = tmp->coef;
			tmp2->exp = tmp->exp;
			tmp2->next = NULL;
			//tmp2 = tmp2->next;
			
			//same->next = tmp2;
		}
		 if (tmp->coef!=0 ) {
			 tmp2 = (struct PolyNode*)malloc(sizeof(struct PolyNode));
			 tmp2->coef = tmp->coef;
			 tmp2->exp = tmp->exp;
			 tmp2 = tmp2->next;
			 tmp2->next = NULL;
			 //same = tmp2;
			 flag = 1;
		}
	
		tmp = tmp->next;
	}*/

	/*while (tmp != NULL && tmp->coef != 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL) return tmp3;
	if (tmp2->coef= 0) tmp3 = tmp->next;*/
	
	
} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode *Add(PolyNode *poly1, PolyNode *poly2) {
	// Fill this in
	
	PolyNode *p1 = poly1, *p2 = poly2,*newNode=NULL,*tmp; 
	  newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	  tmp = newNode;
			//PolyNode *newNode=new PolyNode(); 
	  double coef;
			while (p1 && p2) {
				if (p1->exp > p2->exp )
				{
					newNode->coef = p1->coef;
					newNode->exp = p1->exp;
					p1 = p1->next;
				}
				else if (p2->exp > p1->exp)
				{
					newNode->coef = p2->coef;
					newNode->exp = p2->exp;
					p2 = p2->next;
				}
				else 
				{
					coef = p1->coef + p2->coef;
					newNode->coef = coef;
					newNode->exp = p1->exp;
					p1 = p1->next;
					p2 = p2->next;
				}
				// Dynamically create new node
				if (p1 && p2) {
					newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
					newNode = newNode->next;
					newNode->next = NULL;
				}
			}
			while (p1 || p2) {
				newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
				newNode = newNode->next;
				newNode->next = NULL;
				if (p1->next) {
					newNode->exp = p1->exp;
					newNode->coef = p1->coef;
					p1 = p1->next;
				}
				if (p2->next) {
					newNode->exp = p2->exp;
					newNode->coef = p2->coef;
					p2 = p2->next;
				}
				
			}
			return tmp;
}//end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode *Subtract(PolyNode *poly1, PolyNode *poly2){
	// Fill this in
	PolyNode *p1 = poly1, *p2 = poly2, *newNode = NULL, *tmp;
	newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	tmp = newNode; 
	double coef;

	while (p1 && p2) {
		if (p1->exp > p2->exp) //x^7....  || x^5
		{
			newNode->coef = p1->coef;
			newNode->exp = p1->exp;
			p1 = p1->next;
		}
		else if (p2->exp > p1->exp)
		{
			newNode->coef = p2->coef*(-1);
			newNode->exp = p2->exp;
			p2 = p2->next;
		}
		else
		{
			coef = p1->coef - p2->coef;
			newNode->coef = coef;
			newNode->exp = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		// Dynamically create new node
		if (p1 && p2) {
			newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
			newNode = newNode->next;
			newNode->next = NULL;
		}
	}
	while (p1 || p2) {
		newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
		newNode = newNode->next;
		newNode->next = NULL;
		if (p1->next) {
			newNode->exp = p1->exp;
			newNode->coef = p1->coef;
			p1 = p1->next;
		}
		if (p2->next) {
			newNode->exp = p2->exp;
			newNode->coef = p2->coef;
			p2 = p2->next;
		}

	}
	return tmp;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode *Multiply(PolyNode *poly1, PolyNode *poly2){
	// Fill this in
	PolyNode *p1 = poly1, *p2 = poly2;
	PolyNode *newNode = new PolyNode();
	PolyNode *tmp=newNode;
	int exp; double coef;
	while (p1 != NULL)
	{
		while (p2 != NULL)
		{
			exp = p1->exp + p2->exp;
			coef = p1->coef * p2->coef;
			
			newNode->coef = coef;
			newNode->exp = exp;
			if (p1->next == NULL && p2->next == NULL)
			{
				newNode->next = NULL;
			}
			else {
				newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
				newNode = newNode->next;
				newNode->next = NULL;
			}

			p2 = p2->next;
		}
		p2 = poly2;
		p1 = p1->next;
	}
	//PolyNode *newPolly = new PolyNode();
	PolyNode *ptr1 = new PolyNode(), *ptr2 = new PolyNode(),*same = new PolyNode();
	ptr1 = tmp;
	while (ptr1!=NULL && ptr1->next!=NULL) 
	{
		ptr2 = ptr1;
		while (ptr2->next != NULL)
		{
			if (ptr1->exp == ptr2->next->exp)
			{
				ptr1->coef = ptr1->coef + ptr2->next->coef;
				same = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(same);
			}
			else
			{
				ptr2 = ptr2->next;
			}
			
		}
		ptr1 = ptr1->next;
	}
	return tmp;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode *poly, double x){
	// Fill this in
	double result = 0;
	double xx = x;
	PolyNode *p = poly;
	while (p != NULL)
	{
		if (p->exp != 0)
		{

			result += p->coef*pow(xx, p->exp);
		}
		else
		{
			result += p->coef;
		}
		p = p->next;
	}
	return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode *Derivative(PolyNode *poly){
	// Fill this in
	PolyNode *p = poly,*newPoly;
	PolyNode *newNode = new PolyNode();
	newPoly = newNode;
	while (p!=NULL )
	{
		if (p->exp == 0 && newNode == p)
		{
			newNode->coef = 0; 
			newNode->exp = NULL;
		}
		else if (p->exp == 0 ) {
			newNode->coef = NULL;
			newNode->exp = NULL;		
			break;
		}
		else 
		{
			newNode->coef = p->coef*(p->exp);
			newNode->exp = (p->exp - 1);

		
		}
		newNode->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
		newNode = newNode->next;
		newNode->next = NULL;
		p = p->next;
	}
	return newPoly;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode *poly, int x1, int x2) {
	// Fill this in	
	struct y_result {
		int y; int x;
		struct y_result *next;
	};
	PolyNode *p = poly,*tmp = new  PolyNode();
	int xx1 = x1; int xx2 = x2; struct y_result *head = new  y_result(), *q = new  y_result(),*a = new  y_result(); double result=0;
	q = head; int x, y, yy; 
	
	while (p != NULL && xx1 <= xx2)
	{
		tmp = p;
		while (p != NULL)
		{
			
			if (p->exp != 0)
			{

			result += p->coef*pow(xx1, p->exp);
			}
			else
			{
			result+= p->coef;
			}
			p = p->next;
		}
		head->y = result;
		head->x = xx1;
		head->next = (struct y_result*)malloc(sizeof(struct  y_result));
		head = head->next;
		head->next = NULL;
		p = tmp;
		xx1++;
		result = 0;
	}
	
	char axis[78][78];  int i, j;
	for (i = 0; i < 78; i++) {
		for (j = 0; j < 78; j++)
		{
			axis[i][j] = ' ';
		}
	}
	for (i = 0; i < 78; i++)
	{
		axis[i][39] = '|';
	}
	for (i = 0; i<78; i++)
	{
		axis[39][i] = '-';
	}
	
	a = q; int valY,valX;
	

	while (q != NULL && q->next != NULL) {
		valY = q->y; valX = q->x;
		if (valY == 12 || valY == 11 || valY == 10 || valY == 9 || valY == 8 || valY == 7 || valY == 6 || valY == 5
			|| valY == 4 || valY == 3 || valY == 2 || valY == 1 || valY == 0 || valY == -1 || valY == -2 || valY == -3
			|| valY == -4 || valY == -5 || valY == -6 || valY == -7 || valY == -8 || valY == -9 || valY == -10 || valY == -11 || valY == -12)
		{
			axis[-valY + 39][valX + 39] = '*';
			
		}
		q = q->next;
	}

	for (i = 0; i < 78; i++) {
		for (j = 0; j < 78; j++)
		{
			cout << axis[i][j];
		}
		cout << endl;
	}

}//end-Plot