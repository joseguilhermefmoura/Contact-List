#include "predef.h"
#include "main_functions.h"

int main(){
	/* Initializing the main list */
	List 		    *mainList;
	ListControl     *mainListControl;
	mainList 		= (List *) malloc(sizeof(List));
	mainListControl = (ListControl *) malloc(sizeof(ListControl));
	mainListControl->first = NULL;
	mainListControl->last  = NULL;
	
	char ch;  /* Menu variables */
	int  Ich; /* to get the option. */
	
	{ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
		while(1){
			clearScreen();          
			printf("\n");
			printf("\tWelcome to your contact list.\n");
			printf("\tTo continue, choose an option:\n");
			printf("\n");
			printf("\t-> [ 1 ] Add a new contact;\n");
			printf("\t-> [ 2 ] See your full contact list;\n");
			printf("\t-> [ 3 ] Search for an specific contact;\n");
			printf("\t-> [ 4 ] Update a contact;\n");
			printf("\t-> [ 5 ] Delete a contact;\n");
			printf("\t-> [ESC] Exit the program.\n");
			printf("\n");
			printf("\t-> ");
			ch = getch();
			if(ch == 27)
				Ich = 27;
			else
				Ich = (int)((char)ch - '0'); // The numbers 0-9 are laid out in ascending order in terms of character codes. Hence subtracting '0' from the char value will produce an offset that is equal to the actual number in question.
			
			switch(Ich){
				case 1: 
					mainList = addNewElement(mainList, mainListControl);
					break;
				case 2:
					printFullList(mainList, mainListControl);
					break;
				case 3:
					searchInList(mainList, mainListControl);
					break;
				case 4:
					updateAnElement(mainList, mainListControl);
					break;
				case 5:
					removeAnElement(mainList, mainListControl);
					break;
				case ESC:
					clearScreen();
					exit(EXIT_SUCCESS);
					break;
				default:
					break;
			}
		}
	} /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  END OF MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	
	return 0;
}

