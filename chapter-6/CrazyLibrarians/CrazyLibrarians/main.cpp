#include "czlib.h"
#include <windows.h>

int main()
{

	cout << "Welcome to Crazy Librarians.\n\n";
	cout << "Answer the following questions to help create a new story.\n";
	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");

	tellStory(name, noun, number, bodyPart, verb);

	return 0;
}