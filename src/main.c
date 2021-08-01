#include <stdio.h>
#include <stdlib.h>


int DISASSEMBLE(const unsigned char *BinaryBuffer, int PC);


int main(int argc, char const *argv[])
{

	const char *FileName = "invaders.h";

	int size = 0;

	int ProgramCounter = 0;

	FILE *FilePtr = fopen(FileName , "rb");

	if ( FilePtr == NULL )
	{
		perror("fopen");

		exit( EXIT_FAILURE );
	}


	fseek(FilePtr, 0, SEEK_END);
	size = ftell(FilePtr);
	fseek(FilePtr, 0, SEEK_SET);

	const unsigned char *BinaryBuffer = ( char * ) malloc ( size );

	fread(BinaryBuffer , size , 1, FilePtr );

	fclose( FilePtr );

	// 8080 start executing from 0x200 but for semplicity we skip this detail

	while ( ProgramCounter < size /* + 0x200 */)
	{

		ProgramCounter = ProgramCounter + DISASSEMBLE(BinaryBuffer,ProgramCounter);

	}

	free(BinaryBuffer );

	return 0;
}

