/***
	YAHIAOUI MED YASSINE
						***/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
#include<omp.h>
#define n 3000



int main(){
	double DebutSeq ,FinSeq ,DebutParal ,FinParal ,ResultatSeq ,SommeSeq ,ResultatParal ,SommeParal;
	int i;
	
	// debut de calcul sequantielle
	
	DebutSeq=clock();
	SommeSeq=0;
	for(i=0;i<n*400;i++){
		SommeSeq=SommeSeq+pow(-1,i)/(2*i+1);
	}
	ResultatSeq=SommeSeq*4;
	
	FinSeq=clock();
	
	printf("pi sequantielle = %f \n",ResultatSeq);
    printf("temps execution sequetiel: %f\n",  (double)(FinSeq-DebutSeq)/CLOCKS_PER_SEC); 
    
    //debut de calcul parallel
    SommeParal=0;
    
    #pragma omp parallel 
    {
	DebutParal = clock();
	#pragma omp for reduction( +: sum ) 
    {
    
    	for(i=0;i<n*400;i++){
	    SommeParal=SommeParal+pow(-1,i)/(2*i+1);
	}
	ResultatParal=SommeParal*4;
	FinParal=clock();
	printf("pi parallel = %f \n",ResultatParal);
    printf("temps execution parallel: %f\n",  (double)(FinParal-DebutParal)/CLOCKS_PER_SEC); 
	}
	
    } 
    
     
}
