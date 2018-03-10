#include <stdio.h>
double calBMI (double w, double h);
void category (double bmi);


int main()
{
    double h, w, bmi, bmi_total; // h is height. w is weight.
    char name[100];
    int uw=0, nw=0, ow=0, ob=0, n=0, i=0, nc; // uw is underweight, nw is normal weight and so on. n is no. of students
    double lbmi[100]; //to store bmi for the use of listing students later on
    char lname[100][100]; // to store name for the use of listing students later on

    FILE *fr,*fp;
    fr = fopen ("hw.dat", "r"); //to read data from hw.dat
    fp = fopen ("hw.out", "w"); //to write data into hw.out

    //printing the top of the table
    printf ("Name\t\t\theight(m)\tweight(kg)\tBMI\tCategory");
	printf ("\n============\t\t=========       ==========      ====    =========\n");
	//print it in hw.out as well
	fprintf (fp,"Name\t\t\theight(m)\tweight(kg)\tBMI\tCategory");
	fprintf (fp, "\n============\t\t=========       ==========      ====    =========\n");

	//to read hw.dat file line by line
    while (fscanf(fr,"%99[^0-9] %lf %lf ", name, &h, &w)==3)
    {
        //to display data on screen
        printf ("%s   %.2lf \t    %.0lf", name, h/100, w);
        bmi = calBMI(h, w);
        printf ("\t\t%.2lf\t", bmi);
        category (bmi);

        //copy into 2d array to be used later on in the selected listing
        lbmi[i] = bmi;
        strcpy(lname[i], name);
        i++;

        // to print data into hw.out file
        fprintf (fp, "%s   %.2lf \t    %.0lf", name, h/100, w);
        fprintf (fp, "\t\t%.2lf\t", bmi);
        if (bmi < 18.5) {fprintf (fp, "underweight\n"); uw++;}
        else if (bmi < 25) {fprintf (fp, "normalweight\n"); nw++;}
        else if (bmi < 30) {fprintf (fp, "overweight\n"); ow++;}
        else {fprintf (fp, "obese\n"); ob++;}

        bmi_total += bmi;
        n++; // to calculate number of students

    }
    //to print computed data on screen
    printf ("Number of student underweight\t: %d\n", uw);
    printf ("Number of student normal weight\t: %d\n", nw);
    printf ("Number of student overweight\t: %d\n", ow);
    printf ("Number of student obese\t\t: %d\n", ob);
    printf ("Average BMI of all students\t: %.2lf\n", bmi_total/n);
    printf ("Average category\t\t: ");
    category (bmi_total/n); //using formula average bmi = bmi_total/n

    //print selection list
    printf ("\n\t\t 1. Underweight\n");
    printf ("\t\t 2. Normalweight\n");
    printf ("\t\t 3. Overweight\n");
    printf ("\t\t 4. Obese\n");
    //prompt user to enter category
    printf ("Please enter the category: ");
    scanf ("%d", &nc);
    printf ("List of students: \n");
    //selection for the students to be printed
    //to print selected student based on number entered
    if (nc==1)
    {
        int j=1;
        for (i=0;i<n;i++)
        {
            if (lbmi[i]<18.5) {printf ("%d. %s\n", j, lname[i]); j++;}
        }
    }

    if (nc==2)
    {
        int j=1;
        for (i=0;i<n;i++)
        {
            if (lbmi[i]>=18.5&&lbmi[i]<25) {printf ("%d. %s\n", j, lname[i]); j++;}
        }
    }

    if (nc==3)
    {
        int j=1;
        for (i=0;i<n;i++)
        {
            if (lbmi[i]>=25&&lbmi[i]<30) {printf ("%d. %s\n", j, lname[i]); j++;}
        }
    }


    if (nc==4)
    {
        int j=1;
        for (i=0;i<n;i++)
        {
            if (lbmi[i]>=30) {printf ("%d. %s\n", j, lname[i]); j++;}
        }
    }

    //to print the computed data into hw.out as well
    fprintf (fp, "Number of student underweight\t: %d\n", uw);
    fprintf (fp, "Number of student normal weight\t: %d\n", nw);
    fprintf (fp, "Number of student overweight\t: %d\n", ow);
    fprintf (fp, "Number of student obese\t\t: %d\n", ob);
    fprintf (fp, "Average BMI of all students\t: %.2lf\n", bmi_total/n);
    fprintf (fp, "Average category\t\t: ");
    if (bmi_total/n < 18.5) fprintf (fp, "underweight\n");
    else if (bmi_total/n < 25) fprintf (fp, "normalweight\n");
    else if (bmi_total/n < 30) fprintf (fp, "overweight\n");
    else fprintf (fp, "obese\n");

    fclose (fr);
    fclose (fp);
    return 0;
}

// function to calculate bmi
double calBMI(double h, double w)
{
    double bmi;
    bmi = w / (h*h) *10000;

    return (bmi);
}

// function to categorize weight based on bmi
void category (double bmi)
{
    if (bmi < 18.5) printf ("underweight\n");
    else if (bmi < 25) printf ("normalweight\n");
    else if (bmi < 30) printf ("overweight\n");
    else printf ("obese\n");

    return;
}

