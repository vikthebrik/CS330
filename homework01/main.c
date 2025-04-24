#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>
/**
 * 7) Implement the function 'find_file()' which recursively searches the provided directory and its subdirectories to locate any file that matches the provided file name. Make sure to read the provided code FIRST before beginning the assignment.

8) Test your code against the provided directory structure and answer files. Use the following command to compile the code:

   gcc -std=c11 -D_DEFAULT_SOURCE main.c

   For example, executing './a.out . b.out' should generate the same output as what is shown in the 'ans1' file (it may be in a slightly different order).

   Executing './a.out . a.out' should generate the same output as what is shown in the 'ans2' file (it may be in a slightly different order).

   Play around with different directory structures and file names to make sure your code works correctly - your assignment will be evaluated on a different input directory structure and file names.

9) Commit your code and push it to Bitbucket.

10) Make sure the change has been successfully pushed to Bitbucket by going to your repo on the Bitbucket website and reading your main.c file


Part 2 (Survey)

11) Goto to the Google Forms survey (https://forms.gle/f51789hSxScZ7u2W8Links to an external site. (Links to an external site.)) and fill out the survey.

       a) It will be used to collect your names and Bitbucket Workspace ID
**/
void usage(int argc, char** argv);
void find_file(char* dir_name, char* file_to_find);

int main(int argc, char** argv)
{
	DIR* dp;
	struct dirent* dirp;

	// check if this application is being used properly
	usage(argc, argv);

	// check to see if provided directory is accessible
	errno = 0;
	dp = opendir(argv[1]);
	if(dp == NULL) {
		switch(errno) {
			case EACCES:
				fprintf(stderr, "Permission denied\n");
				break;
			case ENOENT:
				fprintf(stderr, "Directory does not exist\n");
				break;
			case ENOTDIR:
				fprintf(stderr, "'%s' is not a directory\n", argv[1]);
				break;	
		}
	}

	// print all files in the directory
	int cnt = 0;
	while((dirp = readdir(dp)) != NULL) {
	
		fprintf(stdout, "%d: %s", cnt, dirp->d_name);
		if(dirp->d_type == DT_DIR) {
			printf("\t directory");
		}
		printf("\n");
		cnt++;
	}

	// close the directory 
	closedir(dp);


	// now, recursivey traverse the directory structure to find the provided
	// file name
	char* file_to_find = argv[2];
	find_file(argv[1], file_to_find);

	return 0;
}


void usage(int argc, char** argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ./%s directory_name file_to_find\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

void find_file(char* dir_name, char* file_to_find)
{
//Create the same setup as the main file

	DIR* direct;
	char path[PATH_MAX];
	struct dirent* enter;

	//open the directory
	direct = opendir(dir_name);

	//Check if directory is invalid
	if((direct) == NULL)
	{
		fprintf(stderr,"Directory %s is invalid and cannot be opened\n", dir_name);
		return;
	}

	//Traverse through similar to how the print section in main
	while((enter = readdir(direct)) != NULL)
	{
		if(strcmp(enter->d_name, ".") == 0 || strcmp(enter->d_name, "..") == 0)
		{
			continue;//Skip
		}

		snprintf(path, PATH_MAX, "%s/%s",dir_name, enter->d_name);

		//check if the enter is a valid directory
		if(enter->d_type == DT_DIR)
		{
			//Recursively search the sub
			find_file(path, file_to_find);
		}
		else
		{
			//Check if the enter matches find_to_find
			if(strcmp(enter->d_name, file_to_find) == 0)
			{
				printf("Found File: %s\n", dir_name);
			}
		}
	}

	closedir(direct);

}


