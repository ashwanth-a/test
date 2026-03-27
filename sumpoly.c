#include<stdio.h>
     struct term
     {
         int coeff;
         int exp;
     };
     int main()
     {
        struct term p1[20], p2[20], psum[20];
        int n1, n2, i, j, k;
        printf("enter the number of terms in poly 1\n");
        scanf("%d", &n1);
        for(i=0; i<n1; i++)
        {
            printf("input term %d (coeff and exp)\n", i+1);
            scanf("%d %d",&p1[i].coeff, &p1[i].exp);
        }
        printf("enter the number of terms in poly 2\n");
        scanf("%d", &n2);
        for(i=0; i<n2; i++)
        {
            printf("input term %d (coeff and exp)\n", i+1);
            scanf("%d %d",&p2[i].coeff, &p2[i].exp);
        }
        printf("The first polynomial is   ");
        for(i=0; i<n1; i++)
        {
            printf("%dx^%d ", p1[i].coeff, p1[i].exp);
            if(i<n1-1)
                printf("+ ");
        }
        printf("\nThe second polynomial is   ");
        for(i=0; i<n2; i++)
        {
            printf("%dx^%d ", p2[i].coeff, p2[i].exp);
            if(i<n2-1)
                printf("+ ");
        }
        i=0; j=0; k=0;
        while (i<n1 && j<n2)
        {
            if(p1[i].exp == p2[j].exp)
            {
                psum[k].coeff = p1[i].coeff + p2[j].coeff;
                psum[k].exp = p1[i].exp;
                i++; j++; k++;
            }
            else if(p1[i].exp > p2[j].exp)
            {
                psum[k].coeff = p1[i].coeff;
                psum[k].exp = p1[i].exp;
                i++; k++;
            }
            else{
                psum[k].coeff = p2[j].coeff;
                psum[k].exp = p2[j].exp;
                j++; k++;
            }
        }
            while(i<n1)
            {
                psum[k].coeff = p1[i].coeff;
                psum[k].exp = p1[i].exp;
                i++; k++;
 
            }
            while(j<n2)
            {
                psum[k].coeff = p2[j].coeff;
                psum[k].exp = p2[j].exp;
                j++; k++;
 
            }

            
            printf("\nThe sum polynomial is\n");
            for(i=0; i<k; i++)
            {
                printf("%dx^%d ", psum[i].coeff, psum[i].exp);
                if(i<k-1)
                    printf("+ ");
            }   


        
        





        return 0;   
     }   

