#include<stdio.h>
#include<time.h>
#include <unistd.h>
#include <sys/wait.h>

// fork pipe in unistd.h
// read write also
int main(){
	static int cnt  = 0;
	int p[2];
	char* argv[2];
	argv[0] = "pingpong";
	argv[1] = "0";
	pipe(p);
	clock_t start, end;
	start = clock();
	while(end - start < CLOCKS_PER_SEC ){
		if( fork() == 0){
			close(p[0]);
			write(p[1],argv[0], 8);
			exit(0);
		}else{
			close(p[1]);
			wait(0);
			read(1,p[0],8);
			cnt += 8;
		}
		end = clock();
	}
	printf("%d bytes have been trans in %d clock\n", cnt, end-start);
	return 0;
}
