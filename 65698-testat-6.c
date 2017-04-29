#include <stdio.h>
#include <stdlib.h>
#include "testat-6.h"
//Rechnung
/*f(x)= ax^2 + bx +c
f'(x) = 2ax + b = 0
2ax = - b
x = -b/(2*a)*/

int scheitelhoehe(struct parabel *p, double *y) {
	int rc;
	double a = p->a, b = p->b, c=p->c;
	double x1, sh;
	if(a!=0){
		x1 = (-b)/(2*a);
		sh = a*x1*x1 + b*x1 + c;
		*y = sh;
		rc = 0;
	}
	else{
		rc = 1;
	}

    return rc;

}

void sort_parabeln(struct parabel * p, int n) {
    int i, j;
    double h_tausch, p_tausch_a, p_tausch_b, p_tausch_c;
    double hoehe[n];
	double rs; 
    for(i=0; i<n; i++){
    	if(scheitelhoehe(p, &rs)==0){
			hoehe[i] = rs;
    	}
    	else{
    		hoehe[i]= 1E300;
    	}
    	
    }

    for(i = 0; i < n-1; i++){
    	for(j=0; j < (n-1-i); j++){
    		if (hoehe[j] > hoehe[j+1]){
    			h_tausch = hoehe[j];
					p_tausch_a = p[j].a;
					p_tausch_b = p[j].b;
					p_tausch_c = p[j].c;
    			hoehe[j] = hoehe[j+1];
    				p[j].a= p[j+1].a;
    				p[j].b= p[j+1].b;
    				p[j].c= p[j+1].c;
    				p[j+1].a = p_tausch_a;
    				p[j+1].b = p_tausch_b;
    				p[j+1].c = p_tausch_c;
    		}
    	}
    }
}

int main() {
    struct parabel p[] = {
        {1,2,3},
        {2,5,-19},
        {0,0,0},
        {-1,0,0}
    };
    double y;
    printf("Index 1 ist eine echte Parabel: %d\n", scheitelhoehe(p, &y) == 0);
    sort_parabeln(p, sizeof(p) / sizeof(struct parabel));
    return 0;
}

