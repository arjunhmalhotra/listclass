//========================== LIST CLASS [DEFINITIONS] =========================
// Arjun Malhotra
// List.h													(tab width 4)
// Class definition for List Class.
//=============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef LIST_H
#define LIST_H
#define DEFAULT_LIST_SIZE 10

//=============================================================================
// List Class
//=============================================================================

class List
{
private:
			int *pos;				// starting point of list	
			int len;				// size of list
			int cap;				// capacity of list = DEFAULT_LIST_SIZE
public:
			List ( void );						// default constructor
			List ( const List &);				// copy constructor ask kretch

		   ~List ( void );						// destructor
void		append ( int n );					// appending items
bool		isEmpty ( void );					// whether list is empty or not
int			length ( void );					// no. of items in the list
int&		operator[] ( int i );				// access/change operator
void		insert ( int item, int posn );		// inserting at a position
string		toString ( void );					// convert to string
void		remove ( int n );					// removing an index 
List		operator+ ( List l );				// concatenator
List		operator= ( const List l );			// assignment operator
void		clear ( void );						// clear list
		friend ostream & operator<< ( ostream &os, List l ); 	// cout
};

#endif

//=============================================================================
