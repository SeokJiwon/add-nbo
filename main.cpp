#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <arpa/inet.h>


uint32_t read_ntohl(char *f){
	FILE *fp=fopen(f,"rb");
	uint32_t n;
	fread(&n,1,sizeof(uint32_t),fp);
	fclose(fp);
	return ntohl(n);
}

int main(int argc, char *argv[]){

	if(argc<3){
		printf("Usage: %s <filename1> <filename2>\n",argv[0]); 
	}

	uint32_t n1=read_ntohl(argv[1]);
	uint32_t n2=read_ntohl(argv[2]);
	uint32_t s=n1+n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,s,s);
	return 0;
}


