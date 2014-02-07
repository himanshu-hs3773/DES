#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <inttypes.h>
#include <getopt.h> 

#include "DES.h"

//////////////////////////////////////////////////////
//                 GLOBAL VARIABLES                //
////////////////////////////////////////////////////

bool encrypt = true;
bool output = false;

static FILE * outputFile;

//////////////////////////////////////////////////////
//                 FUNCTIONS                       //
////////////////////////////////////////////////////

// usage 
static void usage(int status)
{
    if(status == EXIT_SUCCESS)
    {
	fprintf(stdout,"Usage: app [OPTION] FILE\n"
		"Encrypt or Descrypt DES.\n\n"
		" -d, --decrypt     decrypt DES from input file\n"
		" -e, --encrypt     encrypt DES from input file\n"
		" -h, --help        display this help\n"
		" -o, --output=FILE write result to FILE\n"
		" -k, --key=KEY     required key to be used\n");
    }
    else
    {
	fprintf(stderr, "Try 'app --help' for more information.\n");
    }
    exit(status);
}

int main(int argc, char ** argv)
{
    //////////////////////////////////////////////////////
    //                 OPTION PARSER                   //
    ////////////////////////////////////////////////////

    FILE * inputFile = NULL; //inputFile

    int optc = 0;

    char * key;

    //short options
    const char* short_opts = "dehk:o:";

    //long options 
    const struct option long_opts[] = 
	{ 
	    {"decrypt",        no_argument, NULL, 'd'},
	    {"encrypt",        no_argument, NULL, 'e'},
	    {"help",           no_argument, NULL, 'h'},
	    {"key",      required_argument, NULL, 'k'},
	    {"output",   required_argument, NULL, 'o'},
	    {NULL,                       0, NULL,   0}
	}; 

    while((optc = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1)
    { 
	switch(optc)
	{ 
	case 'd': // decrypt mode
	    encrypt = false;
	    break;

	case 'h': // help
	    usage(EXIT_SUCCESS);
	    break;

	case 'o': // output file
	    outputFile = fopen(optarg, "w");
	    if(outputFile == NULL)
	    {
		// weird error
		// what about: "don't have permission to write output file"?
		fprintf(stderr, "Can't open ouput file\n");
		return EXIT_FAILURE;
	    }
	    output = true;
	    break;

	case 'k': // key
	    if(optarg)
	    {
		key = optarg;
	    }
	    else
	    {
		usage(EXIT_FAILURE);
	    }
	    break;

	default : // no arguments
	    usage(EXIT_FAILURE); 
	}
    }	

    // Check if there is a input file and if we can open it
    if(argv[optind] == NULL)
    {
	fprintf(stderr, "Missing input file argument\n");
	usage(EXIT_FAILURE);
    }

    inputFile = fopen(argv[optind], "r");
    if(inputFile == NULL)
    {
	fprintf(stderr, "Can't find input file\n");
	usage(EXIT_FAILURE);
    }

    

    //////////////////////////////////////////////////////
    //                      APP                        //
    ////////////////////////////////////////////////////
    
<<<<<<< HEAD
    

    //
    // 1. verify parity key
    //
    /*
    // test key parity bits
    if(!key_parity_verify(*key))
    {
    printf("The key you used is malformated\n");
    exit(EXIT_FAILURE);
    }
    */
=======
    int i;
    uint64_t u_key;
    for(i=0;i<64;i++)
    {
        u_key=u_key<<1;
        u_key = (uint64_t)key;
    }
    for(i = 0; i < 64; i++)
    {
	if( ((u_key << i) & 0x8000000000000000) == (uint64_t)0)
	    printf("0");
	else
	    printf("1");
    }
    // but should we do that o.O ?
    // why not keeping uint64_t all the time?
>>>>>>> b5b72009242bee9deacd7f71bf9e8fa30e554e2a

    //
    // 2. key schedule
    //

    //
    // 3. encrypt or decrypt ?
    //
    if(encrypt)
    {

    }
    else
    {

    }

    unsigned char input[8];

    while(fgets(input, 9, inputFile)!=NULL)
    {
        int i,j;
        uint64_t paquet=0;
	for( i = 0; i <= 7; ++i )
	{
		paquet= paquet << 8;
    		paquet |= (uint64_t)input[i];
    		
	}
    }

    //paquet est le block de 64 bits à encrypter

    //On appelle ici la fonction d'encryptage
    //
    // 4. initial permutation
    //

    //
    // 5. read file and rounds
    //

    //
    // 6. final permutation
    //

    //
    // 7. output
    //

    // default output file
    if(output == false) 
	outputFile = fopen("a.txt", "w");

    //
    return EXIT_SUCCESS;
}
