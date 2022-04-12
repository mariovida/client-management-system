#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#include<time.h>

void menu();
struct date {
	int month,day,year;
};
struct {
	char name[60];
  char surname[60];
  int acc_no;
  double phone;
	int sef;
	double oib;
	double br_kartice;
  struct date dob;
} add,upd,check,rem;

void new_acc() {
    int choice, i;
    FILE *ptr;
		srand(time(0));

    ptr=fopen("record2.dat","a+");
    account_no:
    system("cls");
	printf("\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
	printf("\n\n\t\t\t\tSTVARANJE NOVOG RACUNA\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
    printf("\n\n\t> Broj racuna:  ");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %lf %d %lf %lf\n",&add.acc_no,add.name,add.surname,&add.dob.month,&add.dob.day,&add.dob.year,&add.phone,&add.sef,&add.oib,&add.br_kartice)!=EOF)
    {
		if (check.acc_no==add.acc_no) {
			printf("\t*** BROJ RACUNA JE U UPOTREBI! ***");
            sleep(1);
            goto account_no;
		}
    }
    add.acc_no=check.acc_no;
    printf("\n\t> Ime:  ");
    scanf("%s",add.name);
    printf("\n\t> Prezime:  ");
    scanf("%s",add.surname);
    printf("\n\t> Datum rodenja (dd/mm/gggg):  ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\n\t> Broj telefona:  ");
    scanf("%lf",&add.phone);
		printf("\n\t> OIB:  ");
		scanf("%lf",&add.oib);
		add.sef=rand()%9000+1000;
		add.br_kartice=(rand()%70000+30000)*512;
	  fprintf(ptr,"%d %s %s %d/%d/%d %lf %d %lf %lf\n",add.acc_no,add.name,add.surname,add.dob.month,add.dob.day,add.dob.year,add.phone,add.sef,add.oib,add.br_kartice);
    fclose(ptr);
	printf("\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
    printf("\n\n\t\t\t\tRacun je USPJESNO napravljen!\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
    add_invalid:
    printf("\n\n\n\t> Unesite 1 za povratak u GLAVNI IZBORNIK ili 0 za IZLAZ:   ");
    scanf("%d",&choice);
    system("cls");
    if (choice == 1) {
		system("cls");
		menu();
	} else if(choice == 0)
		exit(0);
    else {
		printf("\n\n\tNEISPRAVAN UNOS!");
		Sleep(1);
		system("cls");
		goto add_invalid;
	}
}

void view_list() {
	FILE *view;
	int test=0, choice, i;
    view=fopen("record2.dat","r");

    system("cls");
    printf("\n\n\t\tIME\t\t\tPREZIME\n");

    while(fscanf(view,"%d %s %s %d/%d/%d %lf %d %lf %lf",&add.acc_no,add.name,add.surname,&add.dob.month,&add.dob.day,&add.dob.year,&add.phone,&add.sef,&add.oib,&add.br_kartice)!=EOF) {
    	printf("\n\t\t%s\t\t\t%s",add.name,add.surname);
      test++;
    }

    fclose(view);
		printf("\n\n");
		for(i=0; i<=75; i++) {
			printf("*");
		}
    if (test==0) {
		system("cls");
		printf("\n\n\t\t\t\t*** NEMA ZAPISA ***\n\n\t");
		for(i=0; i<=65; i++) {
			printf("*");
		}
	}

  view_list_invalid:
	printf("\n\n\t> Unesite 1 za povratak u GLAVNI IZBORNIK ili 0 za IZLAZ:   ");
	scanf("%d",&choice);
  system("cls");
  if (choice == 1) {
		system("cls");
		menu();
	} else if(choice == 0)
		exit(0);
	else {
		printf("\n\n\tNEISPRAVAN UNOS!");
		Sleep(1);
		system("cls");
		goto view_list_invalid;
	}
}

void edit(void) {
  int choice,test=0, main_exit;
  FILE *old,*newrec;
  old=fopen("record.dat","r");
  newrec=fopen("new.dat","w");

  printf("\n\t> Unesite broj racuna:  ");
  scanf("%d",&upd.acc_no);
  while(fscanf(old,"%d %s %s %d/%d/%d %lf %d %lf %lf",&add.acc_no,add.name,add.surname,&add.dob.month,&add.dob.day,&add.dob.year,&add.phone,&add.sef,&add.oib,&add.br_kartice)!=EOF) {
    if (add.acc_no==upd.acc_no) {
			test=1;
      printf("\n\tKoji podatak zelite promijeniti?\n\n\t\t1. BROJ TELEFONA\n\t\t2. NIJE U FUNKCIJI\n\n\t> Unesite odabir:  ");
      scanf("%d", &choice);
      system("cls");
      if(choice == 1) {
				printf("\n\t> Unesite novi broj telefona:  ");
        scanf("%lf", &upd.phone);
        fprintf(newrec,"%d %s %s %d/%d/%d %lf %d %lf %lf\n",add.acc_no,add.name,add.surname,add.dob.month,add.dob.day,add.dob.year,upd.phone,add.sef,add.oib,add.br_kartice);
        system("cls");
        printf("\n\n\t*** PROMJENE SU SPREMLJENE! ***");
      } else if(choice == 2) {
				printf("OVA OPCIJA JOS NIJE DOSTUPNA!");
				/*scanf("%lf",&upd.phone);
				fprintf(newrec,"%d %s %s %d/%d/%d %lf\n",add.acc_no,add.name,add.surname,add.dob.month,add.dob.day,add.dob.year,upd.phone);
				system("cls");
        printf("Changes saved!");*/
				sleep(1);
				menu();
      }
    } else

			fprintf(newrec,"%d %s %s %d/%d/%d %lf %d %lf %lf\n",add.acc_no,add.name,add.surname,add.dob.month,add.dob.day,add.dob.year,add.phone,add.sef,add.oib,add.br_kartice);
  }

  fclose(old);
  fclose(newrec);
  remove("record.dat");
  rename("new.dat","record.dat");

	if(test!=1) {
		printf("\n\t\t*** NEMA ZAPISA ***\a\a\a");
    edit_invalid:
    printf("\n\n\n\t> Unesite 0 ako zelite pokusati PONOVNO, 1 za povratak u GLAVNI IZBORNIK ili 2 za IZLAZ:   ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
			menu();
    else if (main_exit==2)
      exit(0);
    else if(main_exit==0)
      edit();
    else {
			printf("\n\n\tNEISPRAVAN UNOS!\a");
      goto edit_invalid;
		}
  } else {
		view_list_invalid:
		printf("\n\n\t> Unesite 1 za povratak u GLAVNI IZBORNIK ili 0 za IZLAZ:   ");
    scanf("%d",&main_exit);
    system("cls");
		if (choice == 1) {
			system("cls");
			menu();
		} else if(choice == 0)
			exit(0);
		else {
			printf("\n\n\tNEISPRAVAN UNOS!");
			Sleep(1);
			system("cls");
			goto view_list_invalid;
		}
	}
}

void erase(void) {
  FILE *old,*newrec;
  int main_exit,test=0,i,choice;
  old=fopen("record2.dat","r");
  newrec=fopen("new.dat","w");

	printf("\n\t> Unesite broj racuna koji zelite obrisati:  ");
  scanf("%d",&rem.acc_no);
  while(fscanf(old,"%d %s %s %d/%d/%d %lf %d %lf %lf",&add.acc_no,add.name,add.surname,&add.dob.month,&add.dob.day,&add.dob.year,&add.phone,&add.sef,&add.oib,&add.br_kartice)!=EOF) {
  	if(add.acc_no!=rem.acc_no)
    	fprintf(newrec,"%d %s %s %d/%d/%d %lf %d %lf %lf\n",add.acc_no,add.name,add.surname,add.dob.month,add.dob.day,add.dob.year,add.phone,add.sef,add.oib,add.br_kartice);
    else {
			test++;
			try_again:
			printf("\n\t> Jeste li sigurni da zelite ukloniti taj racun? [1 = DA | 0 = NE]:  ");
			scanf("%d", &choice);
			if(choice == 1) {
				printf("\n\t> BRISANJE RACUNA");
				for(i=0; i<=3; i++) {
					sleep(1);
					printf(".");
				}
      	printf("\n\n\t\t*** RACUN JE USPJESNO OBRISAN! ***\n");
			} else if(choice == 0) {
				menu();
			} else {
				printf("\n\t\tNEISPRAVAN UNOS!\n");
				sleep(1);
				goto try_again;
			}
    }
  }

	fclose(old);
  fclose(newrec);
  remove("record2.dat");
  rename("new.dat","record2.dat");
  if(test==0) {
  	printf("\n\t\t*** NEMA ZAPISA ***\a\a\a");
  	erase_invalid:
    printf("\n\n\n\t> Unesite 0 ako zelite pokusati PONOVNO, 1 za povratak u GLAVNI IZBORNIK ili 2 za IZLAZ:   ");
    scanf("%d",&main_exit);
    if (main_exit==1)
      menu();
  	else if (main_exit==2)
      exit(0);
    else if(main_exit==0)
      erase();
    else {
			printf("\n\n\tNEISPRAVAN UNOS!");
			sleep(1);
      goto erase_invalid;
		}
  } else {
		printf("\n\n\t");
		for(i=0; i<=70; i++) {
			printf("*");
		}
		printf("\n\n\t> Unesite 1 za povratak u GLAVNI IZBORNIK ili 0 za IZLAZ:   ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
      menu();
    else
      exit(0);
  }
}
void message_alert(void) {
	int i;

	system("cls");
	printf("\n\n\n\t\tNIKADA ME NECETE PRONACI, ALI SE NASTAVITE TRUDITI");
	printf("\n\n\n\t> BRISANJE SUSTAVA");
	for(i=0; i<=5; i++) {
		sleep(1);
		printf(".");
	}
	system("cls");
	printf("\n\n\t\tSUSTAV OBRISAN\n\n\t\t");
	sleep(3);
	system("cls");
	exit(0);
}

void see(void) {
	FILE *ptr;
	int test=0,rate, main_exit;
	int i, choice;
  ptr=fopen("record2.dat","r");
  printf("\n\t> Unesite broj racuna:  ");
  scanf("%d",&check.acc_no);
  while (fscanf(ptr,"%d %s %s %d/%d/%d %lf %d %lf %lf",&add.acc_no,add.name,add.surname,&add.dob.month,&add.dob.day,&add.dob.year,&add.phone,&add.sef,&add.oib,&add.br_kartice)!=EOF) {
		if(add.acc_no==check.acc_no) {
      system("cls");
      test=1;
      printf("\n\n\n\t> BROJ RACUNA:  #%d\n\t> IME:  %s\n\t> PREZIME:  %s\n\t> DATUM RODENJA (dd/mm/gggg):  %d/%d/%d \n\t> BROJ TELEFONA:  0%.0lf\n\t> OIB:  %.0lf\n\t> BROJ KARTICE:  %.0lf\n\n\n\t> LOKACIJA SEFA:  %d\n\n",add.acc_no,add.name,add.surname,add.dob.day,add.dob.month,add.dob.year,add.phone,add.oib,add.br_kartice,add.sef);
			printf("\t");
			for(i=0; i<=70; i++) {
				printf("*");
			}
		}
	}
  fclose(ptr);
  if(test!=1) {
    printf("\n\t\t*** NEMA ZAPISA ***\a\a\a");
    see_invalid:
    printf("\n\n\t> Unesite 0 ako zelite pokusati PONOVNO, 1 za povratak u GLAVNI IZBORNIK ili 2 za IZLAZ:   ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
      menu();
    else if (main_exit==2)
      exit(0);
    else if(main_exit==0)
      see();
    else
      system("cls");
      printf("\n\n\tNEISPRAVAN UNOS!\a");
      goto see_invalid;
	} else {
		view_list_invalid:
		printf("\n\n\t> Unesite 1 za povratak u GLAVNI IZBORNIK ili 0 za IZLAZ:   ");
    scanf("%d",&choice);
    system("cls");
		if (choice == 1) {
			system("cls");
			menu();
		} else if(choice == 0)
			exit(0);
		else {
			printf("\n\n\tNEISPRAVAN UNOS!");
			Sleep(1);
			system("cls");
			goto view_list_invalid;
		}
  }
}

void menu() {
	int choice, i;
	system("cls");
	printf("\n\n\t");
	for(i=0; i<=80; i++) {
		printf("*");
	}
	printf("\n\n\t\t\t\t\t>  GLAVNI IZBORNIK  <");
    printf("\n\n\t\t\t1. NOVI RACUN\n\n\t\t\t2. PROMJENA POSTOJECEG RACUNA\n\n\t\t\t3. INFORMACIJE O RACUNU\n\n\t\t\t4. BRISANJE RACUNA\n\n\t\t\t5. LISTA KLIJENATA\n\n\t\t\t7. IZLAZ\n\n\t");
    for(i=0; i<=80; i++) {
		printf("*");
	}
	printf("\n\n\t> Unesite odabir:   ");
	scanf("%d",&choice);

	system("cls");
	switch(choice) {
    case 1:new_acc();
    break;
    case 2:edit();
    break;
    case 3:see();
    break;
    case 4:erase();
    break;
    case 5:view_list();
    break;
		case 6:message_alert();
		break;
    case 7:
		printf("\n\n\tZATVARANJE SUSTAVA");
		for(i=0; i<=2; i++) {
			sleep(1);
			printf(".");
		}
		system("cls");
		exit(0);
  }
}

int main(void) {
	char pass[10], password[10]="ulaz";
	int i, choice;
	system("cls");
	printf("\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
	printf("\n\n\t\t\t\t     PROJEKT BY MV");
	printf("\n\n\t");
	for(i=0; i<=70; i++) {
		printf("*");
	}
	printf("\n\n\t> Unesite lozinku za prijavu:   ");
	scanf("%s", pass);

	if(strcmp(pass, password)==0) {
		printf("\n\t> LOZINKA ISPRAVNA!\n\t> UCITAVANJE");
		for(i=0; i<=3; i++) {
			/*sleep(1);*/
			printf(".");
		}
		system("cls");
		menu();
	} else {
		printf("\n\t  *** LOZINKA NEISPRAVNA! ***");
		login_try:
		printf("\n\t> Zelite li pokusati ponovno? [ 1=DA | 0=NE ]: ");
		scanf("%d", &choice);
		if (choice==1) {
			system("cls");
			main();
		} else if (choice==0) {
			system("cls");
			printf("\n\n\tZATVARANJE SUSTAVA");
			for(i=0; i<=2; i++) {
				sleep(1);
				printf(".");
			}
			printf("\n");
			return 0;
		} else {
			printf("\n\n\tNEISPRAVAN UNOS!");
			sleep(1);
			system("cls");
			goto login_try;
		}
	}

	return 0;
}
