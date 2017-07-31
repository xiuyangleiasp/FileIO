#include"stdio.h"

void save_var(int i, float loss, float avg_loss, char *filename){
	FILE *fp = fopen(filename, "a+");
	
	fprintf(fp,"%d %f %f\n",i,loss,avg_loss);

	fclose(fp);
}

int main(){

	int i = 0;
	char filename[256] = "logs.txt";
	float loss = 0.0, avg_loss = 0.0;
	for (i = 0; i < 10; i++){
		loss += i;
		avg_loss += loss;
		save_var(i, loss, avg_loss, filename);
	}

	FILE *fp = fopen(filename, "r");

	int j;

	while (fscanf(fp, "%d %f %f\n", &j, &loss, &avg_loss)!=EOF){
		
		printf("%d %f %f\n",j,loss,avg_loss);
	}

	fclose(fp);
	system("pause");
	return 0;
}