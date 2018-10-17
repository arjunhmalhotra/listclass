//========================== LIST CLASS [METHODS] =============================
// Arjun Malhotra
// List.cc							(tab width 4)
// Class Methods for List class.
//=============================================================================

#include "List.h"
#include "string.h"
#include <sstream>
using namespace std;

//=============================================================================
// CONSTRUCTORS & DESTRUCTOR
//=============================================================================
//-----------------------------------------------------------------------------
// Default Constructor 
// initializes a new list
//-----------------------------------------------------------------------------
						List::List ( void )
{
			pos = new int [DEFAULT_LIST_SIZE];
			len = 0;
			cap = DEFAULT_LIST_SIZE;
}
//-----------------------------------------------------------------------------
// Copy Constructor 
// initializes a new list
//-----------------------------------------------------------------------------
						List::List ( const List &l)
{
			len = l.len;
			cap = l.cap;
			pos = new int [l.cap];
			
			for ( int i = 0; i < len; i++ )
				pos[i] = l.pos[i];			
}
//-----------------------------------------------------------------------------
// Destructor
// initializes a new list
//-----------------------------------------------------------------------------
						List::~List ( void )
{
			delete pos;
}
//-----------------------------------------------------------------------------

//=============================================================================
// ACCESSORS
//=============================================================================
//-----------------------------------------------------------------------------
// isEmpty
// returns true if the list is empty, false if not
//-----------------------------------------------------------------------------
bool					List::isEmpty ( void )
{
		return ( len == 0 );
}
//-----------------------------------------------------------------------------
// length
// returns the number of items in the list
//-----------------------------------------------------------------------------
int						List::length ( void )
{
		return len;
}
//-----------------------------------------------------------------------------
// operator[]
// accesses (by reference) the item at the specified index
//-----------------------------------------------------------------------------
int&						List::operator[] ( int i )
{

		if ( i > cap )
			{cout << "ERROR: accessed invalid index" << endl;
			exit(1);}		// fail switch
		else
			return pos[i];
}
//-----------------------------------------------------------------------------
// cout
// overloads cout operator to print list
//-----------------------------------------------------------------------------
ostream & operator<< ( ostream &os, List l )
{
	for ( int i = 0; i < l.len; i++)
		os << l.pos[i] << " ";

	return os;
}
//-----------------------------------------------------------------------------
// toString
// "Prints" the list contents to a string and returns the string
//-----------------------------------------------------------------------------
string					List::toString ( void )
{
		stringstream ss;					// includes ss to switch to string

		for ( int i = 0; i < len; i++ )
		{
			ss << pos[i] << " ";
		}
		string str = ss.str();

		return str;
}
//-----------------------------------------------------------------------------

//=============================================================================
// MODIFIERS
//=============================================================================
//-----------------------------------------------------------------------------
// Append
// appends a new int onto the back of the list
//-----------------------------------------------------------------------------
void					List::append ( int n )
{
			if ( len == cap )
			{
				cap = 2 * cap;
				int *x = new int[cap];
				for ( int i = 0; i < len; i++ )
					x[i] = pos[i];				
				
				delete[] pos;			// deletes old array
				pos = x;				// reassigns to new pointer
				pos[len] = n;
							
			}
			else
				pos[len] = n;
			len += 1;
								
}
//-----------------------------------------------------------------------------
// Insert
// inserts a new value at the specified position and shifts 
//-----------------------------------------------------------------------------
void					List::insert ( int item, int posn )
{

		if ( posn > cap )
			{cout << "ERROR: accessed invalid index" << endl;
			exit(1);}				// fail switch

		else if ( len == cap )
		{	
			cap = cap * 2;
			int *x = new int [cap];
			
			for ( int i = 0; i < posn; i++ )	
				x[i] = pos[i];

			for ( int i = posn; i < cap; i++ )	
				x[i] = pos[i];

			delete[] pos;				// deletes old array
				pos = x;				// assigns to new pointer
		}

		for ( int i = len; i > posn; i-- )	
				pos[i] = pos[i-1];
		len++;
		pos[posn] = item;				// allocates item at index
	
}
//-----------------------------------------------------------------------------
// Remove
// removes an int at a specified location 
//-----------------------------------------------------------------------------
void					List::remove ( int n )
{		

		if ( n > cap )
			{cout << "ERROR: accessed invalid index" << endl;
			exit(1);}			// fail switch
		
		else
		{
			for ( int i = n; i < len-1; i++ )	
					pos[i] = pos[i+1];
		}
		len--;			
}	
//-----------------------------------------------------------------------------
// operator+
// concatenates two lists into a new list. doesn't change either existing list.
//-----------------------------------------------------------------------------
List					List::operator+ ( List l )
{
		List ret;

		for ( int i = 0; i < len; i++ )			// appends first list
			ret.append(pos[i]);		
			
		for ( int j = 0; j < l.len; j++ )		// appends second list
			ret.append(l.pos[j]);
			
		return ret;
}
//-----------------------------------------------------------------------------
// operator=
// assigns one list as another list
//-----------------------------------------------------------------------------
List					List::operator= ( const List l )
{
		delete pos;							// deletes old pointer
			
		len = l.len;
		cap = l.cap;
		pos = new int [l.cap];				// reassigns to new list

		for ( int i = 0; i < l.len; i++ )
			pos[i] = l.pos[i];

		return *this;
}
//-----------------------------------------------------------------------------
// clear
// removes all items from the list
//-----------------------------------------------------------------------------
void					List::clear ( void )
{
		len = 0;					// resets items to zero
}
//-----------------------------------------------------------------------------

//================================= END =======================================

