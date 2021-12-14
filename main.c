/*TODO: put the text in a box
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#define L_LENG 30
//max size of lines that are printed to stdout
#define CAT_LENG 20
//size that a face can be

void print_help(void)
{
	printf("kittysay: <OPTIONS> <STRING>\n"
		   "options:\n"
		   "	-h print this help message\n"
		   "	-k give me your own kitty! note that you'll have to it\n"
		   "	   in quotes\n");
}

int main(int argc, char *argv[])
{
	if(argc == 1){
		print_help();
		exit(0);
	}
	
	//I like the default cat is nice (^_^)
	char cat[CAT_LENG] = {"(^·_·^ ) "};

	int opt = 0;
	while((opt = getopt(argc, argv, "hk:")) != -1){
		switch (opt){
			case 'h':
				print_help();
				exit(0);
				break;
				
			case 'k':
				strcpy(cat, optarg);
				break;
				
			default:
				break;

		}
	}

	int len = L_LENG;

	for(int i = optind; i < argc; i++){

		if(len < 0){
			printf("\n");
			printf("%s ", argv[i]);
			len = L_LENG;
			
		}else{
			printf("%s ", argv[i]);
			len -= strlen(argv[i]) + 1;
			
		}
	}
	
	printf("\n"
		   "\t\\ \n"
		   "\t%s \n", cat);

	return (0);
}
